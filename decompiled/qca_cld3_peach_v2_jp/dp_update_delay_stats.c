__int64 __fastcall dp_update_delay_stats(
        __int64 result,
        _DWORD *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        unsigned __int8 a13,
        __int64 a14,
        char a15)
{
  __int64 v17; // x8
  _DWORD *v18; // x20
  _DWORD *v19; // x20
  _DWORD *v20; // x22
  __int64 v22; // x9
  unsigned __int64 v23; // x10
  _DWORD *v24; // x8
  int v25; // w9
  int v26; // w8
  __int64 v27; // x24
  __int64 v28; // [xsp+8h] [xbp-8h]

  if ( a13 <= 1u )
  {
    if ( a13 )
    {
      if ( a13 == 1 )
      {
        if ( !result )
          return result;
        v19 = (_DWORD *)result;
        result = dp_bucket_index(a3, &cdp_intfrm_delay, a15 & 1);
        if ( (unsigned __int8)result <= 0xDu )
        {
          v17 = (unsigned __int8)result;
          v18 = v19 + 64;
          goto LABEL_23;
        }
        goto LABEL_35;
      }
      return qdf_trace_msg(
               0x45u,
               8u,
               "%s: Incorrect delay mode: %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "dp_fill_delay_buckets",
               a13);
    }
    if ( !result )
      return result;
    v18 = (_DWORD *)result;
    result = dp_bucket_index(a3, &cdp_sw_enq_delay, a15 & 1);
    if ( (unsigned __int8)result >= 0xEu )
      goto LABEL_35;
LABEL_22:
    v17 = (unsigned __int8)result;
    goto LABEL_23;
  }
  if ( a13 == 2 )
  {
    if ( !result )
      return result;
    v20 = (_DWORD *)result;
    result = dp_bucket_index(a3, &cdp_fw_to_hw_delay, a15 & 1);
    if ( (unsigned __int8)result < 0xDu )
    {
      v18 = v20 + 32;
      v22 = (unsigned __int8)result;
      v23 = *(_QWORD *)&v20[2 * (unsigned __int8)result + 32];
      v24 = v20;
      if ( v23 >= 0xFFFFFFFF )
      {
        v28 = (unsigned __int8)result;
        v27 = jiffies;
        if ( dp_check_bucket_list_overflow___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: delay_stat overflow detected: bin:%u",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "dp_check_bucket_list_overflow",
            (unsigned __int8)result);
          dp_check_bucket_list_overflow___last_ticks = v27;
        }
        result = (__int64)qdf_mem_set(v20 + 32, 0x80u, 0);
        v22 = v28;
        v24 = v20;
        v23 = *(_QWORD *)&v18[2 * v28];
      }
      *(_QWORD *)&v18[2 * v22] = v23 + 1;
      if ( (a15 & 1) != 0 )
        v25 = a3;
      else
        v25 = 1000 * a3;
      v24[128] = v25;
      goto LABEL_24;
    }
    goto LABEL_35;
  }
  if ( a13 == 3 )
  {
    if ( !a2 )
      return result;
    v18 = a2;
    result = dp_bucket_index(a3, &cdp_intfrm_delay, a15 & 1);
    if ( (unsigned __int8)result > 0xDu )
      goto LABEL_35;
    goto LABEL_22;
  }
  if ( a13 != 4 )
    return qdf_trace_msg(
             0x45u,
             8u,
             "%s: Incorrect delay mode: %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_fill_delay_buckets",
             a13);
  if ( !a2 )
    return result;
  result = dp_bucket_index(a3, &cdp_intfrm_delay, a15 & 1);
  if ( (unsigned __int8)result > 0xDu )
  {
LABEL_35:
    __break(0x5512u);
    return qdf_trace_msg(
             0x45u,
             8u,
             "%s: Incorrect delay mode: %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_fill_delay_buckets",
             a13);
  }
  v17 = (unsigned __int8)result;
  v18 = a2 + 32;
LABEL_23:
  ++*(_QWORD *)&v18[2 * v17];
LABEL_24:
  if ( a3 && v18 )
  {
    if ( v18[26] - 1 >= a3 )
      v18[26] = a3;
    if ( v18[27] < a3 )
      v18[27] = a3;
    v26 = v18[28];
    if ( v26 )
      v18[28] = (v26 + a3) >> 1;
    else
      v18[28] = a3;
  }
  return result;
}
