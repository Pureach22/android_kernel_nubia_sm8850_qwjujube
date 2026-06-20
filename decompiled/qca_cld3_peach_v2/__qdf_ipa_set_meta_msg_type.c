_BYTE *__fastcall _qdf_ipa_set_meta_msg_type(_BYTE *result, unsigned int a2)
{
  if ( a2 > 0xD )
    *result = 15;
  else
    *result = byte_B2D780[a2];
  return result;
}
