__int64 __fastcall qcom_flash_brightness_set(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w10
  __int64 result; // x0
  unsigned int v5; // w9

  v2 = *(_DWORD *)(a1 + 528);
  result = 0;
  v5 = a2 / 0x3E8;
  if ( v2 < a2 / 0x3E8 )
    v5 = v2;
  *(_DWORD *)(a1 + 540) = v5;
  return result;
}
