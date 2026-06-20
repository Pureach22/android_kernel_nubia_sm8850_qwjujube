__int64 __fastcall sde_hw_ctl_clear_all_blendstages(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x25
  __int64 v3; // x26
  int v4; // w8
  int v5; // w28
  __int64 v6; // x1

  if ( result )
  {
    v1 = result;
    result = sde_reg_write(result, 252, 0, "CTL_FETCH_PIPE_ACTIVE");
    if ( *(int *)(v1 + 80) >= 1 )
    {
      v2 = 0;
      v3 = 16;
      do
      {
        v4 = *(_DWORD *)(*(_QWORD *)(v1 + 88) + v3);
        if ( v4 > 8 )
          break;
        v5 = 4 * v4;
        v6 = v4 == 6 ? 36LL : (unsigned int)(4 * v4 - 4);
        sde_reg_write(v1, v6, 0, "CTL_LAYER(mixer_id)");
        sde_reg_write(v1, (unsigned int)(v5 + 60), 0, "CTL_LAYER_EXT(mixer_id)");
        sde_reg_write(v1, (unsigned int)(v5 + 108), 0, "CTL_LAYER_EXT2(mixer_id)");
        sde_reg_write(v1, (unsigned int)(v5 + 156), 0, "CTL_LAYER_EXT3(mixer_id)");
        result = sde_reg_write(v1, (unsigned int)(v5 + 180), 0, "CTL_LAYER_EXT4(mixer_id)");
        ++v2;
        v3 += 96;
      }
      while ( v2 < *(int *)(v1 + 80) );
    }
  }
  return result;
}
