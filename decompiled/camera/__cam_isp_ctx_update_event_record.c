__int64 __fastcall _cam_isp_ctx_update_event_record(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "__cam_isp_ctx_update_event_record",
             98,
             "Invalid Args");
  if ( a2 <= 1 && !a3 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             1,
             "__cam_isp_ctx_update_event_record",
             110,
             "Invalid arg for event %d",
             a2);
  _X9 = (unsigned __int64 *)(a1 + 42112 + 8LL * a2);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v17 = __ldxr(_X9);
    v18 = v17 + 1;
  }
  while ( __stlxr(v18, _X9) );
  __dmb(0xBu);
  v6 = v18 & 7;
  result = ktime_get_with_offset(1);
  v7 = a1 + ((unsigned __int64)a2 << 9);
  if ( a3 )
  {
    v8 = *(_QWORD *)(a3 + 32);
    *(_QWORD *)(v7 + (v6 << 6) + 42160) = *(_QWORD *)(a3 + 24);
    *(_QWORD *)(v8 + 8LL * a2 + 4456) = result;
  }
  else
  {
    *(_QWORD *)(v7 + (v6 << 6) + 42160) = 0;
  }
  v9 = a1 + 42160 + ((unsigned __int64)a2 << 9) + (v6 << 6);
  *(_QWORD *)(v9 + 8) = result;
  if ( a4 )
  {
    *(_DWORD *)(v9 + 16) = a2;
    if ( a2 == 5 )
    {
      v10 = *(_QWORD *)(a4 + 8);
      *(_QWORD *)v9 = v10;
      *(_QWORD *)(v9 + 32) = v10;
      *(_DWORD *)(v9 + 40) = *(_DWORD *)(a4 + 16);
      *(_QWORD *)(v9 + 24) = *(_QWORD *)a4;
      *(_QWORD *)(v9 + 48) = *(_QWORD *)(a4 + 24);
      *(_QWORD *)(v9 + 56) = *(_QWORD *)(a4 + 32);
    }
  }
  return result;
}
