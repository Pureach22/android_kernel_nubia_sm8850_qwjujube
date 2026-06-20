__int64 __fastcall lim_update_probe_rsp_template_ie_bitmap_beacon1(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const void *v14; // x20
  int v15; // t1

  if ( a3 )
  {
    *(_WORD *)(a3 + 1996) = *(_WORD *)(a2 + 8);
    qdf_mem_copy((void *)(a3 + 1998), (const void *)(a2 + 10), 2u);
    if ( *(_BYTE *)(a2 + 12) )
    {
      *(_DWORD *)(a3 + 1952) |= 1u;
      populate_dot11f_ssid(a1, a3 + 36, a3 + 2000);
    }
    if ( *(_BYTE *)(a2 + 46) )
    {
      *(_DWORD *)(a3 + 1952) |= 2u;
      qdf_mem_copy((void *)(a3 + 2034), (const void *)(a2 + 46), 0xEu);
    }
    v15 = *(unsigned __int8 *)(a2 + 60);
    v14 = (const void *)(a2 + 60);
    if ( v15 )
    {
      *(_DWORD *)(a3 + 1952) |= 8u;
      qdf_mem_copy((void *)(a3 + 2056), v14, 2u);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: PESession is null!",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_update_probe_rsp_template_ie_bitmap_beacon1");
    return 16;
  }
}
