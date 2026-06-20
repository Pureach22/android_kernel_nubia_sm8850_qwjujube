__int64 __fastcall aw_algo_auth_misc_ops(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  unsigned __int64 v4; // x8
  char v5; // w9
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  unsigned __int64 v13; // x8
  size_t v14; // x2
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  unsigned int v18; // w19
  int v19; // w9
  __int64 v20; // x10
  unsigned __int64 StatusReg; // x8
  int v22; // w11
  int v23; // w9
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v27; // x8
  __int64 v28; // x0
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  __int64 v32; // x20
  __int64 *v34; // x8
  __int64 v35; // x1
  __int128 v36; // [xsp+0h] [xbp-20h] BYREF
  int v37; // [xsp+10h] [xbp-10h]
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == -1072400639 )
  {
    v19 = *(_DWORD *)(a1 + 1116);
    v20 = *(_QWORD *)(a1 + 1120);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_DWORD *)(a1 + 1128);
    LODWORD(v36) = v19;
    v23 = *(_DWORD *)(a1 + 1132);
    *(_QWORD *)((char *)&v36 + 4) = v20;
    LOBYTE(v20) = *(_BYTE *)(StatusReg + 70);
    HIDWORD(v36) = v22;
    v37 = v23;
    if ( (v20 & 0x20) != 0 || (v24 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v24 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v24 >= 0x7FFFFFFFEDLL )
    {
      v18 = -14;
    }
    else
    {
      v25 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v25);
      v28 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v36, 20);
      v29 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v31 - 4096);
      _WriteStatusReg(TTBR1_EL1, v31);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v29);
      if ( v28 )
        v18 = -14;
      else
        v18 = 0;
    }
  }
  else if ( a2 == -1072400638 )
  {
    v4 = _ReadStatusReg(SP_EL0);
    v5 = *(_BYTE *)(v4 + 70);
    v37 = 0;
    v36 = 0u;
    if ( (v5 & 0x20) != 0 || (v6 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
      v6 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v6 >= 0x7FFFFFFFEDLL )
    {
      v14 = 20;
      goto LABEL_18;
    }
    v3 = a1;
    v7 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v13 = *(_QWORD *)(v4 + 8);
    _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v13);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v7);
    while ( 1 )
    {
      v14 = _arch_copy_from_user(&v36, a3 & 0xFF7FFFFFFFFFFFFFLL, 20);
      v15 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v17 - 4096);
      _WriteStatusReg(TTBR1_EL1, v17);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v15);
      a1 = v3;
      if ( !v14 )
      {
        v18 = 0;
        goto LABEL_20;
      }
LABEL_18:
      if ( v14 < 0x15 )
        break;
      _fortify_panic(15);
    }
    v32 = a1;
    memset((char *)&v36 - v14 + 20, 0, v14);
    v18 = -14;
    a1 = v32;
LABEL_20:
    aw882xx_dev_algo_auth_set(a1, &v36);
  }
  else
  {
    v34 = *(__int64 **)(a1 + 112);
    v35 = v34[14];
    if ( !v35 )
      v35 = *v34;
    printk(&unk_23228, v35, "aw_algo_auth_misc_ops");
    v18 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
