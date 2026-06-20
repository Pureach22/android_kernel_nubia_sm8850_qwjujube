__int64 __fastcall mmrm_client_register(_DWORD *a1)
{
  void *v1; // x0
  __int64 result; // x0
  void *v3; // x0
  const char *v4; // x1

  if ( !a1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v1 = &unk_CCFF;
LABEL_21:
      printk(v1, "err ", "mmrm_client_register");
    }
LABEL_9:
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      return 0;
    v3 = &unk_CB69;
    v4 = "err ";
LABEL_19:
    printk(v3, v4, "mmrm_client_register");
    return 0;
  }
  if ( drv_data == -517 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v1 = &unk_D2E8;
      goto LABEL_21;
    }
    goto LABEL_9;
  }
  if ( *a1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_E269, "err ", "mmrm_client_register");
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(drv_data + 8) & 1) == 0 )
  {
    if ( (~msm_mmrm_debug & 0x10002) != 0 )
      return 0;
    v3 = &unk_CEBE;
    v4 = "high";
    goto LABEL_19;
  }
  result = mmrm_clk_client_register(*(_QWORD *)(drv_data + 96), (__int64)a1);
  if ( !result )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v1 = &unk_C8DE;
      goto LABEL_21;
    }
    goto LABEL_9;
  }
  return result;
}
