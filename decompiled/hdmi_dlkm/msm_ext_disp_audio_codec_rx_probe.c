__int64 __fastcall msm_ext_disp_audio_codec_rx_probe(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x0
  __int64 device_by_node; // x0
  __int64 result; // x0

  v2 = (__int64 *)_kmalloc_cache_noprof(of_get_parent, 3520, 176);
  v3 = *(_QWORD *)(a1 + 24);
  if ( !v2 )
  {
    dev_err(v3, "%s(): fail to allocate dai data\n", "msm_ext_disp_audio_codec_rx_probe");
    return 4294967284LL;
  }
  if ( !of_get_parent(*(_QWORD *)(v3 + 744)) )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s(): Parent device tree node not found\n", "msm_ext_disp_audio_codec_rx_probe");
LABEL_10:
    kfree(v2);
    return 4294967277LL;
  }
  device_by_node = of_find_device_by_node();
  *v2 = device_by_node;
  if ( !device_by_node )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s(): can't get parent pdev\n", "msm_ext_disp_audio_codec_rx_probe");
    goto LABEL_10;
  }
  if ( (unsigned int)msm_ext_disp_register_audio_codec(device_by_node, v2 + 1) )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s(): can't register with ext disp core", "msm_ext_disp_audio_codec_rx_probe");
    goto LABEL_10;
  }
  _mutex_init(v2 + 8, "&codec_data->dp_ops_lock", &msm_ext_disp_audio_codec_rx_probe___key);
  result = 0;
  *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL) = v2;
  return result;
}
