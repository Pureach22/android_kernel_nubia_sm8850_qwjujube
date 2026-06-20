__int64 __fastcall kgsl_gpumem_sync_cache(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x8
  __int64 v6; // x3

  if ( !result )
    return result;
  v4 = *(_QWORD *)(result + 80);
  if ( (v4 & 8) != 0 )
    return 0;
  if ( (~a4 & 3) != 0 )
  {
    if ( (a4 & 1) != 0 )
    {
      v6 = 3;
      if ( a4 < 0 )
        goto LABEL_6;
    }
    else
    {
      if ( (a4 & 2) == 0 )
        return 4294967274LL;
      v6 = 1;
      if ( a4 < 0 )
        goto LABEL_6;
    }
    goto LABEL_5;
  }
  v6 = 2;
  if ( (a4 & 0x80000000) == 0 )
  {
LABEL_5:
    a3 = *(_QWORD *)(result + 48);
    a2 = 0;
  }
LABEL_6:
  if ( (v4 & 0x8000000) == 0 )
    return 0;
  return kgsl_cache_range_op(result + 8, a2, a3, v6);
}
