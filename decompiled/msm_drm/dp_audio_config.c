__int64 __fastcall dp_audio_config(__int64 *a1, unsigned int a2)
{
  _DWORD *v2; // x9
  __int64 result; // x0
  __int64 v4; // x2
  _QWORD *v5; // x1
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w19
  __int64 ipc_log_context; // x0

  v2 = (_DWORD *)a1[5];
  if ( v2 )
  {
    if ( *(_DWORD *)(a1[17] + 912) )
    {
      return 0;
    }
    else
    {
      v4 = a2;
      v5 = a1 + 3;
      v6 = *a1;
      if ( *(v2 - 1) != 714649827 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v2)(v6, v5, v4);
      if ( (_DWORD)result )
      {
        v8 = result;
        ipc_log_context = get_ipc_log_context(result);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]failed to config audio, err=%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          v8);
        printk(&unk_26B92B, "dp_audio_config");
        return v8;
      }
    }
  }
  else
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]audio_config not defined\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_27C683, "dp_audio_config");
    return 0;
  }
  return result;
}
