__int64 __fastcall cam_tasklet_start(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x12
  __int64 v4; // x10
  __int64 v5; // x13
  _QWORD *v6; // x8
  __int64 v7; // x11
  __int64 v8; // x14
  __int64 *v9; // x1
  unsigned int v16; // w10

  v1 = a1;
  if ( *(_DWORD *)(a1 + 24) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_tasklet_start",
      299,
      "Tasklet already active idx:%d",
      *(_DWORD *)(a1 + 16));
    return 4294967280LL;
  }
  else
  {
    v3 = 0;
    v4 = a1 + 72;
    do
    {
      v5 = v1 + v3;
      v6 = *(_QWORD **)(v1 + v3 + 112);
      v7 = v1 + v3 + 104;
      if ( v7 == *v6 && (v8 = *(_QWORD *)v7, v7 == *(_QWORD *)(*(_QWORD *)v7 + 8LL)) )
      {
        *(_QWORD *)(v8 + 8) = v6;
        *v6 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v1 + v3 + 104);
      }
      *(_QWORD *)(v5 + 104) = v5 + 104;
      *(_QWORD *)(v5 + 112) = v7;
      v9 = *(__int64 **)(v1 + 80);
      if ( (__int64 *)v7 == v9 || *v9 != v4 )
      {
        _list_add_valid_or_report(v7);
      }
      else
      {
        *(_QWORD *)(v1 + 80) = v7;
        *(_QWORD *)(v5 + 104) = v4;
        *(_QWORD *)(v5 + 112) = v9;
        *v9 = v7;
      }
      v3 += 48;
    }
    while ( v3 != 12288 );
    *(_DWORD *)(v1 + 24) = 1;
    __dmb(0xBu);
    _X8 = (unsigned int *)(v1 + 48);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 - 1, _X8) );
    return 0;
  }
}
