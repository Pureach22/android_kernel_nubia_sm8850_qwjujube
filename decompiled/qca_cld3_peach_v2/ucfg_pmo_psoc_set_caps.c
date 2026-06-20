__int64 __fastcall ucfg_pmo_psoc_set_caps(__int64 a1, const void *a2)
{
  __int64 result; // x0

  result = 4;
  if ( a1 )
  {
    if ( a2 )
    {
      pmo_psoc_set_caps(a1, a2);
      return 0;
    }
  }
  return result;
}
