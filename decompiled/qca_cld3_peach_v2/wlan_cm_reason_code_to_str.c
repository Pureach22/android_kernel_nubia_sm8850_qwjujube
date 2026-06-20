const char *__fastcall wlan_cm_reason_code_to_str(unsigned int a1)
{
  if ( a1 > 0xFFEB )
    return (const char *)&unk_98C763;
  if ( (unsigned __int16)(a1 - 1) > 0x46u )
    return "Unknown";
  return off_AD2030[(unsigned __int16)(a1 - 1)];
}
