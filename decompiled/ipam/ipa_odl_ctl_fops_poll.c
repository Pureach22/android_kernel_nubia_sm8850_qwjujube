__int64 __fastcall ipa_odl_ctl_fops_poll(__int64 a1, _DWORD **a2)
{
  _DWORD *v2; // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  if ( a2 )
  {
    v2 = *a2;
    if ( *a2 )
    {
      if ( *(v2 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, void *, _DWORD **))v2)(a1, &odl_ctl_msg_wq, a2);
      __dmb(0xBu);
    }
  }
  if ( *(_BYTE *)(ipa3_odl_ctx + 696) != 1 )
    return 0;
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d Sending read mask to odl control pipe\n", "ipa_odl_ctl_fops_poll", 149);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Sending read mask to odl control pipe\n", "ipa_odl_ctl_fops_poll", 149);
  }
  return 65;
}
