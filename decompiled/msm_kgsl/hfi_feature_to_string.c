const char *__fastcall hfi_feature_to_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x1C )
    return "unknown";
  else
    return off_14F830[a1 - 1];
}
