__int64 __fastcall wlan_mlme_set_cfg_str(
        const void *a1,
        _QWORD *a2,
        size_t n,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( *a2 >= n )
  {
    a2[1] = n;
    qdf_mem_copy(a2 + 2, a1, (unsigned int)n);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Invalid len %zd (>%zd)", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlme_set_cfg_str", n);
    return 4;
  }
}
