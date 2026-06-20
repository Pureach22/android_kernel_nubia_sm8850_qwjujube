__int64 __fastcall wlan_twt_cfg_init(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x19
  char v12; // w22
  char v13; // w21
  int v14; // w9
  char v15; // w8
  __int64 values; // x0
  __int64 v17; // x4
  __int64 v18; // x5
  char v19; // w8
  __int64 v20; // x6
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v38; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
    if ( comp_private_obj )
    {
      v11 = comp_private_obj;
      v12 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10196);
      v13 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10204);
      *(_BYTE *)v11 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10184);
      *(_BYTE *)(v11 + 3) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10185);
      *(_BYTE *)(v11 + 1) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10188);
      *(_BYTE *)(v11 + 2) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10188) != 0;
      v14 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10192);
      *(_BYTE *)(v11 + 8) = v12 & 1;
      *(_DWORD *)(v11 + 4) = v14;
      *(_BYTE *)(v11 + 9) = (v12 & 2) != 0;
      *(_BYTE *)(v11 + 10) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10200);
      v15 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10201);
      *(_WORD *)(v11 + 12) = 1;
      *(_BYTE *)(v11 + 14) = v13 & 1;
      *(_BYTE *)(v11 + 11) = v15;
      *(_BYTE *)(v11 + 15) = (v13 & 2) != 0;
      values = cfg_psoc_get_values(a1);
      v17 = *(unsigned __int8 *)(v11 + 3);
      v18 = *(unsigned __int8 *)(v11 + 1);
      v19 = *(_BYTE *)(values + 10208);
      v20 = *(unsigned __int8 *)(v11 + 9);
      *(_BYTE *)(v11 + 16) = v19 & 1;
      *(_BYTE *)(v11 + 17) = (v19 & 2) != 0;
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: req: %d resp: %d bcast_resp:%d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_twt_cfg_init",
        v17,
        v18,
        v20);
      qdf_trace_msg(
        0x96u,
        8u,
        "r_twt_req: %d r_twt_resp: %d twt_req_ht_vht: %d twt_res_ht_vht: %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        *(unsigned __int8 *)(v11 + 14),
        *(unsigned __int8 *)(v11 + 15),
        *(unsigned __int8 *)(v11 + 16),
        *(unsigned __int8 *)(v11 + 17));
      return 0;
    }
    v38 = "%s: null twt psoc priv obj";
  }
  else
  {
    v38 = "%s: null psoc";
  }
  qdf_trace_msg(0x96u, 2u, v38, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_cfg_init");
  return 16;
}
