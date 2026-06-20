__int64 __fastcall dp_catalog_panel_timing_cfg(unsigned int *a1)
{
  unsigned int v1; // w8
  unsigned int *v3; // x22
  __int64 v4; // x21
  int v5; // w23
  void (__fastcall *v6)(unsigned int *, __int64, _QWORD, __int64); // x8
  __int64 v7; // x3
  unsigned int *v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x3
  _DWORD *v11; // x8
  __int64 v12; // x3
  _DWORD *v13; // x9
  __int64 v14; // x3
  __int64 v15; // x8
  __int64 v16; // x21
  __int64 (__fastcall *v17)(unsigned int *, __int64, __int64); // x8
  int v18; // w0
  _DWORD *v19; // x9
  int v20; // w8
  __int64 v22; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = a1[51];
    if ( v1 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        a1[51]);
      printk(&unk_272496, "dp_catalog_panel_timing_cfg");
    }
    else
    {
      v3 = a1 - 112;
      v4 = *((_QWORD *)a1 - 69);
      v5 = v1 == 1;
      v6 = *((void (__fastcall **)(unsigned int *, __int64, _QWORD, __int64))a1 - 56);
      v7 = *a1;
      v8 = a1 - 144;
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -626862723 )
        __break(0x8228u);
      v6(v8, v4, ((v5 & 1) << 10) | 0x1Cu, v7);
      v9 = *(_DWORD **)v3;
      v10 = a1[1];
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned int *, __int64, _QWORD, __int64))v9)(a1 - 144, v4, ((v5 & 1) << 10) | 0x20u, v10);
      v11 = *(_DWORD **)v3;
      v12 = a1[2];
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned int *, __int64, _QWORD, __int64))v11)(a1 - 144, v4, ((v5 & 1) << 10) | 0x24u, v12);
      v13 = *(_DWORD **)v3;
      v14 = a1[3];
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(unsigned int *, __int64, _QWORD, __int64))v13)(a1 - 144, v4, (v5 << 10) | 0x28u, v14);
      v15 = 0x3FFFFFFFFFFFFF88LL;
      if ( !a1[51] )
        v15 = 0x3FFFFFFFFFFFFF78LL;
      v16 = *(_QWORD *)&a1[v15];
      v17 = *((__int64 (__fastcall **)(unsigned int *, __int64, __int64))a1 - 57);
      if ( *((_DWORD *)v17 - 1) != -1879227436 )
        __break(0x8228u);
      v18 = v17(a1 - 144, v16, 20);
      v19 = *(_DWORD **)v3;
      if ( *((_BYTE *)a1 + 208) )
        v20 = 16;
      else
        v20 = 0;
      if ( *(v19 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD))v19)(a1 - 144, v16, 20, v20 | v18 & 0xFFFFFFEF);
    }
  }
  else
  {
    v22 = get_ipc_log_context(0);
    ipc_log_string(v22, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_panel_timing_cfg");
  }
  return 0;
}
