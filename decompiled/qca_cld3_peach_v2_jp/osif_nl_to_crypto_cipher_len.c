__int64 __fastcall osif_nl_to_crypto_cipher_len(int a1)
{
  bool v2; // zf
  bool v3; // nf
  bool v4; // vf
  __int64 result; // x0
  unsigned int *v6; // x8

  v4 = __OFSUB__(a1, 1027079);
  v2 = a1 == 1027079;
  v3 = a1 - 1027079 < 0;
  result = 4294967274LL;
  if ( v3 ^ v4 | v2 )
  {
    if ( a1 > 1027075 )
    {
      switch ( a1 )
      {
        case 1027076:
          v6 = (unsigned int *)&unk_9DDE1C;
          break;
        case 1027077:
          v6 = (unsigned int *)&unk_9DDE28;
          break;
        case 1027078:
          v6 = (unsigned int *)&unk_9DDE58;
          break;
        default:
          return result;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 1:
          v6 = (unsigned int *)&osif_cipher_crypto_mapping;
          break;
        case 1027073:
          v6 = (unsigned int *)&unk_9DDE04;
          break;
        case 1027074:
          v6 = (unsigned int *)&unk_9DDE10;
          break;
        default:
          return result;
      }
    }
  }
  else if ( a1 <= 1027082 )
  {
    switch ( a1 )
    {
      case 1027080:
        v6 = (unsigned int *)&unk_9DDE34;
        break;
      case 1027081:
        v6 = (unsigned int *)&unk_9DDE40;
        break;
      case 1027082:
        v6 = (unsigned int *)&unk_9DDE4C;
        break;
      default:
        return result;
    }
  }
  else if ( a1 > 1027084 )
  {
    if ( a1 == 1027085 )
    {
      v6 = (unsigned int *)&unk_9DDE7C;
    }
    else
    {
      if ( a1 != 1339905 )
        return result;
      v6 = (unsigned int *)&unk_9DDE88;
    }
  }
  else if ( a1 == 1027083 )
  {
    v6 = (unsigned int *)&unk_9DDE64;
  }
  else
  {
    v6 = (unsigned int *)&unk_9DDE70;
  }
  return v6[2];
}
