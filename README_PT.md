# RedMagic 11 Pro (NX809J) - Guia de Compilação e Inicialização do Kernel

Este guia explica como compilar, empacotar e inicializar o kernel customizado com suporte a **KernelSU-Next** e **Paridade Binária** via memória RAM (sem alterar permanentemente as partições do celular), além de definir as próximas etapas de desenvolvimento.

---

## 📋 Pré-requisitos

Para que a compilação e o empacotamento funcionem corretamente, você deve providenciar os seguintes componentes (que estão configurados no `.gitignore` para manter o repositório limpo):

1. **Toolchain Clang (r536225)**:
   - Baixe a versão do Clang do AOSP (revision `r536225`).
   - Extraia a toolchain na raiz deste repositório em uma pasta chamada `clang-r536225/` (de modo que o binário principal fique em `clang-r536225/bin/clang`).
   - Alternativamente, você pode definir a variável de ambiente `CLANG_DIR` apontando para o seu diretório do Clang antes de compilar.

2. **Device Tree Blob (`dtb.img`)**:
   - Extraia o arquivo `dtb.img` oficial a partir da partição/imagem de boot (`boot.img`) de estoque da ZTE (versão userdebug correspondente).
   - Coloque o arquivo `dtb.img` diretamente na raiz deste repositório. Ele é necessário para concatenar os Device Trees à imagem do kernel durante o empacotamento.

3. **Dependências do Host**:
   - Certifique-se de ter instalado os pacotes essenciais de compilação do Linux (`build-essential`, `libssl-dev`, `bison`, `flex`, `libelf-dev`, `python3`, etc.).

---

## 🔓 Guia de Desbloqueio de Bootloader e Fastboot

Para desbloquear o bootloader do RedMagic 11 Pro (NX809J) e outros dispositivos ZTE/Nubia, siga estes passos:

