__int64 __fastcall policy_mgr_2_freq_same_mac_in_sbs(__int64 a1, unsigned int a2, unsigned int a3)
{
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
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v21; // w8
  unsigned int v22; // w8

  context = policy_mgr_get_context(a1);
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
      "policy_mgr_2_freq_same_mac_in_sbs");
    return 0;
  }
  v15 = (_DWORD *)context;
  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
  {
    if ( v15[300] )
    {
      v16 = v15[333];
      if ( (v16 <= a2 && v15[334] >= a2 || v15[335] <= a2 && v15[336] >= a2)
        && (v16 <= a3 && v15[334] >= a3 || v15[335] <= a3 && v15[336] >= a3) )
      {
        return 1;
      }
      if ( (v17 = v15[337], v17 <= a2) && v15[338] >= a2 || v15[339] <= a2 && v15[340] >= a2 )
      {
        if ( v17 <= a3 && v15[338] >= a3 || v15[339] <= a3 && v15[340] >= a3 )
          return 1;
      }
      if ( (v18 = v15[325], v18 <= a2) && v15[326] >= a2 || v15[327] <= a2 && v15[328] >= a2 )
      {
        if ( v18 <= a3 && v15[326] >= a3 || v15[327] <= a3 && v15[328] >= a3 )
          return 1;
      }
      if ( (v19 = v15[329], v19 <= a2) && v15[330] >= a2 || v15[331] <= a2 && v15[332] >= a2 )
      {
        if ( v19 <= a3 && v15[330] >= a3 || v15[331] <= a3 && v15[332] >= a3 )
          return 1;
      }
    }
    else
    {
      v21 = v15[317];
      if ( (v21 <= a2 && v15[318] >= a2 || v15[319] <= a2 && v15[320] >= a2)
        && (v21 <= a3 && v15[318] >= a3 || v15[319] <= a3 && v15[320] >= a3) )
      {
        return 1;
      }
      if ( (v22 = v15[321], v22 <= a2) && v15[322] >= a2 || v15[323] <= a2 && v15[324] >= a2 )
      {
        if ( v22 <= a3 && v15[322] >= a3 || v15[323] <= a3 && v15[324] >= a3 )
          return 1;
      }
    }
    return 0;
  }
  return 1;
}
