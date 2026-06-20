_QWORD *__fastcall sde_dsc1_2_setup_ops(_QWORD *result)
{
  *result = sde_hw_dsc_disable_0;
  result[3] = sde_hw_dsc_config_0;
  result[6] = sde_hw_dsc_config_thresh_0;
  result[9] = sde_hw_dsc_bind_pingpong_blk_0;
  return result;
}
