__int64 __fastcall wma_update_set_key(
        unsigned int a1,
        char a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x24
  unsigned __int8 *key; // x22
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x19
  void *v56; // x22
  __int16 v57; // t1
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x19
  __int64 v67; // [xsp+0h] [xbp-10h] BYREF
  __int64 v68; // [xsp+8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(54, (__int64)"wma_update_set_key", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v25 = *(_QWORD *)(result + 520) + 488LL * (unsigned __int8)a1;
    if ( v25 )
    {
      *(_BYTE *)(v25 + 432) = 0;
      result = (__int64)_cds_get_context(54, (__int64)"wma_send_set_key_rsp", v17, v18, v19, v20, v21, v22, v23, v24);
      WORD2(v67) = -1;
      LODWORD(v67) = -1;
      if ( result )
      {
        v26 = result;
        v27 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                *(_QWORD *)(result + 24),
                a1,
                8);
        if ( v27 )
        {
          v36 = v27;
          key = (unsigned __int8 *)wlan_crypto_get_key(v27, a4, a3);
          wlan_objmgr_vdev_release_ref(v36, 8u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
          if ( key )
          {
            if ( (a2 & 1) != 0 )
            {
              result = _qdf_mem_malloc(0x20u, "wma_send_set_key_rsp", 6437);
              if ( result )
              {
                *(_BYTE *)(result + 6) = a1;
                v55 = result;
                *(_DWORD *)(result + 16) = 0;
                v57 = *key;
                v56 = key + 16;
                *(_WORD *)(result + 28) = v57;
                qdf_mem_copy((void *)(result + 21), v56, 6u);
                wma_send_msg_high_priority(v26, 4149, v55, 0);
                result = wlan_release_peer_key_wakelock(
                           v36,
                           (unsigned __int8 *)v56,
                           v58,
                           v59,
                           v60,
                           v61,
                           v62,
                           v63,
                           v64,
                           v65);
              }
            }
            else
            {
              result = _qdf_mem_malloc(0x10u, "wma_send_set_key_rsp", 6449);
              if ( result )
              {
                *(_BYTE *)result = a1;
                v66 = result;
                *(_DWORD *)(result + 4) = 0;
                *(_WORD *)(result + 14) = *key;
                qdf_mem_copy((void *)(result + 8), &v67, 6u);
                result = wma_send_msg_high_priority(v26, 4147, v66, 0);
              }
            }
          }
          else
          {
            result = qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: crypto_key not found",
                       v47,
                       v48,
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       "wma_send_set_key_rsp",
                       v67,
                       v68);
          }
        }
        else
        {
          result = qdf_trace_msg(
                     0x36u,
                     2u,
                     "%s: VDEV object not found",
                     v28,
                     v29,
                     v30,
                     v31,
                     v32,
                     v33,
                     v34,
                     v35,
                     "wma_send_set_key_rsp",
                     v67,
                     v68);
        }
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: iface not found for session id %d",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "wma_update_set_key",
                 (unsigned __int8)a1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
