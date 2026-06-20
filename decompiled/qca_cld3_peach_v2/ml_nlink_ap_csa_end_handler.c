__int64 __fastcall ml_nlink_ap_csa_end_handler(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v13; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 v24; // x20
  __int64 v25; // x8
  int v26; // w19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  _BYTE v53[4]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v54[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v55; // [xsp+8h] [xbp-28h] BYREF
  char v56; // [xsp+Ch] [xbp-24h]
  _QWORD v57[2]; // [xsp+10h] [xbp-20h] BYREF
  int v58; // [xsp+20h] [xbp-10h]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: vdev %d csa result %d ",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ml_nlink_ap_csa_end_handler",
    *(unsigned __int8 *)(a2 + 168),
    *a3);
  result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
  if ( (result & 1) != 0 )
  {
    result = wlan_mlme_is_aux_emlsr_support(a1);
    if ( (result & 1) != 0 )
    {
      v54[0] = 0;
      v53[0] = 0;
      v56 = 0;
      v55 = 0;
      v58 = 0;
      v57[0] = 0;
      v57[1] = 0;
      result = policy_mgr_get_ml_sta_info_psoc(a1, v54, v53, (__int64)&v55, (__int64)v57, nullptr, 0, 0);
      if ( (unsigned int)v54[0] - 6 >= 0xFFFFFFFB )
      {
        v13 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                (unsigned __int8)v55,
                90);
        if ( v13 )
        {
          v23 = *(_QWORD *)(v13 + 1360);
          if ( v23 )
          {
            v14 = *(unsigned int **)(v23 + 2224);
            if ( v14 )
            {
              v24 = v13;
              qdf_mutex_acquire(v23 + 1656);
              v25 = *(_QWORD *)(v23 + 2224);
              v26 = *(_DWORD *)(v25 + 1448);
              *(_DWORD *)(v25 + 1448) = v26 & 0xFFFFFFF9;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: clr disable_req to 0x%x from 0x%x by req 0x%x",
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                "ml_nlink_clr_emlsr_mode_disable_req");
              qdf_mutex_release(v23 + 1656);
              if ( (v26 & 4) != 0 )
              {
                v35 = *(_QWORD *)(v24 + 1360);
                if ( v35 && *(_QWORD *)(v35 + 2224) )
                {
                  qdf_mutex_acquire(v35 + 1656);
                  *(_DWORD *)(*(_QWORD *)(v35 + 2224) + 1448LL) |= 0x40u;
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: set disable_req to 0x%x from 0x%x by req 0x%x",
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    "ml_nlink_set_emlsr_mode_disable_req");
                  qdf_mutex_release(v35 + 1656);
                }
                else
                {
                  qdf_trace_msg(
                    0x8Fu,
                    2u,
                    "%s: mlo_ctx or sta_ctx null",
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    "ml_nlink_set_emlsr_mode_disable_req");
                }
              }
              v13 = v24;
              if ( (v26 & 2) != 0 )
              {
                v44 = *(_QWORD *)(v24 + 1360);
                if ( v44 && *(_QWORD *)(v44 + 2224) )
                {
                  qdf_mutex_acquire(v44 + 1656);
                  *(_DWORD *)(*(_QWORD *)(v44 + 2224) + 1448LL) |= 0x20u;
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: set disable_req to 0x%x from 0x%x by req 0x%x",
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    "ml_nlink_set_emlsr_mode_disable_req");
                  qdf_mutex_release(v44 + 1656);
                }
                else
                {
                  qdf_trace_msg(
                    0x8Fu,
                    2u,
                    "%s: mlo_ctx or sta_ctx null",
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    "ml_nlink_set_emlsr_mode_disable_req");
                }
                v13 = v24;
              }
            }
          }
          result = wlan_objmgr_vdev_release_ref(v13, 0x5Au, v14, v15, v16, v17, v18, v19, v20, v21, v22);
        }
        else
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     2u,
                     "%s: invalid vdev for id %d",
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "ml_nlink_get_affect_ml_sta",
                     (unsigned __int8)v55);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
