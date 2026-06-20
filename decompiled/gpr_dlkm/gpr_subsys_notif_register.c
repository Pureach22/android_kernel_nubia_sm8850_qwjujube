__int64 __fastcall gpr_subsys_notif_register(__int64 a1, int a2)
{
  __int64 result; // x0
  int v4; // w20

  result = audio_notifier_register();
  if ( (result & 0x80000000) != 0 )
  {
    v4 = result;
    result = __ratelimit(&gpr_subsys_notif_register__rs, "gpr_subsys_notif_register");
    if ( (_DWORD)result )
      return dev_err(
               *(_QWORD *)(gpr_priv + 8),
               "%s: Audio notifier register failed for domain %d ret = %d\n",
               "gpr_subsys_notif_register",
               a2,
               v4);
  }
  return result;
}
