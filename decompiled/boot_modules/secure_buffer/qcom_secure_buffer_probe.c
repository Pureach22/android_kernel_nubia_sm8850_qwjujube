__int64 __fastcall qcom_secure_buffer_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 property; // x8

  v1 = a1 + 16;
  result = dma_set_mask(a1 + 16, -1);
  if ( !(_DWORD)result )
  {
    v4 = *(_QWORD *)(a1 + 760);
    qcom_secure_buffer_dev = v1;
    property = of_find_property(v4, "qcom,vmid-cp-camera-preview-ro", 0);
    vmid_cp_camera_preview_ro = property != 0;
    return 0;
  }
  return result;
}
