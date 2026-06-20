__int64 __fastcall policy_mgr_get_updated_scan_config(__int64 a1, unsigned int *a2, char a3, char a4, char a5)
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
  unsigned int v19; // w8
  __int64 v20; // x9
  int v21; // w9
  unsigned int v22; // w10
  int v23; // w11
  int v24; // w9
  unsigned int v25; // w10
  int v26; // w8
  const char *v28; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v28 = "%s: Invalid Context";
    goto LABEL_14;
  }
  v19 = *(_DWORD *)(comp_private_obj + 1512);
  *a2 = v19;
  if ( !a1 || (v20 = *(_QWORD *)(a1 + 2800)) == 0 )
  {
    v28 = "%s: tgt_hdl NULL";
LABEL_14:
    qdf_trace_msg(0x4Fu, 2u, v28, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_get_updated_scan_config");
    return 16;
  }
  v21 = *(_DWORD *)(v20 + 760);
  v22 = v21 & 0x80000000;
  v23 = v21 & 0x40000000;
  v24 = v21 & 0x20000000;
  if ( (a3 & 1) == 0 )
    v22 = 0;
  if ( (a4 & 1) == 0 )
    v23 = 0;
  v25 = v22 & 0xE0000000 | v19 & 0x1FFFFFFF;
  if ( (a5 & 1) != 0 )
    v26 = v24;
  else
    v26 = 0;
  *a2 = v25 | v23 | v26;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: scan_config:%x ",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "policy_mgr_get_updated_scan_config");
  return 0;
}
