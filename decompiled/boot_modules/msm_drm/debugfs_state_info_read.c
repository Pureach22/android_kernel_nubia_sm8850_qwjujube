__int64 __fastcall debugfs_state_info_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  _DWORD *v4; // x23
  __int64 v5; // x20
  __int64 v9; // x0
  char *v10; // x19
  char *v11; // x0
  const char *v12; // x3
  int v13; // w0
  const char *v14; // x3
  const char *v15; // x4
  __int64 v16; // x25
  __int64 v17; // x25
  unsigned __int64 v18; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x0
  _QWORD *v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x10

  v4 = *(_DWORD **)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  v10 = (char *)v9;
  if ( !v9 )
    return -12;
  v11 = (char *)(v9 + 15);
  strcpy(v10, "Current State:\n");
  if ( v4[406] )
    v12 = "ON";
  else
    v12 = "OFF";
  v13 = snprintf(v11, 0xFF1u, "\tCTRL_ENGINE = %s\n", v12);
  if ( v4[405] )
    v14 = "ON";
  else
    v14 = "OFF";
  if ( v4[404] )
    v15 = "ON";
  else
    v15 = "OFF";
  v16 = (unsigned int)(snprintf(
                         &v10[v13 + 15],
                         (unsigned int)(4081 - v13),
                         "\tVIDEO_ENGINE = %s\n\tCOMMAND_ENGINE = %s\n",
                         v14,
                         v15)
                     + v13
                     + 15);
  v17 = (unsigned int)(v16 + snprintf(&v10[v16], (unsigned int)(4096 - v16), "\nClock Info:\n"));
  v18 = (unsigned int)(snprintf(
                         &v10[v17],
                         (unsigned int)(4096 - v17),
                         "\tBYTE_CLK = %u, PIXEL_CLK = %u, ESC_CLK = %u\n",
                         v4[594],
                         v4[596],
                         v4[597])
                     + v17);
  if ( v18 > a3 )
    LODWORD(v18) = a3;
  if ( (unsigned int)v18 >= 0x1000 )
    v5 = 4096;
  else
    v5 = (unsigned int)v18;
  _check_object_size(v10, v5, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v20 = a2 & ((__int64)(a2 << 8) >> 8);
  v21 = v5;
  _CF = 0x8000000000LL - v5 >= v20;
  v23 = a4;
  if ( _CF )
  {
    v24 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v29 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v29);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v24);
    v21 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
    v23 = a4;
    v30 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v32 - 4096);
    _WriteStatusReg(TTBR1_EL1, v32);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v30);
  }
  if ( v21 )
    v5 = -14;
  else
    *v23 += v5;
  kfree(v10);
  return v5;
}
