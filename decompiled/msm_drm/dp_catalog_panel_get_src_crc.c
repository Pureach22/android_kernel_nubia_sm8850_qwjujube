__int64 __fastcall dp_catalog_panel_get_src_crc(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  _DWORD **v3; // x23
  __int64 v4; // x20
  _DWORD *v5; // x10
  __int64 v6; // x21
  unsigned int v7; // w22
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int16 v11; // w8
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  v2 = *(_DWORD *)(a1 + 204);
  if ( v2 >= 2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid stream_id:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 204));
    printk(&unk_272496, "dp_catalog_panel_get_src_crc");
    return 4294967274LL;
  }
  else
  {
    v3 = (_DWORD **)(a1 - 456);
    v4 = *(_QWORD *)(a1 - 552);
    v5 = *(_DWORD **)(a1 - 456);
    v6 = a1 - 576;
    if ( v2 )
      v7 = 356;
    else
      v7 = 340;
    v9 = a1 - 576;
    if ( *(v5 - 1) != -1879227436 )
      __break(0x822Au);
    *(_DWORD *)a2 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v5)(v9, v4, v7);
    v10 = *v3;
    if ( *(*v3 - 1) != -1879227436 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v6, v4, v7 + 4);
    result = 0;
    *(_WORD *)(a2 + 4) = v11;
  }
  return result;
}
