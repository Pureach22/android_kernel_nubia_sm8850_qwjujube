__int64 __fastcall lim_process_ml_reconfig(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = *(_QWORD *)(a2 + 16);
  if ( result )
  {
    if ( *(unsigned __int16 *)(a3 + 40) >= 0xCu )
      return mlo_process_ml_reconfig_ie(result, 0);
  }
  return result;
}
