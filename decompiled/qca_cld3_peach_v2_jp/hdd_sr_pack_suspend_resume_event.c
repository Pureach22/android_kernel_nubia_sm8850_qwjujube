__int64 __fastcall hdd_sr_pack_suspend_resume_event(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 result; // x0
  __int64 v30; // x21
  __int64 v31; // x26
  _WORD *v32; // x21
  unsigned int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 <= 1 && (unsigned int)(a2 - 4) > 0xFFFFFFFD )
  {
    LOBYTE(v33) = a2;
    if ( (unsigned int)nla_put(a1, 1, 1, &v33) )
    {
      v28 = "%s: failed to put attr SR Operation";
    }
    else
    {
      v30 = *(_QWORD *)(a1 + 216);
      v31 = *(unsigned int *)(a1 + 208);
      if ( (nla_put(a1, 32770, 0, 0) & 0x80000000) != 0 || (v32 = (_WORD *)(v30 + v31)) == nullptr )
      {
        v28 = "%s: nesting failed";
      }
      else
      {
        v33 = a3;
        if ( !(unsigned int)nla_put(a1, 8, 4, &v33) )
        {
          if ( a2 == 3 && !a3 )
          {
            v33 = a5;
            if ( (unsigned int)nla_put(a1, 3, 4, &v33) || (v33 = a4, (unsigned int)nla_put(a1, 4, 4, &v33)) )
            {
              v28 = "%s: srg_pd_min_offset put fail";
              goto LABEL_11;
            }
            v33 = a6;
            if ( (unsigned int)nla_put(a1, 5, 4, &v33) )
            {
              v28 = "%s: non_srg_pd_offset put fail";
              goto LABEL_11;
            }
          }
          result = 0;
          *v32 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v32;
          goto LABEL_12;
        }
        v28 = "%s: failed to put attr SR Reascon Code";
      }
    }
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "hdd_sr_pack_suspend_resume_event");
    result = 5;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: SR operation is invalid",
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    "hdd_sr_pack_suspend_resume_event");
  result = 4;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
