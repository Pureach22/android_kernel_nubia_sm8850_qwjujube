// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_105478@<X0>(__int64 a1@<X8>)
{
  unsigned __int64 v1; // x1
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x22
  size_t v5; // x0
  size_t v6; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x1
  void *v16; // x0
  __int64 v17; // x2
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x1
  int v21; // w20
  int v22; // w7
  unsigned int v23; // w8
  char v24; // [xsp-60h] [xbp-60h]
  unsigned int v25; // [xsp-5Ch] [xbp-5Ch] BYREF
  _BYTE v26[88]; // [xsp-58h] [xbp-58h] BYREF

  v5 = _arch_copy_from_user(v26, a1 & 0xFF7FFFFFFFFFFFFFLL, v2);
  v6 = v5;
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v13 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v13 - 4096);
  _WriteStatusReg(TTBR1_EL1, v13);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v5 )
  {
    if ( v2 - v5 <= 0xA )
      v1 = 10 - (v2 - v5);
    else
      v1 = 0;
    if ( v1 < v5 )
    {
      _fortify_panic(15, v1, v5);
      JUMPOUT(0x105604);
    }
    memset(&v26[v2 - v5], 0, v5);
    if ( v6 )
      goto LABEL_4;
  }
  v26[v2] = 0;
  if ( (unsigned int)kstrtouint(v26, 0, &v25) || v25 > 2 )
  {
LABEL_4:
    v2 = -14;
  }
  else
  {
    if ( v25 == 1 )
    {
      v17 = *(_QWORD *)(v3 + 56);
      *(_QWORD *)(v3 + 72) = v17;
      v18 = *(_QWORD *)(v3 + 24);
      v19 = *(_QWORD *)(v3 + 32);
      *(_QWORD *)(v3 + 80) = 1000LL * *(unsigned int *)(v4 + 21708);
      v21 = sde_power_clk_set_rate(v18, v19, v17, 0);
      if ( v21 )
      {
        printk(&unk_235203, "_sde_core_perf_mode_write");
        *(_QWORD *)(v3 + 72) = 0;
        *(_QWORD *)(v3 + 80) = 0;
        v25 = 0;
      }
      else
      {
        printk(&unk_227720, v20);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_core_perf_mode_write",
        1330,
        -1,
        *(_QWORD *)(v3 + 56),
        v21,
        -1059143953,
        v22,
        v24);
    }
    else
    {
      if ( v25 == 2 )
      {
        v16 = &unk_21DA0A;
      }
      else
      {
        v16 = &unk_212643;
        *(_QWORD *)(v3 + 72) = 0;
        *(_QWORD *)(v3 + 80) = 0;
      }
      printk(v16, v14);
    }
    v23 = v25;
    *(_BYTE *)(v3 + 88) = 1;
    *(_DWORD *)(v3 + 64) = v23;
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
