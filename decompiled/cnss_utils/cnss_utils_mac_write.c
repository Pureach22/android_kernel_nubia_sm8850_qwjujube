__int64 __fastcall cnss_utils_mac_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x23
  __int64 v6; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  size_t v9; // x22
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  char *v21; // x22
  __int64 result; // x0
  char *v23; // x0
  __int64 v24; // x1
  int v25; // w8
  char *v26; // x20
  int v27; // w8
  size_t v28; // x0
  size_t v29; // x21
  _BYTE *v30; // x22
  char *v31; // x20
  void *v32; // x0
  char *v33; // x1
  __int64 v34; // x0
  char v35[4]; // [xsp+4h] [xbp-9Ch] BYREF
  char *stringp; // [xsp+8h] [xbp-98h] BYREF
  __int16 v37; // [xsp+14h] [xbp-8Ch] BYREF
  char v38; // [xsp+16h] [xbp-8Ah]
  _QWORD v39[17]; // [xsp+18h] [xbp-88h] BYREF

  v39[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 128LL);
  memset(&v39[10], 0, 48);
  if ( a3 >= 0x7F )
    v6 = 127;
  else
    v6 = a3;
  memset(v39, 0, 80);
  stringp = nullptr;
  v35[0] = 0;
  v38 = 0;
  v37 = 0;
  _check_object_size(v39, v6, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  v9 = v6;
  if ( 0x8000000000LL - v6 >= v8 )
  {
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v9 = _arch_copy_from_user(v39, a2 & 0xFF7FFFFFFFFFFFFFLL, v6);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v9 )
      goto LABEL_15;
  }
  if ( v6 - v9 <= 0x80 )
    v10 = 128 - (v6 - v9);
  else
    v10 = 0;
  if ( v10 >= v9 )
  {
    memset((char *)v39 + v6 - v9, 0, v9);
    if ( v9 )
    {
LABEL_39:
      result = -22;
      goto LABEL_40;
    }
LABEL_15:
    *((_BYTE *)v39 + v6) = 0;
    stringp = (char *)v39;
    v21 = strsep(&stringp, "\n");
    result = -22;
    if ( !v21 || !stringp )
      goto LABEL_40;
    v23 = strsep(&stringp, "\n");
    if ( !v23 )
      goto LABEL_39;
    v25 = (unsigned __int8)*v23;
    v26 = v23;
    if ( v25 == 48 )
    {
      v27 = (unsigned __int8)v23[1];
      if ( v27 == 120 )
      {
        if ( v23[2] )
        {
LABEL_21:
          printk(&unk_73FF, v24);
          goto LABEL_39;
        }
      }
      else if ( 120 != v27 )
      {
        goto LABEL_21;
      }
    }
    else if ( 48 != v25 )
    {
      goto LABEL_21;
    }
    v28 = strlen(v23);
    v29 = v28 - 2;
    if ( v28 - 14 > 0x24 || v29 % 0xC )
    {
      v32 = &unk_72D7;
      v33 = (char *)v29;
    }
    else
    {
      if ( !strcmp("provisioned", v21) )
      {
        v30 = (_BYTE *)(v5 + 392);
        *(_DWORD *)(v5 + 416) = v29 / 0xC;
        if ( !v29 )
        {
LABEL_33:
          result = a3;
LABEL_40:
          _ReadStatusReg(SP_EL0);
          return result;
        }
LABEL_30:
        v31 = v26 + 3;
        while ( 1 )
        {
          v37 = *(_WORD *)(v31 - 1);
          if ( (unsigned int)kstrtou8(&v37, 16, v35) )
            goto LABEL_39;
          --v29;
          v31 += 2;
          *v30++ = v35[0];
          if ( !v29 )
            goto LABEL_33;
        }
      }
      if ( !strcmp("derived", v21) )
      {
        v30 = (_BYTE *)(v5 + 420);
        *(_DWORD *)(v5 + 444) = v29 / 0xC;
        if ( !v29 )
          goto LABEL_33;
        goto LABEL_30;
      }
      v32 = &unk_719C;
      v33 = v21;
    }
    printk(v32, v33);
    goto LABEL_39;
  }
  v34 = _fortify_panic(15);
  return cnss_utils_mac_open(v34);
}
