__int64 __fastcall btfmcodec_ioctl(__int64 a1, int a2, int a3)
{
  __int64 v5; // x23
  void *v6; // x0
  __int64 v7; // x22
  void *v8; // x0
  void *v9; // x0
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v26; // x9

  v5 = *(_QWORD *)(a1 + 32);
  if ( (unsigned __int8)log_lvl <= 7u )
    v6 = &unk_D3DA;
  else
    v6 = &unk_D865;
  printk(v6, "btfmcodec_ioctl");
  mutex_lock(v5 + 1040);
  v7 = *(_QWORD *)(v5 + 984);
  if ( v7 )
  {
    mutex_unlock(v5 + 1040);
    if ( a2 == 49071 )
    {
      if ( a3 == 1 )
      {
        if ( !strcmp((const char *)(v7 + 8), "btfmslim") )
        {
          _X8 = (unsigned __int64 *)(v7 + 104);
          __asm { PRFM            #0x11, [X8] }
          do
            v23 = __ldxr(_X8);
          while ( __stxr(v23 | 1, _X8) );
        }
        else if ( !strcmp((const char *)(v7 + 8), "btfmswr_slave") )
        {
          _X8 = (unsigned __int64 *)(v7 + 104);
          __asm { PRFM            #0x11, [X8] }
          do
            v26 = __ldxr(_X8);
          while ( __stxr(v26 | 2, _X8) );
        }
        if ( (unsigned __int8)log_lvl < 8u )
          v8 = &unk_C318;
        else
          v8 = &unk_C006;
      }
      else
      {
        _X8 = (unsigned __int64 *)(v7 + 104);
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr(_X8);
        while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        _X8 = (unsigned __int64 *)(v7 + 104);
        __asm { PRFM            #0x11, [X8] }
        do
          v16 = __ldxr(_X8);
        while ( __stxr(v16 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        if ( (unsigned __int8)log_lvl < 8u )
          v8 = &unk_DDBD;
        else
          v8 = &unk_CADC;
      }
      printk(v8, "btfmcodec_ioctl");
      if ( (unsigned __int8)log_lvl < 8u )
        v9 = &unk_D093;
      else
        v9 = &unk_D613;
      printk(v9, "btfmcodec_ioctl");
    }
    else
    {
      printk(&unk_CDFB, "btfmcodec_ioctl");
    }
  }
  else
  {
    printk(&unk_D059, "btfmcodec_ioctl");
    printk(&unk_C2F7, "btfmcodec_ioctl");
    is_cp_supported = a3 == 1;
    mutex_unlock(v5 + 1040);
  }
  return 0;
}
