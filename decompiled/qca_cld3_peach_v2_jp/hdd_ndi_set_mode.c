__int64 __fastcall hdd_ndi_set_mode(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 adapter_by_iface_name; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // [xsp+0h] [xbp-10h] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_ndi_set_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  WORD2(v54) = 0;
  LODWORD(v54) = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_ndi_set_mode", v54, v55);
  if ( (hdd_is_max_ndi_count_reached(context) & 1) == 0 )
  {
    adapter_by_iface_name = hdd_get_adapter_by_iface_name((__int64)context, a1);
    if ( !adapter_by_iface_name )
    {
      qdf_trace_msg(0x33u, 2u, "%s: adapter is null", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_ndi_set_mode");
      result = 4294967274LL;
      goto LABEL_10;
    }
    v29 = adapter_by_iface_name;
    if ( (cfg_nan_get_ndi_mac_randomize(*context, v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
    {
      if ( (unsigned int)hdd_get_random_nan_mac_addr(context, &v54) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: get random mac address failed",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_ndi_set_mode");
        result = 4294967282LL;
        goto LABEL_10;
      }
      ucfg_dp_update_intf_mac(
        *context,
        (unsigned __int8 *)(v29 + 1617),
        (unsigned __int8 *)&v54,
        *(_QWORD *)(*(_QWORD *)(v29 + 52824) + 32LL));
      hdd_update_dynamic_mac((__int64)context, (const void *)(v29 + 1617), &v54, v46, v47, v48, v49, v50, v51, v52, v53);
      qdf_mem_copy((void *)(v29 + 1617), &v54, 6u);
      dev_addr_mod(*(_QWORD *)(v29 + 32), 0, &v54, 6);
    }
    *(_DWORD *)(v29 + 40) = 11;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Created NDI with device mode:%d and iface_name:%s",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "hdd_ndi_set_mode",
      11,
      a1);
    result = 0;
    goto LABEL_10;
  }
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
