__int64 __fastcall lt9611uxc_firmware_cb(__int64 a1, __int64 a2)
{
  if ( !a1 )
    return printk(&unk_B32F, "lt9611uxc_firmware_cb");
  ((void (__fastcall *)(__int64, __int64))lt9611uxc_firmware_upgrade)(a2, a1);
  return release_firmware(a1);
}
