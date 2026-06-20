__int64 __fastcall mmrm_client_check_scaling_supported(int a1)
{
  void *v2; // x0
  const char *v3; // x1

  if ( drv_data == -517 )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      return 0;
    printk(&unk_D2E8, "err ", "mmrm_client_check_scaling_supported");
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      return 0;
    v2 = &unk_CB69;
    v3 = "err ";
    goto LABEL_10;
  }
  if ( a1 || (*(_BYTE *)(drv_data + 8) & 1) != 0 )
    return 1;
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
    v2 = &unk_CEBE;
    v3 = "high";
LABEL_10:
    printk(v2, v3, "mmrm_client_check_scaling_supported");
  }
  return 0;
}
