__int64 __fastcall handle_rx_hs(__int64 a1, int a2, unsigned int a3, int a4, char a5)
{
  __int64 v6; // x8
  bool v7; // zf
  unsigned int v8; // w8
  __int64 v9; // x22
  unsigned int v10; // w9
  _DWORD *v11; // x10
  int v12; // w12
  _DWORD *v13; // x11
  unsigned int inserted; // w20
  int v15; // w10
  __int64 v16; // x1
  int v17; // w21
  __int64 v18; // x1
  __int64 v19; // x0
  int v20; // w8
  __int64 v21; // x22
  _QWORD v23[12]; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v24[9]; // [xsp+68h] [xbp-48h] BYREF

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
    v7 = a3 == 0;
  else
    v7 = 1;
  v24[8] = v6;
  v8 = *(_DWORD *)(a1 + 556);
  v9 = *(_QWORD *)(a1 + 208);
  v10 = v8 >> 3;
  if ( !v7 )
    v10 = a3;
  if ( a2 )
  {
    v11 = *(_DWORD **)(a1 + 608);
    v12 = a2;
    v13 = (_DWORD *)(*(_QWORD *)(a1 + 16) + 1920LL);
    do
    {
      --v12;
      *v11++ = *v13;
    }
    while ( v12 );
  }
  if ( (a5 & 1) != 0 )
  {
    inserted = 0;
  }
  else
  {
    v15 = a2 - 1;
    v16 = *(_QWORD *)(a1 + 608);
    LOBYTE(v23[0]) = 0;
    v17 = v10 + ((v8 * v15) >> 3);
    inserted = _tty_insert_flip_string_flags(v9, v16, v23, 0, v17);
    if ( v17 != inserted )
      dev_err(*(_QWORD *)(a1 + 344), "%s: ret %d rx_bytes %d\n", "handle_rx_hs", inserted, v17);
    *(_DWORD *)(a1 + 232) += inserted;
    tty_flip_buffer_push(v9, v18);
    v19 = *(_QWORD *)(a1 + 608);
    if ( v17 >= 32 )
      v20 = 32;
    else
      v20 = v17;
    v21 = *(_QWORD *)(a1 + 944);
    memset(v24, 0, 64);
    memset(v23, 0, sizeof(v23));
    hex_dump_to_buffer(v19, v20, 32, 1, v24, 64, 0);
    scnprintf(v23, 96, "%s[0x%.10x:%d] : %s", "Rx", 0, v17, (const char *)v24);
    ipc_log_string(v21, "%s : %s\n", "dump_ipc", (const char *)v23);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s : %s\n");
  }
  _ReadStatusReg(SP_EL0);
  return inserted;
}
