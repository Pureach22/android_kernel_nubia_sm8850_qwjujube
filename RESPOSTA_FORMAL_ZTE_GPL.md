# NOTIFICAÇÃO DE DESCUMPRIMENTO DA LICENÇA GPL v2 — ZTE CORPORATION

**Para:** ZTE Corporation / Nubia Technology Support & Legal Compliance Department  
**Assunto:** Solicitação Formal do Código-Fonte Completo e Correspondente do Kernel do RedMagic 11 Pro (NX809J) — Em conformidade com a GNU General Public License v2 (GPLv2)  
**Dispositivo:** Nubia RedMagic 11 Pro (Model: NX809J)  
**Processador (SoC):** Qualcomm Snapdragon 8 Elite (SM8850 - Codenames: `canoe` / `qwjujube`)  
**Versão do Kernel:** Linux Kernel 6.12.23 (Android 16 GKI)  
**Contato:** idealcreativesuporte@idealcreative.com.br / Telegram: @idealcreative  

---

## 📄 CARTA DE APRESENTAÇÃO E NOTIFICAÇÃO TÉCNICA

Agradeço o retorno e o encaminhamento desta demanda ao setor interno competente. Para que as equipes técnica e jurídica avaliem este chamado com a devida gravidade, formalizo abaixo os pontos cruciais que o motivam, amparados nas regras globais de conformidade de software livre (GPL), na legislação brasileira de Defesa do Consumidor e na viabilidade técnica estrutural do aparelho.

---

### 1. O Paradoxo da Segurança e a Estagnação do Kernel Linux
O mercado global, impulsionado por novas regulamentações de ecodesign e sustentabilidade, tem pressionado as fabricantes a fornecerem ciclos longos de atualizações de segurança. No entanto, na engenharia de software de baixo nível, essa promessa colide com a realidade de um dispositivo de suporte curto e bootloader bloqueado.

O Red Magic 11 Pro (modelo NX809J) foi lançado com o Kernel Linux 6.12.x (Android 16 GKI). Para manter a compatibilidade com os drivers proprietários compilados fora da árvore (*out-of-tree*), o dispositivo fica estruturalmente estagnado. Quando o ecossistema Android exigir saltos para futuras versões LTS do kernel, a fabricante, via de regra, não realizará a migração devido à quebra de compatibilidade com os binários antigos (*vendor blobs*).

Questionamos a Engenharia da ZTE: **o que significa "segurança do dispositivo" se, a médio prazo, o aparelho será mantido em um kernel defasado, e o consumidor final é ativamente bloqueado de aplicar correções críticas ou customizações via KernelSU por conta própria?**

---

### 2. Acordo de Garantia vs. Restrição Abusiva de Hardware
A comunidade de desenvolvedores e usuários avançados concorda com a perda integral da garantia de software no momento em que o bootloader é desbloqueado, mitigando os riscos de suporte técnico para a marca. O que não é aceitável é o bloqueio arbitrário da propriedade após a aquisição.

Ao reter a capacidade oficial de desbloqueio e limitar o suporte a um curto período de atualizações, a postura atual obriga a comunidade de desenvolvimento a recorrer a modos de emergência (EDL) e ferramentas de baixo nível para realizar backups de partições e modificações básicas que deveriam ser acessíveis. Essa política fere o **Direito ao Reparo (Right to Repair)** e o direito de propriedade, impedindo o reaproveitamento de um hardware premium (Snapdragon 8 Elite) para a instalação de distribuições Linux ou custom ROMs, gerando lixo eletrônico (*e-waste*) de forma prematura e irresponsável.

---

### 3. Obsolescência Programada e a Legislação Brasileira (CDC)
No Brasil, o **Superior Tribunal de Justiça (STJ)** possui entendimento pacificado de que a durabilidade de um bem de consumo durável deve corresponder à sua "vida útil esperada", e não se limita ao período da garantia contratual ou de suporte comercial primário.

Tornar um hardware de altíssimo valor e desempenho obsoleto e vulnerável por bloqueios de software configura prática abusiva (violação do **Art. 39 do Código de Defesa do Consumidor - CDC**) e caracteriza estratégia de **obsolescência programada**. A liberação do código-fonte completo e funcional é a ferramenta legal que permite à sociedade civil manter o aparelho seguro após o encerramento do suporte oficial (*End of Life*).

---

