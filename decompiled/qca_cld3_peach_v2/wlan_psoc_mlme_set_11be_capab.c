__int64 __fastcall wlan_psoc_mlme_set_11be_capab(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 result; // x0
  __int16 v14; // w10
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    result = 0;
    v14 = *(_WORD *)(v12 + 2070) & 8;
    if ( (a2 & 1) == 0 )
      v14 = 0;
    *(_WORD *)(v12 + 2070) = v14 | *(_WORD *)(v12 + 2070) & 0xFFF7;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_psoc_mlme_get_cmpt_obj");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: psoc_mlme is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_psoc_mlme_set_11be_capab");
    return 16;
  }
  return result;
}
