
from flask import Flask, request, jsonify
import threading
import time

app = Flask(__name__)

@app.route('/iot/json', methods=['POST'])
def receive_iot_data():
    data = request.get_json()
    print(f"[MOCK FIWARE] Dados recebidos do dispositivo: {data}")
    # Aqui você pode adicionar lógica para simular o processamento do FIWARE
    # Por exemplo, armazenar os dados em uma lista ou banco de dados simulado
    return jsonify({"status": "ok", "message": "Data received by mock IoT Agent"}), 200

@app.route('/health', methods=['GET'])
def health_check():
    return jsonify({"status": "UP", "service": "Mock FIWARE IoT Agent"}), 200

def run_mock_server():
    print("[MOCK FIWARE] Servidor Mock FIWARE IoT Agent iniciado na porta 5000")
    app.run(host='0.0.0.0', port=5000, debug=False)

if __name__ == '__main__':
    run_mock_server()


