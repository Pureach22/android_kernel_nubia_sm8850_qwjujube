__int64 __fastcall mem_buf_alloc_fd(__int64 a1)
{
  unsigned int v1; // w8
  __int64 result; // x0
  _QWORD v4[11]; // [xsp+8h] [xbp-58h] BYREF

  v4[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)a1 )
    goto LABEL_12;
  v1 = *(_DWORD *)(a1 + 16);
  if ( !v1 )
    goto LABEL_12;
  result = 4294967274LL;
  if ( v1 <= 0x10 )
  {
    if ( *(_QWORD *)(a1 + 8) )
    {
      if ( *(_DWORD *)(a1 + 20) == 1
        && *(_DWORD *)(a1 + 32) == 1
        && !*(_QWORD *)(a1 + 48)
        && !*(_QWORD *)(a1 + 56)
        && !*(_QWORD *)(a1 + 64) )
      {
        memset(v4, 0, 80);
        result = mem_buf_prep_alloc_data(v4);
        if ( (result & 0x80000000) == 0 )
        {
          mem_buf_free_alloc_data(v4);
LABEL_12:
          result = 4294967274LL;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
