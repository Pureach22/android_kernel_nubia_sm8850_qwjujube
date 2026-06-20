__int64 __fastcall sde_hw_merge_3d_reset_blend_mode(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    sde_reg_write(result, 4u, 0, "MERGE_3D_MODE");
    return sde_reg_write(v1, 0, 0, "MERGE_3D_MUX");
  }
  return result;
}
