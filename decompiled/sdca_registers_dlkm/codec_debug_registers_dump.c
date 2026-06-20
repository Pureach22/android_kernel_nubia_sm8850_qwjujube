unsigned __int64 __fastcall codec_debug_registers_dump(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  unsigned __int64 v4; // x22
  __int64 *v6; // x26
  __int64 v7; // x21
  __int64 v8; // x25
  unsigned __int64 v10; // x27
  unsigned __int64 StatusReg; // x28
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  unsigned __int8 v14; // w0
  signed int v15; // w0
  __int64 v16; // x23
  __int64 v17; // x24
  unsigned __int64 v18; // x27
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v31; // [xsp+8h] [xbp-28h]
  _QWORD v32[2]; // [xsp+10h] [xbp-20h] BYREF
  int v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v4 = -22;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_28;
  if ( !a1 )
    goto LABEL_28;
  if ( !a3 )
    goto LABEL_28;
  if ( !a4 )
    goto LABEL_28;
  v6 = *(__int64 **)(a1 + 32);
  if ( !v6 )
    goto LABEL_28;
  v33 = 0;
  v32[0] = 0;
  v32[1] = 0;
  v7 = *v6;
  if ( !*v6 )
    goto LABEL_28;
  LODWORD(v8) = *a4 / 20;
  if ( (int)v8 >= *((_DWORD *)v6 + 5) )
  {
    v4 = 0;
    goto LABEL_27;
  }
  v8 = (int)v8;
  v10 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v31 = a3 - 1;
  while ( 1 )
  {
    v12 = (__int64 (__fastcall *)(_QWORD))v6[3];
    v13 = *(unsigned int *)(v6[1] + 4 * v8);
    if ( *((_DWORD *)v12 - 1) != -1896783675 )
      __break(0x8229u);
    if ( (v12(v13) & 1) == 0 )
    {
      v4 = v10;
      goto LABEL_10;
    }
    v14 = snd_soc_component_read(v7, *(unsigned int *)(v6[1] + 4 * v8));
    v15 = scnprintf(v32, 20, "0x%.8x: 0x%.2x\n", *(_DWORD *)(v6[1] + 4 * v8), v14);
    if ( v15 < 0 || (v16 = v15, v4 = v10 + v15, v4 >= v31) )
    {
      v4 = v10;
      goto LABEL_27;
    }
    v17 = v15;
    if ( (unsigned int)v15 >= 0x15 )
      break;
    v18 = a2 + v10;
    _check_object_size(v32, v15, 1);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = v18, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v19 = v18 & ((__int64)(v18 << 8) >> 8);
    if ( 0x8000000000LL - v16 >= v19 )
    {
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      v17 = _arch_copy_to_user(v18 & 0xFF7FFFFFFFFFFFFFLL, v32, v16);
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v29 - 4096);
      _WriteStatusReg(TTBR1_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
    }
    if ( v17 )
    {
      v4 = -14;
      goto LABEL_27;
    }
    v10 = v4;
    *(_QWORD *)a4 += v16;
LABEL_10:
    if ( ++v8 >= *((int *)v6 + 5) )
      goto LABEL_27;
  }
  _copy_overflow(20, v15);
  v4 = -14;
LABEL_27:
  *(_QWORD *)a4 = 20 * (int)v8;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v4;
}
