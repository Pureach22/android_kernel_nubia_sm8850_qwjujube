__int64 __fastcall msm_pcie_reg_dump(__int64 a1, char *a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v5; // x19
  int v8; // w0
  char *v9; // x20
  unsigned int v10; // w21
  unsigned __int64 v11; // x9
  __int64 v12; // x0
  int v13; // w3
  unsigned int v14; // w0
  void *v15; // x0

  if ( !a1 )
    return 4294967274LL;
  while ( !*(_BYTE *)(a1 + 108) || (*(_WORD *)(a1 + 114) & 0xF0) != 0x40 )
  {
    if ( (*(_BYTE *)(a1 + 2851) & 0x80) != 0 )
      a1 = *(_QWORD *)(a1 + 3288);
    v3 = *(_QWORD *)(a1 + 16);
    if ( *(_QWORD *)(v3 + 16) )
    {
      a1 = *(_QWORD *)(v3 + 56);
      if ( a1 )
        continue;
    }
    return 4294967277LL;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  if ( !v5 )
  {
    v15 = &unk_2F4AF;
LABEL_21:
    printk(v15);
    return 4294967277LL;
  }
  ipc_log_string(
    *(_QWORD *)(v5 + 1712),
    "DUMP:%s: RC%d hang event dump buff=%p len=%u\n",
    "msm_pcie_reg_dump",
    *(_DWORD *)(v5 + 1348),
    a2,
    a3);
  if ( *(_DWORD *)(v5 + 1176) == 4 )
  {
    v15 = &unk_28D46;
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v5 + 1568) == 1 )
  {
    v15 = &unk_24F12;
    goto LABEL_21;
  }
  v8 = msm_pcie_reg_copy(v5, a2, a3, 4, 0);
  v9 = &a2[v8];
  v10 = a3 - v8;
  v11 = (unsigned int)readl_relaxed_0(*(_QWORD *)(v5 + 880) + *(unsigned int *)(v5 + 1280));
  v12 = *(_QWORD *)(v5 + 1712);
  v13 = *(_DWORD *)(v5 + 1348);
  if ( ((v11 >> *(_DWORD *)(v5 + 1284)) & 1) != 0 )
  {
    ipc_log_string(v12, "DUMP:%s: RC%d PHY is off, skip DBI\n", "msm_pcie_reg_dump", v13);
    memset(v9, 0, (unsigned int)(4 * *(_DWORD *)(v5 + 3104)));
    v14 = 4 * *(_DWORD *)(v5 + 3104);
  }
  else
  {
    ipc_log_string(v12, "DUMP:%s: RC%d Dump DBI registers\n", "msm_pcie_reg_dump", v13);
    v14 = msm_pcie_reg_copy(v5, v9, v10, 4, 1);
  }
  msm_pcie_reg_copy(v5, &v9[v14], v10 - v14, 1, 2);
  ipc_log_string(*(_QWORD *)(v5 + 1712), "DUMP:%s: RC%d hang event Exit\n", "msm_pcie_reg_dump", *(_DWORD *)(v5 + 1348));
  return 0;
}
