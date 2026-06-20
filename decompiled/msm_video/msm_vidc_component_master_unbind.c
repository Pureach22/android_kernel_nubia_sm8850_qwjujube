__int64 __fastcall msm_vidc_component_master_unbind(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_unbind");
  if ( *(_BYTE *)(v1 + 4768) == 1 )
    *(_BYTE *)(v1 + 4770) = 1;
  msm_vidc_core_deinit(v1, 1);
  synchronize_irq(*(unsigned int *)(*(_QWORD *)(v1 + 3904) + 8LL));
  venus_hfi_queue_deinit(v1);
  media_device_unregister(v1 + 2832);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_9181F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_unregister_video_device");
  v4l2_m2m_unregister_media_controller(*(_QWORD *)(v1 + 2704));
  v4l2_m2m_release(*(_QWORD *)(v1 + 2704));
  *(_QWORD *)(v1 + 1704) = 0;
  video_unregister_device(v1 + 1368);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_9181F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_unregister_video_device");
  v4l2_m2m_unregister_media_controller(*(_QWORD *)(v1 + 1352));
  v4l2_m2m_release(*(_QWORD *)(v1 + 1352));
  *(_QWORD *)(v1 + 352) = 0;
  video_unregister_device(v1 + 16);
  media_device_cleanup(v1 + 2832);
  v4l2_device_unregister(v1 + 2712);
  result = component_unbind_all(a1, v1);
  if ( (msm_vidc_debug & 2) != 0 )
    return printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_unbind");
  return result;
}
