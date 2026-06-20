__int64 __fastcall util_get_noninheritlists(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        _QWORD *a5,
        unsigned __int64 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int64 v14; // x8
  unsigned __int8 *v15; // x11
  __int64 v16; // x10
  bool v17; // cf
  __int64 v18; // x20
  const char *v19; // x2
  __int64 v21; // x20
  __int64 v22; // x20
  unsigned __int64 v23; // x8
  __int64 v24; // x20
  __int64 v25; // x10
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x20
  __int64 v30; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  if ( !a1 )
  {
    v19 = "%s: Pointer to buffer for IEs is NULL";
LABEL_25:
    qdf_trace_msg(0x8Fu, 2u, v19, a7, a8, a9, a10, a11, a12, a13, a14, "util_get_noninheritlists");
    return 29;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: IE buffer length is zero",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "util_get_noninheritlists");
    return 4;
  }
  if ( !a3 )
  {
    v19 = "%s: Pointer to Non-Inheritance element ID list array is NULL";
    goto LABEL_25;
  }
  if ( !a4 )
  {
    v19 = "%s: Pointer to Non-Inheritance element ID list array length is NULL";
    goto LABEL_25;
  }
  if ( !a5 )
  {
    v19 = "%s: Pointer to Non-Inheritance element ID extension list array is NULL";
    goto LABEL_25;
  }
  if ( !a6 )
  {
    v19 = "%s: Pointer to Non-Inheritance element ID extension list array length is NULL";
    goto LABEL_25;
  }
  *a4 = 0;
  *a3 = 0;
  *a6 = 0;
  *a5 = 0;
  if ( a2 >= 3 )
  {
    v14 = a2;
    v15 = a1;
    while ( 1 )
    {
      v16 = v15[1];
      v17 = v14 >= v16 + 2;
      v14 -= v16 + 2;
      if ( !v17 )
        goto LABEL_48;
      if ( v15[1] && *v15 == 255 && v15[2] == 56 )
        break;
      v15 += v16 + 2;
      if ( v14 <= 2 )
        goto LABEL_48;
    }
    if ( !v15 )
      goto LABEL_48;
    if ( v15 + 1 > &a1[a2 - 1] )
    {
      v18 = jiffies;
      if ( util_get_noninheritlists___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Position of length field of Non-Inheritance element would exceed IE buffer boundary",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists");
        util_get_noninheritlists___last_ticks = v18;
      }
      return 27;
    }
    if ( &v15[v16 + 2] > &a1[a2] )
    {
      v21 = jiffies;
      if ( util_get_noninheritlists___last_ticks_174 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Non-Inheritance element with total length %u would exceed IE buffer boundary",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists",
          (unsigned int)(v16 + 2));
        util_get_noninheritlists___last_ticks_174 = v21;
      }
      return 27;
    }
    if ( (unsigned int)v16 <= 2 )
    {
      if ( util_get_noninheritlists___last_ticks_176 - jiffies + 125 < 0 )
      {
        v22 = jiffies;
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Non-Inheritance element size %u is smaller than the minimum required %u",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists",
          (unsigned int)(v16 + 2),
          5);
        util_get_noninheritlists___last_ticks_176 = v22;
      }
      return 27;
    }
    v23 = v15[3];
    *a4 = v23;
    if ( v16 - 3 < v23 )
    {
      v24 = jiffies;
      if ( util_get_noninheritlists___last_ticks_178 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Non-Inheritance element ID list length %zu exceeds remaining unparsed IE space, minus an octet for element"
          " extension ID list length %zu",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists",
          v23,
          v16 - 3);
        util_get_noninheritlists___last_ticks_178 = v24;
      }
      return 27;
    }
    v25 = v16 - 2;
    if ( (_DWORD)v23 )
    {
      *a3 = v15 + 4;
      v26 = *a4;
      v25 -= *a4;
    }
    else
    {
      v26 = 0;
    }
    v27 = v15[v26 + 4];
    v28 = v25 - 1;
    *a6 = v27;
    if ( v25 - 1 < v27 )
    {
      v29 = jiffies;
      if ( util_get_noninheritlists___last_ticks_180 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Non-Inheritance element ID extension list length %zu exceeds remaining unparsed IE space %zu",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists",
          v27,
          v28);
        util_get_noninheritlists___last_ticks_180 = v29;
      }
      return 27;
    }
    if ( (_DWORD)v27 )
    {
      *a5 = &v15[*a4 + 5];
      v28 -= *a6;
    }
    if ( v28 )
    {
      v30 = jiffies;
      if ( util_get_noninheritlists___last_ticks_182 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Unparsed length is %zu, expected 0",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "util_get_noninheritlists",
          v28);
        util_get_noninheritlists___last_ticks_182 = v30;
      }
      return 27;
    }
  }
LABEL_48:
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Non-Inheritance element ID list array length=%zu",
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    "util_get_noninheritlists",
    *a4);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Non-Inheritance element ID extension list array length=%zu",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "util_get_noninheritlists",
    *a6);
  return 0;
}
