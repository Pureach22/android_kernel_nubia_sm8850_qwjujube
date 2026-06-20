__int64 __fastcall dsi_hfi_prop_handler(int a1, int a2, _DWORD *a3, int a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v8; // x22
  __int64 result; // x0

  if ( !a5 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid listener\n");
  v5 = a5 - 1696;
  if ( a5 == 1696 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid object or listener from FW\n");
  v8 = *(_QWORD *)(a5 - 8);
  result = strcmp(*(const char **)(a5 - 1656), "primary");
  if ( (_DWORD)result != a1 )
    return drm_dev_printk(
             0,
             &unk_248D72,
             "*ERROR* [msm-dsi-error]: Component and HFI ID mismatch (%d != %d)\n",
             result,
             a1);
  if ( a2 <= 33554440 )
  {
    if ( (unsigned int)(a2 - 33554438) < 2 )
      return result;
    if ( a2 == -16777208 )
      return dsi_hfi_process_misr_read(v5, a3, a4);
    if ( a2 == 33554440 )
      return msleep(20);
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid HFI property 0x%x\n", a2);
  }
  if ( a2 <= 33554443 )
  {
    if ( (unsigned int)(a2 - 33554441) >= 2 )
    {
      if ( a3 )
        *(_BYTE *)(v8 + 80) = 1;
    }
    return result;
  }
  if ( a2 != 33554444 )
  {
    if ( a2 == 33554445 )
      return result;
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid HFI property 0x%x\n", a2);
  }
  result = dsi_display_hfi_power_supplies(v5, (unsigned int)*a3, (*a3 >> 8) & 1);
  if ( (_DWORD)result )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Could not power on supplies\n");
  return result;
}
