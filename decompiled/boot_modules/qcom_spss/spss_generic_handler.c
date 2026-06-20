__int64 __fastcall spss_generic_handler(__int64 a1, __int64 *a2)
{
  int v2; // w3
  unsigned __int64 v3; // x19
  __int64 v5; // x0
  const char *v6; // x2
  __int64 *v7; // x20
  int v8; // w2
  __int64 v9; // x0
  __int64 *v10; // x19
  __int64 *v11; // x20
  const char *v12; // x2
  __int64 v13; // x9

  v2 = *(_DWORD *)a2[51];
  v3 = *(unsigned int *)a2[47];
  if ( ((v3 >> *((_DWORD *)a2 + 106)) & 1) != 0 )
  {
    v5 = *a2;
    v6 = *(const char **)(a2[1] + 24);
    if ( v2 == 1146441040 )
    {
      v11 = a2;
      dev_err(v5, "wdog bite received from %s!\n", v6);
      if ( *(_BYTE *)(v11[1] + 1204) )
        v12 = "disabled and lead to device crash";
      else
        v12 = "enabled and kick reovery process";
      dev_err(*v11, "rproc recovery state: %s\n", v12);
      v13 = v11[1];
      if ( *(_BYTE *)(v13 + 1204) == 1 )
      {
        *(_DWORD *)(v13 + 972) = 3;
        panic("Panicking, remoterpoc %s crashed\n", *(const char **)(v11[1] + 24));
      }
      *(_DWORD *)v11[48] = 1LL << *((_DWORD *)v11 + 106);
      rproc_report_crash(v11[1], 1);
      a2 = v11;
    }
    else
    {
      v7 = a2;
      if ( v2 )
      {
        dev_info(v5, "SW_INIT_DONE - ERROR [%s] [0x%x].\n", v6);
        dev_err(
          *v7,
          "spare0 register: 0x%08x, spare1 register: 0x%08x, spare2 register: 0x%08x\n",
          *(_DWORD *)(v7[51] - 8),
          *(_DWORD *)(v7[51] - 4),
          *(_DWORD *)v7[51]);
        a2 = v7;
        *(_DWORD *)v7[48] = 1LL << *((_DWORD *)v7 + 106);
      }
      else
      {
        dev_info(v5, "SW_INIT_DONE - 2nd phase loading [%s] completed ok\n", v6);
        *(_DWORD *)v7[48] = 1LL << *((_DWORD *)v7 + 106);
        complete(v7 + 8);
        a2 = v7;
      }
    }
  }
  if ( ((v3 >> *((_DWORD *)a2 + 107)) & 1) != 0 )
  {
    v8 = *(_DWORD *)a2[50];
    v9 = *a2;
    v10 = a2;
    if ( v8 )
      dev_err(
        v9,
        "PBL error status register: 0x%08x, spare0 register: 0x%08x, spare1 register: 0x%08x, spare2 register: 0x%08x\n",
        v8,
        *(_DWORD *)(a2[51] - 8),
        *(_DWORD *)(a2[51] - 4),
        *(_DWORD *)a2[51]);
    else
      dev_info(v9, "PBL_DONE - 1st phase loading [%s] completed ok\n", *(const char **)(a2[1] + 24));
    *(_DWORD *)v10[48] = 1LL << *((_DWORD *)v10 + 107);
  }
  return 1;
}
