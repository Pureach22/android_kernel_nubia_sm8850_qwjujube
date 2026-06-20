__int64 __fastcall move_storage_load(__int64 a1)
{
  unsigned __int64 v1; // x10
  int v2; // w25
  char v4; // w8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x20
  __int64 v7; // x8
  int v8; // w8
  char v9; // w9
  unsigned int v10; // w15
  unsigned __int64 v11; // x24
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x22
  __int64 v14; // x9
  __int64 v15; // x10
  unsigned int v16; // w25
  unsigned __int64 v17; // x0
  __int64 v18; // x24
  unsigned int v19; // w22
  char *v20; // x27
  __int64 v21; // x0
  int v22; // w8
  __int64 v23; // x19
  unsigned int v24; // w11
  __int64 v25; // x12
  __int64 v26; // x22
  int v27; // w26
  unsigned __int64 v28; // x24
  unsigned __int16 *v29; // x8
  unsigned __int64 v30; // x8
  __int64 v33; // x8
  __int64 v34; // x21
  __int64 v35; // x1
  unsigned int v40; // w8
  unsigned __int64 v43; // x9
  unsigned __int64 v46; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v52; // x9
  __int64 v53; // [xsp+0h] [xbp-50h]
  int v54; // [xsp+Ch] [xbp-44h]
  __int64 v55; // [xsp+10h] [xbp-40h]
  char *v56; // [xsp+18h] [xbp-38h]
  __int64 v57; // [xsp+20h] [xbp-30h]
  __int64 v58; // [xsp+28h] [xbp-28h]
  __int64 v59; // [xsp+30h] [xbp-20h]
  unsigned int v60; // [xsp+38h] [xbp-18h]
  unsigned __int64 v61[2]; // [xsp+40h] [xbp-10h] BYREF

  v61[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 3400);
  v61[0] = 0;
  if ( v1 >= move_storage_load_next_balance_time_nsec )
  {
    v4 = 0;
    v2 = 0;
    move_storage_load_next_balance_time_nsec = v1 + 3000000;
    while ( 1 )
    {
      v5 = (unsigned int)(-1LL << v4) & _cpu_possible_mask;
      if ( !(_DWORD)v5 )
        goto LABEL_3;
      v6 = __clz(__rbit64(v5));
      if ( (((unsigned __int64)walt_enforce_high_irq_cpu_mask >> v6) & 1) == 0 )
        goto LABEL_5;
      v7 = *((_QWORD *)&_per_cpu_offset + v6);
      if ( (*(_QWORD *)&walt_rq[v7 + 80] & 2) != 0 || *(_DWORD *)((char *)&runqueues + v7 + 3576) )
        goto LABEL_5;
      walt_lb_cpu_util(v6);
      v8 = storage_boost_cpus;
      v9 = 0;
      v10 = -1;
      v11 = -1;
      do
      {
        v12 = v8 & (unsigned int)(-1LL << v9);
        if ( !(_DWORD)v12 )
          break;
        v13 = __clz(__rbit64(v12));
        if ( v13 != v6 )
        {
          v14 = 1LL << v13;
          if ( (_cpu_active_mask & (1LL << v13)) != 0 && (_cpu_halt_mask[0] & v14) == 0 )
          {
            v15 = *((_QWORD *)&_per_cpu_offset + v13);
            if ( (walt_rq[v15 + 541] & 1) == 0
              && (walt_enforce_high_irq_cpu_mask & v14) == 0
              && (*(_QWORD *)&walt_rq[v15 + 80] & 2) == 0
              && !*(_DWORD *)((char *)&runqueues + v15 + 3576)
              && (v61[0] & v14) == 0 )
            {
              v54 = v2;
              v16 = v10;
              v17 = walt_lb_cpu_util(v13);
              v10 = v16;
              v2 = v54;
              v8 = storage_boost_cpus;
              if ( v17 < v11 )
              {
                v10 = v13;
                v11 = v17;
              }
            }
          }
        }
        v9 = v13 + 1;
      }
      while ( v13 < 0x1F );
      if ( (v10 & 0x80000000) != 0 )
        goto LABEL_5;
      if ( v10 >= 0x20 )
        __break(0x5512u);
      v18 = *((_QWORD *)&_per_cpu_offset + v6);
      v19 = v10;
      v20 = (char *)&runqueues + v18;
      v58 = *((_QWORD *)&_per_cpu_offset + v10);
      v21 = raw_spin_lock_irqsave((char *)&runqueues + v18);
      if ( *(_DWORD *)((char *)&runqueues + v18 + 3576) )
      {
        raw_spin_unlock_irqrestore((char *)&runqueues + v18, v21);
        v22 = 0;
        goto LABEL_51;
      }
      v23 = *((_QWORD *)v20 + 456);
      v55 = v21;
      v56 = (char *)&runqueues + v18;
      if ( (char *)v23 == v20 + 3640 )
      {
LABEL_50:
        raw_spin_unlock_irqrestore(v56, v55);
        v22 = 0;
        goto LABEL_51;
      }
      v24 = v19;
      v25 = v18;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v53 = v24;
      v57 = 1LL << v24;
      v60 = v24;
      v59 = v25;
      while ( 1 )
      {
        if ( *(_BYTE *)(v23 + 17) || *(int *)(v23 - 108) < 100 )
          goto LABEL_31;
        if ( (walt_is_idle_task((char *)(v23 - 256)) & 1) == 0 )
          break;
        v24 = v60;
        v25 = v59;
LABEL_31:
        v23 = *(_QWORD *)(v23 + 8);
        if ( (char *)v23 == v20 + 3640 )
          goto LABEL_43;
      }
      v24 = v60;
      v25 = v59;
      if ( (**(_QWORD **)(v23 + 1120) & v57) == 0 )
        goto LABEL_31;
      v29 = (unsigned __int16 *)(v23 + 4928);
      ++v27;
      if ( (_UNKNOWN *)(v23 - 256) == &init_task )
        v29 = (unsigned __int16 *)&vendor_data_pad;
      v30 = v29[79];
      _CF = v28 >= v30;
      if ( v28 <= v30 )
        v28 = v30;
      if ( !_CF )
        v26 = v23 - 256;
      if ( v27 <= 10 )
        goto LABEL_31;
LABEL_43:
      if ( !v26 )
        goto LABEL_50;
      if ( *(_DWORD *)(v26 + 88) )
      {
        _X0 = (unsigned int *)(v26 + 64);
        __asm { PRFM            #0x11, [X0] }
        do
          v40 = __ldxr(_X0);
        while ( __stxr(v40 + 1, _X0) );
        if ( v40 )
        {
          if ( (((v40 + 1) | v40) & 0x80000000) != 0 )
          {
            v35 = 1;
            goto LABEL_58;
          }
        }
        else
        {
          v35 = 2;
LABEL_58:
          refcount_warn_saturate(_X0, v35);
          v24 = v60;
          v25 = v59;
        }
        *((_DWORD *)v56 + 894) = 1;
        *((_DWORD *)v56 + 895) = v24;
        v33 = *((_QWORD *)&_per_cpu_offset + v53);
        *(_QWORD *)&walt_rq[v25] = v26;
        _X8 = (unsigned __int64 *)&walt_rq[v33 + 80];
        __asm { PRFM            #0x11, [X8] }
        do
          v43 = __ldxr(_X8);
        while ( __stlxr(v43 | 2, _X8) );
        __dmb(0xBu);
        raw_spin_unlock_irqrestore(v56, v55);
        if ( (stop_one_cpu_nowait((unsigned int)v6, stop_walt_lb_active_migration, v56, v56 + 3584) & 1) != 0 )
        {
          _X10 = v61;
          __asm { PRFM            #0x11, [X10] }
          do
            v49 = __ldxr(v61);
          while ( __stxr(v49 | v57, v61) );
          wake_up_if_idle(v60);
          v22 = 1;
        }
        else
        {
          _X8 = (unsigned __int64 *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v53) + 80];
          __asm { PRFM            #0x11, [X8] }
          do
            v52 = __ldxr(_X8);
          while ( __stxr(v52 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          v22 = 0;
        }
      }
      else
      {
        _X10 = v61;
        __asm { PRFM            #0x11, [X10] }
        do
          v46 = __ldxr(v61);
        while ( __stxr(v46 | v57, v61) );
        walt_detach_task(v26, (__int64)v56, (__int64)&runqueues + v58);
        raw_spin_unlock_irqrestore(v56, v55);
        v34 = raw_spin_lock_irqsave((char *)&runqueues + v58);
        walt_attach_task(v26, (__int64)&runqueues + v58);
        raw_spin_unlock_irqrestore((char *)&runqueues + v58, v34);
        v22 = 1;
      }
LABEL_51:
      v2 |= v22;
LABEL_5:
      v4 = v6 + 1;
      if ( v6 >= 0x1F )
        goto LABEL_3;
    }
  }
  LOBYTE(v2) = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v2 & 1;
}
