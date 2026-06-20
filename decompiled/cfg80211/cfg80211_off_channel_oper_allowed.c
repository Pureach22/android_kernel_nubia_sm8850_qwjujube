__int64 __fastcall cfg80211_off_channel_oper_allowed(__int64 a1, __int64 a2)
{
  __int64 v3; // x2
  unsigned int v4; // w8
  unsigned int v5; // w20
  char v6; // w21
  bool v7; // w9
  __int64 v8; // x0
  char v10; // w0

  if ( (cfg80211_wdev_channel_allowed(a1, a2) & 1) != 0 )
  {
    if ( !cfg80211_beaconing_iface_active(a1) )
      goto LABEL_13;
    v4 = *(unsigned __int16 *)(a1 + 1472);
    v5 = 0;
    v6 = 1;
    v7 = *(_WORD *)(a1 + 1472) == 0;
    do
    {
      if ( v7 || (((unsigned __int64)v4 >> v5) & 1) != 0 )
      {
        v8 = wdev_chandef(a1, v5, v3);
        if ( v8 && *(_QWORD *)v8 )
          v6 &= (*(_BYTE *)(*(_QWORD *)v8 + 12LL) & 8) == 0;
      }
      v4 = *(unsigned __int16 *)(a1 + 1472);
      v7 = *(_WORD *)(a1 + 1472) == 0;
      if ( !*(_WORD *)(a1 + 1472) )
        break;
    }
    while ( v5++ < 0xE );
    if ( (v6 & 1) == 0 )
      v10 = regulatory_pre_cac_allowed(*(_QWORD *)a1);
    else
LABEL_13:
      v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  return v10 & 1;
}
