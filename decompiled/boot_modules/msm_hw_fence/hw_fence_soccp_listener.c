__int64 __fastcall hw_fence_soccp_listener(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x20
  __int64 v7; // x0
  unsigned int v14; // w8
  _QWORD v16[6]; // [xsp+0h] [xbp-30h] BYREF

  v5 = a1 + 0x8000;
  v16[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 33520) == 1 )
  {
    do
    {
      if ( !*(_DWORD *)(v5 + 832) )
      {
        memset(v16, 0, 40);
        init_wait_entry(v16, 0);
        while ( 1 )
        {
          v7 = prepare_to_wait_event(a1 + 33576, v16, 2);
          if ( *(_DWORD *)(v5 + 832) )
            break;
          schedule(v7);
        }
        finish_wait(a1 + 33576, v16);
      }
      _X10 = (unsigned int *)(v5 + 832);
      __asm { PRFM            #0x11, [X10] }
      do
        v14 = __ldxr(_X10);
      while ( __stlxr(0, _X10) );
      __dmb(0xBu);
      if ( v14 )
        hw_fence_utils_process_signaled_clients_mask(a1, v14, a3, a4, a5);
    }
    while ( (*(_BYTE *)(v5 + 752) & 1) != 0 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
