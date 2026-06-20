__int64 __fastcall geni_i3c_master_do_daa(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v3; // x21
  int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w20
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x0
  unsigned int v10; // w20
  __int64 v11; // x21
  __int64 v12; // x9
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x0

  v1 = a1 + 20480;
  ipc_log_string(*(_QWORD *)(a1 + 2416), "%s skip_entdaa:0x%x\n", "geni_i3c_master_do_daa", *(_DWORD *)(a1 + 21532));
  if ( *(_QWORD *)(a1 - 104) )
    i3c_trace_log();
  v3 = *(unsigned int *)(v1 + 1052);
  if ( !(_DWORD)v3 )
  {
    result = i3c_master_entdaa_locked(a1);
    if ( (_DWORD)result != 3 && (_DWORD)result )
      return result;
    v10 = 0;
    v11 = a1 + 21176;
    do
    {
      v12 = *(_QWORD *)(v11 + 8LL * (v10 >> 6));
      if ( ((1LL << v10) & v12) != 0 )
      {
        *(_QWORD *)(v11 + 8LL * (v10 >> 6)) = v12 & ~(1LL << v10);
        i3c_master_add_i3c_dev_locked(a1, v10);
      }
      ++v10;
    }
    while ( v10 != 128 );
    i3c_master_enec_locked(a1, 126, 10);
    return 0;
  }
  if ( *(_BYTE *)(v1 + 1056) != 1 )
    return 0;
  v4 = geni_i3c_send_setdasa(a1, v3, SBYTE1(v3));
  if ( v4 )
  {
    v6 = v4;
    ipc_log_string(*(_QWORD *)(a1 + 2416), "setdasa failed %d\n", v4);
    v15 = *(_QWORD *)(a1 - 104);
    if ( v15 )
      dev_err(v15, "setdasa failed %d\n", v6);
    else
      printk(&unk_1331D, v6, v13, v14);
    if ( !*(_QWORD *)(a1 - 104) )
      return v6;
LABEL_27:
    i3c_trace_log();
    return v6;
  }
  if ( (v3 & 0x8000) == 0 )
    *(_QWORD *)(a1 + 8 * ((v3 >> 13) & 3) + 2224) &= ~(3LL << (2 * (BYTE1(v3) & 0x1Fu)));
  result = i3c_master_add_i3c_dev_locked(a1, (unsigned int)(v3 >> 8));
  if ( (_DWORD)result )
  {
    v6 = result;
    ipc_log_string(*(_QWORD *)(a1 + 2416), "adding i3c dev failed %d\n", result);
    v9 = *(_QWORD *)(a1 - 104);
    if ( v9 )
      dev_err(v9, "adding i3c dev failed %d\n", v6);
    else
      printk(&unk_14C09, v6, v7, v8);
    if ( !*(_QWORD *)(a1 - 104) )
      return v6;
    goto LABEL_27;
  }
  return result;
}
