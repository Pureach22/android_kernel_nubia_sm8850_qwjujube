__int64 __fastcall dt_parse_vreg_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  const char *v6; // x21
  unsigned __int64 v7; // x0
  unsigned int v8; // w22
  unsigned int *property; // x0
  int v11; // [xsp+4h] [xbp-7Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v13; // [xsp+10h] [xbp-70h]
  __int64 v14; // [xsp+18h] [xbp-68h]
  __int64 v15; // [xsp+20h] [xbp-60h]
  _QWORD v16[11]; // [xsp+28h] [xbp-58h] BYREF

  v4 = a2;
  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(const char **)(a3 + 8);
  if ( !a2 )
    v4 = *(_QWORD *)(a1 + 744);
  v11 = 0;
  *(_QWORD *)s = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  snprintf(s, 0x20u, "%s-supply", v6);
  memset(v16, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v4, s, 0, 0, 0, v16) || !v16[0] )
  {
    printk(&unk_11033, "dt_parse_vreg_info");
LABEL_15:
    v8 = 0;
    goto LABEL_16;
  }
  v7 = regulator_get(a1, v6);
  *(_QWORD *)a3 = v7;
  if ( v7 < 0xFFFFFFFFFFFFF001LL )
  {
    snprintf(s, 0x20u, "%s-config", *(const char **)(a3 + 8));
    property = (unsigned int *)of_get_property(v4, s, &v11);
    if ( property )
    {
      if ( v11 == 16 )
      {
        *(_DWORD *)(a3 + 16) = bswap32(*property);
        *(_DWORD *)(a3 + 20) = bswap32(property[1]);
        *(_DWORD *)(a3 + 24) = bswap32(property[2]);
        *(_BYTE *)(a3 + 29) = property[3] != 0;
        goto LABEL_14;
      }
      if ( v11 == 20 )
      {
        *(_DWORD *)(a3 + 16) = bswap32(*property);
        *(_DWORD *)(a3 + 20) = bswap32(property[1]);
        *(_DWORD *)(a3 + 24) = bswap32(property[2]);
        *(_BYTE *)(a3 + 29) = property[3] != 0;
        *(_BYTE *)(a3 + 40) = property[4] != 0;
        printk(&unk_1100F, "dt_parse_vreg_info");
LABEL_14:
        printk(&unk_11153, "dt_parse_vreg_info");
        goto LABEL_15;
      }
    }
    printk(&unk_12FBD, "dt_parse_vreg_info");
    goto LABEL_14;
  }
  v8 = v7;
  *(_QWORD *)a3 = 0;
  printk(&unk_13757, "dt_parse_vreg_info");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v8;
}
