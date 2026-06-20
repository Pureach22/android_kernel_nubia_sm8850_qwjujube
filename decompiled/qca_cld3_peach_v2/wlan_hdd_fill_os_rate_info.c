__int64 __fastcall wlan_hdd_fill_os_rate_info(
        unsigned int a1,
        unsigned __int16 a2,
        __int64 a3,
        char a4,
        char a5,
        unsigned int a6,
        unsigned int a7,
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w1
  __int16 v30; // w8
  __int16 v31; // w8
  char v32; // w9
  unsigned int v33; // w1

  *(_BYTE *)(a3 + 5) = a5;
  if ( (a1 & 1) != 0 )
  {
    *(_WORD *)(a3 + 2) = a2;
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: Reporting legacy rate %d",
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             "wlan_hdd_fill_os_rate_info",
             a2);
  }
  hdd_set_rate_bw(a3, 2u, a8, a9, a10, a11, a12, a13, a14, a15);
  *(_BYTE *)(a3 + 4) = a4;
  result = wlan_hdd_fill_os_eht_rateflags(a3, a1, a6, a7);
  if ( (a1 & 0xF00) != 0 )
  {
    if ( (a1 & 0x800) != 0 )
    {
      v29 = 5;
    }
    else if ( (a1 & 0x400) != 0 )
    {
      v29 = 4;
    }
    else
    {
      if ( (a1 & 0x200) == 0 )
      {
LABEL_11:
        v30 = *(_WORD *)a3;
        *(_BYTE *)(a3 + 8) = a6;
        v31 = v30 | 0x10;
        if ( a7 == 3 )
          v32 = 2;
        else
          v32 = a7 == 2;
        *(_WORD *)a3 = v31;
        *(_BYTE *)(a3 + 7) = v32;
        goto LABEL_15;
      }
      v29 = 3;
    }
    result = hdd_set_rate_bw(a3, v29, v21, v22, v23, v24, v25, v26, v27, v28);
    goto LABEL_11;
  }
LABEL_15:
  if ( (a1 & 0x10E0) != 0 )
  {
    if ( (a1 & 0x1000) != 0 )
    {
      v33 = 5;
    }
    else if ( (a1 & 0x80) != 0 )
    {
      v33 = 4;
    }
    else
    {
      if ( (a1 & 0x40) == 0 )
      {
LABEL_23:
        *(_WORD *)a3 |= 2u;
        goto LABEL_24;
      }
      v33 = 3;
    }
    result = hdd_set_rate_bw(a3, v33, v21, v22, v23, v24, v25, v26, v27, v28);
    goto LABEL_23;
  }
LABEL_24:
  if ( (a1 & 6) != 0 )
  {
    if ( (a1 & 4) != 0 )
      result = hdd_set_rate_bw(a3, 3u, v21, v22, v23, v24, v25, v26, v27, v28);
    *(_WORD *)a3 |= 1u;
  }
  if ( (a1 & 8) != 0 )
    *(_WORD *)a3 |= 4u;
  return result;
}
