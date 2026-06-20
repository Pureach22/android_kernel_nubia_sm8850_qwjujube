__int64 __fastcall dp_update_no_ack_stats(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 result; // x0
  __int64 v6; // x8
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  result = qdf_dp_track_noack_check(a1, &v7);
  if ( !a2 || !v7 )
    goto LABEL_5;
  if ( v7 < 0x3F )
  {
    v6 = a2 + 4072LL * a3 + 4LL * v7;
    ++*(_DWORD *)(v6 + 2488);
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return dp_calculate_percentile(result);
}
