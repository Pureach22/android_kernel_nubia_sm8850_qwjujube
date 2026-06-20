__int64 __fastcall sde_hw_cdm_destroy(__int64 result)
{
  if ( result )
    return kfree(result);
  return result;
}
