__int64 __fastcall target_if_get_tsf_stats_for_csa(
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
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w20

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
    if ( comp_private_obj )
    {
      v22 = comp_private_obj;
      v23 = qdf_mc_timer_start(comp_private_obj + 40, 0x3E8u);
      if ( v23 )
      {
        v32 = v23;
        qdf_trace_msg(
          0xA1u,
          2u,
          "%s: Failed to start tsf timer",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "target_if_get_tsf_stats_for_csa");
        return v32;
      }
      else
      {
        *(_BYTE *)(v22 + 208) = a2;
        result = wmi_unified_get_tsf_stats_for_csa(v11, a2);
        if ( (_DWORD)result )
        {
          v42 = result;
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: Failed to get tsf stats for csa",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "target_if_get_tsf_stats_for_csa");
          if ( (unsigned int)qdf_mc_timer_get_current_state(v22 + 40) == 21 )
            qdf_mc_timer_stop(v22 + 40);
          return v42;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc_ll_sap_obj is null",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "target_if_get_tsf_stats_for_csa");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi_handle is null.",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_get_tsf_stats_for_csa");
    return 29;
  }
  return result;
}
