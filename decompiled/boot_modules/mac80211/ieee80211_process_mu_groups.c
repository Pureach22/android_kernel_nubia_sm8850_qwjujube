__int64 __fastcall ieee80211_process_mu_groups(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  _QWORD *v4; // x10
  bool v5; // zf
  __int64 v6; // x8

  v3 = *(_QWORD *)(a2 + 944);
  if ( *(_BYTE *)(v3 + 831) == 1 )
  {
    v4 = (_QWORD *)(v3 + 208);
    v5 = *(_QWORD *)(a3 + 34) == *(_QWORD *)(v3 + 208) && *(_QWORD *)(a3 + 42) == *(_QWORD *)(v3 + 216);
    if ( !v5 || *(_QWORD *)(a3 + 26) != *(_QWORD *)(v3 + 200) )
    {
      *(_QWORD *)(v3 + 200) = *(_QWORD *)(a3 + 26);
      v6 = *(_QWORD *)(a3 + 42);
      *v4 = *(_QWORD *)(a3 + 34);
      v4[1] = v6;
      return ieee80211_link_info_change_notify(result, a2, 0x800000);
    }
  }
  return result;
}
