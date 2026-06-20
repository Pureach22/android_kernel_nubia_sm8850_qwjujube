__int64 __fastcall a6xx_hwsched_process_dbgq(__int64 a1, char a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x9
  unsigned int v14; // w9
  __int64 v15; // [xsp+18h] [xbp-58h] BYREF
  __int64 v16; // [xsp+20h] [xbp-50h]
  __int64 v17; // [xsp+28h] [xbp-48h]
  __int64 v18; // [xsp+30h] [xbp-40h]
  __int64 v19; // [xsp+38h] [xbp-38h]
  __int64 v20; // [xsp+40h] [xbp-30h]
  __int64 v21; // [xsp+48h] [xbp-28h]
  __int64 v22; // [xsp+50h] [xbp-20h]
  __int64 v23; // [xsp+58h] [xbp-18h]
  int v24; // [xsp+60h] [xbp-10h]
  __int64 v25; // [xsp+68h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = to_a6xx_gmu(a1);
  v24 = 0;
  _ReadStatusReg(SP_EL0);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  do
  {
    result = a6xx_hfi_queue_read(v4, 2u, &v15, 0x4Cu);
    if ( (int)result < 1 )
      break;
    switch ( (unsigned __int8)v15 )
    {
      case 'e':
        result = adreno_a6xx_receive_debug_req(v4);
        if ( (unsigned __int8)v15 == 102 )
          goto LABEL_9;
        break;
      case 'd':
        ((void (__fastcall *)(__int64, __int64 *))adreno_a6xx_receive_err_req)(v4, &v15);
        _X8 = (unsigned int *)(a1 + 24448);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 | 0x20, _X8) );
        __dmb(0xAu);
        result = kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
        goto LABEL_14;
      case 'f':
LABEL_9:
        result = to_a6xx_gmu(a1);
        v6 = HIDWORD(v16) - v16;
        if ( HIDWORD(v16) != (_DWORD)v16 )
        {
          v7 = *(_QWORD *)(*(_QWORD *)(result + 24) + 8LL) + 4LL * (unsigned int)(4 * v16);
          do
          {
            --v6;
            v7 += 16;
          }
          while ( v6 );
        }
        break;
    }
  }
  while ( (a2 & 1) == 0 );
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
