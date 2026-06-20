__int64 __fastcall ml_nlink_emlsr_opportunistic_timer_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x23
  unsigned int v24; // w21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  __int64 result; // x0
  __int64 v35; // x8
  int v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int updated; // w0
  void *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55[2]; // [xsp+8h] [xbp-48h] BYREF
  int v56; // [xsp+18h] [xbp-38h]
  _BYTE v57[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v58[4]; // [xsp+24h] [xbp-2Ch] BYREF
  int v59; // [xsp+28h] [xbp-28h] BYREF
  char v60; // [xsp+2Ch] [xbp-24h]
  _QWORD v61[2]; // [xsp+30h] [xbp-20h] BYREF
  int v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v55[0] = 0;
  v55[1] = 0;
  if ( a1 )
  {
    if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0 && (wlan_mlme_is_aux_emlsr_support(a1) & 1) != 0 )
    {
      v58[0] = 0;
      v57[0] = 0;
      v60 = 0;
      v59 = 0;
      v62 = 0;
      v61[0] = 0;
      v61[1] = 0;
      policy_mgr_get_ml_sta_info_psoc(a1, v58, v57, (__int64)&v59, (__int64)v61, nullptr, 0, 0);
      if ( (unsigned int)v58[0] - 6 >= 0xFFFFFFFB )
      {
        v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                (unsigned __int8)v59,
                90);
        if ( v12 )
        {
          v22 = *(_QWORD *)(v12 + 1360);
          if ( v22 )
          {
            if ( !*(_QWORD *)(v22 + 2224) )
              goto LABEL_16;
            v23 = v12;
            qdf_mutex_acquire(v22 + 1656);
            v24 = *(_DWORD *)(*(_QWORD *)(v22 + 2224) + 1448LL);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: disable_req 0x%x",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "ml_nlink_get_emlsr_mode_disable_req",
              v24);
            qdf_mutex_release(v22 + 1656);
            v13 = 4294967070LL;
            if ( (v24 & 0xFFFFFF1E) != 0 )
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: emlsr disabled by req 0x%x",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "ml_nlink_emlsr_opportunistic_timer_handler",
                v24);
LABEL_10:
              v33 = 0;
LABEL_23:
              v12 = v23;
              goto LABEL_24;
            }
            v22 = *(_QWORD *)(v23 + 1360);
            v12 = v23;
            if ( v22 )
            {
LABEL_16:
              v13 = *(_QWORD *)(v22 + 2224);
              if ( v13 )
              {
                v23 = v12;
                qdf_mutex_acquire(v22 + 1656);
                v35 = *(_QWORD *)(v22 + 2224);
                v36 = *(_DWORD *)(v35 + 1448);
                *(_DWORD *)(v35 + 1448) = v36 & 0xFFFFFF9F;
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: clr disable_req to 0x%x from 0x%x by req 0x%x",
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  "ml_nlink_clr_emlsr_mode_disable_req");
                qdf_mutex_release(v22 + 1656);
                if ( (v36 & 0x40) != 0 )
                {
                  v46 = qdf_mem_set(v55, 0x14u, 0);
                  ml_nlink_update_force_link_request(v47, v48, v49, v50, v51, v52, v53, v54, (__int64)v46, v23, v55, 1u);
                  updated = ml_nlink_state_change(a1, 1, 20, a2);
                }
                else
                {
                  v13 = v36 & 0x21;
                  if ( (_DWORD)v13 != 32 )
                    goto LABEL_10;
                  updated = ml_nlink_update_non_force_disallow_bitmap(a1, v23, 20, 1, 0);
                }
                v33 = updated;
                goto LABEL_23;
              }
            }
          }
          v33 = 0;
LABEL_24:
          wlan_objmgr_vdev_release_ref(v12, 0x5Au, (unsigned int *)v13, v14, v15, v16, v17, v18, v19, v20, v21);
          result = v33;
          goto LABEL_14;
        }
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: invalid vdev for id %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "ml_nlink_get_affect_ml_sta",
          (unsigned __int8)v59);
      }
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: psoc null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ml_nlink_emlsr_opportunistic_timer_handler");
    result = 4;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
