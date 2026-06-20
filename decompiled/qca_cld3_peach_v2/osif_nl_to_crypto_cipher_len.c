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
          v6 = (unsigned int *)&unk_ACFA14;
          break;
        case 1027077:
          v6 = (unsigned int *)&unk_ACFA20;
          break;
        case 1027078:
          v6 = (unsigned int *)&unk_ACFA50;
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
          v6 = (unsigned int *)&unk_ACF9FC;
          break;
        case 1027074:
          v6 = (unsigned int *)&unk_ACFA08;
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
        v6 = (unsigned int *)&unk_ACFA2C;
        break;
      case 1027081:
        v6 = (unsigned int *)&unk_ACFA38;
        break;
      case 1027082:
        v6 = (unsigned int *)&unk_ACFA44;
        break;
      default:
        return result;
    }
  }
  else if ( a1 > 1027084 )
  {
    if ( a1 == 1027085 )
    {
      v6 = (unsigned int *)&unk_ACFA74;
    }
    else
    {
      if ( a1 != 1339905 )
        return result;
      v6 = (unsigned int *)&unk_ACFA80;
    }
  }
  else if ( a1 == 1027083 )
  {
    v6 = (unsigned int *)&unk_ACFA5C;
  }
  else
  {
    v6 = (unsigned int *)&unk_ACFA68;
  }
  return v6[2];
}
