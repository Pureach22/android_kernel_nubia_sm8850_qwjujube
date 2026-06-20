__int64 __fastcall gen7_hwsched_process_dbgq(__int64 a1, char a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x9
  __int64 v8; // [xsp+18h] [xbp-58h] BYREF
  __int64 v9; // [xsp+20h] [xbp-50h]
  __int64 v10; // [xsp+28h] [xbp-48h]
  __int64 v11; // [xsp+30h] [xbp-40h]
  __int64 v12; // [xsp+38h] [xbp-38h]
  __int64 v13; // [xsp+40h] [xbp-30h]
  __int64 v14; // [xsp+48h] [xbp-28h]
  __int64 v15; // [xsp+50h] [xbp-20h]
  __int64 v16; // [xsp+58h] [xbp-18h]
  int v17; // [xsp+60h] [xbp-10h]
  __int64 v18; // [xsp+68h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = to_gen7_gmu(a1);
  v17 = 0;
  _ReadStatusReg(SP_EL0);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 0;
  do
  {
    result = gen7_hfi_queue_read(v4, 2u, &v8, 0x4Cu);
    if ( (int)result < 1 )
      break;
    switch ( (unsigned __int8)v8 )
    {
      case 'e':
        result = adreno_gen7_receive_debug_req(v4);
        if ( (unsigned __int8)v8 == 102 )
          goto LABEL_9;
        break;
      case 'd':
        adreno_gen7_receive_err_req(v4, (__int64)&v8);
        result = gen7_hwsched_fault(a1, 32);
        goto LABEL_14;
      case 'f':
LABEL_9:
        result = to_gen7_gmu(a1);
        v6 = HIDWORD(v9) - v9;
        if ( HIDWORD(v9) != (_DWORD)v9 )
        {
          v7 = *(_QWORD *)(*(_QWORD *)(result + 16) + 8LL) + 4LL * (unsigned int)(4 * v9);
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
