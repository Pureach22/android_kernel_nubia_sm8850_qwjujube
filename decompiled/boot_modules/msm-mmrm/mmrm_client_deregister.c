__int64 __fastcall mmrm_client_deregister(_DWORD *a1)
{
  __int64 result; // x0
  unsigned int v2; // w20
  void *v3; // x0
  unsigned int v4; // w19

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_9;
    v2 = -22;
    v3 = &unk_D317;
    goto LABEL_20;
  }
  if ( drv_data == -517 )
  {
    result = 0;
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_9;
    v2 = 0;
    v3 = &unk_D2E8;
    goto LABEL_20;
  }
  if ( *a1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_E269, "err ", "mmrm_client_deregister");
    return 0;
  }
  if ( (*(_BYTE *)(drv_data + 8) & 1) == 0 )
  {
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      printk(&unk_CEBE, "high", "mmrm_client_deregister");
    return 0;
  }
  result = mmrm_clk_client_deregister(*(_QWORD *)(drv_data + 96));
  if ( !(_DWORD)result )
    return result;
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v2 = result;
    v3 = &unk_D1AC;
LABEL_20:
    printk(v3, "err ", "mmrm_client_deregister");
    result = v2;
  }
LABEL_9:
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v4 = result;
    printk(&unk_DA62, "err ", "mmrm_client_deregister");
    return v4;
  }
  return result;
}
