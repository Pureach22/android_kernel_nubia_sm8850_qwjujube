__int64 __fastcall hdd_ndi_open(
        const char *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
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
  unsigned __int8 *intf_addr; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // [xsp+Ch] [xbp-14h] BYREF
  int v73; // [xsp+10h] [xbp-10h] BYREF
  __int16 v74; // [xsp+14h] [xbp-Ch]
  __int64 v75; // [xsp+18h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v73 = 0;
  context = _cds_get_context(51, (__int64)"hdd_ndi_open", a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_ndi_open");
  if ( (hdd_is_max_ndi_count_reached(context) & 1) != 0 )
    goto LABEL_2;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: is_add_virtual_iface %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_ndi_open",
    a2 & 1);
  if ( (cfg_nan_get_ndi_mac_randomize(*context, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
  {
    intf_addr = (unsigned __int8 *)&v73;
    if ( (unsigned int)hdd_get_random_nan_mac_addr(context, &v73) )
    {
      v55 = "%s: get random mac address failed";
LABEL_10:
      qdf_trace_msg(0x33u, 2u, v55, v47, v48, v49, v50, v51, v52, v53, v54, "hdd_ndi_open");
      result = 4294967282LL;
      goto LABEL_11;
    }
  }
  else
  {
    intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)context, 11, v38, v39, v40, v41, v42, v43, v44, v45);
    if ( !intf_addr )
    {
      v55 = "%s: get intf address failed";
      goto LABEL_10;
    }
  }
  v72 = 8;
  if ( hdd_open_adapter(context, 0xBu, a1, intf_addr, 0, 1, &v72, v47, v48, v49, v50, v51, v52, v53, v54) )
  {
    qdf_trace_msg(0x33u, 8u, "%s: exit", v56, v57, v58, v59, v60, v61, v62, v63, "hdd_ndi_open");
    result = 0;
    goto LABEL_11;
  }
  if ( (cfg_nan_get_ndi_mac_randomize(*context, v56, v57, v58, v59, v60, v61, v62, v63) & 1) == 0 )
    wlan_hdd_release_intf_addr((__int64)context, intf_addr, v64, v65, v66, v67, v68, v69, v70, v71);
  qdf_trace_msg(0x33u, 2u, "%s: hdd_open_adapter failed", v64, v65, v66, v67, v68, v69, v70, v71, "hdd_ndi_open");
LABEL_2:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
