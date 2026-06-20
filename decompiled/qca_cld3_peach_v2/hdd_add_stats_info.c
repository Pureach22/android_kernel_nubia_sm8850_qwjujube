__int64 __fastcall hdd_add_stats_info(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  _WORD *v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 216);
  v5 = *(unsigned int *)(a1 + 208);
  v6 = nla_put(a1, 32771, 0, 0);
  result = 4294967274LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v16 = (_WORD *)(v4 + v5);
    if ( v16 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SR stats - srg: ppdu_success %d tried %d opportunities %d non-srg: ppdu_success %d tried %d opportunities %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "hdd_add_stats_info",
        (unsigned int)a2[10],
        (unsigned int)a2[9],
        (unsigned int)a2[8],
        (unsigned int)a2[7],
        a2[6],
        a2[5]);
      v26 = a2[10];
      if ( (unsigned int)nla_put(a1, 6, 4, &v26) )
      {
        v25 = "%s: num_srg_ppdu_success put fail";
      }
      else
      {
        v26 = a2[9];
        if ( (unsigned int)nla_put(a1, 5, 4, &v26) )
        {
          v25 = "%s: num_srg_ppdu_tried put fail";
        }
        else
        {
          v26 = a2[8];
          if ( (unsigned int)nla_put(a1, 4, 4, &v26) )
          {
            v25 = "%s: num_srg_opportunities put fail";
          }
          else
          {
            v26 = a2[7];
            if ( (unsigned int)nla_put(a1, 3, 4, &v26) )
            {
              v25 = "%s: num_non_srg_ppdu_success put fail";
            }
            else
            {
              v26 = a2[6];
              if ( (unsigned int)nla_put(a1, 2, 4, &v26) )
              {
                v25 = "%s: num_non_srg_ppdu_tried put fail";
              }
              else
              {
                v26 = a2[5];
                result = nla_put(a1, 1, 4, &v26);
                if ( !(_DWORD)result )
                {
                  *v16 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v16;
                  goto LABEL_16;
                }
                v25 = "%s: num_non_srg_opportunities put fail";
              }
            }
          }
        }
      }
      qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_add_stats_info");
      result = 4294967274LL;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
