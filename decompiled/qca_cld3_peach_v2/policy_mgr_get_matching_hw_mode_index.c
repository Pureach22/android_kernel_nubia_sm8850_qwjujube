__int64 __fastcall policy_mgr_get_matching_hw_mode_index(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  __int64 v28; // x5
  unsigned __int64 v29; // x13
  bool v30; // cf
  bool v31; // cf
  bool v32; // cf
  bool v33; // cf
  bool v34; // cf
  bool v35; // zf
  bool v36; // zf
  bool v37; // zf
  unsigned int v38; // w19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "policy_mgr_get_matching_hw_mode_index");
    return 234;
  }
  v27 = *(unsigned int *)(comp_private_obj + 1184);
  if ( !(_DWORD)v27 )
    return 234;
  v28 = 0;
  while ( 1 )
  {
    v29 = *(_QWORD *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v28);
    v30 = (unsigned int)(v29 >> 28) >= a2 && (BYTE3(v29) & 0xF) >= a3;
    v31 = v30 && (unsigned __int16)v29 >> 12 >= a4;
    v32 = v31 && (((unsigned int)v29 >> 20) & 0xF) >= a5;
    v33 = v32 && (WORD1(v29) & 0xF) >= a6;
    v34 = v33 && (((unsigned int)v29 >> 8) & 0xF) >= a7;
    v35 = v34 && (((unsigned int)v29 >> 7) & 1) == a9;
    v36 = v35 && (((unsigned int)v29 >> 6) & 1) == a10;
    v37 = v36 && (((unsigned int)v29 >> 5) & 1) == a11;
    if ( v37 && (!a8 || (((unsigned int)v29 >> 3) & 3) == a8) )
      break;
    if ( v27 == ++v28 )
      return 234;
  }
  v38 = v29 & 7;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: hw_mode id %d found at %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "policy_mgr_get_matching_hw_mode_index",
    *(_QWORD *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v28) & 7LL);
  return v38;
}
