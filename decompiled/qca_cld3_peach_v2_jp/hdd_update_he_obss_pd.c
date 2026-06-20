__int64 __fastcall hdd_update_he_obss_pd(__int64 *a1, unsigned __int8 *a2)
{
  __int64 v4; // x8
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _BYTE v23[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v23[0] = 0;
  result = wlan_mlme_get_sr_enable_modes(**(_QWORD **)(v4 + 24), v23);
  if ( ((v23[0] >> *(_DWORD *)(*a1 + 40)) & 1) != 0 )
  {
    if ( a2 )
    {
      if ( a2[820] == 1 )
      {
        result = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_update_he_obss_pd");
        if ( result )
        {
          v14 = result;
          ucfg_spatial_reuse_set_sr_config(result, a2[821], a2[822]);
          ucfg_spatial_reuse_set_sr_enable(v14, a2[820]);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: obss_pd_enable: %d, sr_ctrl: %d, non_srg_max_offset: %d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "hdd_update_he_obss_pd",
            a2[820],
            a2[821],
            a2[822]);
          result = _hdd_objmgr_put_vdev_by_user(v14, 6, "hdd_update_he_obss_pd");
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: SR operation not allowed for mode %d",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "hdd_update_he_obss_pd");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
