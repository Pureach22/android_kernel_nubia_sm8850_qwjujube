__int64 __fastcall ucsi_qti_glink_write(__int64 a1, __int64 *a2, char a3)
{
  const char *v5; // x1
  __int64 v7; // x8
  unsigned int v8; // w9
  unsigned __int64 v10; // x2
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x2
  __int64 v16; // x3
  unsigned int v17; // w21
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x10

  if ( *(unsigned __int16 *)(a1 + 1360) >= 0x211u )
  {
    printk(&unk_757A, "validate_ucsi_msg", 8, 8);
    return (unsigned int)-22;
  }
  if ( (a3 & 1) != 0 )
    v5 = "sync_write:";
  else
    v5 = "async_write:";
  ucsi_log(a1, v5, 8, (__int64)a2, 8u);
  if ( *(_DWORD *)(a1 + 1448) )
  {
    mutex_lock(a1 + 176);
    memset((void *)(a1 + 828), 0, 0x214u);
    *(_DWORD *)(a1 + 824) = 18;
    *(_QWORD *)(a1 + 816) = 0x10000800BLL;
    v7 = *a2;
    *(_DWORD *)(a1 + 64) = 0;
    v8 = *(unsigned __int16 *)(a1 + 1360);
    if ( v8 - 289 < 0xF0 || v8 == 0 )
      v10 = 544;
    else
      v10 = (unsigned __int64)(v8 < 0x121) << 6;
    *(_QWORD *)(a1 + 836) = v7;
    if ( (a3 & 1) != 0 )
    {
      _X8 = (unsigned __int64 *)(a1 + 1368);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 | 2, _X8) );
      *(_DWORD *)(a1 + 96) = 0;
    }
    v11 = pmic_glink_write(*(_QWORD *)(a1 + 16), a1 + 816, v10);
    if ( (v11 & 0x80000000) != 0 )
    {
      v17 = v11;
      printk(&unk_72C1, "ucsi_qti_glink_write", v11, v12);
      if ( (a3 & 1) == 0 )
        goto LABEL_22;
    }
    else
    {
      if ( (unsigned int)wait_for_completion_timeout(a1 + 64, 1250) )
      {
        if ( (a3 & 1) != 0 )
        {
          if ( (unsigned int)wait_for_completion_timeout(a1 + 96, 1250) )
          {
            v17 = 0;
          }
          else
          {
            printk(&unk_73F1, "ucsi_qti_glink_write", v15, v16);
            v17 = -110;
          }
          goto LABEL_32;
        }
        v17 = 0;
LABEL_22:
        mutex_unlock(a1 + 176);
        return v17;
      }
      printk(&unk_7436, "ucsi_qti_glink_write", v13, v14);
      v17 = -110;
      if ( (a3 & 1) == 0 )
        goto LABEL_22;
    }
LABEL_32:
    _X8 = (unsigned __int64 *)(a1 + 1368);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    goto LABEL_22;
  }
  return 0;
}
