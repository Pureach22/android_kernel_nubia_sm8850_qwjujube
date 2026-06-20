__int64 __fastcall policy_mgr_get_ml_and_non_ml_mode_count(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4,
        __int64 a5,
        unsigned __int64 a6,
        unsigned __int64 a7,
        unsigned int a8)
{
  __int64 result; // x0
  unsigned int v15; // w25
  unsigned __int8 v16; // w27
  unsigned int *v17; // x8
  __int64 v18; // x9
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x26
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  *(_BYTE *)a2 = 0;
  *(_BYTE *)a4 = 0;
  result = policy_mgr_get_mode_specific_conn_info(a1, a6, a7, a8);
  if ( (_DWORD)result )
  {
    v15 = result;
    v16 = 0;
    while ( 1 )
    {
      v19 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *(unsigned __int8 *)(a7 + v16),
              24);
      if ( !v19 )
      {
        result = qdf_trace_msg(
                   0x4Fu,
                   2u,
                   "%s: invalid vdev for id %d",
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   "policy_mgr_get_ml_and_non_ml_mode_count",
                   *(unsigned __int8 *)(a7 + v16));
        *(_BYTE *)a2 = 0;
        *(_BYTE *)a4 = 0;
        return result;
      }
      v28 = v19;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v19, v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
        break;
      v17 = a4;
      v18 = a5;
      if ( a5 )
        goto LABEL_4;
LABEL_5:
      ++*(_BYTE *)v17;
      result = wlan_objmgr_vdev_release_ref(v28, 0x18u, v17, v29, v30, v31, v32, v33, v34, v35, v36);
      if ( v15 <= ++v16 )
        return result;
    }
    v17 = a2;
    v18 = a3;
    if ( !a3 )
      goto LABEL_5;
LABEL_4:
    *(_BYTE *)(v18 + *(unsigned __int8 *)v17) = v16;
    goto LABEL_5;
  }
  return result;
}
