__int64 __fastcall walt_halt_cpus(unsigned __int64 *a1, char a2, unsigned int a3)
{
  _DWORD *v6; // x0
  __int64 v7; // x25
  _DWORD *v8; // x1
  char v9; // w10
  unsigned __int64 v14; // x12
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x10
  unsigned __int64 v18; // x10
  char v19; // w8
  char v20; // w9
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  __int64 v23; // x10
  bool v24; // cc
  unsigned int v25; // w24
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x23
  int v31; // w9
  int v32; // w8
  __int64 v33; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // x0
  char v38; // w19
  char v40; // w9
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x9
  __int64 v43; // x10
  _DWORD *v44; // [xsp+8h] [xbp-8h]

  _X22 = a1;
  v6 = (_DWORD *)raw_spin_lock_irqsave(&halt_lock);
  v7 = *(unsigned int *)_X22;
  v8 = v6;
  v9 = 0;
  while ( 1 )
  {
    v16 = *_X22;
    v17 = (unsigned int)(-1LL << v9) & (unsigned int)*_X22;
    if ( !(_DWORD)v17 )
      break;
    v18 = __clz(__rbit64(v17));
    if ( halt_state[*((_QWORD *)&_per_cpu_offset + v18) + a3] )
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v14 = __ldxr(_X22);
      while ( __stxr(v14 & ~(1LL << v18), _X22) );
    }
    _CF = v18 >= 0x1F;
    v9 = v18 + 1;
    if ( _CF )
    {
      LODWORD(v16) = *(_DWORD *)_X22;
      break;
    }
  }
  if ( (_DWORD)v16 )
  {
    v44 = v6;
    v19 = 0;
    do
    {
      v29 = (unsigned int)(-1LL << v19) & *(_DWORD *)_X22;
      if ( !(_DWORD)v29 )
        break;
      v30 = __clz(__rbit64(v29));
      v6 = (_DWORD *)system_32bit_el0_cpumask(v6);
      v31 = __clz(__rbit64((unsigned int)*v6));
      if ( *v6 )
        v32 = v31;
      else
        v32 = 32;
      if ( v32 == (_DWORD)v30 )
      {
        v25 = -22;
        v38 = 1;
        goto LABEL_31;
      }
      v33 = 1LL << v30;
      if ( a3 )
      {
        _X11 = &_cpu_partial_halt_mask;
        __asm { PRFM            #0x11, [X11] }
        do
          v28 = __ldxr((unsigned __int64 *)&_cpu_partial_halt_mask);
        while ( __stxr(v28 | v33, (unsigned __int64 *)&_cpu_partial_halt_mask) );
      }
      else
      {
        _X11 = &_cpu_halt_mask;
        __asm { PRFM            #0x11, [X11] }
        do
          v36 = __ldxr((unsigned __int64 *)&_cpu_halt_mask);
        while ( __stxr(v36 | v33, (unsigned __int64 *)&_cpu_halt_mask) );
      }
      __dsb(0xEu);
      v19 = v30 + 1;
    }
    while ( v30 < 0x1F );
    restrict_cpus_and_freq(_X22);
    if ( !a3 )
    {
      v37 = raw_spin_lock_irqsave(&walt_drain_pending_lock);
      drain_data |= *_X22;
      raw_spin_unlock_irqrestore(&walt_drain_pending_lock, v37);
      wake_up_process(walt_drain_thread);
    }
    v38 = 0;
    v25 = 0;
LABEL_31:
    if ( (v38 & 1) != 0 )
    {
      v8 = v44;
    }
    else
    {
      v8 = v44;
      v40 = 0;
      do
      {
        v41 = v7 & (-1LL << v40);
        if ( !v41 )
          break;
        v42 = __clz(__rbit64(v41));
        v43 = *((_QWORD *)&_per_cpu_offset + v42);
        _CF = v42 >= 0x1F;
        v40 = v42 + 1;
        halt_state[v43 + a3] |= a2;
      }
      while ( !_CF );
    }
  }
  else
  {
    v20 = 0;
    do
    {
      v21 = v7 & (-1LL << v20);
      if ( !v21 )
        break;
      v22 = __clz(__rbit64(v21));
      v23 = *((_QWORD *)&_per_cpu_offset + v22);
      v24 = v22 > 0x1E;
      v20 = v22 + 1;
      halt_state[v23 + a3] |= a2;
    }
    while ( !v24 );
    v25 = 0;
  }
  raw_spin_unlock_irqrestore(&halt_lock, v8);
  return v25;
}
