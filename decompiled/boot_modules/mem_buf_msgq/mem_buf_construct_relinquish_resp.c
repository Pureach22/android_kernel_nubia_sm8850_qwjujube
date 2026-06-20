__int64 __fastcall mem_buf_construct_relinquish_resp(int *a1)
{
  __int64 result; // x0
  int v3; // w9

  result = _kmalloc_cache_noprof(mutex_unlock, 3520, 20);
  if ( !result )
    return -12;
  v3 = *a1;
  *(_QWORD *)(result + 4) = 0x1400000003LL;
  *(_DWORD *)result = v3;
  return result;
}
