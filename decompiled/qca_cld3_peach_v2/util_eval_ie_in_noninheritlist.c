__int64 __fastcall util_eval_ie_in_noninheritlist(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        unsigned __int64 a6,
        _BYTE *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 result; // x0
  const char *v16; // x2
  int v17; // w8
  int v18; // w8
  unsigned __int64 v19; // x10
  int v20; // w9
  unsigned __int64 v21; // x10
  int v22; // w9
  const char *v23; // x2
  __int64 v24; // x4

  if ( a7 )
  {
    if ( a1 )
    {
      if ( a2 <= 2 && *a1 == 255 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Total IE length %zu is smaller than minimum required to access element ID extension %u",
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "util_eval_ie_in_noninheritlist",
          2,
          3);
        return 4;
      }
      *a7 = 0;
      if ( a6 | a4 )
      {
        v17 = *a1;
        if ( v17 == 255 )
        {
          if ( a6 )
          {
            if ( a5 )
            {
              v18 = a1[2];
              v19 = 0;
              v20 = 1;
              while ( v18 != *(unsigned __int8 *)(a5 + v19) )
              {
                v19 = v20;
                result = 0;
                ++v20;
                if ( v19 >= a6 )
                  return result;
              }
LABEL_26:
              *a7 = 1;
              return 0;
            }
            v23 = "%s: NULL pointer to Non-Inheritance element ID extension list though length of element ID extension list is %zu";
            v24 = a6;
LABEL_29:
            qdf_trace_msg(0x8Fu, 2u, v23, a8, a9, a10, a11, a12, a13, a14, a15, "util_eval_ie_in_noninheritlist", v24);
            return 29;
          }
        }
        else if ( a4 )
        {
          if ( a3 )
          {
            v21 = 0;
            v22 = 1;
            while ( v17 != *(unsigned __int8 *)(a3 + v21) )
            {
              v21 = v22;
              result = 0;
              ++v22;
              if ( v21 >= a4 )
                return result;
            }
            goto LABEL_26;
          }
          v23 = "%s: NULL pointer to Non-Inheritance element ID list though length of element ID list is %zu";
          v24 = a4;
          goto LABEL_29;
        }
      }
      return 0;
    }
    v16 = "%s: NULL pointer to IE";
  }
  else
  {
    v16 = "%s: NULL pointer to flag that indicates if element is in a Non-Inheritance list";
  }
  qdf_trace_msg(0x8Fu, 2u, v16, a8, a9, a10, a11, a12, a13, a14, a15, "util_eval_ie_in_noninheritlist");
  return 29;
}
