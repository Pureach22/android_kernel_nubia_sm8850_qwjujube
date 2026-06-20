__int64 __fastcall util_validate_reportingsta_ie(
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
  __int64 v18; // x10
  __int64 v19; // x20
  __int64 v20; // x4
  __int64 v21; // x20
  __int64 v22; // x19

  if ( !a1 )
  {
    v13 = "%s: Pointer to reporting STA IE is NULL";
LABEL_8:
    qdf_trace_msg(0x8Fu, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "util_validate_reportingsta_ie");
    return 29;
  }
  if ( !a2 )
  {
    v13 = "%s: Pointer to start of IE section in reporting frame is NULL";
    goto LABEL_8;
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
        if ( util_validate_reportingsta_ie___last_ticks_192 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Position of element ID extension field of element would exceed frame IE section boundary",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "util_validate_reportingsta_ie");
          util_validate_reportingsta_ie___last_ticks_192 = v17;
        }
      }
      else
      {
        v18 = a1[1];
        if ( v16 != 255 || a1[1] )
        {
          v20 = v18 + 2;
          if ( v16 == 221 && (unsigned int)v18 <= 3 )
          {
            v21 = jiffies;
            if ( util_validate_reportingsta_ie___last_ticks_196 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: Total length %zu of element for reporting STA is smaller than minimum required of %u to access vendor EID",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "util_validate_reportingsta_ie",
                v20,
                6);
              util_validate_reportingsta_ie___last_ticks_196 = v21;
            }
          }
          else
          {
            if ( (unsigned __int64)&a1[v20] <= a2 + a3 )
              return 0;
            v22 = jiffies;
            if ( v16 == 255 )
            {
              if ( util_validate_reportingsta_ie___last_ticks_198 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: Total size %zu octets of element with element ID %u element ID extension %u for reporting STA woul"
                  "d exceed frame IE section boundary",
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  "util_validate_reportingsta_ie");
                util_validate_reportingsta_ie___last_ticks_198 = v22;
              }
            }
            else if ( util_validate_reportingsta_ie___last_ticks_200 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: Total size %zu octets of element with element ID %u for reporting STA would exceed frame IE section boundary",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "util_validate_reportingsta_ie");
              util_validate_reportingsta_ie___last_ticks_200 = v22;
            }
          }
        }
        else
        {
          v19 = jiffies;
          if ( util_validate_reportingsta_ie___last_ticks_194 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Total length %zu of element for reporting STA is smaller than minimum required to access element ID extension %u",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "util_validate_reportingsta_ie",
              2,
              3);
            util_validate_reportingsta_ie___last_ticks_194 = v19;
          }
        }
      }
    }
    else
    {
      v15 = jiffies;
      if ( util_validate_reportingsta_ie___last_ticks_190 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Position of length field of element with element ID %u for reporting STA would exceed frame IE section boundary",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "util_validate_reportingsta_ie",
          *a1);
        util_validate_reportingsta_ie___last_ticks_190 = v15;
      }
    }
  }
  else
  {
    v12 = jiffies;
    if ( util_validate_reportingsta_ie___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Position of element ID field of element for reporting STA would exceed frame IE section boundary",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "util_validate_reportingsta_ie");
      util_validate_reportingsta_ie___last_ticks = v12;
    }
  }
  return 27;
}
