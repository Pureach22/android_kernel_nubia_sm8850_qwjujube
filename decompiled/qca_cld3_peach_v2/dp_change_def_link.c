__int64 __fastcall dp_change_def_link(__int64 *a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 v6; // x23
  __int64 next_deflink_candidate; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
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
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 (*v34)(void); // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v6 = *a1;
  next_deflink_candidate = dp_intf_get_next_deflink_candidate();
  if ( (is_dp_link_valid(next_deflink_candidate, v8, v9, v10, v11, v12, v13, v14, v15) & 1) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Unable to get next def link %pK",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_change_def_link",
      next_deflink_candidate);
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Peer %02x:%02x:%02x:**:**:%02x, change vdev %d -> %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "dp_change_def_link",
    a3[3],
    a3[4],
    a3[5],
    a3[8],
    *(unsigned __int8 *)(a2 + 24),
    *(unsigned __int8 *)(next_deflink_candidate + 24));
  v32 = *(_QWORD *)(v6 + 240);
  if ( !v32 || !*(_QWORD *)v32 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v24, v25, v26, v27, v28, v29, v30, v31, "cdp_txrx_set_peer_param");
    goto LABEL_12;
  }
  v33 = *(_QWORD *)(*(_QWORD *)v32 + 8LL);
  if ( !v33 )
    goto LABEL_12;
  v34 = *(__int64 (**)(void))(v33 + 112);
  if ( !v34 )
    goto LABEL_12;
  if ( *((_DWORD *)v34 - 1) != 201075190 )
    __break(0x8228u);
  result = v34();
  if ( !(_DWORD)result )
    a1[458] = next_deflink_candidate;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
