__int64 __fastcall ll_lt_sap_init(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  __int64 v20; // x0
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19

  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "ll_sap_get_vdev_priv_obj");
    goto LABEL_7;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_7:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ll_lt_sap_init",
      *(unsigned __int8 *)(a1 + 168));
    return 4;
  }
  v19 = (__int64 *)comp_private_obj;
  *(_DWORD *)(comp_private_obj + 8) = -1;
  v20 = _qdf_mem_malloc(0x340u, "ll_lt_sap_init", 174);
  if ( !v20 )
    return 2;
  *v19 = v20;
  *(_DWORD *)(v20 + 8) = 0;
  *(_DWORD *)(v20 + 96) = 0;
  *(_DWORD *)(v20 + 100) = 0;
  *(_DWORD *)(v20 + 104) = 0;
  *(_DWORD *)(v20 + 108) = 0;
  *(_DWORD *)(v20 + 112) = 0;
  *(_DWORD *)(v20 + 116) = 0;
  *(_DWORD *)(v20 + 120) = 0;
  *(_DWORD *)(v20 + 124) = 0;
  *(_DWORD *)(v20 + 128) = 0;
  *(_DWORD *)(v20 + 132) = 0;
  *(_DWORD *)(v20 + 136) = 0;
  *(_DWORD *)(v20 + 140) = 0;
  *(_DWORD *)(v20 + 144) = 0;
  *(_DWORD *)(v20 + 148) = 0;
  *(_DWORD *)(v20 + 152) = 0;
  *(_DWORD *)(v20 + 156) = 0;
  *(_DWORD *)(v20 + 160) = 0;
  *(_DWORD *)(v20 + 164) = 0;
  *(_DWORD *)(v20 + 168) = 0;
  *(_DWORD *)(v20 + 172) = 0;
  *(_DWORD *)(v20 + 176) = 0;
  *(_DWORD *)(v20 + 180) = 0;
  *(_DWORD *)(v20 + 184) = 0;
  *(_DWORD *)(v20 + 188) = 0;
  *(_DWORD *)(v20 + 192) = 0;
  *(_DWORD *)(v20 + 196) = 0;
  *(_DWORD *)(v20 + 200) = 0;
  *(_DWORD *)(v20 + 204) = 0;
  *(_DWORD *)(v20 + 208) = 0;
  *(_DWORD *)(v20 + 212) = 0;
  *(_DWORD *)(v20 + 216) = 0;
  *(_DWORD *)(v20 + 220) = 0;
  *(_DWORD *)(v20 + 224) = 0;
  *(_DWORD *)(v20 + 228) = 0;
  *(_DWORD *)(v20 + 232) = 0;
  *(_DWORD *)(v20 + 236) = 0;
  *(_DWORD *)(v20 + 240) = 0;
  *(_DWORD *)(v20 + 244) = 0;
  *(_QWORD *)v20 = a1;
  v21 = bs_sm_create(v20);
  if ( v21 )
  {
    v30 = v21;
    _qdf_mem_free(*v19);
    *v19 = 0;
    return v30;
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "ll_lt_sap_init",
      *(unsigned __int8 *)(a1 + 168));
    return 0;
  }
}
