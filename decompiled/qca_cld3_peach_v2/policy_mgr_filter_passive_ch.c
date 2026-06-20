__int64 __fastcall policy_mgr_filter_passive_ch(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x24
  unsigned __int64 v15; // x25
  char is_passive_for_freq; // w0
  __int64 v17; // x4

  if ( a1 && a2 && a3 )
  {
    if ( *a3 )
    {
      v14 = 0;
      v15 = 0;
      do
      {
        is_passive_for_freq = wlan_reg_is_passive_for_freq(
                                a1,
                                *(_DWORD *)(a2 + 4 * v15),
                                a4,
                                a5,
                                a6,
                                a7,
                                a8,
                                a9,
                                a10,
                                a11);
        v17 = *(unsigned int *)(a2 + 4 * v15);
        if ( (is_passive_for_freq & 1) != 0 )
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Remove freq: %d from list as it's passive",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "policy_mgr_filter_passive_ch",
            v17);
        else
          *(_DWORD *)(a2 + 4 * v14++) = v17;
        ++v15;
      }
      while ( v15 < (unsigned int)*a3 );
    }
    else
    {
      LODWORD(v14) = 0;
    }
    *a3 = v14;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: NULL parameters", a4, a5, a6, a7, a8, a9, a10, a11, "policy_mgr_filter_passive_ch");
    return 5;
  }
}
