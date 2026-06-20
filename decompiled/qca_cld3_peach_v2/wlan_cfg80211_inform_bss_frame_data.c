__int64 __fastcall wlan_cfg80211_inform_bss_frame_data(__int64 a1, __int64 *a2)
{
  char v2; // w8
  __int64 v3; // x2
  __int64 v4; // x9
  int v5; // w10
  __int64 v6; // x3
  __int64 result; // x0
  __int64 v8; // [xsp+0h] [xbp-40h] BYREF
  __int64 v9; // [xsp+8h] [xbp-38h]
  __int64 v10; // [xsp+10h] [xbp-30h]
  __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  if ( a2 )
  {
    v2 = 0;
    if ( *((_BYTE *)a2 + 40) && *((unsigned __int8 *)a2 + 40) != 255 )
    {
      v2 = 1;
      HIBYTE(v12) = *((_BYTE *)a2 + 40);
      BYTE6(v12) = 1;
    }
    if ( *((_BYTE *)a2 + 41) && *((unsigned __int8 *)a2 + 41) != 255 )
    {
      v2 |= 2u;
      LOBYTE(v13) = *((_BYTE *)a2 + 41);
      BYTE6(v12) = v2;
    }
    if ( *((_BYTE *)a2 + 42) && *((unsigned __int8 *)a2 + 42) != 255 )
    {
      v2 |= 4u;
      BYTE1(v13) = *((_BYTE *)a2 + 42);
      BYTE6(v12) = v2;
    }
    if ( *((_BYTE *)a2 + 43) && *((unsigned __int8 *)a2 + 43) != 255 )
    {
      BYTE2(v13) = *((_BYTE *)a2 + 43);
      BYTE6(v12) = v2 | 8;
    }
    v3 = a2[1];
    v4 = a2[4];
    v5 = *((_DWORD *)a2 + 6);
    v6 = a2[2];
    v8 = *a2;
    v10 = v4;
    LODWORD(v9) = v5;
    result = cfg80211_inform_bss_frame_data(a1, &v8, v3, v6, 2080);
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: bss is null", "wlan_cfg80211_inform_bss_frame_data");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
