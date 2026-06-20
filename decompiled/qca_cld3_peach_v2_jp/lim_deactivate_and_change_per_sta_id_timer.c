__int64 __fastcall lim_deactivate_and_change_per_sta_id_timer(
        __int64 result,
        int a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x19
  const char *v13; // x2
  __int64 pre_auth_node_from_index; // x0
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v12 = result;
  if ( a2 == 9 )
  {
    pre_auth_node_from_index = lim_get_pre_auth_node_from_index(
                                 a4,
                                 a5,
                                 a6,
                                 a7,
                                 a8,
                                 a9,
                                 a10,
                                 a11,
                                 result,
                                 result + 11408,
                                 a3);
    if ( !pre_auth_node_from_index )
    {
      v13 = "%s: Invalid Pre Auth Index passed :%d";
      return qdf_trace_msg(
               0x35u,
               2u,
               v13,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_deactivate_and_change_per_sta_id_timer",
               a3);
    }
    v15 = pre_auth_node_from_index;
    if ( (unsigned int)tx_timer_deactivate(pre_auth_node_from_index + 280) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: unable to deactivate auth response timer",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_deactivate_and_change_per_sta_id_timer");
    result = tx_timer_change(v15 + 280, *(unsigned int *)(*(_QWORD *)(v12 + 8) + 3484LL) / 0xAuLL, 0);
    if ( (_DWORD)result )
    {
      v32 = "%s: unable to change auth rsp timer";
      return qdf_trace_msg(
               0x35u,
               2u,
               v32,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               "lim_deactivate_and_change_per_sta_id_timer");
    }
  }
  else
  {
    if ( a2 != 8 )
      return result;
    if ( *(unsigned __int16 *)(result + 3990) < (unsigned int)a3 )
    {
      v13 = "%s: Invalid staId = %d ";
      return qdf_trace_msg(
               0x35u,
               2u,
               v13,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_deactivate_and_change_per_sta_id_timer",
               a3);
    }
    v33 = a3;
    if ( (unsigned int)tx_timer_deactivate(*(_QWORD *)(result + 1336) + 264LL * a3) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: unable to deactivate CNF wait timer",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_deactivate_and_change_per_sta_id_timer");
    result = tx_timer_change(
               *(_QWORD *)(v12 + 1336) + 264LL * v33,
               *(unsigned int *)(*(_QWORD *)(v12 + 8) + 3316LL) / 0xAuLL,
               *(unsigned int *)(*(_QWORD *)(v12 + 8) + 3316LL) / 0xAuLL);
    if ( (_DWORD)result )
    {
      v32 = "%s: unable to change cnf wait timer";
      return qdf_trace_msg(
               0x35u,
               2u,
               v32,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               "lim_deactivate_and_change_per_sta_id_timer");
    }
  }
  return result;
}