### 4. Conformidade GPLv2: O Mínimo Compilável e Funcional (Causa Raiz do Boot Hang)
O pilar técnico desta notificação é a liberação de um código-fonte de kernel incompleto. Estabelecemos aqui um limite claro de propriedade intelectual: **não solicitamos acesso a segredos industriais da ZTE.**

Compreendemos o direito legal de manter sob código fechado os algoritmos de processamento de imagem das câmeras, calibração de tela e firmwares da banda base (modem). No entanto, nossa exigência técnica — **amparada inegociavelmente pela licença global GPLv2 do Kernel Linux** — é a disponibilização das partes estruturais e configurações de compilação (*defconfig*) necessárias para que o kernel seja compilável e capaz de inicializar (boot) o smartphone de forma autônoma.

#### O Blocker Atual de Inicialização (Evidência de Inconformidade):
Ressalta-se que a omissão de configurações básicas de compilação exigiu a análise estática e reconstrução manual de símbolos e cabeçalhos apenas para viabilizar a compilação inicial da árvore fornecida, indicando uma falha grave em fornecer um ambiente de desenvolvimento reprodutível.

Durante os testes de compilação com a árvore fornecida, o kernel é gerado, mas trava indefinidamente na tela de logotipo (*boot hang*). O log de console (`console-ramoops`) aponta a seguinte falha crítica:
```
[0.181496] arm-scmi arm-scmi.1.auto: Failed to get FC for protocol 13 [MSG_ID:6 / RES_ID:0] - ret:-22
...
[1.112952] arm-scmi arm-scmi.1.auto: timed out in resp (caller: do_xfer+0x140/0x4ec)
[1.116211] scmi_cpuss_telemetry_probe: Not able to find shared memory location
```
Este **timeout no protocolo SCMI** ocorre porque a fabricante omitiu o fragmento de configuração da plataforma (`canoe.fragment`) e as implementações internas do driver de mailbox/SCMI. A cascata de falhas resultante impede o carregamento dos coprocessadores (`adsp-loader`), impossibilita a inicialização do driver de segurança (`keymint`) e impede a descriptografia da partição `/data` (FBE), congelando o sistema operacional em um estado inoperante.

#### O Mínimo Funcional Exigido por Lei:
Para conformidade estrita com a GPLv2, exigimos a publicação dos códigos-fontes (kernel-space) dos seguintes componentes básicos, sem os quais o sistema não opera:
*   **Camada de Inicialização e SCMI:** Configuração de mailbox da CPU (`canoe.fragment` e DTBs de coordenação com o firmware `PDP0`).
*   **Driver do Painel de Toque (Touchscreen):** O código original C do driver do touchscreen (`zte_tpd`).
*   **Políticas de Energia e Carga:** Drivers de gerenciamento de bateria e carga (`zte_charger_policy` e `zte_power_supply`).
*   **Display e Áudio Básico:** Código-fonte em C com suporte mínimo para inicializar o console de tela e codecs básicos de som, sem qualquer dependência de binários proprietários pré-compilados (blobs) ocultos no kernel-space.
*   **Segurança e Descriptografia:** Componentes e configurações de TEE/TrustZone em nível de kernel necessários para a comunicação com o `keymint` e a correta descriptografia FBE da partição `/data`.

*Nota: Firmwares secundários podem permanecer fechados em nível de HAL (User-Space) ou binários carregados na RAM do chip, desde que o kernel Linux fornecido inicialize o Android na tela principal adequadamente.*

---

## 🎯 CONCLUSÃO E SOLICITAÇÃO DE AÇÃO

Solicitamos formalmente que a assessoria jurídica e a engenharia de software da ZTE/Nubia:
1. Providenciem a atualização do repositório open-source, liberando um pacote em estrita conformidade com a GPLv2, contendo as mailboxes de inicialização, drivers de tela/toque, gerenciador de carregamento e o defconfig completo de hardware.
2. Forneçam um caminho oficial para o desbloqueio do bootloader, permitindo a longevidade do dispositivo de forma transparente e segura.

A comunidade técnica está disposta a colaborar com o ecossistema, mas dependemos de uma base de código funcional e que respeite as licenças que regem o Kernel Linux.

Aguardamos um retorno técnico e resolutivo em tempo oportuno.

Atenciosamente,  
**Coding-BR / Ideal Creative**  
*E-mail: idealcreativesuporte@idealcreative.com.br*  
*Telegram: @idealcreative*  
