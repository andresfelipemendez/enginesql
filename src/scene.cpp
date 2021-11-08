#include "Scene.h"
#include "sqlite3.h"
#include <string_view>
#include <iostream>

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
	exit = sqlite3_open(name.c_str(), &db);
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

void  Scene::AddRenderingComponent(std::string gameObject, std::string shader, std::string model) {
	sqlite3_stmt* stmt = nullptr;
	char const* szSQL = "INSERT INTO RenderingComponents(ShaderID, MeshID) VALUES(?, ?);";
	if (sqlite3_prepare_v2(db, szSQL, -1, &stmt, nullptr) != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n%s\n", szSQL,
			sqlite3_errmsg(db));
		return;
	}
	
	int rc;
	rc = sqlite3_exec(db, "BEGIN TRANSACTION", 0, 0, 0);

	rc = sqlite3_bind_text(stmt, 1, shader.c_str(), shader.size(),nullptr);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n%s\n", szSQL, sqlite3_errmsg(db));
		return;
	}
	sqlite3_bind_text(stmt, 2, model.c_str(), model.size(), nullptr);
	
	do {
		rc = sqlite3_step(stmt);
		for (int colIndex = 0; colIndex < sqlite3_column_count(stmt); colIndex++) {
			auto result = sqlite3_column_text(stmt, colIndex);
			std::cout << (result);
			//  Do something with the result.
		}
	} while (rc == SQLITE_ROW);

	

	char* zErrMsg = 0;  //  Can perhaps display the error message if rc != SQLITE_OK.
	rc = sqlite3_exec(db, "END TRANSACTION", 0, 0, &zErrMsg);   //  End the transaction.

	//rc = sqlite3_finalize(stmt);
	sqlite3_finalize(stmt);
}

void Scene::shutDown() {

}