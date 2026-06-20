_QWORD *__fastcall wlan_lmac_if_sptrl_register_rx_ops(_QWORD *result)
{
  result[32] = tgt_get_pdev_target_handle;
  result[33] = tgt_get_psoc_target_handle;
  result[34] = spectral_vdev_get_chan_freq;
  result[35] = spectral_vdev_get_chan_freq_seg2;
  result[36] = spectral_vdev_get_ch_width;
  result[37] = spectral_vdev_get_sec20chan_freq_mhz;
  result[38] = wlan_spectral_is_feature_disabled_pdev;
  result[39] = wlan_spectral_is_feature_disabled_psoc;
  result[40] = tgt_spectral_scan_complete_event;
  return result;
}
