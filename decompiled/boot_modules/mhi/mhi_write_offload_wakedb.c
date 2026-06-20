__int64 __fastcall mhi_write_offload_wakedb(__int64 a1, int a2)
{
  __int64 v2; // x9
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x10
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x10
  unsigned int v18; // w10
  unsigned int v19; // w10
  unsigned int v22; // w10
  unsigned int v23; // w10

  v2 = *(_QWORD *)(a1 + 56);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  _X11 = (unsigned int *)(v5 + 160);
  __asm { PRFM            #0x11, [X11] }
  do
  {
    v18 = __ldxr(_X11);
    v19 = v18 + 1;
  }
  while ( __stlxr(v19, _X11) );
  __dmb(0xBu);
  v6 = v19 & 0x1FF;
  v7 = *(_QWORD *)(v5 + 152) + 16 * v6;
  if ( *(_BYTE *)(v7 + 12) == 1 )
    goto LABEL_6;
  *(_QWORD *)v7 = v2 + 4;
  *(_DWORD *)(*(_QWORD *)(v5 + 152) + 16 * v6 + 8) = a2 >> 31;
  __dmb(0xAu);
  *(_BYTE *)(*(_QWORD *)(v5 + 152) + 16 * v6 + 12) = 1;
  __dmb(0xAu);
  queue_work_on(32, *(_QWORD *)(v5 + 112), v5 + 120);
  v8 = *(_QWORD *)(a1 + 56);
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  _X11 = (unsigned int *)(v9 + 160);
  __asm { PRFM            #0x11, [X11] }
  do
  {
    v22 = __ldxr(_X11);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X11) );
  __dmb(0xBu);
  v6 = v23 & 0x1FF;
  v10 = *(_QWORD *)(v9 + 152) + 16 * v6;
  if ( *(_BYTE *)(v10 + 12) == 1 )
LABEL_6:
    panic("queue full idx %d", v6);
  *(_QWORD *)v10 = v8;
  *(_DWORD *)(*(_QWORD *)(v9 + 152) + 16 * v6 + 8) = a2;
  __dmb(0xAu);
  *(_BYTE *)(*(_QWORD *)(v9 + 152) + 16 * v6 + 12) = 1;
  __dmb(0xAu);
  return queue_work_on(32, *(_QWORD *)(v9 + 112), v9 + 120);
}
