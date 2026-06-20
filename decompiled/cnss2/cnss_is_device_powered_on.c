bool __fastcall cnss_is_device_powered_on(__int64 a1)
{
  return *(_BYTE *)(a1 + 6513) != 0;
}
