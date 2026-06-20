__int64 __fastcall wcd939x_get_hwdep_fw_cal(__int64 a1, int a2)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 216);
  if ( v2 )
  {
    result = wcdcal_get_fw_cal(*(_QWORD *)(a1 + 1048));
    if ( result )
      return result;
    if ( (unsigned int)__ratelimit(&wcd939x_get_hwdep_fw_cal__rs_20, "wcd939x_get_hwdep_fw_cal") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: cal not sent by %d\n", "wcd939x_get_hwdep_fw_cal", a2);
  }
  else if ( (unsigned int)__ratelimit(&wcd939x_get_hwdep_fw_cal__rs, "wcd939x_get_hwdep_fw_cal") )
  {
    printk(&unk_18530, "wcd939x_get_hwdep_fw_cal");
  }
  return 0;
}
