__int64 __fastcall ipa3_attrib_dump(int *a1, __int64 a2)
{
  int v2; // w20
  int v4; // w8
  void *v5; // x0
  void *v6; // x0
  int v7; // w8
  int v8; // w8
  int v9; // w8
  __int64 result; // x0
  unsigned __int64 v11; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v2 = a2;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v11 = 0;
  v12 = 0;
  if ( (v4 & 0x8000000) != 0 )
  {
    printk(&unk_3EC044, a2);
    v4 = *a1;
    if ( (*a1 & 1) == 0 )
    {
LABEL_3:
      if ( (v4 & 0x10000) == 0 )
        goto LABEL_4;
      goto LABEL_9;
    }
  }
  else if ( (v4 & 1) == 0 )
  {
    goto LABEL_3;
  }
  printk(&unk_3F4C99, *((unsigned __int8 *)a1 + 60));
  v4 = *a1;
  if ( (*a1 & 0x10000) == 0 )
  {
LABEL_4:
    if ( (v4 & 2) == 0 )
      goto LABEL_5;
    goto LABEL_10;
  }
LABEL_9:
  printk(&unk_3C091F, *((unsigned __int8 *)a1 + 14));
  printk(&unk_3F76AC, *((unsigned __int8 *)a1 + 15));
  v4 = *a1;
  if ( (*a1 & 2) == 0 )
  {
LABEL_5:
    if ( (v4 & 4) == 0 )
      goto LABEL_16;
    goto LABEL_11;
  }
LABEL_10:
  printk(&unk_3C69BA, *((unsigned __int8 *)a1 + 61));
  if ( (*a1 & 4) == 0 )
    goto LABEL_16;
LABEL_11:
  if ( v2 )
  {
    if ( v2 != 1 )
      goto LABEL_16;
    v5 = &unk_3C9715;
    v11 = __PAIR64__(bswap32(a1[19]), bswap32(a1[18]));
    v12 = _byteswap_uint64(__PAIR64__(a1[20], a1[21]));
  }
  else
  {
    v5 = &unk_3C69C9;
    LODWORD(v11) = bswap32(a1[16]);
  }
  printk(v5, &v11);
LABEL_16:
  if ( (*(_BYTE *)a1 & 8) == 0 )
    goto LABEL_22;
  if ( v2 )
  {
    if ( v2 != 1 )
      goto LABEL_22;
    v6 = &unk_3F76BB;
    v11 = __PAIR64__(bswap32(a1[27]), bswap32(a1[26]));
    v12 = _byteswap_uint64(__PAIR64__(a1[28], a1[29]));
  }
  else
  {
    v6 = &unk_3D8218;
    LODWORD(v11) = bswap32(a1[18]);
  }
  printk(v6, &v11);
LABEL_22:
  v7 = *a1;
  if ( (*a1 & 0x10) != 0 )
  {
    printk(&unk_3EEAF3, *((unsigned __int16 *)a1 + 2));
    v7 = *a1;
    if ( (*a1 & 0x20) == 0 )
    {
LABEL_24:
      if ( (v7 & 0x40) == 0 )
        goto LABEL_25;
      goto LABEL_44;
    }
  }
  else if ( (v7 & 0x20) == 0 )
  {
    goto LABEL_24;
  }
  printk(&unk_3A30F6, *((unsigned __int16 *)a1 + 4));
  v7 = *a1;
  if ( (*a1 & 0x40) == 0 )
  {
LABEL_25:
    if ( (v7 & 0x80) == 0 )
      goto LABEL_26;
    goto LABEL_45;
  }
LABEL_44:
  printk(&unk_3F1D08, *((unsigned __int8 *)a1 + 12));
  v7 = *a1;
  if ( (*a1 & 0x80) == 0 )
  {
LABEL_26:
    if ( (v7 & 0x100) == 0 )
      goto LABEL_27;
    goto LABEL_46;
  }
LABEL_45:
  printk(&unk_3D546B, *((unsigned __int8 *)a1 + 13));
  v7 = *a1;
  if ( (*a1 & 0x100) == 0 )
  {
LABEL_27:
    if ( (v7 & 0x200) == 0 )
      goto LABEL_28;
    goto LABEL_47;
  }
LABEL_46:
  printk(&unk_3F1D13, (unsigned int)a1[4]);
  v7 = *a1;
  if ( (*a1 & 0x200) == 0 )
  {
LABEL_28:
    if ( (v7 & 0x400) == 0 )
      goto LABEL_29;
    goto LABEL_48;
  }
LABEL_47:
  printk(&unk_3B4A19, *((unsigned __int16 *)a1 + 10));
  v7 = *a1;
  if ( (*a1 & 0x400) == 0 )
  {
LABEL_29:
    if ( (v7 & 0x800) == 0 )
      goto LABEL_30;
    goto LABEL_49;
  }
LABEL_48:
  printk(&unk_3F76DF, *((unsigned __int16 *)a1 + 11));
  v7 = *a1;
  if ( (*a1 & 0x800) == 0 )
  {
LABEL_30:
    if ( (v7 & 0x1000) == 0 )
      goto LABEL_31;
    goto LABEL_50;
  }
LABEL_49:
  printk(&unk_3C092F, *((unsigned __int8 *)a1 + 60));
  v7 = *a1;
  if ( (*a1 & 0x1000) == 0 )
  {
LABEL_31:
    if ( (v7 & 0x2000) == 0 )
      goto LABEL_32;
    goto LABEL_51;
  }
LABEL_50:
  printk(&unk_3E6046, (unsigned int)a1[16]);
  if ( (*a1 & 0x2000) == 0 )
  {
LABEL_32:
    if ( (a1[35] & 0x10) == 0 )
      goto LABEL_33;
    goto LABEL_52;
  }
LABEL_51:
  printk(&unk_3C0938, *((unsigned __int8 *)a1 + 68));
  if ( (a1[35] & 0x10) == 0 )
  {
LABEL_33:
    v8 = *a1;
    if ( (*a1 & 0x4000) == 0 )
      goto LABEL_34;
    goto LABEL_53;
  }
LABEL_52:
  printk(&unk_3DB04D, *((unsigned __int8 *)a1 + 68));
  v8 = *a1;
  if ( (*a1 & 0x4000) == 0 )
  {
LABEL_34:
    if ( (v8 & 0x8000) == 0 )
      goto LABEL_36;
    goto LABEL_35;
  }
LABEL_53:
  printk(&unk_3E0A1D, (unsigned int)a1[6]);
  v8 = *a1;
  if ( (*a1 & 0x8000) != 0 )
  {
LABEL_35:
    printk(&unk_3D823C, a2);
    v8 = *a1;
  }
LABEL_36:
  if ( (v8 & 0x200A0000) != 0 )
  {
    printk(&unk_3F4CA3, a1 + 8);
    v8 = *a1;
  }
  if ( (v8 & 0xC0540000) != 0 )
  {
    printk(&unk_3B1DED, a1 + 11);
    if ( (a1[35] & 4) == 0 )
    {
LABEL_40:
      v9 = *a1;
      if ( (*a1 & 0x200000) != 0 )
        goto LABEL_62;
      goto LABEL_57;
    }
  }
  else if ( (a1[35] & 4) == 0 )
  {
    goto LABEL_40;
  }
  printk(&unk_3CC0A5, *((unsigned __int16 *)a1 + 69));
  v9 = *a1;
  if ( (*a1 & 0x200000) != 0 )
    goto LABEL_62;
LABEL_57:
  if ( (a1[35] & 2) == 0 )
  {
    if ( (v9 & 0x10000000) != 0 )
      goto LABEL_63;
LABEL_59:
    if ( (v9 & 0x800000) != 0 )
      goto LABEL_64;
LABEL_60:
    if ( (v9 & 0x1000000) != 0 )
      goto LABEL_70;
    goto LABEL_65;
  }
LABEL_62:
  printk(&unk_3EC053, *((unsigned __int16 *)a1 + 28));
  v9 = *a1;
  if ( (*a1 & 0x10000000) == 0 )
    goto LABEL_59;
LABEL_63:
  printk(&unk_3FAD82, *((unsigned __int16 *)a1 + 68));
  v9 = *a1;
  if ( (*a1 & 0x800000) == 0 )
    goto LABEL_60;
LABEL_64:
  printk(&unk_3D25B3, a2);
  v9 = *a1;
  if ( (*a1 & 0x1000000) != 0 )
    goto LABEL_70;
LABEL_65:
  if ( (a1[35] & 1) == 0 )
  {
    if ( (v9 & 0x2000000) == 0 )
      goto LABEL_67;
LABEL_71:
    printk(&unk_3D25BE, *((unsigned __int8 *)a1 + 12));
    if ( (*a1 & 0x4000000) == 0 )
      goto LABEL_69;
    goto LABEL_68;
  }
LABEL_70:
  printk(&unk_3C0947, a2);
  v9 = *a1;
  if ( (*a1 & 0x2000000) != 0 )
    goto LABEL_71;
LABEL_67:
  if ( (v9 & 0x4000000) != 0 )
  {
LABEL_68:
    LODWORD(v11) = bswap32(a1[18]);
    printk(&unk_3D8218, &v11);
  }
LABEL_69:
  result = printk(&unk_3C36C1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
