__int64 __fastcall sysmon_notif_timeout_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = *(unsigned int *)(a1 - 104);
  if ( (unsigned int)v1 >= 4 )
  {
    __break(0x5512u);
    return sysmon_shutdown_interrupt();
  }
  else
  {
    result = _warn_printk(
               "sysmon msg from %s to %s for %s taking too long",
               *(const char **)(a1 - 32),
               *(const char **)(*(_QWORD *)(a1 - 8) + 128LL),
               subdevice_state_string[v1]);
    __break(0x800u);
  }
  return result;
}
