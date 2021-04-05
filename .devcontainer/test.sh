#!/bin/bash

docker build -f ./Dockerfile.without_vscode -t drogon_subdirectory ..
docker run --name="drogon_subdirectory" -t -d drogon_subdirectory /bin/bash
docker exec -it drogon_subdirectory /bin/bash
