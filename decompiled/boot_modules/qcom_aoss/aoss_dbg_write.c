__int64 __fastcall aoss_dbg_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  unsigned __int64 v3; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  size_t v9; // x2
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  char *v21; // x0
  int v22; // w3
  int v23; // w4
  int v24; // w5
  int v25; // w6
  int v26; // w7
  char v27[8]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v28; // [xsp+8h] [xbp-68h]
  __int64 v29; // [xsp+10h] [xbp-60h]
  __int64 v30; // [xsp+18h] [xbp-58h]
  __int64 v31; // [xsp+20h] [xbp-50h]
  __int64 v32; // [xsp+28h] [xbp-48h]
  __int64 v33; // [xsp+30h] [xbp-40h]
  __int64 v34; // [xsp+38h] [xbp-38h]
  __int64 v35; // [xsp+40h] [xbp-30h]
  __int64 v36; // [xsp+48h] [xbp-28h]
  __int64 v37; // [xsp+50h] [xbp-20h]
  __int64 v38; // [xsp+58h] [xbp-18h]
  int v39; // [xsp+60h] [xbp-10h]
  __int64 v40; // [xsp+68h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v39 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  *(_QWORD *)v27 = 0;
  v28 = 0;
  if ( a3 - 100 < 0xFFFFFFFFFFFFFF9DLL )
  {
    result = -22;
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  _check_object_size(v27, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  v9 = a3;
  if ( 0x8000000000LL - a3 >= v8 )
  {
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v9 = _arch_copy_from_user(v27, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v9 )
    {
      v21 = (char *)strim(v27);
      LODWORD(result) = qmp_send(v3, v21, 100, v22, v23, v24, v25, v26, v27[0]);
      if ( (_DWORD)result )
        result = (int)result;
      else
        result = a3;
      goto LABEL_16;
    }
  }
  if ( a3 - v9 <= 0x64 )
    v10 = 100 - (a3 - v9);
  else
    v10 = 0;
  if ( v10 >= v9 )
  {
    memset(&v27[a3 - v9], 0, v9);
    result = -14;
    goto LABEL_16;
  }
  _fortify_panic(15);
  return aoss_qmp_mbox_resume_early();
}
