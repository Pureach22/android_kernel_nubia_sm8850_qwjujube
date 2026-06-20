__int64 __fastcall qcom_adreno_smmuv2_cfg_probe(__int64 a1)
{
  *(_DWORD *)(a1 + 32) &= ~0x100u;
  return 0;
}
