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

  if ( g_dp_page_pool_allocs == a1 && (v10 = &g_dp_page_pool_allocs, (byte_15C00 & 1) == 0) && dword_15BE8 == a2 )
  {
    v11 = 0;
  }
  else if ( dword_15C08 == a1 && (v10 = &dword_15C08, (byte_15C30 & 1) == 0) && dword_15C18 == a2 )
  {
    v11 = 1;
  }
  else if ( dword_15C38 == a1 && (v10 = &dword_15C38, (byte_15C60 & 1) == 0) && dword_15C48 == a2 )
  {
    v11 = 2;
  }
  else if ( dword_15C68 == a1 && (v10 = &dword_15C68, (byte_15C90 & 1) == 0) && dword_15C78 == a2 )
  {
    v11 = 3;
  }
  else
  {
    if ( dword_15C98 != a1 || (v10 = &dword_15C98, (byte_15CC0 & 1) != 0) || dword_15CA8 != a2 )
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
