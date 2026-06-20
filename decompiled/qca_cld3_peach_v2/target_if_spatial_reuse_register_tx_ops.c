_QWORD *__fastcall target_if_spatial_reuse_register_tx_ops(_QWORD *result)
{
  result[274] = spatial_reuse_send_cfg;
  result[275] = spatial_reuse_send_sr_prohibit_cfg;
  result[276] = spatial_reuse_set_sr_enable_disable;
  result[277] = spatial_reuse_send_pd_threshold;
  return result;
}
