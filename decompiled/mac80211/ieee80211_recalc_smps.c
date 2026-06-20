__int64 __fastcall ieee80211_recalc_smps(__int64 result, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 944) + 832LL);
  if ( v2 )
    return ieee80211_recalc_smps_chanctx(*(_QWORD *)(result + 1616), (_BYTE *)(v2 - 152));
  return result;
}
