__int64 __fastcall hal_dump_reg_write_srng_stats(_DWORD *a1)
{
  _DWORD *v2; // x22
  int v3; // w3
  int v4; // w4
  int v5; // w5
  int v6; // w6
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  _QWORD v48[12]; // [xsp+0h] [xbp-70h] BYREF
  int v49; // [xsp+60h] [xbp-10h]
  __int64 v50; // [xsp+68h] [xbp-8h]

  v2 = a1 + 9216;
  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[1942];
  v4 = a1[1943];
  v5 = a1[1944];
  v6 = a1[1945];
  v49 = 0;
  memset(v48, 0, sizeof(v48));
  v7 = scnprintf(v48, 100, "enq %u deq %u coal %u direct %u", v3, v4, v5, v6);
  qdf_trace_msg(0x46u, 8u, "%s: SW2TCL1: %s", v7, v8, v9, v10, v11, v12, v13, v14, "hal_dump_reg_write_srng_stats", v48);
  v15 = scnprintf(v48, 100, "enq %u deq %u coal %u direct %u", v2[838], v2[839], v2[840], v2[841]);
  qdf_trace_msg(
    0x46u,
    8u,
    "%s: WBM2SW0: %s",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hal_dump_reg_write_srng_stats",
    v48);
  v23 = scnprintf(v48, 100, "enq %u deq %u coal %u direct %u", a1[148], a1[149], a1[150], a1[151]);
  qdf_trace_msg(
    0x46u,
    8u,
    "%s: REO2SW1: %s",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "hal_dump_reg_write_srng_stats",
    v48);
  v31 = scnprintf(v48, 100, "enq %u deq %u coal %u direct %u", a1[226], a1[227], a1[228], a1[229]);
  qdf_trace_msg(
    0x46u,
    8u,
    "%s: REO2SW2: %s",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "hal_dump_reg_write_srng_stats",
    v48);
  v39 = scnprintf(v48, 100, "enq %u deq %u coal %u direct %u", a1[304], a1[305], a1[306], a1[307]);
  result = qdf_trace_msg(
             0x46u,
             8u,
             "%s: REO2SW3: %s",
             v39,
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             "hal_dump_reg_write_srng_stats",
             v48);
  _ReadStatusReg(SP_EL0);
  return result;
}
