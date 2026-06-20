# Análise e Engenharia Reversa do Driver `zte_fingerprint`

Este documento detalha o processo de análise de engenharia reversa e reconstrução lógica do módulo de kernel proprietário `zte_fingerprint.ko` do RedMagic 11 Pro (NX809J).

## Lógica do Driver

O driver serve como um driver de caracteres ponte para o sensor de impressão digital da Goodix sob a tela.
Ele realiza três operações fundamentais no kernel:
1. **Controle de Energia Física e Sinais**: Habilita e desabilita o regulador `"vdd"`, e controla os pinos GPIO de RESET e IRQ (Interrupção) mapeados do Device Tree.
2. **Injeção de Teclas Virtuais (Input Subsytem)**: Cria um dispositivo virtual de input nomeado `"goodix_fp"` capaz de simular cliques em teclas de navegação física (como KEY_HOME, KEY_BACK, KEY_POWER e KEY_VOLUMEUP/DOWN) baseadas em gestos capturados pelo sensor.
3. **Notificação de Estado de Tela via Netlink**: Escuta eventos de transição de tela ativa e inativa do DRM panel (Qualcomm display) por meio de `panel_event_notifier_register`. Ao receber notificações de tela suspensa ou ligada, envia mensagens unicast via Socket Netlink (Protocolo customizado `25`) para o processo HAL do espaço do usuário.

## Estrutura de Dados (`struct gf_device`)

A estrutura interna privada do driver possui o seguinte formato:
```c
struct gf_device {
	struct list_head device_entry;        // 0
	struct platform_device *pdev;         // 16
	dev_t devt;                           // 24 (gf)
	struct input_dev *input_dev;          // 40
	u32 ref_count;                        // 56
	int irq_gpio;                         // 60
	int reset_gpio;                       // 64
	u32 irq_num;                          // 72
	u32 irq_enabled;                      // 76
	struct workqueue_struct *screen_state_wq; // 80
	struct delayed_work screen_state_work; // 88
	u8 screen_state;                      // 113
	struct pinctrl *pinctrl;              // 120
	struct pinctrl_state *pins_active;         // 128
	struct pinctrl_state *pins_suspend;        // 136
	struct regulator *vdd_reg;            // 144
	u8 opened;                            // 112
};
```

## Mapeamento de Comandos IOCTL

O driver de caracteres expõe uma interface IOCTL sob a família de números mágicos `'g'` (`0x67`):

| Comando | Código Hexadecimal | Descrição |
|---|---|---|
| `ZTE_FP_IOCTL_GET_VERSION` | `0x80046700` | Lê e envia a versão do driver (`25`) para o espaço do usuário. |
| `ZTE_FP_IOCTL_RESET` | `0x6702` | Executa um ciclo de reset de hardware de 10ms. |
| `ZTE_FP_IOCTL_ENABLE_IRQ` | `0x6703` | Habilita a interrupção de hardware do sensor. |
| `ZTE_FP_IOCTL_DISABLE_IRQ` | `0x6704` | Desabilita a interrupção de hardware do sensor. |
| `ZTE_FP_IOCTL_POWER_ON` | `0x6707` | Habilita o regulador de tensão do sensor. |
| `ZTE_FP_IOCTL_POWER_OFF` | `0x6708` | Desabilita o regulador de tensão do sensor. |
| `ZTE_FP_IOCTL_CLEANUP` | `0x670c` | Desativa GPIOs e reguladores de tensão em modo de segurança. |
| `ZTE_FP_IOCTL_NAV_EVENT` | `0x4004670e` | Recebe um código de gesto da HAL e envia evento de tecla. |
| `ZTE_FP_IOCTL_REPORT_KEY` | `0x400c6709` | Recebe estado de tecla (KEY_HOME, etc.) e propaga clique via subsistema Input. |
