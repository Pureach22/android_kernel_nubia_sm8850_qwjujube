__int64 __fastcall gunyah_trace_read(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x9
  __int64 v4; // x23
  __int64 v6; // x21
  signed __int64 v7; // x25
  unsigned __int64 StatusReg; // x28
  unsigned int *v9; // x9
  __int64 v10; // x24
  __int64 v11; // x8
  unsigned int v12; // w22
  unsigned int v13; // w27
  int v14; // w21
  int v15; // w8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x20
  __int64 v18; // x23
  __int64 v19; // x26
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x0
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  bool v32; // cc
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9
  __int64 v35; // x20
  __int64 v36; // x0
  unsigned __int64 v38; // [xsp+0h] [xbp-20h]
  __int64 v39; // [xsp+8h] [xbp-18h]
  __int64 v40; // [xsp+10h] [xbp-10h]
  unsigned int v41; // [xsp+1Ch] [xbp-4h]

  v3 = a3 & 0xFFFFFFFFFFFFFFC0LL;
  if ( (__int64)(a3 & 0xFFFFFFFFFFFFFFC0LL) >= 1 && word_7E0C )
  {
    v4 = *(_QWORD *)(a1 + 32);
    v6 = 0;
    v7 = a3 & 0xFFFFFFFFFFFFFFC0LL;
    StatusReg = _ReadStatusReg(SP_EL0);
    v38 = a3 & 0xFFFFFFFFFFFFFFC0LL;
    v39 = v4;
    while ( 2 )
    {
      v40 = v6;
      v9 = (unsigned int *)(*(_QWORD *)(v4 + 8) + 12 * v6);
      v10 = qword_7E38 + 32 * v6;
      v11 = *(_QWORD *)(v10 + 8);
      v12 = *v9;
      v13 = v9[1];
      v14 = *(_DWORD *)(v11 + 48);
      v41 = *(_DWORD *)(v11 + 40);
      do
      {
        if ( v14 - v13 > 1 )
          return -22;
        if ( v14 - v13 == 1 )
        {
          if ( v41 >= v12 )
            return -22;
          v15 = v41 - v12 + *(_DWORD *)(v10 + 24);
          if ( !v15 )
            break;
        }
        else
        {
          v15 = v41 - v12;
          if ( v41 == v12 )
            break;
        }
        v16 = (unsigned int)(v15 << 6);
        if ( (unsigned __int64)(*(_DWORD *)(v10 + 24) + ~v12) << 6 < v16 )
          v16 = (unsigned __int64)(*(_DWORD *)(v10 + 24) + ~v12) << 6;
        if ( v16 >= v7 )
          v17 = v7;
        else
          v17 = v16;
        if ( v17 >> 31 )
        {
          __break(0x800u);
          return -14;
        }
        v18 = *(_QWORD *)v10;
        v19 = v12 << 6;
        _check_object_size(*(_QWORD *)v10 + v19, v17, 1);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v20 = a2 & ((__int64)(a2 << 8) >> 8);
        if ( 0x8000000000LL - v17 < v20 )
          return -14;
        v21 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v27 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v27);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v21);
        v28 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v18 + v19, v17);
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v31 - 4096);
        _WriteStatusReg(TTBR1_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
        if ( v28 == v17 )
          return -14;
        v32 = v7 <= (__int64)v17;
        v7 -= v17;
        a2 += v17;
        v33 = (v17 >> 6) + v12;
        v34 = (unsigned int)(*(_DWORD *)(v10 + 24) - 1);
        v12 = v33 % v34;
        v13 += v33 / v34;
      }
      while ( !v32 );
      v4 = v39;
      v35 = 12 * v40;
      v36 = raw_spin_lock_irqsave(*(_QWORD *)(v39 + 8) + 12 * v40 + 8);
      *(_DWORD *)(*(_QWORD *)(v39 + 8) + v35 + 4) = v13;
      *(_DWORD *)(*(_QWORD *)(v39 + 8) + v35) = v12;
      raw_spin_unlock_irqrestore(*(_QWORD *)(v39 + 8) + 12 * v40 + 8, v36);
      if ( v7 < 1 )
      {
        v3 = v38;
      }
      else
      {
        v6 = v40 + 1;
        v3 = v38;
        if ( v40 + 1 < (unsigned __int64)(unsigned __int16)word_7E0C )
          continue;
      }
      break;
    }
  }
  else
  {
    v7 = a3 & 0xFFFFFFFFFFFFFFC0LL;
  }
  return v3 - v7;
}
