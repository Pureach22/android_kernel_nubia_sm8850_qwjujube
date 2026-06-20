__int64 __fastcall gh_rm_alloc_mem_request_buf(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 *a5)
{
  int v5; // w8
  __int64 v7; // x19
  __int64 result; // x0

  v5 = a1 - 1358954512;
  if ( (unsigned int)(a1 - 1358954512) > 0xA || ((0x40Fu >> v5) & 1) == 0 )
    return -22;
  v7 = 4 * (a4 + a2) + 16 * a3 + qword_14180[v5] + 12;
  result = _kmalloc_noprof(v7, 3520);
  if ( !result )
    return -12;
  *a5 = v7;
  return result;
}
