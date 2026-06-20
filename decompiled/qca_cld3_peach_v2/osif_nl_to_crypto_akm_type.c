__int64 __fastcall osif_nl_to_crypto_akm_type(int a1)
{
  _DWORD *v1; // x8
  unsigned int v2; // w19

  if ( a1 <= 4232703 )
  {
    v1 = &osif_akm_type_crypto_mapping;
    switch ( a1 )
    {
      case 1027073:
        goto LABEL_26;
      case 1027074:
        v1 = &unk_ACF950;
        goto LABEL_26;
      case 1027075:
        v1 = &unk_ACF978;
        goto LABEL_26;
      case 1027076:
        v1 = &unk_ACF980;
        goto LABEL_26;
      case 1027077:
        v1 = &unk_ACF958;
        goto LABEL_26;
      case 1027078:
        v1 = &unk_ACF960;
        goto LABEL_26;
      case 1027080:
        v1 = &unk_ACF968;
        goto LABEL_26;
      case 1027081:
        v1 = &unk_ACF970;
        goto LABEL_26;
      case 1027083:
        v1 = &unk_ACF998;
        goto LABEL_26;
      case 1027084:
        v1 = &unk_ACF9A0;
        goto LABEL_26;
      case 1027086:
        v1 = &unk_ACF9A8;
        goto LABEL_26;
      case 1027087:
        v1 = &unk_ACF9B0;
        goto LABEL_26;
      case 1027088:
        v1 = &unk_ACF9B8;
        goto LABEL_26;
      case 1027089:
        v1 = &unk_ACF9C0;
        goto LABEL_26;
      case 1027090:
        v1 = &unk_ACF9C8;
        goto LABEL_26;
      case 1027093:
        v1 = &unk_ACF9E8;
        goto LABEL_26;
      case 1027096:
        v1 = &unk_ACF9D8;
        goto LABEL_26;
      case 1027097:
        v1 = &unk_ACF9E0;
        goto LABEL_26;
      default:
        goto LABEL_28;
    }
  }
  switch ( a1 )
  {
    case 4232704:
      v1 = &unk_ACF988;
      break;
    case 1349491201:
      v1 = &unk_ACF990;
      break;
    case 1349491202:
      v1 = &unk_ACF9D0;
      break;
    default:
LABEL_28:
      v2 = 2;
      qdf_trace_msg(72, 2, "%s: Unknown type: %d", "osif_nl_to_crypto_akm_type", a1);
      return v2;
  }
LABEL_26:
  v2 = v1[1];
  qdf_trace_msg(72, 8, "%s: Akm suite, NL: %d, crypto: %d", "osif_nl_to_crypto_akm_type", a1, v2);
  return v2;
}
