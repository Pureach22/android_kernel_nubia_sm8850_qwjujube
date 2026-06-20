bool __fastcall kgsl_genpd_is_enabled(unsigned __int64 a1)
{
  _BOOL8 result; // x0
  unsigned __int64 v3; // x8

  result = 0;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v3 = *(_QWORD *)(a1 + 592);
      result = 0;
      if ( v3 )
      {
        if ( v3 <= 0xFFFFFFFFFFFFF000LL )
          return *(_DWORD *)(v3 + 388) == 0;
      }
    }
  }
  return result;
}
