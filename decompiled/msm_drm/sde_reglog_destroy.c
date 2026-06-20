__int64 __fastcall sde_reglog_destroy(__int64 result)
{
  if ( result )
    return vfree(result);
  return result;
}
