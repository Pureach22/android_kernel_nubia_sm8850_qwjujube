__int64 __fastcall sde_hw_pp_get_caps(__int64 result)
{
  if ( result )
    return *(_QWORD *)(*(_QWORD *)(result + 40) + 32LL);
  return result;
}
