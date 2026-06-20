__int64 __fastcall ml_nlink_undo_emlsr_downgrade_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w4
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 v33; // x8
  __int64 v34; // x19
  int v35; // w20
  __int64 v36; // x22
  __int64 v37; // x8
  int v38; // w21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _BYTE v56[4]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v57[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v58; // [xsp+8h] [xbp-28h] BYREF
  char v59; // [xsp+Ch] [xbp-24h]
  _QWORD v60[2]; // [xsp+10h] [xbp-20h] BYREF
  int v61; // [xsp+20h] [xbp-10h]
  __int64 v62; // [xsp+28h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = mlo_is_mld_sta(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (result & 1) == 0 )
  {
    result = wlan_mlme_is_aux_emlsr_support(a1);
    if ( (result & 1) != 0 )
    {
      result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
      if ( (result & 1) != 0 )
      {
        v23 = *(_DWORD *)(a2 + 16);
        if ( v23 < 4 || v23 == 16 )
        {
          v57[0] = 0;
          v56[0] = 0;
          v59 = 0;
          v58 = 0;
          v61 = 0;
          v60[0] = 0;
          v60[1] = 0;
          result = policy_mgr_get_ml_sta_info_psoc(a1, v57, v56, (__int64)&v58, (__int64)v60, nullptr, 0, 0);
          if ( (unsigned int)v57[0] - 6 >= 0xFFFFFFFB )
          {
            v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1,
                    (unsigned __int8)v58,
                    90);
            if ( v24 )
            {
              v33 = a3 - 11;
              v34 = v24;
              if ( (unsigned int)v33 >= 3 )
              {
                if ( a3 == 25 )
                {
                  v35 = 256;
                }
                else
                {
                  v33 = a3 & 0xFFFFFFFE;
                  if ( (_DWORD)v33 == 6 )
                  {
                    v35 = 16;
                  }
                  else
                  {
                    if ( a3 != 30 )
                    {
                      qdf_trace_msg(
                        0x8Fu,
                        8u,
                        "%s: not handled for evt %d",
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        v31,
                        v32,
                        "ml_nlink_undo_emlsr_downgrade_handler",
                        a3);
LABEL_27:
                      result = wlan_objmgr_vdev_release_ref(
                                 v34,
                                 0x5Au,
                                 (unsigned int *)v33,
                                 v25,
                                 v26,
                                 v27,
                                 v28,
                                 v29,
                                 v30,
                                 v31,
                                 v32);
                      goto LABEL_28;
                    }
                    v35 = 512;
                  }
                }
              }
              else
              {
                v35 = 8;
              }
              v36 = *(_QWORD *)(v24 + 1360);
              if ( v36 && (v33 = *(_QWORD *)(v36 + 2224)) != 0 )
              {
                qdf_mutex_acquire(v36 + 1656);
                v37 = *(_QWORD *)(v36 + 2224);
                v38 = *(_DWORD *)(v37 + 1448);
                *(_DWORD *)(v37 + 1448) = v38 & ~v35;
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: clr disable_req to 0x%x from 0x%x by req 0x%x",
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  "ml_nlink_clr_emlsr_mode_disable_req");
                qdf_mutex_release(v36 + 1656);
              }
              else
              {
                v38 = 0;
              }
              if ( (v38 & v35) != 0 )
              {
                v47 = *(_QWORD *)(v34 + 1360);
                if ( v47 && *(_QWORD *)(v47 + 2224) )
                {
                  qdf_mutex_acquire(v47 + 1656);
                  *(_DWORD *)(*(_QWORD *)(v47 + 2224) + 1448LL) |= 0x40u;
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: set disable_req to 0x%x from 0x%x by req 0x%x",
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    "ml_nlink_set_emlsr_mode_disable_req");
                  qdf_mutex_release(v47 + 1656);
                }
                else
                {
                  qdf_trace_msg(
                    0x8Fu,
                    2u,
                    "%s: mlo_ctx or sta_ctx null",
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    "ml_nlink_set_emlsr_mode_disable_req");
                }
              }
              goto LABEL_27;
            }
            result = qdf_trace_msg(
                       0x8Fu,
                       2u,
                       "%s: invalid vdev for id %d",
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       "ml_nlink_get_affect_ml_sta",
                       (unsigned __int8)v58);
          }
        }
        else
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: op_mode: %d",
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "ml_nlink_undo_emlsr_downgrade_handler");
        }
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
