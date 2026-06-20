__int64 __fastcall cm_connect_start_ind(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 result; // x0
  __int64 rso_config_fl; // x0
  int v16; // w9
  int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // [xsp+8h] [xbp-28h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  if ( a1 && a2 )
  {
    v10 = *(_QWORD *)(a1 + 152);
    if ( v10 && (v11 = *(_QWORD *)(v10 + 80)) != 0 )
    {
      if ( (wlan_dp_is_local_pkt_capture_active() & 1) != 0 || (policy_mgr_is_sta_mon_concurrency(v11) & 1) == 0 )
      {
        rso_config_fl = wlan_cm_get_rso_config_fl(a1, "cm_connect_start_ind", 1071);
        if ( rso_config_fl )
        {
          *(_WORD *)(rso_config_fl + 84) = *((_WORD *)a2 + 60);
          *(_DWORD *)(rso_config_fl + 64) = *((_DWORD *)a2 + 19);
          *(_DWORD *)(rso_config_fl + 72) = *((_DWORD *)a2 + 21);
          *(_DWORD *)(rso_config_fl + 76) = *((_DWORD *)a2 + 20);
          v16 = *((_DWORD *)a2 + 22);
          *(_BYTE *)(rso_config_fl + 960) = 0;
          *(_DWORD *)(rso_config_fl + 68) = v16;
          v17 = a2[128];
          if ( v17 == 64 )
            LOWORD(v17) = 192;
          *(_WORD *)(rso_config_fl + 1364) = *((_WORD *)a2 + 60) & 0xFF3F | v17;
        }
        if ( wlan_get_vendor_ie_ptr_from_oui(&unk_94D6FC, 4u, *((unsigned __int8 **)a2 + 20), *((_DWORD *)a2 + 38)) )
          LOBYTE(v21) = 1;
        v18 = *(_QWORD *)(a1 + 152);
        if ( v18 )
          v19 = *(_QWORD *)(v18 + 80);
        else
          v19 = 0;
        wlan_cm_roam_cfg_set_value(v19, *(unsigned __int8 *)(a1 + 104), 23, &v20);
        result = 0;
      }
      else
      {
        result = 11;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev_id: %d psoc not found",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "cm_connect_start_ind",
        *a2);
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev or req is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "cm_connect_start_ind");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
