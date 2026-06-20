__int64 __fastcall audio_notifier_service_cb(__int64 result, unsigned int a2, unsigned int a3)
{
  unsigned __int64 v3; // x27
  __int64 v4; // x19
  __int64 v5; // x21
  char *v6; // x20
  __int64 v7; // x0
  int v8; // w21
  _DWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v4 = 1;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result <= 268435454 )
  {
    if ( result == 1 )
      goto LABEL_12;
    if ( result != 2 )
      goto LABEL_16;
  }
  else
  {
    if ( result != 0xFFFFFFF )
    {
      if ( result == 0x1FFFFFFF )
        goto LABEL_12;
      if ( result == 805306367 )
      {
        v4 = 0;
        service_early_down = 1;
        goto LABEL_12;
      }
LABEL_16:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( service_early_down == 1 )
    {
      service_early_down = 0;
      result = printk(&unk_80F8, "audio_notifier_convert_opcode");
      goto LABEL_16;
    }
  }
  v4 = 0;
LABEL_12:
  v9[0] = a2;
  v9[1] = a3;
  v5 = 576LL * a3 + 1152LL * a2;
  v6 = &service_data[v5];
  printk(&unk_8291, "audio_notifier_service_cb");
  v7 = mutex_lock(&notifier_mutex);
  if ( (v5 | 0x18uLL) <= 0x900 )
  {
    *((_DWORD *)v6 + 6) = v4;
    v8 = srcu_notifier_call_chain(v6 + 56, v4, v9);
    result = mutex_unlock(&notifier_mutex);
    if ( v8 < 0 )
    {
      result = __ratelimit(&audio_notifier_service_cb__rs, "audio_notifier_service_cb");
      if ( (_DWORD)result )
        result = printk(&unk_7F88, "audio_notifier_service_cb");
    }
    goto LABEL_16;
  }
  __break(1u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return audio_notifier_ssr_modem_cb(v7);
}
