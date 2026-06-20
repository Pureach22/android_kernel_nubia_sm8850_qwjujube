__int64 __fastcall ucfg_dp_update_link_mac_addr(__int64 a1, _WORD *a2, char a3)
{
  __int64 context; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 comp_private_obj; // x19
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
  int v32; // w9
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 (*v43)(void); // x8
  __int64 result; // x0
  __int64 v45; // [xsp+8h] [xbp-38h] BYREF
  __int64 v46; // [xsp+10h] [xbp-30h]
  __int64 v47; // [xsp+18h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  __int64 v50; // [xsp+30h] [xbp-10h]
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = dp_get_context();
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v7, v8, v9, v10, v11, v12, v13, v14, "dp_get_vdev_priv_obj");
    comp_private_obj = 0;
  }
  if ( (is_dp_link_valid(comp_private_obj, v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: dp_link from vdev %pK is invalid",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "ucfg_dp_update_link_mac_addr",
      a1);
    result = 4;
    goto LABEL_18;
  }
  v32 = *(_DWORD *)a2;
  *(_WORD *)(comp_private_obj + 29) = a2[2];
  *(_DWORD *)(comp_private_obj + 25) = v32;
  if ( (a3 & 1) == 0 )
  {
    result = 0;
    goto LABEL_18;
  }
  v46 = 0;
  v47 = 0;
  v45 = 0;
  qdf_mem_copy(&v45, a2, 6u);
  v41 = *(_QWORD *)(context + 240);
  if ( !v41 || !*(_QWORD *)v41 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v33, v34, v35, v36, v37, v38, v39, v40, "cdp_txrx_set_vdev_param");
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  v42 = *(_QWORD *)(*(_QWORD *)v41 + 8LL);
  if ( !v42 || (v43 = *(__int64 (**)(void))(v42 + 40)) == nullptr )
  {
    qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v33, v34, v35, v36, v37, v38, v39, v40);
    goto LABEL_17;
  }
  v48 = v45;
  v49 = v46;
  v50 = v47;
  if ( *((_DWORD *)v43 - 1) != -96731432 )
    __break(0x8228u);
  result = v43();
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
