__int64 __fastcall mhi_queue(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x20
  unsigned __int64 v6; // x8
  __int64 result; // x0
  void (__fastcall *v8)(_QWORD); // x8
  __int64 lock_irqsave; // x21
  void (__fastcall *v10)(_QWORD); // x8
  void (__fastcall *v11)(_QWORD); // x8
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  void (__fastcall *v17)(__int64, __int64, __int64); // x8
  __int64 v18; // x2
  unsigned int v24; // w9

  v3 = *(_QWORD *)(a1 + 16);
  v4 = 32;
  if ( a3 == 1 )
    v4 = 24;
  if ( *(_DWORD *)(v3 + 336) > 0x7Fu )
    return 4294967291LL;
  v5 = *(_QWORD *)(a1 + v4);
  v6 = *(_QWORD *)(v5 + 152) + *(_QWORD *)(v5 + 160);
  if ( v6 >= *(_QWORD *)(v5 + 136) + *(_QWORD *)(v5 + 168) )
    v6 = *(_QWORD *)(v5 + 136);
  if ( v6 == *(_QWORD *)(v5 + 144) )
    return 4294967285LL;
  result = mhi_gen_tre(*(_QWORD *)(a1 + 16), v5, a2);
  if ( !(_DWORD)result )
  {
    v8 = *(void (__fastcall **)(_QWORD))(v3 + 544);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -2145957670 )
        __break(0x8228u);
      v8(v3);
    }
    lock_irqsave = raw_read_lock_irqsave(v3 + 320);
    if ( (*(_BYTE *)(v3 + 336) & 0x30) != 0 )
    {
      pm_wakeup_dev_event(*(_QWORD *)(v3 + 16) + 40LL, 0, 0);
      v10 = *(void (__fastcall **)(_QWORD))(v3 + 512);
      if ( *((_DWORD *)v10 - 1) != -700558418 )
        __break(0x8228u);
      v10(v3);
      v11 = *(void (__fastcall **)(_QWORD))(v3 + 528);
      if ( *((_DWORD *)v11 - 1) != -2145957670 )
        __break(0x8228u);
      v11(v3);
    }
    v12 = *(void (__fastcall **)(_QWORD))(v3 + 504);
    if ( *((_DWORD *)v12 - 1) != -2145957670 )
      __break(0x8228u);
    v12(v3);
    if ( *(_DWORD *)(v5 + 216) == 1 )
    {
      _X8 = (unsigned int *)(v3 + 356);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 + 1, _X8) );
    }
    if ( (*(_DWORD *)(v3 + 340) & *(_DWORD *)(v3 + 336)) != 0 )
    {
      v14 = *(_QWORD *)(v5 + 152);
      v15 = *(_QWORD *)(v5 + 136);
      v16 = *(_QWORD *)(v5 + 112);
      __dmb(2u);
      **(_QWORD **)(v5 + 120) = v14 - v15 + v16;
      v17 = *(void (__fastcall **)(__int64, __int64, __int64))(v5 + 248);
      v18 = *(_QWORD *)(v5 + 192);
      if ( *((_DWORD *)v17 - 1) != -396405511 )
        __break(0x8228u);
      v17(v3, v5 + 224, v18);
    }
    raw_read_unlock_irqrestore(v3 + 320, lock_irqsave);
    return 0;
  }
  return result;
}
