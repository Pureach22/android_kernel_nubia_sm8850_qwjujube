__int64 __fastcall pmo_core_enable_mc_addr_filtering_in_fwr(
        __int64 a1,
        unsigned int a2,
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
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  int v25; // w0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w21
  __int64 comp_private_obj; // x23
  __int64 v45; // x0
  __int64 v46; // x21
  const char *v47; // x2
  __int64 v48; // x4
  int v49; // w22

  result = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !(_DWORD)result )
  {
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
    if ( !v15 )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: vdev is NULL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "pmo_core_enable_mc_addr_filtering_in_fwr");
      v43 = 4;
LABEL_20:
      wlan_objmgr_psoc_release_ref(a1, 0xAu, v35, v36, v37, v38, v39, v40, v41, v42);
      return v43;
    }
    v24 = v15;
    v25 = pmo_core_mc_addr_flitering_sanity(v15);
    if ( v25 )
    {
LABEL_19:
      v43 = v25;
      wlan_objmgr_vdev_release_ref(v24, 0xAu, v26, v27, v28, v29, v30, v31, v32, v33, v34);
      goto LABEL_20;
    }
    if ( (unsigned int)wlan_vdev_is_up() )
    {
      v25 = 4;
      goto LABEL_19;
    }
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: enable mclist trigger: %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "pmo_core_enable_mc_addr_filtering_in_fwr",
      a3);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v24, 4u);
    v45 = _qdf_mem_malloc(0xC2u, "pmo_core_handle_enable_mc_list_trigger", 406);
    if ( !v45 )
    {
      v25 = 2;
      goto LABEL_19;
    }
    v46 = v45;
    if ( a3 )
    {
      if ( a3 != 6 )
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: invalid pmo trigger for enable mc list",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "pmo_core_handle_enable_mc_list_trigger");
        v49 = 4;
        goto LABEL_18;
      }
      if ( (*(_BYTE *)(*(_QWORD *)comp_private_obj + 13LL) & 1) == 0 )
      {
        v47 = "%s: active offload is disabled, skip in mode %d";
        v48 = 6;
LABEL_15:
        qdf_trace_msg(
          0x4Du,
          8u,
          v47,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "pmo_core_handle_enable_mc_list_trigger",
          v48);
        v49 = 0;
LABEL_18:
        _qdf_mem_free(v46);
        v25 = v49;
        goto LABEL_19;
      }
    }
    else if ( *(_BYTE *)(*(_QWORD *)comp_private_obj + 13LL) == 1 )
    {
      v47 = "%s: active offload is enabled, skip in mode %d";
      v48 = 0;
      goto LABEL_15;
    }
    v49 = pmo_core_do_enable_mc_addr_list(v24, comp_private_obj, v45);
    goto LABEL_18;
  }
  return result;
}
