__int64 __fastcall sme_display_disconnect_stats(
        __int64 a1,
        unsigned __int8 a2,
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
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v53; // x2

  if ( a1 && a2 <= 5u && (v10 = *(_QWORD *)(a1 + 17296)) != 0 && (v11 = v10 + 96LL * a2, (*(_BYTE *)(v11 + 1) & 1) != 0) )
  {
    if ( v11 )
    {
      qdf_trace_msg(
        0x34u,
        4u,
        "Total No. of Disconnections: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        *(unsigned int *)(v11 + 64));
      qdf_trace_msg(
        0x34u,
        4u,
        "No. of Disconnects Triggered by Application: %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        *(unsigned int *)(v11 + 68));
      qdf_trace_msg(
        0x34u,
        4u,
        "No. of Disassoc Sent by Peer: %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        *(unsigned int *)(v11 + 72));
      qdf_trace_msg(
        0x34u,
        4u,
        "No. of Deauth Sent by Peer: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        *(unsigned int *)(v11 + 76));
      qdf_trace_msg(
        0x34u,
        4u,
        "No. of Disconnections due to Beacon Miss: %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        *(unsigned int *)(v11 + 80));
      return qdf_trace_msg(
               0x34u,
               4u,
               "No. of Disconnections due to Peer Kickout: %d",
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               *(unsigned int *)(v11 + 84));
    }
    v53 = "%s: %s Failed to get session for id: %d";
  }
  else
  {
    v53 = "%s: %s Invalid session id: %d";
  }
  return qdf_trace_msg(
           0x34u,
           2u,
           v53,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "sme_display_disconnect_stats",
           "sme_display_disconnect_stats",
           a2);
}
