__int64 __fastcall sde_core_perf_mode_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  int v8; // w0
  __int64 result; // x0
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v12; // x8
  __int64 v14; // x8
  _QWORD *v15; // x11
  unsigned __int64 v16; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x9
  unsigned __int64 v24; // x10
  char s[8]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v26; // [xsp+10h] [xbp-80h]
  __int64 v27; // [xsp+18h] [xbp-78h]
  __int64 v28; // [xsp+20h] [xbp-70h]
  __int64 v29; // [xsp+28h] [xbp-68h]
  __int64 v30; // [xsp+30h] [xbp-60h]
  __int64 v31; // [xsp+38h] [xbp-58h]
  __int64 v32; // [xsp+40h] [xbp-50h]
  __int64 v33; // [xsp+48h] [xbp-48h]
  __int64 v34; // [xsp+50h] [xbp-40h]
  __int64 v35; // [xsp+58h] [xbp-38h]
  __int64 v36; // [xsp+60h] [xbp-30h]
  __int64 v37; // [xsp+68h] [xbp-28h]
  __int64 v38; // [xsp+70h] [xbp-20h]
  __int64 v39; // [xsp+78h] [xbp-18h]
  __int64 v40; // [xsp+80h] [xbp-10h]
  __int64 v41; // [xsp+88h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v39 = 0;
  v40 = 0;
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
  v27 = 0;
  v28 = 0;
  *(_QWORD *)s = 0;
  v26 = 0;
  if ( v4 )
  {
    if ( *a4
      || (v8 = snprintf(
                 s,
                 0x80u,
                 "mode %d min_mdp_clk %llu min_bus_vote %llu\n",
                 *(_DWORD *)(v4 + 64),
                 *(_QWORD *)(v4 + 72),
                 *(_QWORD *)(v4 + 80)),
          (unsigned int)v8 > 0x7F) )
    {
      result = 0;
    }
    else
    {
      if ( a3 < 0x80 )
        goto LABEL_14;
      v10 = v8;
      _check_object_size(s, v8, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v12 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v10;
      _CF = 0x8000000000LL - v10 >= v12;
      v14 = v10;
      v15 = a4;
      if ( _CF )
      {
        v16 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v21 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v21);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v16);
        v14 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v10;
        v15 = a4;
        v22 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v24 - 4096);
        _WriteStatusReg(TTBR1_EL1, v24);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v22);
      }
      if ( v14 )
LABEL_14:
        result = -14;
      else
        *v15 += result;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
