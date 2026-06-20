__int64 __fastcall kgsl_prop_query_capabilities(__int64 *a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  size_t v4; // x19
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x22
  size_t v9; // x20
  int v10; // w21
  __int64 v11; // x20
  __int64 v12; // x9
  unsigned __int64 v13; // x21
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v22; // x8
  __int64 v23; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  _DWORD *v27; // x8
  unsigned int v28; // w27
  __int64 v29; // x25
  unsigned __int64 v30; // x23
  _DWORD *v31; // x0
  _DWORD *v32; // x21
  unsigned int v33; // w26
  _DWORD *v34; // x8
  __int64 v35; // x22
  unsigned __int64 v36; // x23
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x21
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v50; // x8
  __int64 v51; // x0
  unsigned __int64 v52; // x8
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int64 v56; // [xsp+8h] [xbp-28h]
  __int64 v57; // [xsp+10h] [xbp-20h]
  unsigned __int64 v58; // [xsp+18h] [xbp-18h] BYREF
  __int64 v59; // [xsp+20h] [xbp-10h]
  __int64 v60; // [xsp+28h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  if ( !v2 )
  {
    result = 0;
    *(_QWORD *)(a2 + 16) = 24;
    goto LABEL_8;
  }
  if ( v2 >= 0x18 )
    v4 = 24;
  else
    v4 = *(_QWORD *)(a2 + 16);
  v6 = *(_QWORD *)(a2 + 8);
  v56 = 0;
  v57 = 0;
  v55 = 0;
  _check_object_size(&v55, v4, 0);
  if ( inline_copy_from_user_0((int)&v55, v6, v4) )
    goto LABEL_6;
  if ( !(_DWORD)v57 )
  {
    result = -22;
    goto LABEL_8;
  }
  if ( (_DWORD)v57 != 1 )
  {
    result = -95;
    goto LABEL_8;
  }
  if ( !v56 )
  {
    v11 = 0;
    v56 = 16;
    goto LABEL_20;
  }
  v8 = *a1;
  if ( v56 >= 0x10 )
    v9 = 16;
  else
    v9 = v56;
  v10 = v55;
  v58 = 0;
  v59 = 0;
  _check_object_size(&v58, v9, 0);
  if ( inline_copy_from_user_0((int)&v58, v10, v9) )
    goto LABEL_16;
  v27 = *(_DWORD **)(*(_QWORD *)(v8 + 8752) + 232LL);
  if ( v27 )
  {
    if ( *(v27 - 1) != -722337215 )
      __break(0x8228u);
    v28 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v27)(v8, 0, 0) + 9;
  }
  else
  {
    v28 = 9;
  }
  if ( !(_DWORD)v59 )
    goto LABEL_62;
  if ( (unsigned int)v59 >= v28 )
    v29 = v28;
  else
    v29 = (unsigned int)v59;
  v30 = 4LL * (unsigned int)v29;
  v31 = (_DWORD *)_kmalloc_noprof(v30, 3520);
  v32 = v31;
  if ( !v31 )
  {
    v12 = a2;
    v11 = -12;
    goto LABEL_21;
  }
  if ( (unsigned int)v29 >= 9 )
    v33 = 9;
  else
    v33 = v29;
  if ( v28 )
  {
    if ( v29 && v30 )
    {
      *v31 = 8;
      if ( (_DWORD)v29 == 1 )
        goto LABEL_64;
      if ( v30 != 4 )
      {
        v31[1] = 9;
        if ( (_DWORD)v29 == 2 )
          goto LABEL_64;
        if ( v30 >= 9 )
        {
          v31[2] = 35;
          if ( (_DWORD)v29 == 3 )
            goto LABEL_64;
          if ( v30 >= 0xD )
          {
            v31[3] = 36;
            if ( (_DWORD)v29 == 4 )
              goto LABEL_64;
            if ( v30 >= 0x11 )
            {
              v31[4] = 39;
              if ( (_DWORD)v29 == 5 )
                goto LABEL_64;
              if ( v30 >= 0x15 )
              {
                v31[5] = 40;
                if ( (_DWORD)v29 == 6 )
                  goto LABEL_64;
                if ( v30 >= 0x19 )
                {
                  v31[6] = 44;
                  if ( (_DWORD)v29 == 7 )
                    goto LABEL_64;
                  if ( v30 >= 0x1D )
                  {
                    v31[7] = 49;
                    if ( (_DWORD)v29 == 8 )
                      goto LABEL_64;
                    if ( v30 >= 0x21 )
                    {
                      v31[8] = 50;
                      goto LABEL_64;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    __break(1u);
LABEL_62:
    LODWORD(v59) = v28;
    goto LABEL_75;
  }
  v33 = 0;
LABEL_64:
  v34 = *(_DWORD **)(*(_QWORD *)(v8 + 8752) + 232LL);
  if ( v34 )
  {
    if ( *(v34 - 1) != -722337215 )
      __break(0x8228u);
    v33 += ((__int64 (__fastcall *)(__int64, _DWORD *, _QWORD))v34)(v8, &v31[v33], (unsigned int)v29 - v33);
  }
  v35 = 4LL * v33;
  LODWORD(v59) = v33;
  if ( v33 >> 29 )
  {
    __break(0x800u);
  }
  else
  {
    v36 = v58;
    _check_object_size(v32, 4LL * v33, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v38 = v36, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v38 = v36 & ((__int64)(v36 << 8) >> 8);
    if ( 0x8000000000LL - v35 >= v38 )
    {
      v39 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v41 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v41);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v39);
      LODWORD(v35) = _arch_copy_to_user(v36 & 0xFF7FFFFFFFFFFFFFLL, v32, 4LL * v33);
      v42 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v44 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v44 - 4096);
      _WriteStatusReg(TTBR1_EL1, v44);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v42);
    }
  }
  kfree(v32);
  if ( (_DWORD)v35 )
  {
LABEL_16:
    v11 = -14;
    goto LABEL_20;
  }
LABEL_75:
  v45 = v55;
  _check_object_size(&v58, v9, 1);
  v46 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v46 + 70) & 0x20) != 0 || (v47 = v45, (*(_QWORD *)v46 & 0x4000000) != 0) )
    v47 = v45 & ((__int64)(v45 << 8) >> 8);
  if ( 0x8000000000LL - v9 < v47 )
  {
    v12 = a2;
    v11 = -14;
    goto LABEL_21;
  }
  v48 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v50 = *(_QWORD *)(v46 + 8);
  _WriteStatusReg(TTBR1_EL1, v50 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v50);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v48);
  v51 = _arch_copy_to_user(v45 & 0xFF7FFFFFFFFFFFFFLL, &v58, v9);
  v52 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v54 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v54 - 4096);
  _WriteStatusReg(TTBR1_EL1, v54);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v52);
  if ( v51 )
    v11 = -14;
  else
    v11 = 0;
LABEL_20:
  v12 = a2;
LABEL_21:
  v13 = *(_QWORD *)(v12 + 8);
  _check_object_size(&v55, v4, 1);
  v14 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v14 + 70) & 0x20) != 0 || (v15 = v13, (*(_QWORD *)v14 & 0x4000000) != 0) )
    v15 = v13 & ((__int64)(v13 << 8) >> 8);
  if ( 0x8000000000LL - v4 < v15 )
  {
LABEL_6:
    result = -14;
    goto LABEL_8;
  }
  v16 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v22 = *(_QWORD *)(v14 + 8);
  _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v22);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v16);
  v23 = _arch_copy_to_user(v13 & 0xFF7FFFFFFFFFFFFFLL, &v55, v4);
  v24 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v26 - 4096);
  _WriteStatusReg(TTBR1_EL1, v26);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v24);
  if ( v23 )
    result = -14;
  else
    result = v11;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
