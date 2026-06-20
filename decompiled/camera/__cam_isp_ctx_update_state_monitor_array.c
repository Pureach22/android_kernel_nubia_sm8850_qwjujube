__int64 __fastcall _cam_isp_ctx_update_state_monitor_array(__int64 result, int a2, __int64 a3)
{
  _QWORD *v3; // x8
  unsigned __int64 v5; // x19
  __int64 v6; // x21
  unsigned __int64 v7; // x20
  __int64 v8; // x10
  __int64 v9; // x9
  unsigned __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x0
  __int64 v13; // x1
  unsigned __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x1
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9

  v3 = *(_QWORD **)result;
  _X10 = (unsigned __int64 *)(result + 37400);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v22 = __ldxr(_X10);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X10) );
  __dmb(0xBu);
  v5 = v23 % 0x54;
  v6 = result + 37408;
  v7 = result + 37408 + 56 * (v23 % 0x54);
  v8 = *(_QWORD *)(result + 8);
  *(_DWORD *)v7 = *(_DWORD *)(result + 20);
  *(_DWORD *)(v7 + 4) = a2;
  *(_QWORD *)(v7 + 8) = a3;
  *(_QWORD *)(v7 + 16) = v8;
  if ( a2 == 11 )
  {
    v9 = v3[66];
    v10 = v6 + 56 * v5;
    *(_QWORD *)(v7 + 24) = v3[65];
    *(_QWORD *)(v7 + 32) = v9;
    v11 = v3[68];
    *(_QWORD *)(v10 + 40) = v3[67];
    *(_QWORD *)(v10 + 48) = v11;
  }
  else
  {
    v12 = ktime_get_with_offset(2);
    *(_QWORD *)(v7 + 24) = ns_to_timespec64(v12);
    *(_QWORD *)(v7 + 32) = v13;
    v14 = v6 + 56 * v5;
    v15 = ktime_get_with_offset(1);
    result = ns_to_timespec64(v15);
    *(_QWORD *)(v14 + 40) = result;
    *(_QWORD *)(v14 + 48) = v16;
  }
  return result;
}
