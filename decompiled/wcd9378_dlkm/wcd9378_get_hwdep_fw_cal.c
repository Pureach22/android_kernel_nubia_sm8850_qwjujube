__int64 __fastcall wcd9378_get_hwdep_fw_cal(__int64 a1, int a2)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 216);
  if ( !v2 )
  {
    printk(&unk_12F4A, "wcd9378_get_hwdep_fw_cal");
    return 0;
  }
  result = wcdcal_get_fw_cal(*(_QWORD *)(a1 + 1048));
  if ( !result )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: cal not sent by %d\n", "wcd9378_get_hwdep_fw_cal", a2);
    return 0;
  }
  return result;
}
