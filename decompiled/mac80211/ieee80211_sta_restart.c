__int64 __fastcall ieee80211_sta_restart(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  _QWORD v3[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v4; // [xsp+28h] [xbp-18h]
  __int16 v5; // [xsp+30h] [xbp-10h]
  __int64 v6; // [xsp+38h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(result + 2477) & 8) != 0 )
  {
    v1 = *(_DWORD *)(result + 1624);
    if ( (v1 & 0x10) != 0 )
    {
      v5 = 0;
      *(_DWORD *)(result + 1624) = v1 & 0xFFFFFFEF;
      v4 = 0;
      goto LABEL_6;
    }
    if ( (v1 & 0x40) != 0 )
    {
      v5 = 0;
      v4 = 0;
      *(_DWORD *)(result + 1624) = v1 & 0xFFFFFFAF;
LABEL_6:
      v3[0] = 0;
      v3[1] = 0;
      v2 = result;
      ieee80211_set_disassoc(result, 0xC0u, 1u, 1, (__int64)v3);
      cfg80211_tx_mlme_mgmt(*(_QWORD *)(v2 + 1608), v3, 26, 0);
      result = drv_event_callback(*(_QWORD *)(v2 + 1616));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
