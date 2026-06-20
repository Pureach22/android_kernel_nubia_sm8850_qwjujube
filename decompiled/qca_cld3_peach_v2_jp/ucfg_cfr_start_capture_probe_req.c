__int64 __fastcall ucfg_cfr_start_capture_probe_req(__int64 a1, const void *a2, const void *a3)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  const char *v15; // x2
  __int64 v17; // x23
  __int64 v18; // x25
  unsigned int v19; // w24
  _BYTE *v20; // x22
  _BYTE *v21; // x22
  __int16 v22; // w8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v15 = "%s: Pdev cfr object is null!";
    goto LABEL_7;
  }
  v14 = comp_private_obj;
  if ( !*(_BYTE *)(comp_private_obj + 8) )
  {
    v15 = "%s: CFR is not supported on this chip";
    goto LABEL_7;
  }
  if ( *(unsigned __int16 *)(comp_private_obj + 42) == *(unsigned __int16 *)(comp_private_obj + 40) )
  {
    v15 = "%s: max cfr client reached";
LABEL_7:
    qdf_trace_msg(0x6Au, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "ucfg_cfr_start_capture_probe_req");
    return 4294967274LL;
  }
  v17 = comp_private_obj + 1444;
  v18 = 0;
  v19 = -1;
  v20 = (_BYTE *)(comp_private_obj + 1444);
  do
  {
    if ( (v19 & 0x80000000) != 0 && !v20[20] )
      v19 = v18;
    if ( !(unsigned int)qdf_mem_cmp(v20, a2, 6u) )
    {
      qdf_trace_msg(
        0x6Au,
        4u,
        "%s: Node already present. Updating params",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "ucfg_cfr_start_capture_probe_req");
      qdf_mem_copy(v20 + 8, a3, 0xCu);
      v20[20] = 1;
      return 0;
    }
    ++v18;
    v20 += 24;
  }
  while ( v18 != 10 );
  if ( (v19 & 0x80000000) != 0 )
  {
    v15 = "%s: Maximum client capacity reached";
    goto LABEL_7;
  }
  if ( v19 > 9 )
  {
    __break(0x5512u);
    return ucfg_cfr_stop_capture_probe_req();
  }
  else
  {
    v21 = (_BYTE *)(v17 + 24LL * v19);
    qdf_mem_copy(v21, a2, 6u);
    qdf_mem_copy(v21 + 8, a3, 0xCu);
    v22 = *(_WORD *)(v14 + 42);
    v21[20] = 1;
    *(_WORD *)(v14 + 42) = v22 + 1;
    return 0;
  }
}
