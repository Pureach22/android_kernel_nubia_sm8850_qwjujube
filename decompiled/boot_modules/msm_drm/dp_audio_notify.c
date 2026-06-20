__int64 __fastcall dp_audio_notify(__int64 *a1, unsigned int a2)
{
  _DWORD *v2; // x8
  __int64 v6; // x0
  __int64 *v7; // x1
  __int64 *v8; // x22
  unsigned int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 StatusReg; // x21
  int v13; // w2
  __int64 ipc_log_context; // x0

  *((_DWORD *)a1 + 96) = 0;
  v2 = (_DWORD *)a1[6];
  if ( !v2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]audio notify not defined\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26B8F5, "dp_audio_notify");
    return 0;
  }
  v7 = a1 + 3;
  v6 = *a1;
  *((_DWORD *)a1 + 40) = 0;
  v8 = a1 + 20;
  if ( *(v2 - 1) != 714649827 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))v2)(v6, v7, a2);
  if ( !v9 )
  {
    if ( !(*((_DWORD *)a1 + 96) | a2) && *((_BYTE *)a1 + 152) == 1 )
    {
      v10 = wait_for_completion_timeout(v8, 1000);
      v9 = v10;
      v11 = get_ipc_log_context(v10);
      StatusReg = _ReadStatusReg(SP_EL0);
      v13 = *(_DWORD *)(StatusReg + 1800);
      if ( v9 )
      {
        ipc_log_string(v11, "[d][%-4d]success\n", v13);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(StatusReg + 1800));
      }
      else
      {
        ipc_log_string(v11, "[e][%-4d]timeout. state=%d err=%d\n", v13, a2, 0);
        printk(&unk_22D385, "dp_audio_notify");
        return (unsigned int)-110;
      }
      return v9;
    }
    return 0;
  }
  return v9;
}
