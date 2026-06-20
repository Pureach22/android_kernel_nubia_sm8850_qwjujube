__int64 __fastcall dp_ctrl_host_init(__int64 a1, char a2, char a3)
{
  _QWORD *v3; // x20
  _QWORD *v5; // x0
  void (__fastcall *v6)(_QWORD); // x8
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v3 = *(_QWORD **)(a1 + 176);
    *(_BYTE *)(a1 + 256) = a2 & 1;
    v5 = v3;
    if ( (a3 & 1) != 0 )
    {
      v6 = (void (__fastcall *)(_QWORD))v3[14];
      if ( *((_DWORD *)v6 - 1) != 289804815 )
        __break(0x8228u);
      v6(v3);
      v7 = (void (__fastcall *)(_QWORD))v3[17];
      v8 = *(_QWORD *)(a1 + 176);
      if ( *((_DWORD *)v7 - 1) != -91942776 )
        __break(0x8228u);
      v7(v8);
      v5 = *(_QWORD **)(a1 + 176);
    }
    v9 = (_DWORD *)v3[16];
    if ( *(v9 - 1) != 289804815 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v9)(v5, 1);
    result = 0;
    *(_DWORD *)(a1 + 264) = 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid input data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_23AC6D, "dp_ctrl_host_init");
    return 4294967274LL;
  }
  return result;
}
