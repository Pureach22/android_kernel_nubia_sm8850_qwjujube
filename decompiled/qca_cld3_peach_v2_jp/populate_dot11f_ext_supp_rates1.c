__int64 __fastcall populate_dot11f_ext_supp_rates1(
        __int64 a1,
        unsigned __int8 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 v12; // x9
  unsigned int cfg_str; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  size_t v23; // x2
  size_t n; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  int v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 0xFu )
  {
    v12 = *(_QWORD *)(a1 + 8);
    v27 = 0;
    n = 12;
    v26 = 0;
    cfg_str = wlan_mlme_get_cfg_str(&v26, v12 + 2816, &n, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( cfg_str )
    {
      v11 = cfg_str;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to retrieve nItem from CFG status: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "populate_dot11f_ext_supp_rates1",
        cfg_str);
    }
    else
    {
      v23 = n;
      if ( n )
      {
        a3[1] = n;
        qdf_mem_copy(a3 + 2, &v26, v23);
        v11 = 0;
        *a3 = 1;
      }
      else
      {
        v11 = 0;
      }
    }
  }
  else
  {
    v11 = 0;
    *a3 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
