__int64 __fastcall hdd_add_param_info(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4, char a5)
{
  __int64 v10; // x24
  __int64 v11; // x25
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _WORD *v22; // x24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  int v32; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  v11 = *(unsigned int *)(a1 + 208);
  v12 = nla_put(a1, 32770, 0, 0);
  result = 4294967274LL;
  if ( (v12 & 0x80000000) == 0 )
  {
    v22 = (_WORD *)(v10 + v11);
    if ( v22 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SR params of connected AP srg_max_pd_offset %d srg_min_pd_offset %d non_srg_pd_offset %d non_srg_obss_pd_dis"
        "allow %d hesega_val_15_enable %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_add_param_info",
        a2,
        a3,
        a4,
        (unsigned __int8)(a5 & 2) >> 1,
        (unsigned __int8)(a5 & 0x10) >> 4);
      v32 = a3;
      if ( (unsigned int)nla_put(a1, 3, 4, &v32) || (v32 = a2, (unsigned int)nla_put(a1, 4, 4, &v32)) )
      {
        v31 = "%s: srg_pd_min_offset put fail";
      }
      else
      {
        v32 = a4;
        if ( (unsigned int)nla_put(a1, 5, 4, &v32) )
        {
          v31 = "%s: non_srg_pd_offset put fail";
        }
        else if ( (a5 & 2) != 0 && (unsigned int)nla_put(a1, 2, 0, 0) )
        {
          v31 = "%s: non_srg_obss_pd_disallow put fail or enabled";
        }
        else
        {
          if ( (a5 & 0x10) == 0 || !(unsigned int)nla_put(a1, 1, 0, 0) )
          {
            result = 0;
            *v22 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v22;
            goto LABEL_7;
          }
          v31 = "%s: hesega_val_15_enable put fail or disabled";
        }
      }
      qdf_trace_msg(0x33u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_add_param_info");
      result = 4294967274LL;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
