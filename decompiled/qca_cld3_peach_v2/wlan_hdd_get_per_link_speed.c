__int64 __fastcall wlan_hdd_get_per_link_speed(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int16 v10; // w9
  const char *v11; // x2
  unsigned int v12; // w1
  __int64 result; // x0
  unsigned int v14; // [xsp+Ch] [xbp-14h] BYREF
  int v15; // [xsp+10h] [xbp-10h] BYREF
  __int16 v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( hdd_cm_is_vdev_associated((_DWORD *)a1) )
  {
    v10 = *(_WORD *)(a1 + 312);
    v15 = *(_DWORD *)(a1 + 308);
    v16 = v10;
    if ( !(unsigned int)wlan_hdd_get_linkspeed_for_peermac((__int64 *)a1, &v15, &v14, v2, v3, v4, v5, v6, v7, v8, v9) )
    {
      qdf_trace_msg(0x33u, 8u, "%s: linkspeed = %d", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_hdd_get_per_link_speed", v14);
      result = v14;
      goto LABEL_6;
    }
    v11 = "%s: Unable to retrieve SME linkspeed";
    v12 = 2;
  }
  else
  {
    v11 = "%s: Not connected";
    v12 = 8;
  }
  qdf_trace_msg(0x33u, v12, v11, v2, v3, v4, v5, v6, v7, v8, v9, "wlan_hdd_get_per_link_speed");
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
