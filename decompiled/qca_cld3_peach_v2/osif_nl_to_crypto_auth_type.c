__int64 __fastcall osif_nl_to_crypto_auth_type(unsigned int a1)
{
  unsigned int v1; // w19

  if ( a1 < 9 )
  {
    v1 = osif_auth_type_crypto_mapping[a1];
    qdf_trace_msg(72, 8, "%s: Auth type, NL: %d, crypto: %d", "osif_nl_to_crypto_auth_type", a1, v1);
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Unknown type: %d", "osif_nl_to_crypto_auth_type", a1);
    return 0;
  }
  return v1;
}
