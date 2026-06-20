__int64 __fastcall pmo_set_sap_wow_bitmask(
        __int64 result,
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
  unsigned int v10; // w8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
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
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7

  if ( result && a2 > 3 )
  {
    v10 = 8 * a2;
    *(_DWORD *)(result + 4LL * (0x17 / (8 * a2))) |= 1 << (0x17 % (8 * a2));
    *(_DWORD *)(result + 4LL * (0xB / (8 * a2))) |= 1 << (0xB % (8 * a2));
    *(_DWORD *)(result + 4LL * (9 / (8 * a2))) |= 1 << (9 % (8 * a2));
    *(_DWORD *)(result + 4LL * (0xC / v10)) |= 1 << (0xC % v10);
    *(_DWORD *)(result + 4LL * (0xD / v10)) |= 1 << (0xD % v10);
    *(_DWORD *)(result + 4LL * (2 / v10)) |= 4u;
    *(_DWORD *)(result + 4LL * (8 / v10)) |= 1 << (8 % v10);
    *(_DWORD *)(result + 4LL * (0xE / v10)) |= 1 << (0xE % v10);
    *(_DWORD *)(result + 4LL * (0x23 / v10)) |= 1 << (0x23 % v10);
    *(_DWORD *)(result + 4LL * (0x24 / v10)) |= 1 << (0x24 % v10);
    *(_DWORD *)(result + 4LL * (0x2B / v10)) |= 1 << (0x2B % v10);
    *(_DWORD *)(result + 4LL * (0x2D / v10)) |= 1 << (0x2D % v10);
    *(_DWORD *)(result + 4LL * (0x2F / v10)) |= 1 << (0x2F % v10);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "pmo_set_wow_event_bitmap",
      4);
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      "pmo_set_wow_event_bitmap",
      4);
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: wow bitmask length shorter than %d",
             v99,
             v100,
             v101,
             v102,
             v103,
             v104,
             v105,
             v106,
             "pmo_set_wow_event_bitmap",
             4);
  }
  return result;
}
