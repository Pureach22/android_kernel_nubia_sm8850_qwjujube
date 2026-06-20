__int64 __fastcall wlan_cm_update_fils_ft(__int64 a1, __int64 a2, const void *a3, unsigned __int8 a4)
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
  __int64 ext_hdl; // x0
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v6 )
  {
    v15 = v6;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v6, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( ext_hdl )
    {
      if ( a4 )
      {
        if ( a3 )
        {
          v17 = *(_QWORD *)(ext_hdl + 24080);
          if ( v17 )
          {
            if ( (*(_BYTE *)v17 & 1) != 0 )
            {
              *(_BYTE *)(v17 + 791) = a4;
              qdf_mem_copy((void *)(*(_QWORD *)(ext_hdl + 24080) + 743LL), a3, a4);
              wlan_objmgr_vdev_release_ref(v15, 2u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
              return 0;
            }
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev legacy private object is NULL",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlan_cm_update_fils_ft");
    }
    wlan_objmgr_vdev_release_ref(v15, 2u, (unsigned int *)v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "wlan_cm_update_fils_ft");
  }
  return 16;
}
