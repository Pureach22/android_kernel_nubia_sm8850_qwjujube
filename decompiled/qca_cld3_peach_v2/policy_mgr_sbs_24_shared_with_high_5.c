bool __fastcall policy_mgr_sbs_24_shared_with_high_5(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v4; // x19
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  unsigned int v25; // w8
  bool v26; // cf
  __int64 v27; // [xsp+0h] [xbp-30h]
  __int64 v28; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a1 + 1200) )
    return 1;
  v27 = v1;
  v28 = v2;
  v4 = *(_QWORD *)a1;
  context = policy_mgr_get_context(*(_QWORD *)a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_get_sbs_cut_off_freq",
      v1,
      v28);
LABEL_13:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid cut off freq",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_sbs_24_shared_with_high_5",
      v27,
      v28);
    return 0;
  }
  v15 = (_DWORD *)context;
  if ( (policy_mgr_is_hw_sbs_capable(v4) & 1) == 0 )
    goto LABEL_13;
  v24 = v15[300];
  if ( !v24 )
  {
    v25 = v15[323];
    if ( v25 <= v15[319] )
      v25 = v15[319];
    v24 = v25 - 1;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sbs cutoff freq %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_get_sbs_cut_off_freq",
      v25 - 1,
      v1,
      v28);
    if ( !v24 )
      goto LABEL_13;
  }
  if ( *(_DWORD *)(a1 + 1268) && v24 < *(_DWORD *)(a1 + 1276) )
    return 1;
  if ( *(_DWORD *)(a1 + 1284) )
    v26 = v24 >= *(_DWORD *)(a1 + 1292);
  else
    v26 = 1;
  return !v26;
}
