__int64 __fastcall sde_hw_sspp_setup_inverse_pma(__int64 result, int a2, int a3)
{
  if ( result )
  {
    if ( a2 != 2 )
      return sde_reg_write(
               result,
               *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 1216LL),
               a3 != 0,
               "offset");
  }
  return result;
}
