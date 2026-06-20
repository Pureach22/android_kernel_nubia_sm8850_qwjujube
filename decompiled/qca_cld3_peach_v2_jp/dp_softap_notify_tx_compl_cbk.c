__int64 __fastcall dp_softap_notify_tx_compl_cbk(
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  result = is_dp_link_valid(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    v21 = (*(unsigned __int8 *)(a1 + 71) >> 3) & 0xF;
    if ( v21 == 1 )
    {
      return dp_softap_inspect_tx_eap_pkt(a2, a1, 1);
    }
    else if ( v21 == 4 )
    {
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: sending DHCP indication",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "dp_softap_notify_tx_compl_cbk");
      result = is_dp_link_valid(a2, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( (result & 1) != 0 )
        return dp_post_dhcp_ind(
                 a2,
                 (unsigned __int8 *)(*(_QWORD *)(a1 + 224) + 70LL),
                 0,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37);
    }
  }
  return result;
}
