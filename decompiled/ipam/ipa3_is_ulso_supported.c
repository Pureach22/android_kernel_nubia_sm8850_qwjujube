__int64 ipa3_is_ulso_supported()
{
  char v0; // w8

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
    v0 = *(_BYTE *)(ipa3_ctx + 51097);
  return v0 & 1;
}
