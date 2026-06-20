__int64 __fastcall channel_config_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  __int64 v4; // x19
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 v9; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  size_t v12; // x23
  unsigned __int64 v13; // x1
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  int v24; // w8
  char *v25; // x0
  int v26; // w8
  unsigned int v27; // w23
  __int64 v29; // x0
  char *stringp; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v31[6]; // [xsp+10h] [xbp-30h] BYREF

  v4 = a3;
  v31[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  memset(v31, 0, 32);
  v8 = *(_QWORD *)(v7 + 128);
  stringp = (char *)v31;
  if ( a3 >= 0x27 )
    v9 = 39;
  else
    v9 = a3;
  v31[4] = 0;
  _check_object_size(v31, v9, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( 0x8000000000LL - v9 >= v11 )
  {
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v12 = _arch_copy_from_user(v31, a2 & 0xFF7FFFFFFFFFFFFFLL, v9);
    v21 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v23 - 4096);
    _WriteStatusReg(TTBR1_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v21);
    if ( !v12 )
    {
LABEL_16:
      v24 = LOBYTE(v31[0]);
      if ( (unsigned int)LOBYTE(v31[0]) - 58 >= 0xFFFFFFF6 )
      {
        if ( *(a4 - 1) != 280633428 )
          __break(0x8234u);
        if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))a4)(v8, 4, 255, (unsigned int)(v24 - 48))
            & 0x80000000) == 0 )
          goto LABEL_34;
      }
      else if ( (*((_BYTE *)&ctype + LOBYTE(v31[0])) & 3) != 0 )
      {
        do
        {
          v25 = strsep(&stringp, " ");
          if ( !v25 )
            goto LABEL_34;
          v26 = (unsigned __int8)*v25;
          v27 = v26 - 97;
          if ( (unsigned int)(v26 - 97) < 4 )
          {
            if ( (unsigned int)(unsigned __int8)*strsep(&stringp, " ") - 58 < 0xFFFFFFF6 )
              break;
          }
          else
          {
            v27 = v26 - 65;
            if ( (unsigned int)(v26 - 65) > 3 || (unsigned int)(unsigned __int8)*strsep(&stringp, " ") - 58 < 0xFFFFFFF6 )
              break;
          }
          if ( *(a4 - 1) != 280633428 )
            __break(0x8234u);
        }
        while ( (((__int64 (__fastcall *)(__int64, _QWORD))a4)(v8, v27) & 0x80000000) == 0 );
      }
      printk(&unk_7909);
LABEL_33:
      v4 = -14;
LABEL_34:
      _ReadStatusReg(SP_EL0);
      return v4;
    }
  }
  else
  {
    v12 = v9;
  }
  if ( v9 - v12 <= 0x28 )
    v13 = 40 - (v9 - v12);
  else
    v13 = 0;
  if ( v13 >= v12 )
  {
    memset((char *)v31 + v9 - v12, 0, v12);
    if ( v12 )
      goto LABEL_33;
    goto LABEL_16;
  }
  v29 = _fortify_panic(15);
  return nb7vpq904m_eq_config(v29);
}
