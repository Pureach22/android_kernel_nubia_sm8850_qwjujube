__int64 __fastcall mem_buf_construct_alloc_resp(int *a1, int a2, int a3, int a4)
{
  __int64 result; // x0
  int v9; // w8

  result = _kmalloc_cache_noprof(mutex_unlock, 3520, 24);
  if ( !result )
    return -12;
  v9 = *a1;
  *(_DWORD *)(result + 12) = a2;
  *(_DWORD *)(result + 16) = a3;
  *(_DWORD *)(result + 20) = a4;
  *(_QWORD *)(result + 4) = 0x1800000001LL;
  *(_DWORD *)result = v9;
  return result;
}
