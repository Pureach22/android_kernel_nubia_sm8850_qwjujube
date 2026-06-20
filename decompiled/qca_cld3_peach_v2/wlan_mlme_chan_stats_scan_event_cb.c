__int64 __fastcall wlan_mlme_chan_stats_scan_event_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  result = util_is_scan_completed(a2, v3);
  if ( (result & 1) != 0 )
    result = mlme_send_scan_done_complete_cb();
  _ReadStatusReg(SP_EL0);
  return result;
}
