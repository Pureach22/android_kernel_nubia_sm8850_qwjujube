__int64 __fastcall uaudio_qmi_plat_remove(__int64 a1)
{
  __int64 result; // x0

  snd_usb_unregister_platform_ops();
  iommu_detach_device(*(_QWORD *)(uaudio_qdev + 24), a1 + 16);
  result = iommu_domain_free(*(_QWORD *)(uaudio_qdev + 24));
  *(_QWORD *)(uaudio_qdev + 24) = 0;
  return result;
}
