__int64 __fastcall _cam_isp_ctx_update_frame_timing_record(__int64 result, __int64 a2)
{
  unsigned __int64 *v4; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x1
  unsigned __int64 v8; // x8
  __int64 *v9; // x19
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x19
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x1
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9

  _X8 = (unsigned __int64 *)(a2 + 45232);
  if ( (_DWORD)result == 3 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v23 = __ldxr(_X8);
      v24 = v23 + 1;
    }
    while ( __stlxr(v24, _X8) );
    __dmb(0xBu);
    v4 = (unsigned __int64 *)(a2 + ((v24 % 5) << 6) + 45240);
    v5 = ktime_get_with_offset(1);
    result = ns_to_timespec64(v5);
    v6 = *(_QWORD *)(a2 + 37312);
    v4[4] = result;
    v4[5] = v7;
    *v4 = v6 / 0x3B9ACA00;
    v4[1] = v6 % 0x3B9ACA00;
  }
  else
  {
    v8 = *_X8 % 5;
    switch ( (_DWORD)result )
    {
      case 6:
        v15 = a2 + (v8 << 6) + 45240;
        v16 = ktime_get_with_offset(1);
        result = ns_to_timespec64(v16);
        *(_QWORD *)(v15 + 48) = result;
        *(_QWORD *)(v15 + 56) = v17;
        break;
      case 4:
        v12 = a2 + (v8 << 6) + 45240;
        v13 = ktime_get_with_offset(1);
        result = ns_to_timespec64(v13);
        *(_QWORD *)(v12 + 16) = result;
        *(_QWORD *)(v12 + 24) = v14;
        break;
      case 1:
        v9 = (__int64 *)(a2 + (v8 << 6) + 45240);
        v10 = ktime_get_with_offset(result);
        result = ns_to_timespec64(v10);
        *v9 = result;
        v9[1] = v11;
        break;
    }
  }
  return result;
}
