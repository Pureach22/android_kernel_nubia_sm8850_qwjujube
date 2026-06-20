__int64 __fastcall dp_catalog_panel_dp_flush(__int64 a1, int a2)
{
  unsigned int v2; // w8
  bool v4; // zf
  __int64 v5; // x21
  _DWORD *v6; // x8
  unsigned int v7; // w22
  __int64 v9; // x0
  __int64 v10; // x1
  int v11; // w0
  _DWORD *v12; // x9
  __int64 v14; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 204);
    if ( v2 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_dp_flush");
    }
    else
    {
      v4 = v2 == 0;
      v5 = *(_QWORD *)(a1 - 552);
      v6 = *(_DWORD **)(a1 - 456);
      if ( v4 )
        v7 = 760;
      else
        v7 = 764;
      v9 = a1 - 576;
      v10 = *(_QWORD *)(a1 - 552);
      if ( *(v6 - 1) != -1879227436 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v9, v10, v7);
      if ( !a2 && *(_BYTE *)(a1 + 213) )
        v11 &= ~4u;
      v12 = *(_DWORD **)(a1 - 448);
      if ( *(v12 - 1) != -626862723 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v12)(
               a1 - 576,
               v5,
               v7,
               v11 | (unsigned int)(1LL << a2));
    }
  }
  else
  {
    v14 = get_ipc_log_context(0);
    ipc_log_string(v14, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_dp_flush");
  }
}
