__int64 __fastcall sde_core_perf_mmrm_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x22
  __int64 requested_clk; // x0
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v13; // x8
  __int64 v15; // x8
  _QWORD *v16; // x11
  unsigned __int64 v17; // x8
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v25; // x10
  char s[8]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v27; // [xsp+10h] [xbp-80h]
  __int64 v28; // [xsp+18h] [xbp-78h]
  __int64 v29; // [xsp+20h] [xbp-70h]
  __int64 v30; // [xsp+28h] [xbp-68h]
  __int64 v31; // [xsp+30h] [xbp-60h]
  __int64 v32; // [xsp+38h] [xbp-58h]
  __int64 v33; // [xsp+40h] [xbp-50h]
  __int64 v34; // [xsp+48h] [xbp-48h]
  __int64 v35; // [xsp+50h] [xbp-40h]
  __int64 v36; // [xsp+58h] [xbp-38h]
  __int64 v37; // [xsp+60h] [xbp-30h]
  __int64 v38; // [xsp+68h] [xbp-28h]
  __int64 v39; // [xsp+70h] [xbp-20h]
  __int64 v40; // [xsp+78h] [xbp-18h]
  __int64 v41; // [xsp+80h] [xbp-10h]
  __int64 v42; // [xsp+88h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  *(_QWORD *)s = 0;
  v27 = 0;
  if ( v4 )
  {
    if ( *a4
      || (requested_clk = sde_power_mmrm_get_requested_clk(*(_QWORD *)(v4 + 24), *(char **)(v4 + 32)),
          v9 = snprintf(s, 0x80u, "mmrm clk_limit:%llu clk:%s\n", requested_clk, *(const char **)(v4 + 32)),
          (unsigned int)v9 > 0x7F) )
    {
      result = 0;
    }
    else
    {
      if ( a3 < 0x80 )
        goto LABEL_14;
      v11 = v9;
      _check_object_size(s, v9, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v13 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v11;
      _CF = 0x8000000000LL - v11 >= v13;
      v15 = v11;
      v16 = a4;
      if ( _CF )
      {
        v17 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v17);
        v15 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v11;
        v16 = a4;
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v25 - 4096);
        _WriteStatusReg(TTBR1_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
      }
      if ( v15 )
LABEL_14:
        result = -14;
      else
        *v16 += result;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
