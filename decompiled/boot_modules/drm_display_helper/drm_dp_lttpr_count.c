__int64 __fastcall drm_dp_lttpr_count(__int64 a1)
{
  unsigned int v1; // w19
  __int64 result; // x0

  v1 = *(unsigned __int8 *)(a1 + 2);
  result = _sw_hweight8(*(unsigned __int8 *)(a1 + 2));
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 8 )
    {
      return 4294967262LL;
    }
    else if ( (_DWORD)result == 1 )
    {
      return __clz(v1) - 23;
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
