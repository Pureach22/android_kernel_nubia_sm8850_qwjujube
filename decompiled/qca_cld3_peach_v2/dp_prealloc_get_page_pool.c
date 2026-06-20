int *__fastcall dp_prealloc_get_page_pool(
        unsigned int a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int *v10; // x19
  __int64 v11; // x4

  if ( g_dp_page_pool_allocs == a1 && (v10 = &g_dp_page_pool_allocs, (byte_16520 & 1) == 0) && dword_16508 == a2 )
  {
    v11 = 0;
  }
  else if ( dword_16528 == a1 && (v10 = &dword_16528, (byte_16550 & 1) == 0) && dword_16538 == a2 )
  {
    v11 = 1;
  }
  else if ( dword_16558 == a1 && (v10 = &dword_16558, (byte_16580 & 1) == 0) && dword_16568 == a2 )
  {
    v11 = 2;
  }
  else if ( dword_16588 == a1 && (v10 = &dword_16588, (byte_165B0 & 1) == 0) && dword_16598 == a2 )
  {
    v11 = 3;
  }
  else
  {
    if ( dword_165B8 != a1 || (v10 = &dword_165B8, (byte_165E0 & 1) != 0) || dword_165C8 != a2 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: get page pool %d type %d size %d failed",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "dp_prealloc_get_page_pool",
        5);
      return nullptr;
    }
    v11 = 4;
  }
  *((_BYTE *)v10 + 40) = 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: get page pool %d type %d size %d success",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_prealloc_get_page_pool",
    v11,
    a1);
  return v10;
}
