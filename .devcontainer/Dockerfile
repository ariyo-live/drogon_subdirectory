FROM drogonframework/drogon

LABEL description="Drogon Subdirectory"

RUN apt-get update && apt -y upgrade
RUN apt-get install -y mariadb-server

WORKDIR /workspaces/drogon_subdirectory
RUN drogon_ctl create project http_server

CMD /usr/bin/mysqld_safe --user=mysql &

EXPOSE 80 3306