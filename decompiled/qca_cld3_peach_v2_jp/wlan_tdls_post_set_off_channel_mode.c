__int64 __fastcall wlan_tdls_post_set_off_channel_mode(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // [xsp+8h] [xbp-48h] BYREF
  __int64 v49; // [xsp+10h] [xbp-40h]
  __int64 (__fastcall *v50)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-38h]
  __int64 v51; // [xsp+20h] [xbp-30h]
  __int64 v52; // [xsp+28h] [xbp-28h]
  __int64 v53; // [xsp+30h] [xbp-20h]
  __int64 v54; // [xsp+38h] [xbp-18h] BYREF
  __int64 v55[2]; // [xsp+40h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55[0] = 0;
  v52 = 0;
  v53 = 0;
  v50 = nullptr;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  result = tdls_get_vdev(a1, 0x11u);
  if ( result )
  {
    v2 = result;
    if ( (unsigned int)tdls_get_vdev_objects(result, v55, &v54) )
    {
      wlan_objmgr_vdev_release_ref(v2, 0x11u, v3, v4, v5, v6, v7, v8, v9, v10, v11);
      result = qdf_trace_msg(
                 0,
                 2u,
                 "%s: Failed to get TDLS objects",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "wlan_tdls_post_set_off_channel_mode");
    }
    else
    {
      v20 = _qdf_mem_malloc(0x18u, "wlan_tdls_post_set_off_channel_mode", 259);
      if ( v20 )
      {
        *(_QWORD *)v20 = v2;
        *(_BYTE *)(v20 + 8) = 3;
        LOWORD(v48) = 22;
        *(_QWORD *)(v20 + 16) = wlan_tdls_offchan_parms_callback;
        v30 = v20;
        v49 = v20;
        v50 = tdls_process_cmd;
        result = scheduler_post_message_debug(
                   0,
                   0,
                   73,
                   (unsigned __int16 *)&v48,
                   0x112u,
                   (__int64)"wlan_tdls_post_set_off_channel_mode");
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: post set offchanmode msg fail",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "wlan_tdls_post_set_off_channel_mode");
          wlan_objmgr_vdev_release_ref(v2, 0x11u, v39, v40, v41, v42, v43, v44, v45, v46, v47);
          result = _qdf_mem_free(v30);
        }
      }
      else
      {
        result = wlan_objmgr_vdev_release_ref(v2, 0x11u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
