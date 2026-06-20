__int64 __fastcall dp_audio_get_data(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 ipc_log_context; // x0
  __int64 v5; // x0
  void *v6; // x0
  __int64 v7; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_audio_get_data");
    return -19;
  }
  v1 = *(_QWORD *)(a1 + 168);
  if ( !v1 )
  {
    v5 = get_ipc_log_context(a1);
    ipc_log_string(v5, "[e][%-4d]invalid ext disp data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_23E67E;
LABEL_9:
    printk(v6, "dp_audio_get_data");
    return -22;
  }
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]invalid intf data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_27C631;
    goto LABEL_9;
  }
  return v2 - 352;
}
