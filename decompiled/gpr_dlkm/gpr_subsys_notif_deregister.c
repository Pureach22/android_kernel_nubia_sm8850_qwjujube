__int64 __fastcall gpr_subsys_notif_deregister(const char *a1)
{
  __int64 result; // x0

  result = audio_notifier_deregister();
  if ( (result & 0x80000000) != 0 )
  {
    result = __ratelimit(&gpr_subsys_notif_deregister__rs, "gpr_subsys_notif_deregister");
    if ( (_DWORD)result )
      return dev_err(
               *(_QWORD *)(gpr_priv + 8),
               "%s: Audio notifier de-register failed for client %s\n",
               "gpr_subsys_notif_deregister",
               a1);
  }
  return result;
}
