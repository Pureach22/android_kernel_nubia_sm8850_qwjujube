const char *__fastcall ipa_get_version_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x14 )
    return "Invalid version";
  else
    return (const char *)*(&off_1E4090 + (unsigned int)(a1 - 1));
}
