__int64 __fastcall walt_start_cpus(unsigned __int64 *a1, char a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x10
  __int64 v9; // x19
  char v10; // w13
  unsigned __int64 v11; // x13
  unsigned __int64 v12; // x13
  __int64 v13; // x14
  char v15; // w12
  unsigned __int64 v20; // x14
  unsigned __int64 v21; // x12
  unsigned __int64 v22; // x12
  char v23; // w8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x24
  __int64 v30; // x8
  unsigned __int64 v32; // x9

  _X21 = a1;
  v6 = raw_spin_lock_irqsave(&halt_lock);
  v8 = *(unsigned int *)_X21;
  v9 = v6;
  v10 = 0;
  do
  {
    v11 = v8 & (-1LL << v10);
    if ( !v11 )
      break;
    v12 = __clz(__rbit64(v11));
    v13 = *((_QWORD *)&_per_cpu_offset + v12);
    _CF = v12 >= 0x1F;
    v10 = v12 + 1;
    halt_state[v13 + a3] &= ~a2;
  }
  while ( !_CF );
  v15 = 0;
  do
  {
    v21 = (unsigned int)(-1LL << v15) & *(_DWORD *)_X21;
    if ( !(_DWORD)v21 )
      break;
    v22 = __clz(__rbit64(v21));
    if ( halt_state[*((_QWORD *)&_per_cpu_offset + v22) + a3] )
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v20 = __ldxr(_X21);
      while ( __stxr(v20 & ~(1LL << v22), _X21) );
    }
    _CF = v22 >= 0x1F;
    v15 = v22 + 1;
  }
  while ( !_CF );
  sched_clock(v6, v7);
  v23 = 0;
  _X26 = &_cpu_halt_mask;
  _X28 = &_cpu_partial_halt_mask;
  do
  {
    v28 = (unsigned int)(-1LL << v23) & *(_DWORD *)_X21;
    if ( !(_DWORD)v28 )
      break;
    __dsb(0xEu);
    v29 = __clz(__rbit64(v28));
    v30 = 1LL << v29;
    if ( a3 )
    {
      __asm { PRFM            #0x11, [X28] }
      do
        v27 = __ldxr((unsigned __int64 *)&_cpu_partial_halt_mask);
      while ( __stxr(v27 & ~v30, (unsigned __int64 *)&_cpu_partial_halt_mask) );
    }
    else
    {
      __asm { PRFM            #0x11, [X26] }
      do
        v32 = __ldxr((unsigned __int64 *)&_cpu_halt_mask);
      while ( __stxr(v32 & ~v30, (unsigned __int64 *)&_cpu_halt_mask) );
    }
    walt_smp_call_newidle_balance((unsigned int)v29);
    v23 = v29 + 1;
  }
  while ( v29 < 0x1F );
  restrict_cpus_and_freq(_X21);
  return raw_spin_unlock_irqrestore(&halt_lock, v9);
}
