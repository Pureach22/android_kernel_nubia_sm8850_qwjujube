__int64 __fastcall dp_ctrl_mst_send_act(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  void (__fastcall *v3)(_QWORD); // x9
  __int64 (*v4)(void); // x8
  __int64 v5; // x0
  __int64 ipc_log_context; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_BYTE *)(result + 258) == 1 )
  {
    v1 = *(_QWORD *)(result + 176);
    v2 = result;
    v3 = *(void (__fastcall **)(_QWORD))(v1 + 200);
    if ( *((_DWORD *)v3 - 1) != -91942776 )
      __break(0x8229u);
    v3(v1);
    msleep(20);
    v4 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 176) + 208LL);
    if ( *((_DWORD *)v4 - 1) != 1395674136 )
      __break(0x8228u);
    v5 = v4();
    ipc_log_context = get_ipc_log_context(v5);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]mst act trigger complete failed\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_25622B, "dp_ctrl_mst_send_act");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
