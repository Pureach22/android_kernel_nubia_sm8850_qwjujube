__int64 __fastcall mhi_write_reg_offload(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x8
  unsigned int v15; // w8
  unsigned int v16; // w8

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  _X10 = (unsigned int *)(v4 + 160);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v15 = __ldxr(_X10);
    v16 = v15 + 1;
  }
  while ( __stlxr(v16, _X10) );
  __dmb(0xBu);
  v5 = v16 & 0x1FF;
  v6 = *(_QWORD *)(v4 + 152) + 16LL * (unsigned int)v5;
  if ( *(_BYTE *)(v6 + 12) == 1 )
    panic("queue full idx %d", v5);
  v7 = 16 * v5;
  *(_QWORD *)v6 = a2 + a3;
  *(_DWORD *)(*(_QWORD *)(v4 + 152) + v7 + 8) = a4;
  __dmb(0xAu);
  *(_BYTE *)(*(_QWORD *)(v4 + 152) + v7 + 12) = 1;
  __dmb(0xAu);
  return queue_work_on(32, *(_QWORD *)(v4 + 112), v4 + 120);
}
