#include "Scene.h"

#include "sqlite3.h"

#include <string_view>


std::vector<GameObject> Scene::gameObjects;

Scene::Scene() {
	if (SQLITE_OK != (ret = sqlite3_initialize()))
	{
		printf("Failed to initialize library: %d\n", ret);
	}
}

Scene::~Scene() {
	if (nullptr != db) sqlite3_close(db);
}

bool Scene::open(std::string name) {
	int exit = 0;
	exit = sqlite3_open("scene1.db", &db);
	sceneName = name;
	return exit == SQLITE_OK;
}

void Scene::Load()
{
	std::string sql = "SELECT * from Scene";
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		GameObject go;
		go.GUID = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		go.Name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		Scene::gameObjects.push_back(go);
	};
	sqlite3_finalize(stmt);
}

static int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	std::string_view colName;
	std::string_view value;
	GameObject go;
	for (i = 0; i < argc; i++) {

		colName = azColName[i];
		value = argv[i] ? argv[i] : "NULL";

		if (colName == "GUID") {
			go.GUID = value;
		}
		else if (colName == "Name") {
			go.Name = value;
		}
	}
	Scene::gameObjects.push_back(go);

	return 0;
}

std::string Scene::getValue()
{
	auto sql = "SELECT * from scene1";
	const char* data = "Callback function called";
	char* zErrMsg = 0;
	int rc;
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	return sql;
}
