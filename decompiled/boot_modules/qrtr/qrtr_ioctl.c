__int64 __fastcall qrtr_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v5; // x19
  unsigned int v6; // w21
  int v8; // w9
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x11
  unsigned __int64 v12; // x11
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x9
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x11
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  _QWORD v32[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h]
  __int64 v34; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v34 = 0;
  v35 = 0;
  v32[1] = 0;
  v33 = 0;
  v32[0] = 0;
  lock_sock_nested(v5, 0);
  if ( (unsigned int)(a2 - 35083) > 0x11 )
    goto LABEL_9;
  v6 = -22;
  if ( ((1 << (a2 - 11)) & 0x3F803) != 0 )
    goto LABEL_3;
  if ( a2 == 35093 )
  {
    v6 = -14;
    if ( !(unsigned int)get_user_ifreq(v32, 0, a3) )
    {
      v8 = *(_DWORD *)(v5 + 848);
      v33 = *(_QWORD *)(v5 + 840);
      LODWORD(v34) = v8;
      if ( (unsigned int)put_user_ifreq(v32, a3) )
        v6 = -14;
      else
        v6 = 0;
    }
  }
  else
  {
LABEL_9:
    if ( a2 == 21531 )
    {
      v22 = *(_QWORD *)(v5 + 168);
      _W8 = 0;
      if ( v22 != v5 + 168 && v22 )
        _W8 = *(_DWORD *)(v22 + 112);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v25 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v25 = a3 & ((__int64)(a3 << 8) >> 8);
      v6 = -14;
      if ( v25 < 0x7FFFFFFFFDLL )
      {
        v26 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v28 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v28);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v26);
        __asm { STTR            W8, [X10] }
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v6 = 0;
        v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v31 - 4096);
        _WriteStatusReg(TTBR1_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
      }
    }
    else if ( a2 == 21521 )
    {
      v9 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v9 + 70) & 0x20) != 0 || (v10 = a3, (*(_QWORD *)v9 & 0x4000000) != 0) )
        v10 = a3 & ((__int64)(a3 << 8) >> 8);
      v6 = -14;
      if ( v10 < 0x7FFFFFFFFDLL )
      {
        _W10 = (*(_DWORD *)(v5 + 372) - *(_DWORD *)(v5 + 380) + 1)
             & ~((*(_DWORD *)(v5 + 372) - *(_DWORD *)(v5 + 380) + 1) >> 31);
        v12 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v18 = *(_QWORD *)(v9 + 8);
        _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v18);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v12);
        __asm { STTR            W10, [X9] }
        v19 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v6 = 0;
        v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v21 - 4096);
        _WriteStatusReg(TTBR1_EL1, v21);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v19);
      }
    }
    else
    {
      v6 = -515;
    }
  }
LABEL_3:
  release_sock(v5);
  _ReadStatusReg(SP_EL0);
  return v6;
}
