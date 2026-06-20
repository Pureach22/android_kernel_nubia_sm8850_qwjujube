__int64 __fastcall hdd_remove_vlp_depriority_channels(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int16 v31; // w24
  unsigned int v32; // w23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x3
  __int16 v42; // [xsp+4h] [xbp-Ch] BYREF
  char v43; // [xsp+6h] [xbp-Ah]
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 80);
  if ( result && *a3 >= 2 )
  {
    v43 = 0;
    v42 = 0;
    ucfg_reg_get_current_country(result, &v42, a4, a5, a6, a7, a8, a9, a10, a11);
    result = ucfg_reg_get_num_rules_of_ap_pwr_type(a1, 2u, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( (_BYTE)result )
    {
      if ( *a3 )
      {
        v31 = 0;
        v32 = 0;
        do
        {
          result = ucfg_reg_is_vlp_depriority_freq(a1, *(unsigned __int16 *)(a2 + 2LL * v31));
          v41 = *(unsigned __int16 *)(a2 + 2LL * v31);
          if ( (result & 1) != 0 )
            result = qdf_trace_msg(0x33u, 8u, "skip freq %u", v33, v34, v35, v36, v37, v38, v39, v40, v41);
          else
            *(_WORD *)(a2 + 2LL * v32++) = v41;
          ++v31;
        }
        while ( *a3 > v31 );
      }
      else
      {
        v32 = 0;
      }
      *a3 = v32;
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Current country %.2s don't support VLP",
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 "hdd_remove_vlp_depriority_channels",
                 &v42);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
