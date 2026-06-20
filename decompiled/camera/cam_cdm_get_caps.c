__int64 __fastcall cam_cdm_get_caps(__int64 a1, _QWORD *a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x8

  if ( !a1 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a3 == 8 && a2 )
  {
    v5 = *(_QWORD *)(a1 + 3680);
    if ( v5 )
    {
      *a2 = *(_QWORD *)(v5 + 224);
      return 0;
    }
  }
  return result;
}
