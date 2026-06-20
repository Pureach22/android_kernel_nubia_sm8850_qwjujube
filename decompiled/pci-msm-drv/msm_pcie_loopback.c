__int64 __fastcall msm_pcie_loopback(__int64 *a1, char a2)
{
  __int64 v4; // x21
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x22
  unsigned __int8 *v10; // x0
  void *v11; // x0
  unsigned __int8 *v12; // x22
  __int64 v13; // x24
  int v14; // w0
  __int64 v15; // x24
  int v16; // w0
  __int64 v17; // x26
  int v18; // w27
  int v19; // w0
  __int64 v20; // x26
  int v21; // w0
  __int64 v22; // x27
  int v23; // w28
  int v24; // w0
  __int64 v25; // x24
  int v26; // w0
  __int64 v27; // x24
  int v28; // w0
  __int64 v29; // x25
  int v30; // w26
  int v31; // w0
  unsigned int *v32; // x28
  int v33; // w27
  __int64 v34; // x25
  int v35; // w26
  int v36; // w0
  __int64 v37; // x24
  int v38; // w25
  int v39; // w0
  __int64 v40; // x24
  int v41; // w25
  int v42; // w0
  __int64 v43; // x24
  int v44; // w25
  int v45; // w0
  __int64 v46; // x24
  int v47; // w25
  int v48; // w0
  __int64 v49; // x24
  int v50; // w25
  int v51; // w0
  __int64 v52; // x24
  int v53; // w25
  int v54; // w0
  __int64 v55; // x24
  int v56; // w23
  const char *v57; // x4
  unsigned int v58; // w8
  __int64 v59; // x21
  char v60; // w8
  int v61; // w4
  int v62; // w5
  bool v63; // zf
  const char *v64; // x21
  void *v65; // x0
  const char *v66; // x21
  char v67; // [xsp+8h] [xbp-18h]
  int v68; // [xsp+Ch] [xbp-14h]
  _QWORD v69[2]; // [xsp+10h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1[51];
  v69[0] = 0;
  if ( arm64_use_ng_mappings )
    v5 = 0x68000000000F13LL;
  else
    v5 = 0x68000000000713LL;
  v6 = ioremap_prot(v4 + 0x800000, 4096, v5);
  if ( !v6 )
  {
    if ( a1 )
    {
      ipc_log_string(
        a1[213],
        "ERR:%s: PCIe: RC%d: ioremap fails for loopback_lbar_phy\n",
        "msm_pcie_loopback",
        *((_DWORD *)a1 + 337));
      ipc_log_string(
        a1[212],
        "%s: PCIe: RC%d: ioremap fails for loopback_lbar_phy\n",
        "msm_pcie_loopback",
        *((_DWORD *)a1 + 337));
    }
    result = printk(&unk_29EEB);
    goto LABEL_80;
  }
  v8 = v6;
  if ( a1 )
    ipc_log_string(
      a1[214],
      "DBG_FS:%s: PCIe: RC%d: Allocate 4K DDR memory and map LBAR.\n",
      "msm_pcie_loopback",
      *((_DWORD *)a1 + 337));
  printk(&unk_24A36);
  v9 = *a1;
  if ( (unsigned int)dma_set_mask(*a1 + 16, -1) )
  {
    if ( a1 )
    {
      ipc_log_string(a1[213], "ERR:%s: PCIe: RC%d: DMA set mask failed\n", "msm_pcie_loopback", *((_DWORD *)a1 + 337));
      ipc_log_string(a1[212], "%s: PCIe: RC%d: DMA set mask failed\n", "msm_pcie_loopback", *((_DWORD *)a1 + 337));
    }
    v11 = &unk_2433D;
    goto LABEL_18;
  }
  dma_set_coherent_mask(v9 + 16, -1);
  v10 = (unsigned __int8 *)dma_alloc_attrs(*a1 + 16, 4096, v69, 3264, 0);
  if ( !v10 )
  {
    if ( a1 )
      ipc_log_string(
        a1[214],
        "DBG_FS:%s: PCIe: RC%d: failed to dma_alloc_coherent.\n",
        "msm_pcie_loopback",
        *((_DWORD *)a1 + 337));
    v11 = &unk_2F68C;
LABEL_18:
    printk(v11);
    result = iounmap(v8);
    goto LABEL_80;
  }
  v12 = v10;
  if ( a1 )
  {
    ipc_log_string(
      a1[214],
      "DBG_FS:%s: PCIe: RC%d: VIR DDR memory address: 0x%pK\n",
      "msm_pcie_loopback",
      *((_DWORD *)a1 + 337),
      v10);
    printk(&unk_287E6);
    ipc_log_string(
      a1[214],
      "DBG_FS:%s: PCIe: RC%d: IOVA DDR memory address: %pad\n",
      "msm_pcie_loopback",
      *((_DWORD *)a1 + 337),
      v69);
  }
  else
  {
    printk(&unk_287E6);
  }
  printk(&unk_226CF);
  v67 = a2;
  v68 = v69[0];
  if ( (a2 & 1) != 0 )
  {
    if ( a1 )
      ipc_log_string(
        a1[214],
        "DBG_FS:%s: PCIe: RC%d: Configure Local Loopback.\n",
        "msm_pcie_loopback",
        *((_DWORD *)a1 + 337));
    printk(&unk_21EE8);
    v13 = a1[113];
    v14 = readl_relaxed_0((unsigned int *)(v13 + 2192));
    writel_relaxed_0(v14 | 0x10000u, v13 + 2192);
    readl_relaxed_0((unsigned int *)(v13 + 2192));
    if ( a1 )
    {
      v17 = a1[214];
      v18 = *((_DWORD *)a1 + 337);
      v19 = readl_relaxed_0((unsigned int *)(a1[113] + 2192));
      ipc_log_string(v17, "DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n", "msm_pcie_loopback", v18, v4 + 2192, v19);
      readl_relaxed_0((unsigned int *)(a1[113] + 2192));
      printk(&unk_2CE3A);
      v20 = a1[113];
      v21 = readl_relaxed_0((unsigned int *)(v20 + 2232));
      writel_relaxed_0(v21 | 0x80000000, v20 + 2232);
      readl_relaxed_0((unsigned int *)(v20 + 2232));
      v22 = a1[214];
      v23 = *((_DWORD *)a1 + 337);
      v24 = readl_relaxed_0((unsigned int *)(a1[113] + 2232));
      ipc_log_string(v22, "DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n", "msm_pcie_loopback", v23, v4 + 2232, v24);
    }
    else
    {
      readl_relaxed_0((unsigned int *)(*(_QWORD *)algn_388 + 2192LL));
      printk(&unk_2CE3A);
      v15 = *(_QWORD *)algn_388;
      v16 = readl_relaxed_0((unsigned int *)(*(_QWORD *)algn_388 + 2232LL));
      writel_relaxed_0(v16 | 0x80000000, v15 + 2232);
      readl_relaxed_0((unsigned int *)(v15 + 2232));
    }
    readl_relaxed_0((unsigned int *)(a1[113] + 2232));
    printk(&unk_2CE3A);
  }
  else
  {
    if ( a1 )
      ipc_log_string(
        a1[214],
        "DBG_FS:%s: PCIe: RC%d: Configure remote Loopback.\n",
        "msm_pcie_loopback",
        *((_DWORD *)a1 + 337));
    printk(&unk_25D5E);
  }
  v25 = a1[113];
  v26 = readl_relaxed_0((unsigned int *)(v25 + 1808));
  writel_relaxed_0(v26 | 4u, v25 + 1808);
  readl_relaxed_0((unsigned int *)(v25 + 1808));
  v27 = a1[113];
  v28 = readl_relaxed_0((unsigned int *)(v27 + 4));
  writel_relaxed_0(v28 | 6u, v27 + 4);
  readl_relaxed_0((unsigned int *)(v27 + 4));
  if ( a1 )
  {
    v29 = a1[214];
    v30 = *((_DWORD *)a1 + 337);
    v31 = readl_relaxed_0((unsigned int *)(a1[113] + 1808));
    ipc_log_string(v29, "DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n", "msm_pcie_loopback", v30, v4 + 1808, v31);
  }
  readl_relaxed_0((unsigned int *)(a1[113] + 1808));
  printk(&unk_2CE3A);
  v32 = (unsigned int *)a1[112];
  v33 = *(_DWORD *)a1[57];
  if ( a1 )
    ipc_log_string(a1[214], "DBG_FS:%s: PCIe: RC%d: Setup iATU.\n", "msm_pcie_loopback", *((_DWORD *)a1 + 337));
  printk(&unk_22CE8);
  writel_relaxed_0(0, v32 + 129);
  readl_relaxed_0(v32 + 129);
  writel_relaxed_0(0, v32 + 128);
  if ( a1 )
  {
    v34 = a1[214];
    v35 = *((_DWORD *)a1 + 337);
    v36 = readl_relaxed_0(v32 + 128);
    ipc_log_string(
      v34,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_CTRL1:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v35,
      v33 + 512,
      v36);
  }
  readl_relaxed_0(v32 + 128);
  printk(&unk_25D8C);
  writel_relaxed_0((unsigned int)(v4 + 0x800000), v32 + 130);
  if ( a1 )
  {
    v37 = a1[214];
    v38 = *((_DWORD *)a1 + 337);
    v39 = readl_relaxed_0(v32 + 130);
    ipc_log_string(
      v37,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LBAR:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v38,
      v33 + 520,
      v39);
  }
  readl_relaxed_0(v32 + 130);
  printk(&unk_22700);
  writel_relaxed_0(0, v32 + 131);
  if ( a1 )
  {
    v40 = a1[214];
    v41 = *((_DWORD *)a1 + 337);
    v42 = readl_relaxed_0(v32 + 131);
    ipc_log_string(
      v40,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_UBAR:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v41,
      v33 + 524,
      v42);
  }
  readl_relaxed_0(v32 + 131);
  printk(&unk_22734);
  writel_relaxed_0((unsigned int)(v4 + 8396799), v32 + 132);
  if ( a1 )
  {
    v43 = a1[214];
    v44 = *((_DWORD *)a1 + 337);
    v45 = readl_relaxed_0(v32 + 132);
    ipc_log_string(
      v43,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LAR:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v44,
      v33 + 528,
      v45);
  }
  readl_relaxed_0(v32 + 132);
  printk(&unk_25DC1);
  writel_relaxed_0(v68 & 0xFFFFF000, v32 + 133);
  if ( a1 )
  {
    v46 = a1[214];
    v47 = *((_DWORD *)a1 + 337);
    v48 = readl_relaxed_0(v32 + 133);
    ipc_log_string(
      v46,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LTAR:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v47,
      v33 + 532,
      v48);
  }
  readl_relaxed_0(v32 + 133);
  printk(&unk_24A6E);
  writel_relaxed_0(HIDWORD(v69[0]), v32 + 134);
  if ( a1 )
  {
    v49 = a1[214];
    v50 = *((_DWORD *)a1 + 337);
    v51 = readl_relaxed_0(v32 + 134);
    ipc_log_string(
      v49,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_UTAR:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v50,
      v33 + 536,
      v51);
    readl_relaxed_0(v32 + 134);
    printk(&unk_21F15);
    writel_relaxed_0(0x80000000LL, v32 + 129);
    v52 = a1[214];
    v53 = *((_DWORD *)a1 + 337);
    v54 = readl_relaxed_0(v32 + 129);
    ipc_log_string(
      v52,
      "DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_CTRL2:\t0x%x: 0x%x\n",
      "msm_pcie_loopback",
      v53,
      v33 + 516,
      v54);
    readl_relaxed_0(v32 + 129);
    printk(&unk_2CE91);
    v55 = a1[214];
    v56 = *((_DWORD *)a1 + 337);
    if ( ((unsigned int)readl_relaxed_0((unsigned int *)(a1[111] + 8)) & 0x3C000) <= 0x23000 )
    {
      v58 = ((unsigned int)readl_relaxed_0((unsigned int *)(a1[111] + 8)) >> 12) & 0x3F;
      if ( v58 > 0x23 )
        goto LABEL_81;
      v57 = msm_pcie_ltssm_str[v58];
    }
    else
    {
      v57 = "LTSSM_INVALID";
    }
    ipc_log_string(v55, "DBG_FS:%s: PCIe RC%d: LTSSM_STATE: %s\n", "msm_pcie_loopback", v56, v57);
  }
  else
  {
    readl_relaxed_0(v32 + 134);
    printk(&unk_21F15);
    writel_relaxed_0(0x80000000LL, v32 + 129);
    readl_relaxed_0(v32 + 129);
    printk(&unk_2CE91);
  }
  if ( ((unsigned int)readl_relaxed_0((unsigned int *)(a1[111] + 8)) & 0x3C000) <= 0x23000
    && (((unsigned int)readl_relaxed_0((unsigned int *)(a1[111] + 8)) >> 12) & 0x3F) > 0x23 )
  {
LABEL_81:
    __break(0x5512u);
  }
  printk(&unk_2BAD1);
  get_random_bytes(v8, 4096);
  usleep_range_state(100, 101, 2);
  v59 = 0;
  v60 = 0;
  do
  {
    while ( 1 )
    {
      v61 = *(unsigned __int8 *)(v8 + v59);
      v62 = v12[v59];
      if ( v61 == v62 )
        break;
      if ( a1 )
        ipc_log_string(
          a1[214],
          "DBG_FS:%s: PCIe: RC%d: exp %x: got %x\n",
          "msm_pcie_loopback",
          *((_DWORD *)a1 + 337),
          v61,
          v62);
      printk(&unk_25622);
      v63 = v59++ == 4095;
      v60 = 1;
      if ( v63 )
        goto LABEL_65;
    }
    ++v59;
  }
  while ( v59 != 4096 );
  if ( (v60 & 1) != 0 )
  {
LABEL_65:
    if ( a1 )
    {
      if ( (v67 & 1) != 0 )
        v64 = "Local";
      else
        v64 = "Remote";
      ipc_log_string(
        a1[214],
        "DBG_FS:%s: PCIe: RC%d: %s Loopback Test failed\n",
        "msm_pcie_loopback",
        *((unsigned int *)a1 + 337),
        v64);
    }
    v65 = &unk_25644;
    goto LABEL_79;
  }
  if ( a1 )
  {
    if ( (v67 & 1) != 0 )
      v66 = "Local";
    else
      v66 = "Remote";
    ipc_log_string(
      a1[214],
      "DBG_FS:%s: PCIe: RC%d: %s Loopback Test Passed\n",
      "msm_pcie_loopback",
      *((unsigned int *)a1 + 337),
      v66);
  }
  v65 = &unk_24AA2;
LABEL_79:
  printk(v65);
  iounmap(v8);
  result = dma_free_attrs(*a1 + 16, 4096, v12, v69[0], 0);
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
