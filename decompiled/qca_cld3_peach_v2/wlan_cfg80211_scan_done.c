__int64 __fastcall wlan_cfg80211_scan_done(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  unsigned int (*v6)(void); // x8
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int (**)(void))(a4 + 32);
  v8 = 0;
  v9 = 0;
  BYTE6(v9) = a3;
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -1466421336 )
      __break(0x8228u);
    if ( v6() )
      goto LABEL_5;
LABEL_7:
    result = qdf_trace_msg(
               72,
               8,
               "%s: scan done callback has been dropped :%s",
               "wlan_cfg80211_scan_done",
               (const char *)(a1 + 296));
    goto LABEL_8;
  }
  if ( (*(_DWORD *)(a1 + 176) & 1) == 0 )
    goto LABEL_7;
LABEL_5:
  result = cfg80211_scan_done(a2, &v8);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