### 1. Instalar o Fastboot e o ADB
* **Windows**: Baixe o [Android SDK Platform-Tools](https://developer.android.com/tools/releases/platform-tools) oficial e adicione-o ao PATH do seu sistema.
* **Linux (Ubuntu/Debian)**: Instale via apt:
  ```bash
  sudo apt update
  sudo apt install android-tools-adb android-tools-fastboot
  ```
* **macOS**: Instale via Homebrew:
  ```bash
  brew install android-platform-tools
  ```

### 2. Extrair e Gravar a ABL Desbloqueada
Para desbloquear o bootloader, você precisa substituir a partição do gerenciador de boot (`abl`) pela versão customizada e desbloqueada:
1. Inicialize seu dispositivo no modo EDL e abra a ferramenta **ZTE Family Toolbox** (ZTE Toolbox).
2. Faça o backup/dump das suas partições oficiais **`abl_a`** e **`abl_b`**.
3. Grave o arquivo de ABL desbloqueada fornecido neste repositório (**`abl_unlock.elf`**) em ambos os slots (`abl_a` e `abl_b`).
   * *Alternativamente, se você já possui acesso ao fastboot:*
     ```bash
     fastboot flash abl_a abl_unlock.elf
     fastboot flash abl_b abl_unlock.elf
     ```
4. > [!IMPORTANT]
   > **ZTE Toolbox Opção 19**: Após gravar a ABL desbloqueada via ZTE Toolbox, você **DEVE** executar a **Opção 19** no ZTE Family Toolbox para limpar os flags de boot do aparelho. Se você pular este passo, o dispositivo entrará em **Dumper Mode** (tela de Crash Dump) na próxima inicialização e não dará boot.


### 3. Desativar a Verificação do vbmeta
Após gravar o ABL desbloqueado, você **DEVE** gravar as imagens de `vbmeta` e `vbmeta_system` de estoque desativando as proteções de integridade para evitar bootloops ou falhas de verificação do AVB:

```bash
fastboot --disable-verity flash vbmeta_a vbmeta.img
fastboot --disable-verity flash vbmeta_b vbmeta.img
fastboot --disable-verity --disable-verification flash vbmeta_system_a vbmeta_system.img
fastboot --disable-verity --disable-verification flash vbmeta_system_b vbmeta_system.img
```

> [!CAUTION]
> **NUNCA** use a flag `--disable-verification` ao gravar `vbmeta_a` ou `vbmeta_b` (use apenas `--disable-verity`). Se você utilizar `--disable-verification` no `vbmeta` principal, o seu dispositivo ficará travado no bootloader (stuck at bootloader) e não inicializará, exigindo uma recuperação completa via **Modo EDL**!

4. Por fim, execute o comando de desbloqueio:
   ```bash
   fastboot flashing unlock
   ```
   Confirme o desbloqueio na tela do aparelho usando os botões de volume e o botão Power.

---

## 🚀 1. Como Compilar e Inicializar o Kernel

### Passo A: Compilar o Kernel principal e Techpacks
Temos o script unificado [super_build.sh](super_build.sh) que configura o ambiente, aplica a defconfig da plataforma (`nx809j_defconfig`), insere as flags de segurança (CFI Permissive, KernelSU-Next) e compila os binários com a toolchain Clang apropriada.

Execute no terminal:
```bash
./super_build.sh
```
* O kernel será compilado e a imagem resultante ficará localizada em: `kernel_platform/common/arch/arm64/boot/Image`.

---

### Passo B: Empacotar e Assinar a Imagem de Boot (DTB + AVB)
Os drivers dinâmicos Qualcomm exigem a junção física dos Device Trees (`dtb.img`) no cabeçalho do kernel. O script [repack_perfect_sign.sh](repack_perfect_sign.sh) cuida do empacotamento sem ramdisk interno (tamanho exato de 64MB) e faz a assinatura criptográfica obrigatória via AVB para evitar bloqueio do bootloader.

Execute:
```bash
./repack_perfect_sign.sh
```
* Isso gerará a imagem assinada pronta para boot na raiz do projeto: **`dev_reverse_perfect.img`**.

---

### Passo C: Inicializar na Memória RAM (Boot Temporário)
> [!WARNING]
> **NUNCA execute `fastboot flash boot` ou grave esta imagem permanentemente no dispositivo durante a fase de testes.** O boot deve ser feito sempre temporariamente na RAM. Se o sistema travar ou apresentar falhas, um simples pressionar do botão Power por 10 segundos restaura o boot oficial original.

1. Reinicie o smartphone no modo bootloader:
   ```bash
   adb reboot bootloader
   ```
2. Carregue a imagem diretamente na memória RAM usando o fastboot:
   ```bash
   sudo fastboot boot dev_reverse_perfect.img
   ```
   *(Insira a senha de superusuário (sudo) caso o terminal solicite privilégios de root para comunicação USB com o fastboot)*.

3. O celular iniciará o Android. Após inicializado, você pode validar o kernel ativo rodando:
   ```bash
   adb shell uname -a
   ```
   Você verá a string indicando a sua compilação customizada com suporte ao **KernelSU-Next** ativo.

---

## 🛠️ 2. Próximos Passos do Projeto

Agora que alcançamos a compatibilidade de paridade binária estável (onde o kernel customizado carrega e roda o sistema normalmente), podemos iniciar as tarefas específicas de desenvolvimento descritas em [NEXT_STEPS.md](NEXT_STEPS.md):

### 1. Implantar e Testar os Módulos Reconstruídos (.ko)
Como o carregamento via RAM usa as partições físicas e monta `/vendor_dlkm` do sistema original, os módulos ativos no momento são os originais da ZTE. Para colocar em execução as nossas reconstruções (com código aberto refeito via Ghidra):
* **Método Built-in:** Modifique o `Kbuild` dos drivers que reconstruímos (como `zte_charger_policy` e `zte_led`) alterando a compilação para embutida (`obj-y` em vez de `obj-m`). Assim, eles serão compilados diretamente dentro do arquivo `Image` e carregados antes do sistema inicializar os oficiais.

### 2. Overclock da GPU para 1200MHz+
* Extrair e descompilar o Device Tree original (`dtb.img` ou `dtbo.img`) para formato texto (`.dts`).
* Localizar a tabela de OPPs (Operating Performance Points) da GPU Adreno 830.
* Adicionar os steps de frequência de overclock (com os binds de tensão corretos) para atingir 1200MHz+ de forma estável.
* Recompilar a árvore e testar via `fastboot boot`.

### 3. Integração Completa de Outros Techpacks
* Adaptar e compilar os módulos de toque (`touch-drivers`) para validar a interação física do painel usando nossa árvore.
* Validar a compilação de redes móveis e conectividade (`dataipa`).

### 4. Auditoria de Travas Proprietárias e CFI
* Monitorar os logs de pânico (`dmesg` e `console-ramoops-0`) para mapear qualquer falha de CFI (Control Flow Integrity) remanescente nos módulos carregados.

---

## 📬 Contato e Suporte

Se você tiver dúvidas, precisar de suporte ou quiser colaborar neste projeto de engenharia reversa, entre em contato através de:
* 📧 **E-mail:** [idealcreativesuporte@idealcreative.com.br](mailto:idealcreativesuporte@idealcreative.com.br)
* 💬 **Grupo do Telegram:** [Entrar no Grupo](https://web.telegram.org/a/#-1003471835008_307)
* 🌐 **Tópico no XDA:** [Guia de Unlock e Ferramentas do RedMagic 11 Pro](https://xdaforums.com/t/red-magic-11-pro-guide-bootloader-unlock-free-also-support-rm10-pad3pro-z70u-z80u-unlock-zte-family-toolbox.4780930/)
