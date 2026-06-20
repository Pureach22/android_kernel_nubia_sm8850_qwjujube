__int64 __fastcall hdd_update_vdev_nss(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w20
  __int64 v12; // x19
  __int64 result; // x0
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v14[0] = 0;
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(v2, v14) )
    qdf_trace_msg(0x33u, 2u, "%s: unable to get vht_enable2x2", v3, v4, v5, v6, v7, v8, v9, v10, "hdd_update_vdev_nss");
  if ( v14[0] && !cds_is_sub_20_mhz_enabled(v3, v4, v5, v6, v7, v8, v9, v10) )
    v11 = v14[0] + 1;
  else
    v11 = 1;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: max nss %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "hdd_update_vdev_nss",
    (unsigned __int8)v11);
  v12 = a1[2];
  sme_update_vdev_type_nss(v12, v11, 0);
  result = sme_update_vdev_type_nss(v12, v11, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
