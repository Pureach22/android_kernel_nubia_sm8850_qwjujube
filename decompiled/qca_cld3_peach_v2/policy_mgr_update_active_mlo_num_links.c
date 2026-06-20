__int64 __fastcall policy_mgr_update_active_mlo_num_links(__int64 a1, unsigned int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x8
  unsigned int v25; // w21
  __int64 v26; // x19
  __int64 context; // x0
  _QWORD *v28; // x23
  unsigned __int8 connection_count; // w25
  unsigned int v30; // w23
  unsigned int v31; // w24
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w0
  const char *v41; // x2
  __int64 v42; // x4
  const char *v43; // x2
  unsigned int v44; // w1
  char v45; // w8
  const char *v46; // x2
  __int64 v47; // x4
  _BYTE v48[4]; // [xsp+Ch] [xbp-34h] BYREF
  _BYTE v49[4]; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v50[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v51; // [xsp+18h] [xbp-28h] BYREF
  char v52; // [xsp+1Ch] [xbp-24h]
  _QWORD v53[2]; // [xsp+20h] [xbp-20h] BYREF
  int v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50[0] = 0;
  v49[0] = 0;
  v48[0] = 0;
  v52 = 0;
  v51 = 0;
  v54 = 0;
  v53[0] = 0;
  v53[1] = 0;
  if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) == 0 )
  {
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
    if ( !v15 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev_id: %d vdev not found",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "policy_mgr_update_active_mlo_num_links",
        (unsigned __int8)a2);
      result = 16;
      goto LABEL_23;
    }
    v24 = *(unsigned int *)(v15 + 16);
    if ( (_DWORD)v24 )
    {
      v25 = 16;
LABEL_22:
      wlan_objmgr_vdev_release_ref(v15, 0x18u, (unsigned int *)v24, v16, v17, v18, v19, v20, v21, v22, v23);
      result = v25;
      goto LABEL_23;
    }
    v26 = v15;
    if ( wlan_cm_is_vdev_connected(v15, v16, v17, v18, v19, v20, v21, v22, v23) )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(v26, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
      {
        context = policy_mgr_get_context(a1);
        if ( context )
        {
          v28 = (_QWORD *)context;
          connection_count = policy_mgr_get_connection_count(a1);
          policy_mgr_get_ml_sta_info(v28, v50, v49, (__int64)&v51, (__int64)v53, v48, 0, 0);
          v30 = v50[0];
          v31 = v49[0];
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev %d: num_ml_sta %d disabled %d num_non_ml: %d conn cout %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "policy_mgr_update_active_mlo_num_links",
            (unsigned __int8)a2,
            v50[0],
            v49[0],
            v48[0],
            connection_count);
          v24 = (unsigned __int8)(v30 - 6);
          if ( (unsigned int)v24 >= 0xFB )
          {
            if ( (unsigned __int8)a3 == 1 )
            {
LABEL_12:
              v40 = policy_mgr_mlo_sta_set_link_ext(
                      a1,
                      1u,
                      5u,
                      v30,
                      (unsigned __int8 *)&v51,
                      0,
                      0,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23);
              if ( v40 )
              {
                v25 = v40;
                v41 = "%s: fail to send no force cmd for num_links:%d";
                v42 = v30;
              }
              else
              {
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: clear force mode setting for num_links:%d",
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  "policy_mgr_update_active_mlo_num_links",
                  v30);
                v24 = (unsigned int)policy_mgr_process_mlo_sta_dynamic_force_num_link(a1, v30, &v51, a3);
                v15 = v26;
                v25 = v24;
                if ( (_DWORD)v24 )
                  goto LABEL_22;
                v41 = "%s: vdev %d: link enable allowed";
                v42 = (unsigned __int8)a2;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                v41,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                "policy_mgr_update_active_mlo_num_links",
                v42);
              goto LABEL_21;
            }
            if ( v30 >= v31 )
              v45 = v31;
            else
              v45 = 0;
            if ( (_BYTE)a3 )
            {
              if ( v30 <= 1 )
              {
                v46 = "%s: num_ml_sta %d < 2, can't force active cnt %d";
                v47 = v30;
LABEL_35:
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  v46,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  "policy_mgr_update_active_mlo_num_links",
                  v47);
                goto LABEL_20;
              }
              v47 = (unsigned __int8)(v30 - v45);
              if ( (unsigned int)v47 <= 1 && connection_count > (unsigned int)v47 )
              {
                v46 = "%s: enabled link num %d < 2, concurrent conn present %d";
                goto LABEL_35;
              }
              if ( (policy_mgr_is_ml_sta_links_in_mcc(a1, (__int64)v53, (__int64)&v51, 0, v30, nullptr) & 1) != 0 )
              {
                v43 = "%s: enabled links are mcc, concurrency disallow";
                v44 = 8;
                goto LABEL_19;
              }
              LOBYTE(v31) = v49[0];
              v30 = v50[0];
              if ( (unsigned __int8)a3 == 2 && !v49[0] )
                goto LABEL_12;
            }
            if ( (policy_mgr_sta_ml_link_enable_allowed(a1, v31, v30, (__int64)v53, (__int64)&v51) & 1) != 0 )
              goto LABEL_12;
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: vdev %d: link enable not allowed",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "policy_mgr_update_active_mlo_num_links",
              (unsigned __int8)a2);
          }
LABEL_20:
          v25 = 16;
LABEL_21:
          v15 = v26;
          goto LABEL_22;
        }
        v43 = "%s: Invalid Context";
      }
      else
      {
        v43 = "%s: vdev is not mlo vdev";
      }
    }
    else
    {
      v43 = "%s: vdev is not in connected state";
    }
    v44 = 2;
LABEL_19:
    qdf_trace_msg(0x4Fu, v44, v43, v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_update_active_mlo_num_links");
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Concurrency exists, cannot enter EMLSR mode",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "policy_mgr_update_active_mlo_num_links");
  result = 16;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
