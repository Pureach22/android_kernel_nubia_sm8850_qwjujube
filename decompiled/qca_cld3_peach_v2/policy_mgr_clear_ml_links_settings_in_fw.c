__int64 __fastcall policy_mgr_clear_ml_links_settings_in_fw(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 v13; // x8
  unsigned int v14; // w24
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *context; // x0
  unsigned int v25; // w25
  unsigned int v26; // w22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w8
  int v36; // w23
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w22
  const char *v46; // x2
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _BYTE v56[4]; // [xsp+Ch] [xbp-34h] BYREF
  _BYTE v57[4]; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v58[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v59; // [xsp+18h] [xbp-28h] BYREF
  char v60; // [xsp+1Ch] [xbp-24h]
  _QWORD v61[2]; // [xsp+20h] [xbp-20h] BYREF
  int v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v2 = a2;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58[0] = 0;
  v57[0] = 0;
  v56[0] = 0;
  v60 = 0;
  v59 = 0;
  v62 = 0;
  v61[0] = 0;
  v61[1] = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v4 )
  {
    v13 = *(unsigned int *)(v4 + 16);
    if ( (_DWORD)v13 )
    {
      v14 = 16;
LABEL_20:
      wlan_objmgr_vdev_release_ref(v4, 0x18u, (unsigned int *)v13, v5, v6, v7, v8, v9, v10, v11, v12);
      goto LABEL_21;
    }
    v15 = v4;
    if ( wlan_cm_is_vdev_connected(v4, v5, v6, v7, v8, v9, v10, v11, v12) )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(v15, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
      {
        context = (_QWORD *)policy_mgr_get_context(a1);
        if ( context )
        {
          policy_mgr_get_ml_sta_info(context, v58, v57, (__int64)&v59, (__int64)v61, v56, 0, 0);
          v25 = v58[0];
          v26 = v57[0];
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev %d: num_ml_sta %d disabled %d num_non_ml: %d",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "policy_mgr_clear_ml_links_settings_in_fw",
            v2,
            v58[0],
            v57[0],
            v56[0]);
          v14 = 16;
          v13 = (unsigned __int8)(v25 - 6);
          if ( (unsigned int)v13 >= 0xFB )
          {
            v4 = v15;
            if ( v26 > 5 )
              goto LABEL_20;
            if ( v25 >= v26 )
              v35 = v26;
            else
              v35 = 0;
            v36 = v25 - v35;
            if ( (policy_mgr_sta_ml_link_enable_allowed(a1, v26, v25, (__int64)v61, (__int64)&v59) & 1) != 0 )
            {
              v36 += v26;
              v45 = (unsigned __int8)v36;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: Link enable allowed, total num_links: %d",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "policy_mgr_clear_ml_links_settings_in_fw",
                (unsigned __int8)v36);
            }
            else
            {
              v45 = (unsigned __int8)v36;
            }
            if ( (unsigned __int8)(v36 - 6) > 0xFAu )
            {
              v14 = policy_mgr_mlo_sta_set_link_ext(
                      a1,
                      1u,
                      5u,
                      v36,
                      (unsigned __int8 *)&v59,
                      0,
                      0,
                      v37,
                      v38,
                      v39,
                      v40,
                      v41,
                      v42,
                      v43,
                      v44);
              v4 = v15;
              if ( v14 )
                goto LABEL_20;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: clear user mode setting for num_links:%d",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "policy_mgr_clear_ml_links_settings_in_fw",
                v45);
              v14 = policy_mgr_process_mlo_sta_dynamic_force_num_link(
                      a1,
                      v36,
                      (unsigned __int8 *)&v59,
                      0,
                      v48,
                      v49,
                      v50,
                      v51,
                      v52,
                      v53,
                      v54,
                      v55);
              v4 = v15;
              if ( v14 )
                goto LABEL_20;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: clear mixed mode setting for num_links:%d",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "policy_mgr_clear_ml_links_settings_in_fw",
                v45);
            }
            else
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: vdev %d: invalid num_link_to_no_force: %d",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "policy_mgr_clear_ml_links_settings_in_fw",
                v2,
                v45);
            }
          }
LABEL_19:
          v4 = v15;
          goto LABEL_20;
        }
        v46 = "%s: vdev: %d Invalid Context";
      }
      else
      {
        v46 = "%s: vdev: %d is not mlo vdev";
      }
    }
    else
    {
      v46 = "%s: vdev: %d is not in connected state";
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      v46,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_clear_ml_links_settings_in_fw",
      v2);
    v14 = 16;
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: vdev: %d vdev not found",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "policy_mgr_clear_ml_links_settings_in_fw",
    v2);
  v14 = 16;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v14;
}
