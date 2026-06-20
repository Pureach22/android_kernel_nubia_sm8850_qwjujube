void __fastcall sub_630CC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6, __int64 a7, int a8)
{
  __int64 v8; // x9
  unsigned __int16 v9; // w10
  __int64 v10; // x11
  __int64 v11; // x20
  __int64 v12; // x29
  unsigned __int64 StatusReg; // x22
  __int64 v14; // x2
  __int64 v15; // x6
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x1
  __int64 v19; // x12

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v12 - 24) = a2;
    *(_DWORD *)(v12 - 28) = a6;
    *(_QWORD *)(v12 - 40) = a3;
    v14 = *(_QWORD *)(v12 - 24);
    v15 = *(unsigned int *)(v12 - 28);
    *(_DWORD *)(v12 - 44) = a8;
    v16 = _traceiter_rdev_tx_control_port(0, v11 + 992, v14, *(_QWORD *)(v12 - 40), v9, v8 + 4, v15, v10 != 0);
    v17 = *(_QWORD *)(v12 - 40);
    v18 = *(_QWORD *)(v12 - 24);
    v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v19;
    if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v16, v18, v17);
  }
  JUMPOUT(0x62FD8);
}
