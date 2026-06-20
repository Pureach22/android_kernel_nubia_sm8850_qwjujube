__int64 __fastcall pmo_core_disable_mc_addr_filtering_in_fwr(
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
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  unsigned int *v22; // x8
  unsigned int v23; // w22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 comp_private_obj; // x22
  __int64 v33; // x0
  __int64 v34; // x20
  const char *v35; // x2
  __int64 v36; // x4

  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: psoc is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "pmo_core_disable_mc_addr_filtering_in_fwr");
    return 4;
  }
  v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pmo_core_disable_mc_addr_filtering_in_fwr");
    return 29;
  }
  v21 = v12;
  v23 = pmo_core_mc_addr_flitering_sanity(v12);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: disable mclist trigger: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "pmo_core_disable_mc_addr_filtering_in_fwr",
      a3);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v21, 4u);
    v33 = _qdf_mem_malloc(0xC2u, "pmo_core_handle_disable_mc_list_trigger", 497);
    if ( v33 )
    {
      v34 = v33;
      if ( a3 == 1 )
      {
        if ( *(_BYTE *)(*(_QWORD *)comp_private_obj + 13LL) == 1 )
        {
          v35 = "%s: active offload is enabled, skip in mode %d";
          v36 = 1;
          goto LABEL_15;
        }
      }
      else
      {
        if ( a3 != 8 && a3 != 6 )
        {
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: invalid pmo trigger for disable mc list",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "pmo_core_handle_disable_mc_list_trigger");
          v23 = 4;
          goto LABEL_18;
        }
        if ( (*(_BYTE *)(*(_QWORD *)comp_private_obj + 13LL) & 1) == 0 )
        {
          v35 = "%s: active offload is disabled, skip in mode %d";
          v36 = a3;
LABEL_15:
          qdf_trace_msg(
            0x4Du,
            8u,
            v35,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "pmo_core_handle_disable_mc_list_trigger",
            v36);
          v23 = 0;
LABEL_18:
          _qdf_mem_free(v34);
          goto LABEL_19;
        }
      }
      v23 = pmo_core_do_disable_mc_addr_list(v21, comp_private_obj, v33);
      goto LABEL_18;
    }
    v23 = 2;
  }
LABEL_19:
  wlan_objmgr_vdev_release_ref(v21, 0xAu, v22, v24, v25, v26, v27, v28, v29, v30, v31);
  return v23;
}
