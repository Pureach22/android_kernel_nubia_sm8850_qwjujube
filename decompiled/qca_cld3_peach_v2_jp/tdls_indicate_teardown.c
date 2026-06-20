__int64 __fastcall tdls_indicate_teardown(
        __int64 *a1,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _DWORD *v35; // x8
  __int64 v36; // x2
  __int64 v37; // x1
  __int64 v38; // x8
  void (__fastcall *v39)(__int64, __int64, __int64 *); // x8
  __int64 v40; // x0
  __int64 result; // x0
  const char *v42; // x4
  const char *v43; // x2
  __int64 v44; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v45[3]; // [xsp+18h] [xbp-18h] BYREF

  v45[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = 0;
  v45[1] = 0;
  if ( !a1 || !a2 )
  {
    if ( a1 )
      v42 = "curr_peer";
    else
      v42 = "tdls_vdev";
    qdf_trace_msg(0, 2u, "%s: %s is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "tdls_indicate_teardown", v42);
    result = 16;
    goto LABEL_25;
  }
  if ( !*a1 )
  {
    v43 = "%s: NULL vdev";
    goto LABEL_23;
  }
  v12 = *(_QWORD *)(*a1 + 152);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v43 = "%s: can't get psoc";
LABEL_23:
    qdf_trace_msg(0, 2u, v43, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_24;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_24:
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d tdls_soc: is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "tdls_indicate_teardown",
      *(unsigned __int8 *)(*a1 + 104));
    result = 14;
    goto LABEL_25;
  }
  v25 = *((unsigned int *)a2 + 9);
  v26 = comp_private_obj;
  if ( (_DWORD)v25 == 4 )
  {
    tdls_set_peer_link_status(a2, 5, 0xFFFFFFFFLL);
    qdf_trace_msg(
      0,
      4u,
      "%s: vdev:%d Teardown reason %d peer:%02x:%02x:%02x:**:**:%02x",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "tdls_indicate_teardown",
      *(unsigned __int8 *)(*a1 + 104),
      a3,
      a2[24],
      a2[25],
      a2[26],
      a2[29]);
    v35 = *(_DWORD **)(v26 + 296);
    if ( v35 )
    {
      v36 = *(unsigned int *)(v26 + 344);
      v37 = *(unsigned __int8 *)(*a1 + 104);
      if ( *(v35 - 1) != 792568820 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v35)(v26, v37, v36, 0);
    }
    v38 = *a1;
    LOWORD(v45[0]) = a3;
    v44 = v38;
    qdf_mem_copy((char *)v45 + 2, a2 + 24, 6u);
    v39 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v26 + 264);
    if ( v39 )
    {
      v40 = *(_QWORD *)(v26 + 272);
      if ( *((_DWORD *)v39 - 1) != 1890320457 )
        __break(0x8228u);
      v39(v40, 6, &v44);
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d link state %d peer:%02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "tdls_indicate_teardown",
      *(unsigned __int8 *)(*a1 + 104),
      v25,
      a2[24],
      a2[25],
      a2[26],
      a2[29]);
    result = 4;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
