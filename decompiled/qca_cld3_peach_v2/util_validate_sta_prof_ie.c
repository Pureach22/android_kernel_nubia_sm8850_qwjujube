__int64 __fastcall util_validate_sta_prof_ie(
        unsigned __int8 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // x11
  __int64 v12; // x20
  const char *v13; // x2
  __int64 v15; // x20
  int v16; // w5
  __int64 v17; // x20
  __int64 v18; // x20
  __int64 v19; // x19

  if ( !a1 )
  {
    v13 = "%s: Pointer to STA profile IE is NULL";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "util_validate_sta_prof_ie");
    return 29;
  }
  if ( !a2 )
  {
    v13 = "%s: Pointer to start of IE section in STA profile is NULL";
    goto LABEL_9;
  }
  if ( !a3 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of IE section in STA profile is zero",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "util_validate_sta_prof_ie");
    return 4;
  }
  v11 = a2 + a3 - 1;
  if ( v11 >= (unsigned __int64)a1 )
  {
    if ( (unsigned __int64)(a1 + 1) <= v11 )
    {
      v16 = *a1;
      if ( (unsigned __int64)(a1 + 2) > v11 && v16 == 255 )
      {
        v17 = jiffies;
        if ( util_validate_sta_prof_ie___last_ticks_219 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Position of element ID extension field of element would exceed STA profile IE section boundary",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "util_validate_sta_prof_ie");
          util_validate_sta_prof_ie___last_ticks_219 = v17;
        }
      }
      else if ( v16 != 255 || a1[1] )
      {
        if ( (unsigned __int64)&a1[a1[1] + 2] <= a2 + a3 )
          return 0;
        v19 = jiffies;
        if ( v16 == 255 )
        {
          if ( util_validate_sta_prof_ie___last_ticks_223 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Total size %zu octets of element with element ID %u element ID extension %u in STA profile would excee"
              "d STA profile IE section boundary",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "util_validate_sta_prof_ie");
            util_validate_sta_prof_ie___last_ticks_223 = v19;
          }
        }
        else if ( util_validate_sta_prof_ie___last_ticks_225 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Total size %zu octets of element with element ID %u in STA profile would exceed STA profile IE section boundary",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "util_validate_sta_prof_ie");
          util_validate_sta_prof_ie___last_ticks_225 = v19;
        }
      }
      else
      {
        v18 = jiffies;
        if ( util_validate_sta_prof_ie___last_ticks_221 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Total length %zu of STA profile element is smaller than minimum required to access element ID extension %u",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "util_validate_sta_prof_ie",
            2,
            3);
          util_validate_sta_prof_ie___last_ticks_221 = v18;
        }
      }
    }
    else
    {
      v15 = jiffies;
      if ( util_validate_sta_prof_ie___last_ticks_217 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Position of length field of element with element ID %u in STA profile would exceed STA profile IE section boundary",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "util_validate_sta_prof_ie",
          *a1);
        util_validate_sta_prof_ie___last_ticks_217 = v15;
      }
    }
  }
  else
  {
    v12 = jiffies;
    if ( util_validate_sta_prof_ie___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Position of element ID field of STA profile element would exceed STA profile IE section boundary",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_validate_sta_prof_ie");
      util_validate_sta_prof_ie___last_ticks = v12;
    }
  }
  return 27;
}
