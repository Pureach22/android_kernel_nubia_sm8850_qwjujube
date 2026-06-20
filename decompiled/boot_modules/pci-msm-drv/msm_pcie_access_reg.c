__int64 __fastcall msm_pcie_access_reg(__int64 a1, char a2)
{
  __int64 v4; // x0
  const char *v5; // x20
  unsigned int v6; // w8
  __int64 v7; // x25
  __int64 v8; // x9
  void *v9; // x0
  __int64 result; // x0
  unsigned int v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w22
  int v14; // w19
  int v15; // w22
  __int64 v16; // x21
  char v17; // w23
  int v18; // w0
  int v19; // w21
  __int64 v20; // x22
  int v21; // w0
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 1712);
    if ( (a2 & 1) != 0 )
      v5 = "writing";
    else
      v5 = "reading";
    ipc_log_string(
      v4,
      "DBG_FS:%s: \n\nPCIe: RC%d: %s a PCIe register\n\n",
      "msm_pcie_access_reg",
      *(_DWORD *)(a1 + 1348),
      v5);
  }
  printk(&unk_2DF42);
  if ( !base_sel )
  {
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: Invalid base_sel: 0x%x\n", "msm_pcie_access_reg", 0);
    v9 = &unk_2DE44;
LABEL_15:
    result = printk(v9);
    goto LABEL_24;
  }
  v6 = base_sel - 1;
  v7 = a1 + 352;
  v8 = a1 + 352 + 24LL * (unsigned int)(base_sel - 1);
  if ( !*(_QWORD *)(v8 + 8) )
  {
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1712),
        "DBG_FS:%s: PCIe: RC%d Resource does not exist\n",
        "msm_pcie_access_reg",
        *(_DWORD *)(a1 + 1348));
    v9 = &unk_22603;
    goto LABEL_15;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: base: %s: 0x%pK\nwr_offset: 0x%x\n",
      "msm_pcie_access_reg",
      *(const char **)v8,
      *(const void **)(v8 + 16),
      wr_offset);
    v6 = base_sel - 1;
  }
  if ( v6 > 8 || (printk(&unk_2C18C), v11 = base_sel - 1, (unsigned int)(base_sel - 1) > 8) )
LABEL_34:
    __break(0x5512u);
  v12 = (unsigned int)wr_offset;
  v13 = *(_DWORD *)(*(_QWORD *)(v7 + 24LL * v11 + 8) + 8LL) - **(_DWORD **)(v7 + 24LL * v11 + 8) - 3;
  if ( wr_offset <= v13 )
  {
    if ( (wr_offset & 3) == 0 )
    {
      if ( (a2 & 1) != 0 )
      {
        v14 = wr_mask;
        v15 = wr_value;
        v16 = *(_QWORD *)(v7 + 24LL * v11 + 16);
        v17 = __clz(__rbit64((unsigned int)wr_mask));
        v18 = readl_relaxed_0((unsigned int *)(v16 + (unsigned int)wr_offset));
        writel_relaxed_0((v15 << v17) | v18 & (unsigned int)~v14, v16 + v12);
        result = readl_relaxed_0((unsigned int *)(v16 + v12));
        goto LABEL_24;
      }
      v22[0] = **(_QWORD **)(a1 + 408) + (unsigned int)wr_offset;
      if ( !a1
        || (v19 = *(_DWORD *)(a1 + 1348),
            v20 = *(_QWORD *)(a1 + 1712),
            v21 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v7 + 24LL * v11 + 16) + (unsigned int)wr_offset)),
            ipc_log_string(
              v20,
              "DBG_FS:%s: PCIe: RC%d: register: 0x%pa value: 0x%x\n",
              "msm_pcie_access_reg",
              v19,
              v22,
              v21),
            v11 = base_sel - 1,
            (unsigned int)(base_sel - 1) <= 8) )
      {
        readl_relaxed_0((unsigned int *)(*(_QWORD *)(v7 + 24LL * v11 + 16) + (unsigned int)wr_offset));
        result = printk(&unk_23ABD);
        goto LABEL_24;
      }
      goto LABEL_34;
    }
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe: RC%d: offset 0x%x is not correctly aligned\n",
        "msm_pcie_check_align",
        *(_DWORD *)(a1 + 1348),
        wr_offset);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: offset 0x%x is not correctly aligned\n",
        "msm_pcie_check_align",
        *(_DWORD *)(a1 + 1348),
        v12);
    }
    printk(&unk_255EA);
    LODWORD(v12) = wr_offset;
  }
  if ( a1 )
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: PCIe: RC%d: Invalid wr_offset: 0x%x. wr_offset should be no more than 0x%x\n",
      "msm_pcie_access_reg",
      *(_DWORD *)(a1 + 1348),
      v12,
      v13);
  result = printk(&unk_2E6F5);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
