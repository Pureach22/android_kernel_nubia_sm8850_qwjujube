__int64 __fastcall gen7_hfi_send_cmd_wait_inline(__int64 a1, int *a2, unsigned int a3, int *a4)
{
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x22
  __int64 result; // x0
  __int64 v12; // x27
  const char *v13; // x23
  unsigned int v20; // w8
  unsigned int v21; // w8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = to_gen7_gmu(a1);
  _X9 = (unsigned int *)(v8 + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v20 = __ldxr(_X9);
    v21 = v20 + 1;
  }
  while ( __stlxr(v21, _X9) );
  __dmb(0xBu);
  v9 = *a2 | (a3 << 6) & 0xFF00 | (v21 << 20);
  *a2 = v9;
  if ( a4 )
  {
    v10 = v8;
    *a4 = v9;
    result = gen7_hfi_cmdq_write(a1, a2, a3);
    if ( !(_DWORD)result )
    {
      v22 = 0;
      v12 = -250LL - jiffies;
      v13 = "abort";
      do
      {
        gmu_core_regread(a1, 129426, &v22);
        if ( (v22 & 1) != 0 )
          goto LABEL_6;
        gmu_core_regread(a1, 129052, &v22);
        if ( (v22 & 0xE00) != 0 )
          goto LABEL_5;
        usleep_range_state(10, 100, 2);
      }
      while ( jiffies + v12 < 0 );
      v13 = "timeout";
LABEL_5:
      gmu_core_regread(a1, 129426, &v22);
      if ( (v22 & 1) != 0 )
      {
LABEL_6:
        gmu_core_regwrite(a1, 129425, 1);
        result = ((__int64 (__fastcall *)(__int64, __int64, int *))gen7_hfi_process_queue)(v10, 1, a4);
        goto LABEL_8;
      }
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Reg poll %s: offset 0x%x, want 0x%x, got 0x%x\n", v13, 129426, 1, 0);
      dev_err(
        *(_QWORD *)(a1 + 1544) + 16LL,
        "Timed out waiting on ack for 0x%8.8x (id %d, sequence %d)\n",
        *a2,
        (unsigned __int8)*a2,
        (unsigned int)*a2 >> 20);
      gmu_core_fault_snapshot(a1, 5);
      result = 4294967186LL;
    }
  }
  else
  {
    result = gen7_hfi_cmdq_write(a1, a2, a3);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
