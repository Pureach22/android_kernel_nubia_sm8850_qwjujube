__int64 __fastcall dsp_utilization_stats_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned int v4; // w0
  unsigned __int64 v5; // x8
  int v6; // w11
  __int64 v7; // x10
  unsigned __int64 v8; // x8
  int v9; // w10
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x10
  int v12; // w13
  unsigned __int64 v13; // x8
  bool v14; // cc
  int v15; // w10
  int v16; // w11
  __int64 result; // x0
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  void *v29; // x0
  unsigned __int64 v30; // x10
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x11
  unsigned __int64 v38; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x9
  void *v44; // x8
  unsigned int v45; // w19
  int v46; // [xsp+0h] [xbp-10h] BYREF
  int v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  if ( a2 == -2147192573 )
  {
    if ( (byte_9601 & 1) == 0 )
      sysmon_smem_init_cdsp();
    if ( !qword_9670 || (unsigned __int64)qword_9670 > 0xFFFFFFFFFFFFF000LL )
    {
      printk(&unk_9D62, "sysmon_subsystem_stats");
      result = 4294967170LL;
      goto LABEL_62;
    }
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v11 = *(_QWORD *)(qword_9670 + 4);
    v12 = *(_DWORD *)qword_9670;
    v13 = _ReadStatusReg(SP_EL0);
    v14 = StatusReg - v11 > 0x1D96FF && StatusReg > v11;
    v15 = *(_DWORD *)(v13 + 68);
    if ( v14 )
      v16 = 0;
    else
      v16 = v12;
    v46 = v16;
    if ( (v15 & 0x200000) != 0 )
    {
      if ( (a3 & ((__int64)(a3 << 8) >> 8)) >= 0x7FFFFFFFFDLL )
        goto LABEL_56;
    }
    else
    {
      if ( (*(_QWORD *)v13 & 0x4000000) == 0 )
      {
        if ( a3 >= 0x7FFFFFFFFDLL )
          goto LABEL_56;
        goto LABEL_37;
      }
      if ( (a3 & ((__int64)(a3 << 8) >> 8)) >= 0x7FFFFFFFFDLL )
        goto LABEL_56;
      if ( (v15 & 0x200000) == 0 )
      {
LABEL_37:
        v18 = a3;
        if ( (*(_QWORD *)v13 & 0x4000000) == 0 )
          goto LABEL_39;
      }
    }
    v18 = a3 & ((__int64)(a3 << 8) >> 8);
LABEL_39:
    if ( v18 < 0x7FFFFFFFFDLL )
    {
      v19 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(v13 + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v19);
      result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v46, 4);
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
      if ( !result )
        goto LABEL_62;
    }
    v29 = &unk_A326;
LABEL_57:
    printk(v29, "sysmon_subsystem_stats");
    result = -14;
    goto LABEL_62;
  }
  if ( a2 == -2147192574 )
  {
    v4 = sysmon_stats_query_hmx_utlization(&v47);
    if ( v4 )
    {
      v44 = &unk_9C5E;
LABEL_60:
      v45 = v4;
      printk(v44, "sysmon_subsystem_stats");
      result = v45;
      goto LABEL_62;
    }
    v8 = _ReadStatusReg(SP_EL0);
    v9 = *(_DWORD *)(v8 + 68);
    if ( (v9 & 0x200000) != 0 )
    {
      if ( (a3 & ((__int64)(a3 << 8) >> 8)) >= 0x7FFFFFFFFDLL )
        goto LABEL_56;
    }
    else
    {
      if ( (*(_QWORD *)v8 & 0x4000000) == 0 )
      {
        if ( a3 >= 0x7FFFFFFFFDLL )
          goto LABEL_56;
        goto LABEL_44;
      }
      if ( (a3 & ((__int64)(a3 << 8) >> 8)) >= 0x7FFFFFFFFDLL )
        goto LABEL_56;
      if ( (v9 & 0x200000) == 0 )
      {
LABEL_44:
        v30 = a3;
        if ( (*(_QWORD *)v8 & 0x4000000) == 0 )
          goto LABEL_46;
      }
    }
    v30 = a3 & ((__int64)(a3 << 8) >> 8);
LABEL_46:
    if ( v30 < 0x7FFFFFFFFDLL )
    {
      v31 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(v8 + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v31);
      result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v47, 4);
      v34 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v36 - 4096);
      _WriteStatusReg(TTBR1_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v34);
      if ( !result )
        goto LABEL_62;
    }
    v29 = &unk_9CEB;
    goto LABEL_57;
  }
  if ( a2 != -2147192575 )
  {
    result = -22;
    goto LABEL_62;
  }
  v4 = sysmon_stats_query_hvx_utlization(&v47);
  if ( v4 )
  {
    v44 = &unk_A698;
    goto LABEL_60;
  }
  v5 = _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(v5 + 68);
  v7 = a3 << 8;
  if ( (v6 & 0x200000) != 0 )
  {
    if ( (a3 & (v7 >> 8)) >= 0x7FFFFFFFFDLL )
      goto LABEL_56;
    goto LABEL_52;
  }
  if ( (*(_QWORD *)v5 & 0x4000000) == 0 )
  {
    if ( a3 >= 0x7FFFFFFFFDLL )
      goto LABEL_56;
    goto LABEL_51;
  }
  if ( (a3 & (v7 >> 8)) >= 0x7FFFFFFFFDLL )
  {
LABEL_56:
    v29 = &unk_9DD7;
    goto LABEL_57;
  }
  if ( (v6 & 0x200000) != 0 )
  {
LABEL_52:
    v37 = a3 & (v7 >> 8);
    goto LABEL_53;
  }
LABEL_51:
  v37 = a3;
  if ( (*(_QWORD *)v5 & 0x4000000) != 0 )
    goto LABEL_52;
LABEL_53:
  if ( v37 >= 0x7FFFFFFFFDLL )
    goto LABEL_55;
  v38 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v40 = *(_QWORD *)(v5 + 8);
  _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v40);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v38);
  result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v47, 4);
  v41 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v43 - 4096);
  _WriteStatusReg(TTBR1_EL1, v43);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v41);
  if ( result )
  {
LABEL_55:
    v29 = &unk_A3B7;
    goto LABEL_57;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
