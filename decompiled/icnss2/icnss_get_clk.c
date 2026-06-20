__int64 __fastcall icnss_get_clk(_QWORD *a1)
{
  __int64 v1; // x9
  unsigned __int64 **v2; // x19
  unsigned __int64 v3; // x20
  char **v4; // x20
  __int64 v7; // x0
  char *v8; // x8
  const char *v9; // x22
  __int64 v10; // x21
  __int64 v11; // x9
  unsigned __int64 *v12; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 **v14; // x8
  unsigned __int64 v15; // x11
  int v16; // w3
  __int64 v17; // x0
  __int64 *v18; // x1

  if ( !a1 )
  {
    LODWORD(v3) = -19;
    return (unsigned int)v3;
  }
  v1 = a1[38];
  v2 = (unsigned __int64 **)(a1 + 29);
  if ( v1 > 30543 )
  {
    if ( v1 == 43981 )
    {
      v4 = &icnss_adrestea_clk_list;
      goto LABEL_12;
    }
    if ( v1 != 30544 )
      goto LABEL_5;
  }
  else if ( v1 != 25680 && v1 != 26448 )
  {
LABEL_5:
    if ( *v2 == (unsigned __int64 *)v2 )
      goto LABEL_14;
    goto LABEL_13;
  }
  v4 = &icnss_clk_list;
LABEL_12:
  if ( *v2 != (unsigned __int64 *)v2 )
  {
LABEL_13:
    ipc_log_string(icnss_ipc_log_context, "Clocks have already been updated\n");
LABEL_14:
    LODWORD(v3) = 0;
    return (unsigned int)v3;
  }
  v7 = devm_kmalloc(a1[1] + 16LL, 48, 3520);
  if ( v7 )
  {
    v9 = *v4;
    v8 = v4[1];
    v10 = v7;
    v11 = a1[1];
    *(_QWORD *)(v7 + 24) = *v4;
    *(_QWORD *)(v7 + 32) = v8;
    v3 = devm_clk_get(v11 + 16, v9);
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      v16 = *(_DWORD *)(v10 + 32);
      v17 = icnss_ipc_log_context;
      *(_QWORD *)(v10 + 16) = v3;
      ipc_log_string(v17, "Got clock: %s, freq: %u\n", v9, v16);
      v18 = (__int64 *)a1[30];
      if ( (unsigned __int64 **)v10 != v2 && v18 != (__int64 *)v10 && (unsigned __int64 **)*v18 == v2 )
      {
        LODWORD(v3) = 0;
        a1[30] = v10;
        *(_QWORD *)v10 = v2;
        *(_QWORD *)(v10 + 8) = v18;
        *v18 = v10;
        return (unsigned int)v3;
      }
      _list_add_valid_or_report(v10, v18);
      goto LABEL_14;
    }
    if ( !*(_DWORD *)(v10 + 36) )
    {
      ipc_log_string(icnss_ipc_log_context, "Failed to get optional clock %s, err = %d\n", v9, v3);
      goto LABEL_14;
    }
    printk("%sFailed to get clock %s, err = %d\n", byte_130B32, v9, v3);
    ipc_log_string(icnss_ipc_log_context, "%sFailed to get clock %s, err = %d\n", (const char *)&unk_12DBF3, v9, v3);
  }
  else
  {
    LODWORD(v3) = -12;
  }
  v12 = *v2;
  if ( *v2 != (unsigned __int64 *)v2 )
  {
    v13 = 0xDEAD000000000100LL;
    do
    {
      v14 = (unsigned __int64 **)v12[1];
      if ( *v14 == v12 && (v15 = *v12, *(unsigned __int64 **)(*v12 + 8) == v12) )
      {
        *(_QWORD *)(v15 + 8) = v14;
        *v14 = (unsigned __int64 *)v15;
      }
      else
      {
        _list_del_entry_valid_or_report(v12);
      }
      *v12 = v13;
      v12[1] = v13 + 34;
      v12 = *v2;
    }
    while ( *v2 != (unsigned __int64 *)v2 );
  }
  return (unsigned int)v3;
}
