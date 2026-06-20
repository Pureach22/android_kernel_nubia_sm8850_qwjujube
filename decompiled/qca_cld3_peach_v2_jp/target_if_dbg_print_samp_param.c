__int64 __fastcall target_if_dbg_print_samp_param(
        char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  qdf_trace_msg(
    0x56u,
    8u,
    "%s: \nSAMP Packet : -------------------- START --------------------",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_dbg_print_samp_param");
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: Freq        = %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "target_if_dbg_print_samp_param",
    *((unsigned __int16 *)a1 + 44));
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: RSSI        = %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "target_if_dbg_print_samp_param",
    (unsigned int)*a1);
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: Bin Count   = %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "target_if_dbg_print_samp_param",
    *((unsigned int *)a1 + 10));
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: Timestamp   = %d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "target_if_dbg_print_samp_param",
    *((unsigned int *)a1 + 4));
  return qdf_trace_msg(
           0x56u,
           8u,
           "%s: SAMP Packet : -------------------- END -----------------------",
           v42,
           v43,
           v44,
           v45,
           v46,
           v47,
           v48,
           v49,
           "target_if_dbg_print_samp_param");
}
