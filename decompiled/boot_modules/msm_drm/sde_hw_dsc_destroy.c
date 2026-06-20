__int64 __fastcall sde_hw_dsc_destroy(__int64 result)
{
  if ( result )
    return kfree(result);
  return result;
}
