__int64 __fastcall util_parse_rv_multi_link_ctrl(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  __int64 v14; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  __int64 v27; // x20
  unsigned __int64 *v28; // x8
  __int64 v29; // x25
  __int64 v30; // x21
  __int64 v31; // x21
  __int64 v32; // x22
  unsigned __int64 v33; // x4
  __int64 v34; // x22
  __int16 v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  if ( a2 == 1 )
  {
    v14 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu < ML Control size %u",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "util_parse_rv_multi_link_ctrl",
        1,
        2);
      util_parse_rv_multi_link_ctrl___last_ticks = v14;
    }
    goto LABEL_23;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ML seq payload len is 0",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_parse_rv_multi_link_ctrl");
    result = 4;
    goto LABEL_24;
  }
  qdf_mem_copy(&v35, a1, 2u);
  if ( a2 <= 2 )
  {
    v26 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks_297 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML rv seq payload len %zu insufficient for common info length size %u after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_multi_link_ctrl",
        2,
        1,
        2);
      util_parse_rv_multi_link_ctrl___last_ticks_297 = v26;
    }
LABEL_23:
    result = 27;
    goto LABEL_24;
  }
  v27 = a1[2];
  if ( (v35 & 0x10) == 0 )
  {
    v28 = a4;
    if ( v27 == 1 )
      goto LABEL_20;
    goto LABEL_11;
  }
  if ( (unsigned int)v27 <= 6 )
  {
    v30 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks_299 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML rv Common Info Length %zu insufficient to access MLD MAC addr size %u.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_multi_link_ctrl",
        v27,
        6);
      util_parse_rv_multi_link_ctrl___last_ticks_299 = v30;
    }
    goto LABEL_23;
  }
  if ( a2 <= 8 )
  {
    v31 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks_301 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for MLD MAC size %u after parsed payload len %zu.",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_multi_link_ctrl",
        a2,
        6,
        3);
      util_parse_rv_multi_link_ctrl___last_ticks_301 = v31;
    }
    goto LABEL_23;
  }
  v28 = a4;
  if ( v27 != 7 )
  {
LABEL_11:
    v29 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks_303 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: ML rv seq common info len %zu doesn't match with expected common info len %zu",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_multi_link_ctrl",
        a1[2]);
      v28 = a4;
      util_parse_rv_multi_link_ctrl___last_ticks_303 = v29;
    }
  }
LABEL_20:
  v32 = v27 + 2;
  v33 = a2 - (v27 + 2);
  if ( a2 < v27 + 2 )
  {
    v34 = jiffies;
    if ( util_parse_rv_multi_link_ctrl___last_ticks_305 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload len %zu insufficient for rv link info after parsed mutli-link control %u and indicated Common"
        " Info length %zu",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "util_parse_rv_multi_link_ctrl",
        a2,
        2,
        v27);
      util_parse_rv_multi_link_ctrl___last_ticks_305 = v34;
    }
    goto LABEL_23;
  }
  if ( v28 )
  {
    *v28 = v33;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link_info_len:%zu, parsed_payload_len:%zu, rv_cinfo_len %zu ",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_rv_multi_link_ctrl");
  }
  if ( a2 == v32 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: No Link Info field present",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "util_parse_rv_multi_link_ctrl",
      v33);
    result = 0;
    if ( a3 )
      *a3 = 0;
  }
  else
  {
    result = 0;
    if ( a3 )
      *a3 = &a1[v32];
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
