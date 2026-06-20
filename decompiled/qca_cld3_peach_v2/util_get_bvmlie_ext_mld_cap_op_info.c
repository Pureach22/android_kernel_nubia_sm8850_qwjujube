__int64 __fastcall util_get_bvmlie_ext_mld_cap_op_info(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 result; // x0
  unsigned int v16; // w22
  unsigned __int8 *v17; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w14
  __int64 v30; // x11
  _BYTE *v31; // x9
  _WORD *v32; // x10
  unsigned __int64 v33; // x13
  __int64 v34; // x20
  __int64 v35; // [xsp+8h] [xbp-38h]

  result = 29;
  if ( !a1 || !a2 || !a3 || !a4 )
    return result;
  *a3 = 0;
  *a4 = 0;
  if ( a2 < 5 || *a1 != 255 || a1[2] != 107 )
    return 4;
  v35 = v13;
  v16 = *(unsigned __int16 *)(a1 + 3);
  if ( (v16 & 7) != 0 )
    return 11;
  v17 = a1;
  if ( (unsigned int)util_validate_bv_mlie_min_seq_len(a2, a5, a6, a7, a8, a9, a10, a11, a12) )
    return 4;
  v29 = v16 >> 4;
  if ( ((v16 >> 4) & 1) != 0 )
  {
    if ( a2 < 0xD )
      return 27;
    v33 = a2;
    v31 = a3;
    v32 = a4;
    v30 = 8;
  }
  else
  {
    v30 = 7;
    v31 = a3;
    v32 = a4;
    v33 = a2;
  }
  if ( (v29 & 2) != 0 )
  {
    if ( v30 + 6 > v33 )
      return 27;
    ++v30;
  }
  if ( (v29 & 4) != 0 )
  {
    if ( v30 + 7 > v33 )
      return 27;
    v30 += 2;
  }
  if ( (v29 & 8) != 0 )
  {
    if ( v30 + 7 > v33 )
      return 27;
    v30 += 2;
  }
  if ( (v29 & 0x10) != 0 )
  {
    if ( v30 + 7 <= v33 )
    {
      v30 += 2;
      goto LABEL_30;
    }
    return 27;
  }
LABEL_30:
  if ( (v29 & 0x20) != 0 )
  {
    if ( v30 + 6 > v33 )
      return 27;
    ++v30;
  }
  if ( (v29 & 0x40) != 0 )
  {
    result = 27;
    if ( v30 + 2 <= (unsigned __int64)v17[5] && v30 + 7 <= v33 )
    {
      *v32 = *(_WORD *)&v17[v30 + 5];
      *v31 = 1;
      return 0;
    }
  }
  else
  {
    v34 = jiffies;
    if ( util_get_bvmlie_ext_mld_cap_op_info___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Ext mld caps not found",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "util_get_bvmlie_ext_mld_cap_op_info",
        v12,
        v35);
      util_get_bvmlie_ext_mld_cap_op_info___last_ticks = v34;
    }
    return 0;
  }
  return result;
}
