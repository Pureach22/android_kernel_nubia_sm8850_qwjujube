const char *__fastcall ipa3_usb_teth_prot_to_string(unsigned int a1)
{
  if ( a1 > 5 )
    return "unsupported";
  else
    return off_1E5248[a1];
}
