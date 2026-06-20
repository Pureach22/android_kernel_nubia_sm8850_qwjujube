_QWORD *__fastcall target_if_spatial_reuse_register_tx_ops(_QWORD *result)
{
  result[261] = spatial_reuse_send_cfg;
  result[262] = spatial_reuse_send_sr_prohibit_cfg;
  result[263] = spatial_reuse_set_sr_enable_disable;
  result[264] = spatial_reuse_send_pd_threshold;
  return result;
}
