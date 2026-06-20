__int64 __fastcall gen7_send_hw_fence_hfi_wait_ack(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w8
  unsigned int v7; // w20
  __int64 result; // x0
  unsigned int v15; // w8
  unsigned int v16; // w8

  if ( *(_QWORD *)(a1 + 11112) )
  {
    raw_spin_lock(a1 + 23152);
    LODWORD(qword_17BDD8) = 0;
    _init_swait_queue_head(&qword_17BDE0, "&x->wait", &init_completion___key_2);
    *(_QWORD *)(a2 + 32) |= a3;
    _X9 = (unsigned int *)(a1 + 23208);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v15 = __ldxr(_X9);
      v16 = v15 + 1;
    }
    while ( __stlxr(v16, _X9) );
    __dmb(0xBu);
    v6 = *(_DWORD *)a2 | (v16 << 20) | 0xC00;
    *(_DWORD *)a2 = v6;
    LODWORD(hw_fence_ack) = v6;
    v7 = gen7_hfi_cmdq_write(a1, (int *)a2, 0x30u);
    raw_spin_unlock(a1 + 23152);
    result = v7;
    if ( !v7 )
    {
      result = adreno_hwsched_wait_ack_completion(
                 a1,
                 *(_QWORD *)(a1 + 1544) + 16LL,
                 &hw_fence_ack,
                 gen7_hwsched_process_msgq);
      if ( !(_DWORD)result )
      {
        if ( dword_17BD94 )
        {
          dev_err(
            *(_QWORD *)(a1 + 1544) + 16LL,
            "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n",
            dword_17BD90,
            dword_17BD94);
          gmu_core_fault_snapshot(a1, 14);
          result = 4294967274LL;
        }
        else
        {
          result = 0;
        }
      }
    }
    qword_17BDF8 = 0;
    qword_17BE00 = 0;
    qword_17BDE8 = 0;
    qword_17BDF0 = 0;
    qword_17BDD8 = 0;
    qword_17BDE0 = 0;
    qword_17BDC8 = 0;
    qword_17BDD0 = 0;
    qword_17BDB8 = 0;
    qword_17BDC0 = 0;
    qword_17BDA8 = 0;
    qword_17BDB0 = 0;
    qword_17BD98 = 0;
    qword_17BDA0 = 0;
    hw_fence_ack = 0;
    *(_QWORD *)&dword_17BD90 = 0;
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
  return result;
}
