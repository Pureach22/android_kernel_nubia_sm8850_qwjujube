# RedMagic 11 Pro (NX809J) - Guia de Compilação e Inicialização do Kernel

Este guia explica como compilar, empacotar e inicializar o kernel customizado com suporte a **KernelSU-Next** e **Paridade Binária** via memória RAM (sem alterar permanentemente as partições do celular), além de definir as próximas etapas de desenvolvimento.

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
