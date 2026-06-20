__int64 __fastcall sde_hw_dspp_destroy(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    reg_dmav1_deinit_dspp_ops(result);
    reg_dmav1_deinit_ltm_ops(v1);
    return kfree(v1);
  }
  return result;
}
