__int64 __fastcall hdcp2_init_smcinvoke(int a1)
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(memcpy, 3520, 128);
  if ( result )
    *(_DWORD *)(result + 124) = a1;
  return result;
}
