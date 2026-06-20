__int64 __fastcall sde_hw_merge_3d_setup_blend_mode(__int64 result, int a2)
{
  unsigned int v2; // w2

  if ( result )
  {
    if ( a2 )
      v2 = 2 * a2 - 1;
    else
      v2 = 0;
    return sde_reg_write(result, 4u, v2, "MERGE_3D_MODE");
  }
  return result;
}
