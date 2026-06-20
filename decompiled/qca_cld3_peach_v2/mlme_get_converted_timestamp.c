__int64 __fastcall mlme_get_converted_timestamp(unsigned int a1, char *s)
{
  return snprintf(
           s,
           0x18u,
           "[%02d:%02d:%02d.%06u]",
           (unsigned __int16)(a1 / 0x36EE80 - 24 * ((2731 * (a1 / 0x36EE80)) >> 16)),
           a1 / 0xEA60 - 60 * ((71582789 * (unsigned __int64)(a1 / 0xEA60)) >> 32),
           a1 / 0x3E8 - 60 * ((71582789 * (unsigned __int64)(a1 / 0x3E8)) >> 32),
           1000 * (a1 % 0x3E8));
}
