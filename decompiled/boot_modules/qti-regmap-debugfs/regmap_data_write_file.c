__int64 __fastcall regmap_data_write_file(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x19
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x9
  size_t v8; // x21
  unsigned __int64 v9; // x1
  __int64 result; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  char *v21; // x0
  __int64 *v22; // x8
  __int64 v23; // [xsp+0h] [xbp-30h] BYREF
  __int64 v24; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+10h] [xbp-20h] BYREF
  __int64 v26; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v27[2]; // [xsp+20h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( regmap_data_write < 5 )
    goto LABEL_14;
  if ( a3 >= 0x1F )
    v4 = 31;
  else
    v4 = a3;
  v5 = *(_QWORD *)(a1 + 32);
  v26 = 0;
  v27[0] = 0;
  v24 = 0;
  v25 = 0;
  v23 = 0;
  _check_object_size(&v24, v4, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v7 = a2 & ((__int64)(a2 << 8) >> 8);
  v8 = v4;
  if ( 0x8000000000LL - v4 < v7 )
    goto LABEL_9;
  v11 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v17 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v17);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v11);
  v8 = _arch_copy_from_user(&v24, a2 & 0xFF7FFFFFFFFFFFFFLL, v4);
  v18 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v20 - 4096);
  _WriteStatusReg(TTBR1_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v18);
  if ( v8 )
  {
LABEL_9:
    if ( v4 - v8 <= 0x20 )
      v9 = 32 - (v4 - v8);
    else
      v9 = 0;
    if ( v9 < v8 )
    {
      _fortify_panic(15);
LABEL_69:
      v21 = (char *)v22 + 20;
      goto LABEL_80;
    }
    memset((char *)&v24 + v4 - v8, 0, v8);
    if ( v8 )
    {
LABEL_14:
      result = -14;
LABEL_85:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v21 = (char *)&v24;
  *((_BYTE *)&v24 + v4) = 0;
  if ( (unsigned __int8)v24 != 32 )
    goto LABEL_80;
  if ( BYTE1(v24) != 32 )
  {
    v21 = (char *)&v24 + 1;
    goto LABEL_80;
  }
  if ( BYTE2(v24) != 32 )
  {
    v21 = (char *)&v24 + 2;
    goto LABEL_80;
  }
  if ( BYTE3(v24) != 32 )
  {
    v21 = (char *)&v24 + 3;
    goto LABEL_80;
  }
  if ( BYTE4(v24) != 32 )
  {
    v21 = (char *)&v24 + 4;
    goto LABEL_80;
  }
  if ( BYTE5(v24) != 32 )
  {
    v21 = (char *)&v24 + 5;
    goto LABEL_80;
  }
  if ( BYTE6(v24) != 32 )
  {
    v21 = (char *)&v24 + 6;
    goto LABEL_80;
  }
  if ( HIBYTE(v24) != 32 )
  {
    v21 = (char *)&v24 + 7;
    goto LABEL_80;
  }
  if ( (unsigned __int8)v25 != 32 )
  {
    v21 = (char *)&v25;
    goto LABEL_80;
  }
  if ( BYTE1(v25) != 32 )
  {
    v21 = (char *)&v25 + 1;
    goto LABEL_80;
  }
  if ( BYTE2(v25) != 32 )
  {
    v21 = (char *)&v25 + 2;
    goto LABEL_80;
  }
  if ( BYTE3(v25) != 32 )
  {
    v21 = (char *)&v25 + 3;
    goto LABEL_80;
  }
  if ( BYTE4(v25) != 32 )
  {
    v21 = (char *)&v25 + 4;
    goto LABEL_80;
  }
  if ( BYTE5(v25) != 32 )
  {
    v21 = (char *)&v25 + 5;
    goto LABEL_80;
  }
  if ( BYTE6(v25) != 32 )
  {
    v21 = (char *)&v25 + 6;
    goto LABEL_80;
  }
  if ( HIBYTE(v25) != 32 )
  {
    v21 = (char *)&v25 + 7;
    goto LABEL_80;
  }
  if ( (unsigned __int8)v26 != 32 )
  {
    v21 = (char *)&v26;
    goto LABEL_80;
  }
  if ( BYTE1(v26) != 32 )
  {
    v21 = (char *)&v26 + 1;
    goto LABEL_80;
  }
  if ( BYTE2(v26) != 32 )
  {
    v21 = (char *)&v26 + 2;
    goto LABEL_80;
  }
  v22 = &v24;
  if ( BYTE3(v26) != 32 )
  {
    v21 = (char *)&v26 + 3;
    goto LABEL_80;
  }
  if ( BYTE4(v26) != 32 )
    goto LABEL_69;
  if ( BYTE5(v26) != 32 )
  {
    v21 = (char *)&v26 + 5;
    goto LABEL_80;
  }
  if ( BYTE6(v26) != 32 )
  {
    v21 = (char *)&v26 + 6;
    goto LABEL_80;
  }
  if ( HIBYTE(v26) != 32 )
  {
    v21 = (char *)&v26 + 7;
    goto LABEL_80;
  }
  if ( LOBYTE(v27[0]) != 32 )
  {
    v21 = (char *)v27;
    goto LABEL_80;
  }
  if ( BYTE1(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 1;
    goto LABEL_80;
  }
  if ( BYTE2(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 2;
    goto LABEL_80;
  }
  if ( BYTE3(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 3;
    goto LABEL_80;
  }
  if ( BYTE4(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 4;
    goto LABEL_80;
  }
  if ( BYTE5(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 5;
    goto LABEL_80;
  }
  if ( BYTE6(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 6;
LABEL_80:
    if ( (unsigned int)kstrtoull(v21, 16, &v23) )
    {
      result = -22;
    }
    else
    {
      LODWORD(result) = regmap_write(*(_QWORD *)(v5 + 16), *(unsigned int *)(v5 + 32), (unsigned int)v23);
      if ( (int)result >= 0 )
        result = v4;
      else
        result = (int)result;
    }
    goto LABEL_85;
  }
  if ( HIBYTE(v27[0]) != 32 )
  {
    v21 = (char *)v27 + 7;
    goto LABEL_80;
  }
  __break(1u);
  return regmap_debugfs_generate_cache(&v24);
}
