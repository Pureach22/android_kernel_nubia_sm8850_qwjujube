__int64 __fastcall csr_roaming_state_msg_processor(
        __int64 result,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  unsigned __int64 v11; // x8
  __int64 v12; // x19
  unsigned __int16 *v13; // x20
  unsigned __int64 v14; // x8
  __int64 v15; // x20
  unsigned __int16 *v16; // x21
  const char *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 v26; // x8
  __int64 v27; // x19
  unsigned __int16 *v28; // x20
  const char *v29; // x0
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

  v10 = *a2;
  if ( v10 > 0x140E )
  {
    switch ( v10 )
    {
      case 0x140Fu:
        return csr_roam_send_disconnect_done_indication();
      case 0x1426u:
        return csr_roam_joined_state_msg_processor();
      case 0x148Eu:
        v12 = result;
        v13 = a2;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Invoke SAE callback",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "csr_roaming_state_msg_processor");
        return csr_sae_callback(v12, v13);
    }
LABEL_13:
    v14 = *((unsigned __int8 *)a2 + 4);
    if ( v14 > 5 )
      goto LABEL_25;
    v15 = result;
    v16 = a2;
    v17 = mac_trace_getcsr_roam_sub_state(*(_DWORD *)(result + 4 * v14 + 17196));
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Unexpected message type: %d[0x%X] received in substate %s",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "csr_roaming_state_msg_processor",
      v10,
      v10,
      v17);
    result = csr_is_conn_state_disconnected(v15, *((unsigned __int8 *)v16 + 4));
    if ( (result & 1) != 0 )
      return result;
    result = v15;
    a2 = v16;
    return csr_roam_check_for_link_status_change(result, a2);
  }
  if ( v10 == 5125 )
    return csr_roam_check_for_link_status_change(result, a2);
  if ( v10 != 5129 )
  {
    if ( v10 == 5133 )
    {
      v11 = *((unsigned __int8 *)a2 + 4);
      if ( v11 <= 5 )
      {
        if ( *(_DWORD *)(result + 4 * v11 + 17196) == 4 )
          return csr_roam_complete(result, a3, a4, a5, a6, a7, a8, a9, a10);
        return result;
      }
LABEL_25:
      __break(0x5512u);
      return csr_sae_callback(result, a2);
    }
    goto LABEL_13;
  }
  v26 = *((unsigned __int8 *)a2 + 4);
  if ( v26 >= 6 )
    goto LABEL_25;
  if ( *(_DWORD *)(result + 4 * v26 + 17196) == 2 )
  {
    v27 = result;
    v28 = a2;
    v29 = mac_trace_getcsr_roam_sub_state(2u);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: eWNI_SME_DISASSOC_RSP subState = %s",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "csr_roaming_state_msg_processor",
      v29);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Received disassoc response for vdev : %d status : %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "csr_roam_roaming_state_disassoc_rsp_processor",
      *((unsigned __int8 *)v28 + 4),
      *((unsigned int *)v28 + 2));
    if ( *((unsigned __int8 *)v28 + 4) <= 5uLL )
    {
      result = v27;
      if ( *(_QWORD *)(v27 + 17224) + 96LL * *((unsigned __int8 *)v28 + 4) )
        return csr_roam_complete(result, a3, a4, a5, a6, a7, a8, a9, a10);
    }
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: session not found",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_roam_roaming_state_disassoc_rsp_processor");
  }
  return result;
}
