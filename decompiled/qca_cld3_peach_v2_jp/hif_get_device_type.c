__int64 __fastcall hif_get_device_type(int a1, unsigned int a2, int *a3, int *a4)
{
  int v5; // w9
  const char *v6; // x2
  __int64 result; // x0
  int v8; // w8
  int v9; // w9

  if ( a1 <= 28704 )
  {
    if ( a1 > 265 )
    {
      switch ( a1 )
      {
        case 4352:
          goto LABEL_41;
        case 4353:
          goto LABEL_37;
        case 4354:
          goto LABEL_21;
        case 4355:
          goto LABEL_45;
        case 4356:
          v5 = 26;
          *a3 = 21;
          v6 = "%s:  *********** QCN9000 *************";
          goto LABEL_68;
        case 4357:
          goto LABEL_44;
        case 4358:
        case 4363:
        case 4364:
        case 4365:
        case 4367:
          goto LABEL_54;
        case 4359:
          v5 = 31;
          *a3 = 26;
          v6 = "%s:  *********** KIWI *************";
          goto LABEL_68;
        case 4360:
          v5 = 38;
          *a3 = 33;
          v6 = "%s:  *********** WCN6450 *************";
          goto LABEL_68;
        case 4361:
          v5 = 32;
          *a3 = 27;
          v6 = "%s:  *********** QCN9224 *************";
          goto LABEL_68;
        case 4362:
          v5 = 34;
          *a3 = 29;
          v6 = "%s:  *********** MANGO *************";
          goto LABEL_68;
        case 4366:
          v5 = 37;
          *a3 = 32;
          v6 = "%s:  *********** PEACH *************";
          goto LABEL_68;
        case 4368:
          v5 = 40;
          *a3 = 35;
          v6 = "%s:  *********** WCN7750 *************";
          goto LABEL_68;
        case 4369:
          v5 = 43;
          *a3 = 38;
          v6 = "%s:  *********** FIG *************";
          goto LABEL_68;
        case 4370:
          v5 = 42;
          *a3 = 37;
          v6 = "%s:  *********** QCC2072 *************";
          goto LABEL_68;
        default:
          if ( a1 == 266 )
          {
LABEL_45:
            v5 = 27;
            *a3 = 22;
            v6 = "%s:  *********** QCA6490 *************";
          }
          else
          {
            if ( a1 != 268 )
              goto LABEL_54;
LABEL_44:
            v5 = 28;
            *a3 = 23;
            v6 = "%s:  *********** QCA6750 *************";
          }
          break;
      }
      goto LABEL_68;
    }
    if ( a1 > 69 )
    {
      if ( a1 > 85 )
      {
        if ( a1 == 86 )
        {
          v5 = 17;
          *a3 = 14;
          v6 = "%s:  *********** QCA9888 *************";
          goto LABEL_68;
        }
        if ( a1 == 264 )
        {
LABEL_37:
          v5 = 23;
          *a3 = 18;
          v6 = "%s:  *********** QCA6390 *************";
          goto LABEL_68;
        }
      }
      else
      {
        if ( a1 == 70 )
        {
          v5 = 15;
          *a3 = 12;
          v6 = "%s:  *********** QCA9984 *************";
          goto LABEL_68;
        }
        if ( a1 == 80 )
        {
          v5 = 7;
          *a3 = 6;
          v6 = "%s:  *********** AR9887 **************";
LABEL_68:
          *a4 = v5;
          qdf_trace_msg(61, 5, v6, "hif_get_device_type");
          result = 0;
          goto LABEL_69;
        }
      }
      goto LABEL_54;
    }
    if ( a1 != 60 )
    {
      if ( a1 != 62 )
      {
        if ( a1 == 64 )
        {
          v5 = 9;
          *a3 = 11;
          v6 = "%s:  *********** AR900B *************";
          goto LABEL_68;
        }
        goto LABEL_54;
      }
      if ( a2 <= 0x32 )
      {
        if ( ((1LL << a2) & 0x5000100000000LL) != 0 )
        {
          result = 0;
          v8 = 8;
          v9 = 12;
LABEL_75:
          *a3 = v8;
          *a4 = v9;
          return result;
        }
        if ( ((1LL << a2) & 0xA0000) != 0 )
        {
          result = 0;
          v8 = 7;
          v9 = 8;
          goto LABEL_75;
        }
      }
      qdf_trace_msg(61, 2, "%s: dev_id = 0x%x, rev_id = 0x%x", "hif_get_device_type", 62, a2);
      return 4294967277LL;
    }
    result = 0;
    v8 = 6;
    v9 = 7;
    goto LABEL_75;
  }
  if ( a1 > 43980 )
  {
    if ( a1 <= 65529 )
    {
      if ( a1 > 65526 )
      {
        if ( a1 == 65527 )
        {
          v5 = 39;
          *a3 = 34;
          v6 = "%s:  *********** QCN6432 *************";
        }
        else if ( a1 == 65528 )
        {
          v5 = 36;
          *a3 = 31;
          v6 = "%s:  *********** QCN9160 *************";
        }
        else
        {
          v5 = 35;
          *a3 = 30;
          v6 = "%s:  *********** QCA5332 *************";
        }
        goto LABEL_68;
      }
      if ( a1 == 43981 )
      {
LABEL_41:
        v5 = 21;
        *a3 = 16;
        v6 = "%s:  *********** QCA6290EMU *************";
        goto LABEL_68;
      }
      if ( a1 == 65526 )
      {
        v5 = 41;
        *a3 = 36;
        v6 = "%s:  *********** QCA5424 *************";
        goto LABEL_68;
      }
      goto LABEL_54;
    }
    if ( a1 <= 65532 )
    {
      if ( a1 == 65530 )
      {
        v5 = 33;
        *a3 = 28;
        v6 = "%s:  *********** QCA9574 *************";
      }
      else if ( a1 == 65531 )
      {
        v5 = 30;
        *a3 = 25;
        v6 = "%s:  *********** QCN6122 *************";
      }
      else
      {
        v5 = 29;
        *a3 = 24;
        v6 = "%s:  *********** qca5018 *************";
      }
      goto LABEL_68;
    }
    if ( a1 != 65533 )
    {
      if ( a1 == 65534 )
      {
        v5 = 24;
        *a3 = 19;
        v6 = "%s:  *********** QCA8074V2 *************";
        goto LABEL_68;
      }
      if ( a1 == 0xFFFF )
      {
        v5 = 20;
        *a3 = 15;
        v6 = "%s:  *********** QCA8074  *************";
        goto LABEL_68;
      }
      goto LABEL_54;
    }
LABEL_34:
    v5 = 25;
    *a3 = 20;
    v6 = "%s:  *********** QCA6018 *************";
    goto LABEL_68;
  }
  if ( a1 > 43535 )
  {
    if ( (unsigned int)(a1 - 43968) >= 4 && (unsigned int)(a1 - 43536) >= 2 )
      goto LABEL_54;
    goto LABEL_34;
  }
  if ( (unsigned int)(a1 - 39168) < 4 )
  {
LABEL_21:
    v5 = 22;
    *a3 = 17;
    v6 = "%s:  *********** QCN7605 *************";
    goto LABEL_68;
  }
  if ( a1 == 28705 )
  {
    result = 0;
    v8 = 10;
    v9 = 19;
    goto LABEL_75;
  }
LABEL_54:
  qdf_trace_msg(61, 2, "%s: Unsupported device ID = 0x%x!", "hif_get_device_type", a1);
  result = 4294967277LL;
LABEL_69:
  if ( *a4 )
    return result;
  qdf_trace_msg(61, 2, "%s: Unsupported target_type!", "hif_get_device_type");
  return 4294967277LL;
}
