__int64 __fastcall wlan_psoc_mlme_get_11be_capab(__int64 a1, bool *a2)
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    *a2 = (*(_BYTE *)(v12 + 2070) & 8) != 0;
    return 0;
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
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_psoc_mlme_get_11be_capab");
    return 16;
  }
}
