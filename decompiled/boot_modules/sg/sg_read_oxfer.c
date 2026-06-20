__int64 __fastcall sg_read_oxfer(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  unsigned int v5; // w21
  int v6; // w8
  __int64 v7; // x24
  unsigned __int64 v8; // x26
  unsigned __int64 StatusReg; // x27
  __int64 v10; // x22
  __int64 v11; // x25
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 v14; // x23
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v22; // x9
  __int64 v23; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x23
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v32; // x8
  __int64 v33; // x0
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  int v37; // [xsp+1Ch] [xbp-14h]
  int v38; // [xsp+20h] [xbp-10h]

  result = 0;
  if ( a2 )
  {
    v5 = a3;
    if ( a3 >= 1 )
    {
      if ( *(_WORD *)(a1 + 24) )
      {
        v6 = *(_DWORD *)(a1 + 48);
        v7 = 0;
        v8 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        v37 = v6 + 12;
        v10 = 1 << (v6 + 12);
        v11 = a2 << 8;
        v38 = 1 << (v6 + 12);
        while ( 1 )
        {
          v12 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 8 * v8);
          if ( !v12 )
            break;
          v13 = (v12 << 6) + 0xFFFFD000000000LL;
          if ( (int)v5 < v38 )
          {
            v27 = v13 & 0xFFFFFFFFFFF000LL;
            _check_object_size(v13 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL, v5, 1);
            v28 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v28 + 70) & 0x20) != 0 || (v29 = a2 + v7, (*(_QWORD *)v28 & 0x4000000) != 0) )
              v29 = (a2 + v7) & (v11 >> 8);
            if ( 0x8000000000LL - (unsigned __int64)v5 < v29 )
              return 4294967282LL;
            v30 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v32 = *(_QWORD *)(v28 + 8);
            _WriteStatusReg(TTBR1_EL1, v32 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v32);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v30);
            v33 = _arch_copy_to_user((a2 + v7) & 0xFF7FFFFFFFFFFFFFLL, v27 | 0xFF00000000000000LL, v5);
            v34 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v36 - 4096);
            _WriteStatusReg(TTBR1_EL1, v36);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v34);
            if ( v33 )
              return 4294967282LL;
            return 0;
          }
          if ( v37 == 31 )
          {
            __break(0x800u);
            return 4294967282LL;
          }
          v14 = v13 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
          _check_object_size(v14, v10, 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a2 + v7, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v15 = (a2 + v7) & (v11 >> 8);
          if ( 0x8000000000LL - v10 < v15 )
            return 4294967282LL;
          v16 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v22 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v22);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v16);
          v23 = _arch_copy_to_user((a2 + v7) & 0xFF7FFFFFFFFFFFFFLL, v14, v10);
          v24 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v26 - 4096);
          _WriteStatusReg(TTBR1_EL1, v26);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v24);
          if ( v23 )
            return 4294967282LL;
          if ( (int)(v5 - v38) >= 1 )
          {
            ++v8;
            v7 += v10;
            v5 -= v38;
            v11 += v10 << 8;
            if ( v8 < *(unsigned __int16 *)(a1 + 24) )
              continue;
          }
          return 0;
        }
      }
      return 0;
    }
  }
  return result;
}
