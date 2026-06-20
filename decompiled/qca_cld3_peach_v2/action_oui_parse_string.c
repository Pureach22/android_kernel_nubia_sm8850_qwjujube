__int64 __fastcall action_oui_parse_string(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  const char *v23; // x2
  __int64 comp_private_obj; // x0
  __int64 v25; // x21
  unsigned int v26; // w0
  unsigned int v27; // w23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  void *v38; // x0
  __int64 v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7

  qdf_trace_msg(0x63u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "action_oui_parse_string");
  if ( !a1 )
  {
    v23 = "%s: psoc is NULL";
LABEL_10:
    qdf_trace_msg(0x63u, 2u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "action_oui_parse_string");
    goto LABEL_11;
  }
  if ( a3 >= 0x1C )
  {
    v22 = "%s: Invalid action_oui id: %u";
LABEL_8:
    qdf_trace_msg(0x63u, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "action_oui_parse_string", a3);
LABEL_11:
    v36 = 4;
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v23 = "%s: psoc priv is NULL";
    goto LABEL_10;
  }
  v25 = comp_private_obj;
  v26 = strlen(a2);
  v27 = v26;
  if ( v26 - 840 <= 0xFFFFFCB8 )
  {
    v22 = "%s: Invalid string length: %u";
    goto LABEL_8;
  }
  v38 = (void *)_qdf_mem_malloc(v26 + 1, "action_oui_parse_string", 725);
  if ( v38 )
  {
    v39 = (__int64)v38;
    qdf_mem_copy(v38, a2, v27);
    *(_BYTE *)(v39 + v27) = 0;
    v36 = action_oui_parse(v25, v39, a3, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( v36 )
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Failed to parse: %u",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "action_oui_parse_string",
        a3);
    _qdf_mem_free(v39);
  }
  else
  {
    v36 = 2;
  }
LABEL_12:
  qdf_trace_msg(0x63u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "action_oui_parse_string");
  return v36;
}
