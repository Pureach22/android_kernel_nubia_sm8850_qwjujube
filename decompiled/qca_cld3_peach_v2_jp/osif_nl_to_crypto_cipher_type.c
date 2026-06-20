__int64 __fastcall osif_nl_to_crypto_cipher_type(int a1)
{
  _DWORD *v1; // x8
  unsigned int v2; // w19

  if ( a1 > 1027079 )
  {
    if ( a1 <= 1027082 )
    {
      if ( a1 == 1027080 )
      {
        v1 = &unk_9DDE34;
      }
      else if ( a1 == 1027081 )
      {
        v1 = &unk_9DDE40;
      }
      else
      {
        v1 = &unk_9DDE4C;
      }
      goto LABEL_29;
    }
    if ( a1 <= 1027084 )
    {
      if ( a1 == 1027083 )
        v1 = &unk_9DDE64;
      else
        v1 = &unk_9DDE70;
      goto LABEL_29;
    }
    if ( a1 == 1027085 )
    {
      v1 = &unk_9DDE7C;
      goto LABEL_29;
    }
    if ( a1 == 1339905 )
    {
      v1 = &unk_9DDE88;
      goto LABEL_29;
    }
LABEL_31:
    qdf_trace_msg(72, 2, "%s: Unknown type: %d", "osif_nl_to_crypto_cipher_type", a1);
    return 19;
  }
  if ( a1 > 1027075 )
  {
    if ( a1 == 1027076 )
    {
      v1 = &unk_9DDE1C;
      goto LABEL_29;
    }
    if ( a1 == 1027077 )
    {
      v1 = &unk_9DDE28;
      goto LABEL_29;
    }
    if ( a1 != 1027078 )
      goto LABEL_31;
    v1 = &unk_9DDE58;
  }
  else
  {
    if ( a1 == 1 )
    {
      v1 = &osif_cipher_crypto_mapping;
      goto LABEL_29;
    }
    if ( a1 == 1027073 )
    {
      v1 = &unk_9DDE04;
      goto LABEL_29;
    }
    if ( a1 != 1027074 )
      goto LABEL_31;
    v1 = &unk_9DDE10;
  }
LABEL_29:
  v2 = v1[1];
  qdf_trace_msg(72, 8, "%s: Cipher suite, NL: %d, crypto: %d", "osif_nl_to_crypto_cipher_type", a1, v2);
  return v2;
}
