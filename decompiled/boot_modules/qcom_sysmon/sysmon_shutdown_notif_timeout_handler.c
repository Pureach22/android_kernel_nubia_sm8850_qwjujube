__int64 __fastcall sysmon_shutdown_notif_timeout_handler(__int64 a1)
{
  __int64 result; // x0

  result = _warn_printk("sysmon_send_shutdown to %s taking too long", *(const char **)(a1 - 32));
  __break(0x800u);
  return result;
}
