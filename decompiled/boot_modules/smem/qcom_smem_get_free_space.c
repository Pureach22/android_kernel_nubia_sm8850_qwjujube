unsigned __int64 __fastcall qcom_smem_get_free_space(unsigned int a1)
{
  __int64 v1; // x9
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // t1
  unsigned __int64 result; // x0
  __int64 v6; // x9

  if ( !_smem )
    return 4294966779LL;
  if ( a1 <= 0x18 )
  {
    v1 = _smem + 32LL * a1;
    v4 = *(_QWORD *)(v1 + 72);
    v2 = v1 + 72;
    v3 = v4;
    if ( v4 )
    {
      result = (unsigned int)(*(_DWORD *)(v3 + 16) - *(_DWORD *)(v3 + 12));
      if ( (unsigned int)result <= *(_DWORD *)(v2 + 24) )
        return result;
      return 4294967274LL;
    }
  }
  v6 = *(_QWORD *)(_smem + 40);
  if ( v6 )
  {
    result = (unsigned int)(*(_DWORD *)(v6 + 16) - *(_DWORD *)(v6 + 12));
    if ( (unsigned int)result > *(_DWORD *)(_smem + 64) )
      return 4294967274LL;
  }
  else
  {
    result = *(unsigned int *)(*(_QWORD *)(_smem + 888) + 200LL);
    if ( *(_QWORD *)(_smem + 896) < result )
      return 4294967274LL;
  }
  return result;
}
