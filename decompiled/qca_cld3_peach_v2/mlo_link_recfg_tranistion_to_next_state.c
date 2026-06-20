__int64 __fastcall mlo_link_recfg_tranistion_to_next_state(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  __int64 v11; // x4
  unsigned __int8 v12; // w8
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v9 = *(unsigned __int8 *)(a1 + 3024);
  v11 = (unsigned int)(char)v9;
  if ( v9 >= 7 && v9 != 255 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unexpected curr_state_idx %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_tranistion_to_next_state",
      v11);
    return 16;
  }
  if ( (v9 & 0x80) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: prev idx %d st %d evt %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_tranistion_to_next_state",
      v11,
      *(unsigned int *)(a1 + 312LL * *(unsigned __int8 *)(a1 + 3024) + 840),
      *(unsigned int *)(a1 + 312LL * *(unsigned __int8 *)(a1 + 3024) + 844));
    v12 = *(_BYTE *)(a1 + 3024) + 1;
    *(_BYTE *)(a1 + 3024) = v12;
    if ( v12 <= 7u )
      goto LABEL_6;
    __break(0x5512u);
  }
  v12 = 0;
  *(_BYTE *)(a1 + 3024) = v11 + 1;
LABEL_6:
  v13 = a1 + 312LL * v12;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: next idx %d st %d evt %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlo_link_recfg_tranistion_to_next_state",
    v12,
    *(unsigned int *)(v13 + 840),
    *(unsigned int *)(v13 + 844));
  wlan_sm_transition_to(*(_QWORD *)(a1 + 824), *(_DWORD *)(v13 + 840), v14, v15, v16, v17, v18, v19, v20, v21);
  v30 = wlan_sm_dispatch(
          *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 3888LL) + 824LL),
          *(_DWORD *)(v13 + 844),
          0x108u,
          v13 + 848,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v30 )
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: state %d event %d status %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "mlo_link_recfg_tranistion_to_next_state",
      *(unsigned int *)(v13 + 840),
      *(unsigned int *)(v13 + 844),
      v30);
  return v30;
}
