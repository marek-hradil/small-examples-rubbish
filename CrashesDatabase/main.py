import psycopg2
from psycopg2 import OperationalError
import statistics

def create_connection(db_name, db_user, db_password, db_host, db_port):
    connection = None
    try:
        connection = psycopg2.connect(
            database=db_name,
            user=db_user,
            password=db_password,
            host=db_host,
            port=db_port,
        )
        print("Connection to PostgreSQL DB successful")
    except OperationalError as e:
        print(f"The error '{e}' occurred")
    return connection


connection = create_connection("crashes", "main", "password", "localhost", 6000)
cursor = connection.cursor()
cursor.execute("""
    SELECT id, druh_komun, hodina AS hour FROM crashes;
""")
res = cursor.fetchall()

variance([hodina for row in res])

for id, druh, hodina in res:

print(res)
