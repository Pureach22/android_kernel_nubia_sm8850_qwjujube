__int64 __fastcall sde_hw_sspp_setup_scaler_cac(__int64 result, int *a2)
{
  if ( result )
  {
    if ( a2 )
      return sde_hw_setup_scaler_cac(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 100LL), a2);
  }
  return result;
}
