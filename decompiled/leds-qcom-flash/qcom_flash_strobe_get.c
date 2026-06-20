__int64 __fastcall qcom_flash_strobe_get(__int64 a1, _BYTE *a2)
{
  char v2; // w8

  v2 = *(_BYTE *)(a1 + 561);
  *a2 = v2;
  return 0;
}
