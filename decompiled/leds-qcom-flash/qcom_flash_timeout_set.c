__int64 __fastcall qcom_flash_timeout_set(__int64 a1, unsigned int a2)
{
  *(_DWORD *)(a1 + 544) = a2 / 0x3E8;
  return 0;
}
