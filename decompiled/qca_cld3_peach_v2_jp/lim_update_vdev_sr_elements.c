__int64 __fastcall lim_update_vdev_sr_elements(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 v10; // w22
  unsigned __int8 v11; // w19
  unsigned __int8 v12; // w20
  __int64 v14; // x24
  __int64 v15; // x25
  unsigned __int8 v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 cmpt_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0

  v10 = *(_BYTE *)(a2 + 812);
  v11 = *(_BYTE *)(a2 + 813);
  v12 = *(_BYTE *)(a2 + 814);
  v14 = *(_QWORD *)(a2 + 815);
  v15 = *(_QWORD *)(a2 + 823);
  v16 = *(_BYTE *)(a2 + 811) & 0x1F;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Spatial Reuse Control field: %x Non-SRG Max PD Offset: %x SRG range %d - %d srg_color_bit_map:%llu srg_partial_b"
    "ssid_bit_map: %llu",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_update_vdev_sr_elements",
    v16,
    v10,
    v11,
    v12,
    v14,
    v15);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 16), v17, v18, v19, v20, v21, v22, v23, v24);
  if ( cmpt_obj )
    *(_QWORD *)(cmpt_obj + 200) = v15;
  v34 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 16), v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v34 )
    *(_QWORD *)(v34 + 192) = v14;
  v43 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 16), v35, v36, v37, v38, v39, v40, v41, v42);
  if ( v43 )
    *(_BYTE *)(v43 + 182) = v16;
  v52 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 16), v44, v45, v46, v47, v48, v49, v50, v51);
  if ( v52 )
    *(_BYTE *)(v52 + 183) = v10;
  result = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 16), v53, v54, v55, v56, v57, v58, v59, v60);
  if ( result )
  {
    *(_BYTE *)(result + 184) = v12;
    *(_BYTE *)(result + 185) = v11;
  }
  return result;
}
