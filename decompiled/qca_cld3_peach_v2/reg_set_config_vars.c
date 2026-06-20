__int64 __fastcall reg_set_config_vars(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w10
  unsigned int ref; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_obj )
  {
    v21 = *(_DWORD *)(psoc_obj + 91144);
    *(_BYTE *)(psoc_obj + 91150) = *(_DWORD *)a2 != 0;
    *(_DWORD *)(psoc_obj + 91156) = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(psoc_obj + 91164) = *(_DWORD *)(a2 + 8) != 0;
    *(_BYTE *)(psoc_obj + 91140) = *(_DWORD *)(a2 + 16) != 0;
    *(_BYTE *)(psoc_obj + 91148) = *(_DWORD *)(a2 + 20) != 0;
    *(_BYTE *)(psoc_obj + 93232) = *(_DWORD *)(a2 + 24) != 0;
    *(_DWORD *)(psoc_obj + 91144) = v21 & *(_DWORD *)(a2 + 12);
    *(_DWORD *)(psoc_obj + 93084) = *(_DWORD *)(a2 + 28);
    *(_BYTE *)(psoc_obj + 93233) = *(_BYTE *)(a2 + 32);
    *(_BYTE *)(psoc_obj + 93234) = *(_BYTE *)(a2 + 33);
    *(_BYTE *)(psoc_obj + 93235) = *(_BYTE *)(a2 + 34);
    *(_BYTE *)(psoc_obj + 93256) = *(_BYTE *)(a2 + 35);
    *(_BYTE *)(psoc_obj + 93956) = *(_BYTE *)(a2 + 36);
    *(_BYTE *)(psoc_obj + 93957) = *(_BYTE *)(a2 + 37);
    *(_BYTE *)(psoc_obj + 93958) = *(_BYTE *)(a2 + 38);
    *(_BYTE *)(psoc_obj + 93959) = *(_BYTE *)(a2 + 39);
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0x15u, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( ref )
    {
      v31 = ref;
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: error taking psoc ref cnt",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "reg_set_config_vars");
      return v31;
    }
    else
    {
      v33 = wlan_objmgr_iterate_obj_list(a1, 1, reg_change_pdev_for_config, 0, 1, 0x15u);
      wlan_objmgr_psoc_release_ref(a1, 0x15u, v34, v35, v36, v37, v38, v39, v40, v41);
      return v33;
    }
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: psoc priv obj is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "reg_set_config_vars");
    return 16;
  }
}
