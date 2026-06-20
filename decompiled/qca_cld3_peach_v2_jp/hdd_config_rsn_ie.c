__int64 __fastcall hdd_config_rsn_ie(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4

  v10 = *(unsigned __int8 *)(a2 + 4);
  if ( v10 < 2 )
  {
    *(_BYTE *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 3284LL) = v10;
    qdf_trace_msg(0x33u, 8u, "%s: force_rsne_override - %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_rsn_ie");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid value %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_rsn_ie");
    return 4294967274LL;
  }
}
