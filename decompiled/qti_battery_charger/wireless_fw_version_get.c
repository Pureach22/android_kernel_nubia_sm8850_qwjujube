unsigned __int64 __fastcall wireless_fw_version_get(__int64 a1, unsigned __int16 *a2, char a3)
{
  unsigned __int64 result; // x0
  const char *v4; // x20

  if ( (a3 & 1) != 0 )
    return 0xFFFFFFFFLL;
  v4 = *(const char **)(a1 + 536);
  if ( strstr(v4, "idt9412") )
    return a2[75] | (a2[74] << 16);
  if ( strstr(v4, "idt") )
    return a2[67] | (a2[66] << 16);
  result = (unsigned __int64)strstr(v4, "cps");
  if ( result )
    return bswap32(a2[98]) >> 16;
  return result;
}
