__int64 __fastcall gsi_ctrl_pkt_alloc(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x8
  __int64 result; // x0

  v4 = 1;
  if ( (a2 & 0x10) == 0 )
    v4 = 2;
  if ( (a2 & 0x400010) != 0 )
    v5 = v4;
  else
    v5 = 0;
  v6 = _kmalloc_cache_noprof(kmalloc_caches[14 * v5 + 5], a2 | 0x100, 32);
  if ( v6 )
  {
    v7 = v6;
    v8 = _kmalloc_noprof(a1, a2);
    result = v7;
    *(_QWORD *)v7 = v8;
    if ( v8 )
    {
      *(_DWORD *)(v7 + 8) = a1;
      return result;
    }
    kfree(v7);
  }
  return -12;
}
