__int64 __fastcall cm_connect_resp_fill_mld_addr_from_cm_id(
        __int64 a1,
        int a2,
        __int64 a3,
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
  __int64 cmpt_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  _QWORD *v33; // x1
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  __int64 v43; // x8
  __int64 v44; // x21
  int v45; // w8
  _QWORD *v46; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v47[3]; // [xsp+8h] [xbp-18h] BYREF

  v47[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = nullptr;
  v47[0] = 0;
  result = wlan_vdev_mlme_is_mlo_vdev(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (result & 1) != 0 )
  {
    if ( a1 )
    {
      if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
      {
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
        if ( cmpt_obj && (v32 = *(_QWORD *)(cmpt_obj + 512)) != 0 )
        {
          qdf_mutex_acquire(v32 + 120);
          qdf_list_peek_front((_QWORD *)(v32 + 96), v47);
          v33 = (_QWORD *)v47[0];
          if ( v47[0] )
          {
            while ( 1 )
            {
              qdf_list_peek_next((_QWORD *)(v32 + 96), v33, &v46);
              if ( *(_DWORD *)(v47[0] + 16LL) == a2 )
                break;
              v33 = v46;
              v46 = nullptr;
              v47[0] = v33;
              if ( !v33 )
                goto LABEL_18;
            }
            v43 = *(_QWORD *)(v47[0] + 1040LL);
            if ( v43 )
            {
              v44 = *(_QWORD *)(v43 + 24);
              if ( v44 )
              {
                if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v34, v35, v36, v37, v38, v39, v40, v41) & 1) != 0
                  && *(_DWORD *)(v44 + 1912) | *(unsigned __int16 *)(v44 + 1916) )
                {
                  v45 = *(_DWORD *)(v44 + 1912);
                  *(_WORD *)(a3 + 157) = *(_WORD *)(v44 + 1916);
                  *(_DWORD *)(a3 + 153) = v45;
                }
              }
            }
          }
LABEL_18:
          result = qdf_mutex_release(v32 + 120);
        }
        else
        {
          result = qdf_trace_msg(
                     0x68u,
                     2u,
                     "%s:%u: vdev %d cm_ctx is NULL",
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     "cm_connect_resp_fill_mld_addr_from_cm_id",
                     512,
                     *(unsigned __int8 *)(a1 + 168),
                     v46);
        }
      }
    }
    else
    {
      v42 = jiffies;
      if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x68u,
                   2u,
                   "%s:%u: vdev is NULL",
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   "cm_connect_resp_fill_mld_addr_from_cm_id",
                   512);
        cm_get_cm_ctx_fl___last_ticks = v42;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
