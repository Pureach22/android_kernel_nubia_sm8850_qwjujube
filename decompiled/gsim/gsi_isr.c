__int64 gsi_isr()
{
  _DWORD *v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  void (__fastcall *v3)(_QWORD); // x9
  __int64 (*v4)(void); // x8
  int v5; // w0
  __int64 v6; // x8
  void (*v7)(void); // x8
  unsigned int v15; // w9
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = *(_DWORD **)(gsi_ctx + 112);
  if ( v0 )
  {
    v1 = *(_QWORD *)(gsi_ctx + 128);
    v16[0] = 0;
    if ( *(v0 - 1) != -1974482485 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _BYTE *))v0)(v1, v16);
    if ( v16[0] == 1 )
    {
      gsi_handle_irq();
      v3 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 120);
      v2 = *(_QWORD *)(gsi_ctx + 128);
      if ( *((_DWORD *)v3 - 1) != -1066802076 )
        __break(0x8229u);
      v3(v2);
    }
  }
  else
  {
    v4 = *(__int64 (**)(void))(gsi_ctx + 136);
    if ( *((_DWORD *)v4 - 1) != 1874538549 )
      __break(0x8228u);
    v5 = v4();
    v6 = gsi_ctx;
    if ( v5 )
    {
      *(_DWORD *)(gsi_ctx + 29268) = 0;
      gsi_handle_irq();
    }
    else
    {
      if ( *(_DWORD *)(gsi_ctx + 29268) == 5 )
      {
        v7 = *(void (**)(void))(gsi_ctx + 144);
        if ( *((_DWORD *)v7 - 1) != -440107680 )
          __break(0x8228u);
        v7();
        v6 = gsi_ctx;
      }
      _X8 = (unsigned int *)(v6 + 29268);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 + 1, _X8) );
    }
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
