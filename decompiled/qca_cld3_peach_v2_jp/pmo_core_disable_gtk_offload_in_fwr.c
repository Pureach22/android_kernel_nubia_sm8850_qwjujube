__int64 __fastcall pmo_core_disable_gtk_offload_in_fwr(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int ref; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 comp_private_obj; // x21
  __int64 v28; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x20
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_disable_gtk_offload_in_fwr");
  if ( a1 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !ref )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      v28 = _qdf_mem_malloc(0x80u, "pmo_core_disable_gtk_offload_in_fwr", 313);
      if ( v28 )
      {
        v38 = (_DWORD *)v28;
        if ( *(_DWORD *)(a1 + 16) == 11 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: gtk offload is not supported in NaN mode",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "pmo_core_do_disable_gtk_offload");
          ref = 4;
        }
        else
        {
          ref = pmo_core_is_gtk_enabled_in_fwr(a1, comp_private_obj);
          if ( !ref )
          {
            *v38 = 1;
            ref = pmo_tgt_send_gtk_offload_req(a1, v38);
          }
        }
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v39, v40, v41, v42, v43, v44, v45, v46, v47);
        _qdf_mem_free((__int64)v38);
      }
      else
      {
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
        ref = 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "pmo_core_disable_gtk_offload_in_fwr");
    ref = 4;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_core_disable_gtk_offload_in_fwr");
  return ref;
}
