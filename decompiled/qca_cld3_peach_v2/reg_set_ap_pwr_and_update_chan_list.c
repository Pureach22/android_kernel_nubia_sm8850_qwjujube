__int64 __fastcall reg_set_ap_pwr_and_update_chan_list(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 psoc_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned int v32; // w1
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_set_ap_pwr_and_update_chan_list");
    return 4;
  }
  v21 = pdev_obj;
  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Regulatory psoc private object is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "reg_get_reg_rules_for_pdev");
LABEL_9:
    v31 = "%s: No psoc_reg_rules";
    v32 = 8;
    goto LABEL_10;
  }
  if ( *(unsigned __int8 *)(a1 + 40) >= 3uLL )
  {
    __break(0x5512u);
    return reg_set_both_psd_eirp_preferred_support();
  }
  if ( psoc_obj + 30364LL * *(unsigned __int8 *)(a1 + 40) == -29624 )
    goto LABEL_9;
  if ( a2 < 4 )
  {
    if ( *(_BYTE *)(psoc_obj + 30364LL * *(unsigned __int8 *)(a1 + 40) + 29624 + a2 + 150) )
    {
      v34 = reg_get_pdev_obj(a1, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( v34 )
      {
        *(_DWORD *)(v34 + 58204) = a2;
        reg_compute_pdev_current_chan_list(v21, v35, v36, v37, v38, v39, v40, v41, v42);
        return 0;
      }
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg component is NULL",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "reg_set_cur_6g_ap_pwr_type");
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: failed to set AP power type to %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "reg_set_ap_pwr_and_update_chan_list",
        a2);
    }
    return 16;
  }
  v31 = "%s: Unsupported 6G AP power type";
  v32 = 2;
LABEL_10:
  qdf_trace_msg(0x51u, v32, v31, v23, v24, v25, v26, v27, v28, v29, v30, "reg_get_num_rules_of_ap_pwr_type");
  return 16;
}
