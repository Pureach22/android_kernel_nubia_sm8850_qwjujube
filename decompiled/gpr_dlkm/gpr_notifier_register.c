__int64 gpr_notifier_register()
{
  int v0; // w8
  unsigned int v1; // w0
  unsigned int v2; // w19
  unsigned int v3; // w0
  unsigned int v4; // w19
  __int64 result; // x0

  v0 = *(_DWORD *)(gpr_priv + 56);
  if ( v0 == 1 )
  {
    v3 = audio_notifier_register("gpr_modem", 1, &modem_service_nb);
    if ( (v3 & 0x80000000) != 0 )
    {
      v4 = v3;
      if ( (unsigned int)__ratelimit(&gpr_subsys_notif_register__rs, "gpr_subsys_notif_register") )
        dev_err(
          *(_QWORD *)(gpr_priv + 8),
          "%s: Audio notifier register failed for domain %d ret = %d\n",
          "gpr_subsys_notif_register",
          1,
          v4);
    }
  }
  else if ( v0 == 2 )
  {
    v1 = audio_notifier_register("gpr_adsp", 0, &adsp_service_nb);
    if ( (v1 & 0x80000000) != 0 )
    {
      v2 = v1;
      if ( (unsigned int)__ratelimit(&gpr_subsys_notif_register__rs, "gpr_subsys_notif_register") )
        dev_err(
          *(_QWORD *)(gpr_priv + 8),
          "%s: Audio notifier register failed for domain %d ret = %d\n",
          "gpr_subsys_notif_register",
          0,
          v2);
    }
  }
  result = __ratelimit(&gpr_notifier_register__rs, "gpr_notifier_register");
  if ( (_DWORD)result )
    return dev_info(
             *(_QWORD *)(gpr_priv + 8),
             "%s: registered via subsys_notif_register for domain id(%d)",
             "gpr_notifier_register",
             *(_DWORD *)(gpr_priv + 56));
  return result;
}
