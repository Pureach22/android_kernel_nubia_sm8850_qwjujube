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
        v1 = &unk_9DDD58;
        goto LABEL_26;
      case 1027075:
        v1 = &unk_9DDD80;
        goto LABEL_26;
      case 1027076:
        v1 = &unk_9DDD88;
        goto LABEL_26;
      case 1027077:
        v1 = &unk_9DDD60;
        goto LABEL_26;
      case 1027078:
        v1 = &unk_9DDD68;
        goto LABEL_26;
      case 1027080:
        v1 = &unk_9DDD70;
        goto LABEL_26;
      case 1027081:
        v1 = &unk_9DDD78;
        goto LABEL_26;
      case 1027083:
        v1 = &unk_9DDDA0;
        goto LABEL_26;
      case 1027084:
        v1 = &unk_9DDDA8;
        goto LABEL_26;
      case 1027086:
        v1 = &unk_9DDDB0;
        goto LABEL_26;
      case 1027087:
        v1 = &unk_9DDDB8;
        goto LABEL_26;
      case 1027088:
        v1 = &unk_9DDDC0;
        goto LABEL_26;
      case 1027089:
        v1 = &unk_9DDDC8;
        goto LABEL_26;
      case 1027090:
        v1 = &unk_9DDDD0;
        goto LABEL_26;
      case 1027093:
        v1 = &unk_9DDDF0;
        goto LABEL_26;
      case 1027096:
        v1 = &unk_9DDDE0;
        goto LABEL_26;
      case 1027097:
        v1 = &unk_9DDDE8;
        goto LABEL_26;
      default:
        goto LABEL_28;
    }
  }
  switch ( a1 )
  {
    case 4232704:
      v1 = &unk_9DDD90;
      break;
    case 1349491201:
      v1 = &unk_9DDD98;
      break;
    case 1349491202:
      v1 = &unk_9DDDD8;
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
