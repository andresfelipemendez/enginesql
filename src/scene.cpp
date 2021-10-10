#include "scene.h"

#include "sqlite3.h"

#include <string_view>


std::vector<GameObject> scene::gameObjects;

scene::scene() {
	if (SQLITE_OK != (ret = sqlite3_initialize()))
	{
		printf("Failed to initialize library: %d\n", ret);
	}
}

scene::~scene() {
	if (nullptr != db) sqlite3_close(db);
}

bool scene::open(std::string name) {
	int exit = 0;
	exit = sqlite3_open("scene1.db", &db);
	return SQLITE_OK == 0;
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
	scene::gameObjects.push_back(go);

	return 0;
}

std::string scene::getValue()
{
	auto sql = "SELECT * from scene1";
	const char* data = "Callback function called";
	char* zErrMsg = 0;
	int rc;
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	return sql;
}
