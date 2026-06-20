__int64 __fastcall mlo_link_set_resp_link_recfg_handler(
        __int64 result,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 v12; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x19
  __int64 v24; // x20
  void (__fastcall *v25)(__int64, __int64, unsigned int *); // x8
  __int64 v26; // x1
  __int64 v27; // x1
  double v28; // d0
  unsigned int *v29; // x8
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( (a3[1] & 1) == 0 )
  {
    v11 = *(_QWORD *)(a2 + 1360);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 3888);
      if ( v12 )
      {
        result = wlan_serialization_get_active_cmd(
                   result,
                   *(unsigned __int8 *)(a2 + 168),
                   0x21u,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11);
        if ( result )
        {
          qdf_mutex_acquire(v11 + 1656);
          v23 = *(__int64 **)(v12 + 3200);
          if ( v23 )
          {
            *(_QWORD *)(v12 + 3200) = 0;
            v24 = *v23;
            qdf_mutex_release(v11 + 1656);
            v25 = (void (__fastcall *)(__int64, __int64, unsigned int *))v23[1];
            v26 = v23[3];
            if ( *((_DWORD *)v25 - 1) != 662908326 )
              __break(0x8228u);
            v25(v24, v26, a3);
            v27 = *a3;
            *((_BYTE *)a3 + 4) = 1;
            v28 = mlo_link_recfg_set_link_resp(v24, v27);
            wlan_objmgr_vdev_release_ref(v24, 0x5Au, v29, v28, v30, v31, v32, v33, v34, v35, v36);
            return _qdf_mem_free((__int64)v23);
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: no pending set link for link recfg, vdev %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "mlo_link_set_resp_link_recfg_handler",
              *(unsigned __int8 *)(a2 + 168));
            return qdf_mutex_release(v11 + 1656);
          }
        }
      }
    }
  }
  return result;
}
