__int64 __fastcall compat_ipa3_ioctl(int a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // w8
  int v5; // w8
  _QWORD v7[3]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v8; // [xsp+18h] [xbp-48h]
  __int64 v9; // [xsp+20h] [xbp-40h]
  __int64 v10; // [xsp+28h] [xbp-38h]
  __int64 v11; // [xsp+30h] [xbp-30h] BYREF
  __int64 v12; // [xsp+38h] [xbp-28h]
  __int64 v13; // [xsp+40h] [xbp-20h]
  __int64 v14; // [xsp+48h] [xbp-18h]
  __int64 v15; // [xsp+50h] [xbp-10h]
  __int64 v16; // [xsp+58h] [xbp-8h]

  result = -515;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  if ( (int)a2 <= 52997 )
  {
    switch ( (unsigned int)a2 )
    {
      case 0xC004CF00:
        a2 = 3221802752LL;
        goto LABEL_51;
      case 0xC004CF01:
        v5 = -1073164544;
        goto LABEL_46;
      case 0xC004CF02:
        a2 = 3221802754LL;
        goto LABEL_51;
      case 0xC004CF03:
        a2 = 3221802755LL;
        goto LABEL_51;
      case 0xC004CF04:
        a2 = 3221802756LL;
        goto LABEL_51;
      case 0xC004CF05:
        v4 = 5;
        goto LABEL_50;
      case 0xC004CF06:
      case 0xC004CF07:
      case 0xC004CF08:
      case 0xC004CF09:
      case 0xC004CF0A:
      case 0xC004CF0B:
      case 0xC004CF0C:
      case 0xC004CF0E:
      case 0xC004CF14:
      case 0xC004CF15:
      case 0xC004CF21:
      case 0xC004CF28:
      case 0xC004CF29:
      case 0xC004CF2B:
      case 0xC004CF2C:
      case 0xC004CF2D:
      case 0xC004CF2E:
      case 0xC004CF2F:
      case 0xC004CF30:
      case 0xC004CF31:
      case 0xC004CF32:
      case 0xC004CF38:
      case 0xC004CF39:
      case 0xC004CF3A:
      case 0xC004CF3B:
      case 0xC004CF3C:
      case 0xC004CF3D:
      case 0xC004CF3E:
      case 0xC004CF3F:
      case 0xC004CF40:
      case 0xC004CF41:
      case 0xC004CF42:
      case 0xC004CF43:
      case 0xC004CF44:
      case 0xC004CF45:
      case 0xC004CF46:
      case 0xC004CF47:
      case 0xC004CF48:
      case 0xC004CF49:
      case 0xC004CF4A:
      case 0xC004CF4B:
      case 0xC004CF4C:
      case 0xC004CF4D:
      case 0xC004CF50:
      case 0xC004CF51:
      case 0xC004CF52:
      case 0xC004CF53:
      case 0xC004CF54:
      case 0xC004CF55:
      case 0xC004CF56:
      case 0xC004CF57:
      case 0xC004CF5A:
      case 0xC004CF5B:
      case 0xC004CF5C:
      case 0xC004CF5D:
        goto LABEL_52;
      case 0xC004CF0D:
        v4 = 13;
        goto LABEL_50;
      case 0xC004CF0F:
        a2 = 3221802767LL;
        goto LABEL_51;
      case 0xC004CF10:
        a2 = 3221802768LL;
        goto LABEL_51;
      case 0xC004CF11:
        v4 = 17;
        goto LABEL_50;
      case 0xC004CF12:
        v4 = 18;
        goto LABEL_50;
      case 0xC004CF13:
        v4 = 19;
        goto LABEL_50;
      case 0xC004CF16:
        result = inline_copy_from_user((int)&v11, a3, 0x28u);
        if ( !result )
        {
          v7[0] = v11;
          v7[1] = v12;
          v7[2] = v13;
          v8 = v14;
          HIBYTE(v8) = 0;
          v9 = (unsigned int)v15;
          v10 = SHIDWORD(v15);
          LODWORD(result) = ipa3_allocate_nat_device(v7);
          if ( (_DWORD)result )
          {
            result = (int)result;
          }
          else
          {
            HIDWORD(v15) = v10;
            result = inline_copy_to_user(a3, &v11, 40);
          }
        }
        goto LABEL_52;
      case 0xC004CF17:
        v4 = 23;
        goto LABEL_50;
      case 0xC004CF18:
        a2 = 3221802776LL;
        goto LABEL_51;
      case 0xC004CF19:
        v4 = 25;
        goto LABEL_50;
      case 0xC004CF1A:
        v4 = 26;
        goto LABEL_50;
      case 0xC004CF1B:
        v4 = 27;
        goto LABEL_50;
      case 0xC004CF1C:
        a2 = 3221802780LL;
        goto LABEL_51;
      case 0xC004CF1D:
        v4 = 29;
        goto LABEL_50;
      case 0xC004CF1E:
        a2 = 3221802782LL;
        goto LABEL_51;
      case 0xC004CF1F:
        a2 = 3221802783LL;
        goto LABEL_51;
      case 0xC004CF20:
        a2 = 3221802784LL;
        goto LABEL_51;
      case 0xC004CF22:
        v4 = 34;
        goto LABEL_50;
      case 0xC004CF23:
        v4 = 35;
        goto LABEL_50;
      case 0xC004CF24:
        v4 = 36;
        goto LABEL_50;
      case 0xC004CF25:
        v4 = 37;
        goto LABEL_50;
      case 0xC004CF26:
        v4 = 38;
        goto LABEL_50;
      case 0xC004CF27:
        v4 = 39;
        goto LABEL_50;
      case 0xC004CF2A:
        v4 = 42;
        goto LABEL_50;
      case 0xC004CF33:
        v4 = 51;
        goto LABEL_50;
      case 0xC004CF34:
      case 0xC004CF35:
        result = compat_ipa3_nat_ipv6ct_alloc_table(a3);
        goto LABEL_52;
      case 0xC004CF36:
        v4 = 54;
        goto LABEL_50;
      case 0xC004CF37:
        v4 = 55;
LABEL_50:
        a2 = v4 | 0xC008CF00;
        goto LABEL_51;
      case 0xC004CF4E:
        a2 = 3222064974LL;
        goto LABEL_51;
      case 0xC004CF4F:
        a2 = 3221540687LL;
        goto LABEL_51;
      case 0xC004CF58:
        a2 = 3229929304LL;
        goto LABEL_51;
      case 0xC004CF59:
        v5 = -1065037992;
        goto LABEL_46;
      case 0xC004CF5E:
        a2 = 1074057054;
        goto LABEL_51;
      case 0xC004CF5F:
        v5 = 1074057054;
LABEL_46:
        a2 = v5 | 1u;
        goto LABEL_51;
      default:
        if ( (_DWORD)a2 == -2147168479 )
          goto LABEL_51;
        goto LABEL_52;
    }
  }
  if ( (unsigned int)(a2 - 1074056968) <= 0xD && ((1 << (a2 - 8)) & 0x304F) != 0
    || (unsigned int)(a2 - 52998) <= 6 && ((1 << (a2 - 6)) & 0x43) != 0 )
  {
LABEL_51:
    result = ipa3_ioctl(-515, a2, (unsigned int)a3);
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
