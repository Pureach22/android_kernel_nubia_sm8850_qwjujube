__int64 __fastcall bam_dma_irq(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x8
  unsigned __int64 i; // x24
  __int64 v5; // x26
  __int64 v6; // x0
  unsigned int v7; // w0
  _QWORD *v8; // x22
  int v9; // w14
  int v10; // w13
  __int64 v11; // x23
  int v12; // w8
  unsigned int v13; // w21
  unsigned int v14; // w8
  _QWORD *v15; // x28
  unsigned __int16 v16; // w8
  unsigned int v17; // w10
  __int64 v18; // x20
  __int64 v19; // x9
  int v20; // w8
  int v21; // w8
  __int64 v22; // x9
  _QWORD *v23; // x0
  __int64 v24; // x2
  _QWORD *v25; // x1
  _QWORD *v26; // x2
  _QWORD *v27; // x0
  _QWORD *v28; // x8
  __int64 v29; // x9
  unsigned __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x20
  unsigned __int64 v43; // x8
  unsigned int v44; // [xsp+Ch] [xbp-14h]
  __int64 v45; // [xsp+18h] [xbp-8h]

  v44 = readl_relaxed(
          *(_QWORD *)a2
        + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 176LL)
        + (unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 188LL)));
  if ( (v44 & 0x7FFFFFFF) != 0 )
  {
    v3 = *(unsigned int *)(a2 + 416);
    if ( (_DWORD)v3 )
    {
      for ( i = 0; i < v3; ++i )
      {
        if ( ((v44 >> i) & 1) != 0 )
        {
          v5 = *(_QWORD *)(a2 + 408) + 408 * i;
          v6 = readl_relaxed(
                 *(_QWORD *)a2
               + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 256LL)
               + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 260LL) * i)
               + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 264LL) * i)
               + (unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 268LL)));
          writel_relaxed(
            v6,
            *(_QWORD *)a2
          + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 272LL)
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 276LL) * i)
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 280LL) * i)
          + (unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 284LL)));
          v45 = raw_spin_lock_irqsave(v5 + 160);
          v7 = readl_relaxed(
                 *(_QWORD *)a2
               + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 336LL)
               + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 340LL) * i)
               + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 440) + 344LL) * i)
               + (unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 348LL)));
          v8 = *(_QWORD **)(v5 + 376);
          v9 = 31;
          v10 = 4095;
          if ( v8 != (_QWORD *)(v5 + 376) )
          {
            v11 = v5 + 200;
            if ( *(_BYTE *)(a2 + 532) )
              v12 = 31;
            else
              v12 = 4095;
            v13 = (__PAIR64__(((v7 >> 3) - *(unsigned __int16 *)(v5 + 360)) & v12, (unsigned __int16)v7 >> 3)
                 - *(unsigned __int16 *)(v5 + 360)) >> 32;
            do
            {
              v14 = *((_DWORD *)v8 - 5);
              if ( v13 < v14 )
                break;
              v15 = (_QWORD *)*v8;
              v16 = *(_WORD *)(v5 + 360) + v14;
              *(_WORD *)(v5 + 360) = v16;
              if ( *(_BYTE *)(a2 + 532) )
                v17 = v9;
              else
                v17 = v10;
              *(_WORD *)(v5 + 360) = v16 % v17;
              v18 = *((unsigned int *)v8 - 5);
              v19 = *(v8 - 1) + 8 * v18;
              v20 = *((_DWORD *)v8 - 6) - v18;
              *((_DWORD *)v8 - 6) = v20;
              *(v8 - 1) = v19;
              if ( v20 )
              {
                v26 = *(_QWORD **)v11;
                v27 = v8 - 5;
                if ( *(_QWORD *)(*(_QWORD *)v11 + 8LL) != v11 || v27 == (_QWORD *)v11 || v26 == v27 )
                {
                  _list_add_valid_or_report(v27, v5 + 200);
                }
                else
                {
                  v26[1] = v27;
                  *(v8 - 5) = v26;
                  *(v8 - 4) = v11;
                  *(_QWORD *)v11 = v27;
                }
              }
              else
              {
                v21 = *((_DWORD *)v8 - 48);
                if ( v21 <= 0 )
                {
                  __break(0x800u);
                  goto LABEL_48;
                }
                v22 = *(v8 - 22);
                v23 = v8 - 5;
                *(_DWORD *)(v22 + 20) = v21;
                v24 = v22 + 216;
                *((_DWORD *)v8 - 48) = 0;
                v25 = *(_QWORD **)(v22 + 224);
                if ( v8 - 5 == (_QWORD *)(v22 + 216) || v25 == v23 || *v25 != v24 )
                {
                  _list_add_valid_or_report(v23, v25);
                }
                else
                {
                  *(_QWORD *)(v22 + 224) = v23;
                  *(v8 - 5) = v24;
                  *(v8 - 4) = v25;
                  *v25 = v23;
                }
                _X10 = (unsigned __int64 *)(v22 + 120);
                __asm { PRFM            #0x11, [X10] }
                do
                  v36 = __ldxr(_X10);
                while ( __stlxr(v36 | 1, _X10) );
                __dmb(0xBu);
                if ( (v36 & 1) == 0 )
                {
                  _tasklet_schedule(v22 + 112);
                  v9 = 31;
                  v10 = 4095;
                }
              }
              v28 = (_QWORD *)v8[1];
              if ( (_QWORD *)*v28 == v8 && (v29 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
              {
                *(_QWORD *)(v29 + 8) = v28;
                *v28 = v29;
              }
              else
              {
                _list_del_entry_valid_or_report(v8);
              }
              v13 -= v18;
              *v8 = 0xDEAD000000000100LL;
              v8[1] = 0xDEAD000000000122LL;
              v8 = v15;
            }
            while ( v15 != (_QWORD *)(v5 + 376) );
          }
          raw_spin_unlock_irqrestore(v5 + 160, v45);
          v3 = *(unsigned int *)(a2 + 416);
        }
      }
    }
LABEL_48:
    _X9 = (unsigned __int64 *)(a2 + 472);
    __asm { PRFM            #0x11, [X9] }
    do
      v43 = __ldxr(_X9);
    while ( __stlxr(v43 | 1, _X9) );
    __dmb(0xBu);
    if ( (v43 & 1) == 0 )
      _tasklet_schedule(a2 + 464);
  }
  v37 = _pm_runtime_resume(*(_QWORD *)(a2 + 8), 4);
  if ( (v37 & 0x80000000) != 0 )
    return 0;
  if ( (v44 & 0x80000000) != 0 )
  {
    v38 = readl_relaxed(
            *(_QWORD *)a2
          + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 112LL)
          + (unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 124LL)));
    __dsb(0xFu);
    v37 = writel_relaxed(
            v38,
            *(_QWORD *)a2
          + *(unsigned int *)(*(_QWORD *)(a2 + 440) + 128LL)
          + (unsigned int)(*(_DWORD *)(a2 + 424) * *(_DWORD *)(*(_QWORD *)(a2 + 440) + 140LL)));
  }
  v39 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)(v39 + 520) = ktime_get_mono_fast_ns(v37);
  _pm_runtime_suspend(*(_QWORD *)(a2 + 8), 13);
  return 1;
}
