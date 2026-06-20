__int64 __fastcall a6xx_hfi_send_cmd_wait_inline(__int64 a1, int *a2, unsigned int a3, int *a4)
{
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x23
  __int64 result; // x0
  unsigned int v12; // w0
  unsigned int v13; // w20
  unsigned int v20; // w8
  unsigned int v21; // w8

  v8 = to_a6xx_gmu(a1);
  _X9 = (unsigned int *)(v8 + 36);
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
    result = a6xx_hfi_queue_write(a1, 0, a2, a3);
    __dsb(0xEu);
    if ( !(_DWORD)result )
    {
      gmu_core_regwrite(a1, 129428, 1);
      v12 = gmu_core_timed_poll_check(a1, 129426, 1, 1000, 1);
      if ( v12 )
      {
        v13 = v12;
        dev_err(
          *(_QWORD *)(a1 + 1544) + 16LL,
          "Timed out waiting on ack for 0x%8.8x (id %d, sequence %d)\n",
          *a2,
          (unsigned __int8)*a2,
          (unsigned int)*a2 >> 20);
        gmu_core_fault_snapshot(a1, 5);
        return v13;
      }
      else
      {
        gmu_core_regwrite(a1, 129425, 1);
        return ((__int64 (__fastcall *)(__int64, __int64, int *))a6xx_hfi_process_queue)(v10, 1, a4);
      }
    }
  }
  else
  {
    result = a6xx_hfi_queue_write(a1, 0, a2, a3);
    __dsb(0xEu);
    if ( !(_DWORD)result )
    {
      gmu_core_regwrite(a1, 129428, 1);
      return 0;
    }
  }
  return result;
}
