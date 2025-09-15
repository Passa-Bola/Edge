
#include <ThingerESP32.h>
#include <WiFi.h>

#define USERNAME "seu_usuario_thinger"
#define DEVICE_ID "chuteira_inteligente"
#define DEVICE_CREDENTIAL "sua_credencial_thinger"

#define WIFI_SSID "seu_ssid_wifi"
#define WIFI_PASSWORD "sua_senha_wifi"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conecta ao Wi-Fi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Configura o recurso para enviar dados para o Thinger.io
  thing["dados_chuteira"] >> [](pson &out){
    // Simula dados do sensor de pressão/força
    int forca_simulada = random(50, 200); // Força entre 50 e 200
    bool toque_simulado = (forca_simulada > 100); // Considera toque se força > 100

    // Simula contagem de toques e passes (incrementa a cada 'toque')
    static int contagem_toques = 0;
    static int contagem_passes = 0;
    static bool ultimo_estado_toque = false;

    if (toque_simulado && !ultimo_estado_toque) {
      contagem_toques++;
      // Lógica simplificada para passes: a cada 3 toques, um passe
      if (contagem_toques % 3 == 0) {
        contagem_passes++;
      }
    }
    ultimo_estado_toque = toque_simulado;

    out["forca"] = forca_simulada;
    out["toque"] = toque_simulado;
    out["contagem_toques"] = contagem_toques;
    out["contagem_passes"] = contagem_passes;
    out["usage_rate"] = (float)contagem_toques / (contagem_toques + random(10, 50)); // Exemplo simples de usage rate
  };
}

void loop() {
  thing.handle();
  delay(5000); // Envia dados a cada 5 segundos
}


