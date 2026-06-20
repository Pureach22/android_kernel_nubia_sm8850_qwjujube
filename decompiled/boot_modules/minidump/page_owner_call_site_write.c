__int64 __fastcall page_owner_call_site_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x1
  void *v4; // x0
  __int64 v5; // x19
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v8; // x8
  size_t v9; // x21
  unsigned __int64 v10; // x1
  __int64 v11; // x1
  unsigned __int64 v12; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v23; // x0
  size_t v24; // x0
  size_t v25; // x0
  __int64 v26; // x9
  unsigned __int64 *v27; // x1
  size_t v28; // x2
  _QWORD v29[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  if ( a3 >= 0x32 )
  {
    if ( (unsigned int)__ratelimit(&page_owner_call_site_write__rs, "page_owner_call_site_write") )
    {
      v4 = &unk_113940;
LABEL_31:
      printk(v4, v3);
      v5 = -22;
      goto LABEL_21;
    }
LABEL_20:
    v5 = -22;
    goto LABEL_21;
  }
  v5 = a3;
  _check_object_size(v29, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  v9 = v5;
  if ( 0x8000000000LL - v5 >= v8 )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v9 = _arch_copy_from_user(v29, a2 & 0xFF7FFFFFFFFFFFFFLL, v5);
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
    if ( !v9 )
      goto LABEL_18;
  }
  if ( v5 - v9 <= 0x32 )
    v10 = 50 - (v5 - v9);
  else
    v10 = 0;
  if ( v10 < v9 )
  {
    _fortify_panic(15, v10, v9);
    goto LABEL_33;
  }
  memset((char *)v29 + v5 - v9, 0, v9);
  if ( !v9 )
  {
LABEL_18:
    if ( LOBYTE(v29[0]) != 95 && (*((_BYTE *)&ctype + LOBYTE(v29[0])) & 3) == 0 )
    {
      if ( (unsigned int)__ratelimit(&page_owner_call_site_write__rs_146, "page_owner_call_site_write") )
      {
        v4 = &unk_112A3E;
        goto LABEL_31;
      }
      goto LABEL_20;
    }
    v23 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
    a2 = v23;
    if ( !v23 )
    {
      v5 = -12;
      goto LABEL_21;
    }
    v24 = strnlen((const char *)(v23 + 16), 0x32u);
    v9 = v24;
    if ( v24 < 0x33 )
    {
      if ( v24 == 50 )
      {
        v25 = _fortify_panic(4, 50, 51);
      }
      else
      {
        v25 = strnlen((const char *)v29, v24);
        if ( v25 < 0x32 )
        {
          sized_strscpy(a2 + 16, v29);
          v26 = raw_spin_lock_irqsave(&accounted_call_site_lock);
          v27 = (unsigned __int64 *)off_280;
          if ( off_280 != (_UNKNOWN **)a2 && *off_280 == (_UNKNOWN *)&accounted_call_site_list )
          {
            off_280 = (_UNKNOWN **)a2;
            *(_QWORD *)a2 = &accounted_call_site_list;
            *(_QWORD *)(a2 + 8) = v27;
            *v27 = a2;
LABEL_29:
            raw_spin_unlock_irqrestore(&accounted_call_site_lock, v26);
            goto LABEL_21;
          }
LABEL_37:
          _list_add_valid_or_report(a2);
          goto LABEL_29;
        }
      }
      v28 = v25 + 1;
LABEL_36:
      _fortify_panic(2, 50, v28);
      goto LABEL_37;
    }
LABEL_33:
    v28 = v9 + 1;
    goto LABEL_36;
  }
  if ( (unsigned int)__ratelimit(&page_owner_call_site_write__rs_144, "page_owner_call_site_write") )
    printk(&unk_1133FC, v11);
  v5 = -14;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v5;
}
