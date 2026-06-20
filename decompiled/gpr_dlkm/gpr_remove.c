__int64 __fastcall gpr_remove(__int64 a1)
{
  int v2; // w8
  const char *v3; // x3

  wakeup_source_unregister(*(_QWORD *)(gpr_priv + 96));
  snd_event_client_deregister(a1);
  dev_info(
    a1,
    "%s: deregistering via subsys_notif_register for domain_id(%d)",
    "gpr_remove",
    *(_DWORD *)(gpr_priv + 56));
  v2 = *(_DWORD *)(gpr_priv + 56);
  if ( v2 == 1 )
  {
    if ( (audio_notifier_deregister("gpr_modem") & 0x80000000) != 0
      && (unsigned int)__ratelimit(&gpr_subsys_notif_deregister__rs, "gpr_subsys_notif_deregister") )
    {
      v3 = "gpr_modem";
      goto LABEL_10;
    }
  }
  else if ( v2 == 2
         && (audio_notifier_deregister("gpr_adsp") & 0x80000000) != 0
         && (unsigned int)__ratelimit(&gpr_subsys_notif_deregister__rs, "gpr_subsys_notif_deregister") )
  {
    v3 = "gpr_adsp";
LABEL_10:
    dev_err(
      *(_QWORD *)(gpr_priv + 8),
      "%s: Audio notifier de-register failed for client %s\n",
      "gpr_subsys_notif_deregister",
      v3);
  }
  return device_for_each_child(a1, 0, gpr_remove_device);
}
