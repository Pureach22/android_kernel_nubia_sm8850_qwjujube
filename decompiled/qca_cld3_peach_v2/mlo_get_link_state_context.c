__int64 __fastcall mlo_get_link_state_context(__int64 a1, _QWORD *a2, _QWORD *a3, unsigned int a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 v26; // x23
  unsigned int v27; // w20

  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a4, 90);
  if ( v6 )
  {
    v15 = v6;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v6, v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
    {
      v25 = *(_QWORD *)(v15 + 1360);
      if ( v25 )
      {
        v26 = *(_QWORD *)(v25 + 2224);
        if ( v26 )
        {
          qdf_mutex_acquire(v25 + 1656);
          *a2 = *(_QWORD *)(v26 + 304);
          *a3 = *(_QWORD *)(v26 + 312);
          qdf_mutex_release(v25 + 1656);
          v27 = 0;
        }
        else
        {
          v27 = 4;
        }
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: null mlo_dev_ctx",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "mlo_get_link_state_context");
        v27 = 29;
      }
    }
    else
    {
      v27 = 29;
    }
    wlan_objmgr_vdev_release_ref(v15, 0x5Au, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  else
  {
    return 29;
  }
  return v27;
}
