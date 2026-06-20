__int64 __fastcall mem_buf_construct_relinquish_msg(int *a1, int a2, int a3)
{
  __int64 result; // x0
  int v7; // w9

  result = _kmalloc_cache_noprof(mutex_unlock, 3520, 20);
  if ( !result )
    return -12;
  v7 = *a1;
  *(_DWORD *)(result + 12) = a3;
  *(_DWORD *)(result + 16) = a2;
  *(_QWORD *)(result + 4) = 0x1400000002LL;
  *(_DWORD *)result = v7;
  return result;
}
