__int64 __fastcall ucfg_cfr_stop_capture_probe_req(__int64 a1, const void *a2)
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
  _WORD *v12; // x19
  void *v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v23; // x2

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v23 = "%s: Pdev cfr object is NULL!";
LABEL_17:
    qdf_trace_msg(0x6Au, 2u, v23, v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_cfr_stop_capture_probe_req");
    return 4294967274LL;
  }
  v12 = (_WORD *)comp_private_obj;
  if ( !*(_BYTE *)(comp_private_obj + 8) )
  {
    v23 = "%s: CFR is not supported on this chip";
    goto LABEL_17;
  }
  v13 = (void *)(comp_private_obj + 1444);
  if ( !(unsigned int)qdf_mem_cmp((const void *)(comp_private_obj + 1444), a2, 6u) )
    goto LABEL_14;
  v13 = v12 + 734;
  if ( !(unsigned int)qdf_mem_cmp(v12 + 734, a2, 6u) )
    goto LABEL_14;
  v13 = v12 + 746;
  if ( !(unsigned int)qdf_mem_cmp(v12 + 746, a2, 6u) )
    goto LABEL_14;
  v13 = v12 + 758;
  if ( (unsigned int)qdf_mem_cmp(v12 + 758, a2, 6u)
    && (v13 = v12 + 770, (unsigned int)qdf_mem_cmp(v12 + 770, a2, 6u))
    && (v13 = v12 + 782, (unsigned int)qdf_mem_cmp(v12 + 782, a2, 6u))
    && (v13 = v12 + 794, (unsigned int)qdf_mem_cmp(v12 + 794, a2, 6u))
    && (v13 = v12 + 806, (unsigned int)qdf_mem_cmp(v12 + 806, a2, 6u))
    && (v13 = v12 + 818, (unsigned int)qdf_mem_cmp(v12 + 818, a2, 6u))
    && (v13 = v12 + 830, (unsigned int)qdf_mem_cmp(v12 + 830, a2, 6u)) )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Trying to delete mac not present in pool. Ignoring request.",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "ucfg_cfr_stop_capture_probe_req");
    return 0;
  }
  else
  {
LABEL_14:
    qdf_mem_set(v13, 0x18u, 0);
    --v12[21];
    return 0;
  }
}
