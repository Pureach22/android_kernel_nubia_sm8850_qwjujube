__int64 __fastcall sde_encoder_pm_qos_remove_request(__int64 result)
{
  __int64 v1; // x19
  char v2; // w8
  __int64 v3; // x24
  int v4; // w7
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x22
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = result;
  v2 = 0;
  v3 = result + 1376;
  do
  {
    v5 = (unsigned int)(-1LL << v2) & *(_DWORD *)(v1 + 3936);
    if ( !(_DWORD)v5 )
      break;
    v6 = __clz(__rbit64(v5));
    if ( get_cpu_device((unsigned int)v6) )
    {
      dev_pm_qos_remove_request(v3 + 80LL * (unsigned int)v6);
      result = sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "_sde_encoder_pm_qos_remove_request",
                 368,
                 4,
                 *(_DWORD *)(v1 + 24),
                 v6,
                 -1059143953,
                 v4,
                 vars0);
    }
    else
    {
      result = printk(&unk_276F4E, "_sde_encoder_pm_qos_remove_request");
    }
    v2 = v6 + 1;
  }
  while ( v6 < 0x1F );
  *(_QWORD *)(v1 + 3936) = 0;
  return result;
}
