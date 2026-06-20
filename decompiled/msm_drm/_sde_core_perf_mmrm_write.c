__int64 __fastcall sde_core_perf_mmrm_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x10
  size_t v11; // x20
  unsigned __int64 v12; // x1
  unsigned __int64 v13; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  int v23; // w23
  __int64 v24; // x25
  const char *v25; // x21
  int v26; // w24
  __int64 v27; // x20
  int v28[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-20h] BYREF
  int v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  result = -19;
  if ( v3 )
  {
    v5 = *(_QWORD *)(v3 + 24);
    if ( v5 )
    {
      if ( a3 > 0x13 )
        goto LABEL_16;
      v30 = 0;
      v29[0] = 0;
      v29[1] = 0;
      *(_QWORD *)v28 = 0;
      _check_object_size(v29, a3, 0);
      StatusReg = _ReadStatusReg(SP_EL0);
      v9 = a2;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v10 = a2 & ((__int64)(a2 << 8) >> 8);
      v11 = a3;
      if ( 0x8000000000LL - a3 < v10 )
        goto LABEL_32;
      v13 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v13);
      v11 = _arch_copy_from_user(v29, v9 & 0xFF7FFFFFFFFFFFFFLL, a3);
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v22 - 4096);
      _WriteStatusReg(TTBR1_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      if ( v11 )
      {
LABEL_32:
        if ( a3 - v11 <= 0x14 )
          v12 = 20 - (a3 - v11);
        else
          v12 = 0;
        if ( v12 < v11 )
        {
          _fortify_panic(15, v12, v11);
          JUMPOUT(0x104F7C);
        }
        memset((char *)v29 + a3 - v11, 0, v11);
        if ( v11 )
          goto LABEL_16;
      }
      *((_BYTE *)v29 + a3) = 0;
      if ( (unsigned int)kstrtoull(v29, 0, v28) )
      {
LABEL_16:
        result = -14;
      }
      else
      {
        v23 = *(_DWORD *)(v5 + 32);
        if ( !v23 )
          goto LABEL_24;
        v24 = *(_QWORD *)(v5 + 40);
        v25 = *(const char **)(v3 + 32);
        v26 = 0;
        while ( 1 )
        {
          v27 = v24 + 120LL * v26;
          if ( !strcmp((const char *)(v27 + 8), v25) )
            break;
          if ( v23 == ++v26 )
            goto LABEL_24;
        }
        if ( v27 )
        {
          *(_QWORD *)v28 = clk_round_rate(*(_QWORD *)v27);
          printk(&unk_25AEE4, *(_QWORD *)v28);
          if ( (unsigned int)sde_power_mmrm_set_clk_limit((int)v24 + 120 * v26, *(_QWORD *)(v3 + 24), v28[0]) )
            printk(&unk_250113, "_sde_core_perf_mmrm_write");
        }
        else
        {
LABEL_24:
          printk(&unk_2500E2, "_sde_core_perf_mmrm_write");
        }
        result = a3;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
