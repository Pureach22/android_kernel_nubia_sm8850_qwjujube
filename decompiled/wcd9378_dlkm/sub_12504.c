__int64 __fastcall sub_12504(__int64 a1, __int64 a2)
{
  __int64 v2; // x29

  if ( (v2 & 0x4000000000000000LL) != 0 )
    return wcd9378_rx2_mode_put(a1, a2);
  else
    return wcd9378_mbhc_request_micbias();
}
