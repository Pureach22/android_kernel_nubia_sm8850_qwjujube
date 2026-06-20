__int64 __fastcall icnss_request_bus_bandwidth(__int64 a1, unsigned int a2)
{
  _DWORD *v2; // x20
  _DWORD *v4; // x22
  unsigned int *v5; // x8
  int v6; // w0
  __int64 v7; // x23
  unsigned int v8; // w20

  v2 = *(_DWORD **)(a1 + 152);
  if ( !v2 )
    return 4294967277LL;
  if ( (a2 & 0x80000000) != 0 )
    return 4294967274LL;
  if ( !v2[416] )
    return 4294967201LL;
  if ( v2[418] <= a2 )
  {
    printk("%sicnss2: Invalid bus bandwidth Type: %d", byte_130B32, a2);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid bus bandwidth Type: %d", (const char *)&unk_12DBF3, a2);
    return 4294967274LL;
  }
  else
  {
    v4 = v2 + 412;
    while ( 1 )
    {
      v4 = *(_DWORD **)v4;
      if ( v4 == v2 + 412 )
        break;
      v5 = (unsigned int *)(*((_QWORD *)v4 + 4) + 8LL * a2);
      v6 = icc_set_bw(*((_QWORD *)v4 + 3), *v5, v5[1]);
      if ( v6 )
      {
        v7 = 8LL * a2;
        v8 = v6;
        printk(
          "%sicnss2: Could not set BW Cfg: %d, err = %d ICC Path: %s Val: %d %d\n",
          byte_130B32,
          a2,
          v6,
          *((const char **)v4 + 2),
          *(_DWORD *)(*((_QWORD *)v4 + 4) + v7),
          *(_DWORD *)(*((_QWORD *)v4 + 4) + v7 + 4));
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Could not set BW Cfg: %d, err = %d ICC Path: %s Val: %d %d\n",
          (const char *)&unk_12DBF3,
          a2,
          v8,
          *((const char **)v4 + 2),
          *(_DWORD *)(*((_QWORD *)v4 + 4) + v7),
          *(_DWORD *)(*((_QWORD *)v4 + 4) + v7 + 4));
        return v8;
      }
    }
    v2[417] = a2;
    return 0;
  }
}
