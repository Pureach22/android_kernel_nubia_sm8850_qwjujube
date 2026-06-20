__int64 __fastcall osif_crypto_to_nl_suites(unsigned int a1)
{
  unsigned int v1; // w19

  if ( a1 < 0x1E && ((0x38FFCDE3u >> a1) & 1) != 0 )
  {
    v1 = *(_DWORD *)*(&off_ACFA90 + a1);
    qdf_trace_msg(72, 8, "%s: Akm suite, crypto: %d -> NL: 0x%x", "osif_crypto_to_nl_suites", a1, v1);
    return v1;
  }
  else
  {
    qdf_trace_msg(72, 8, "%s: Unknown crypto type: %d", "osif_crypto_to_nl_suites", a1);
    return 0;
  }
}
