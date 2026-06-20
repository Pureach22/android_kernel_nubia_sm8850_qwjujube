__int64 __fastcall delete_request(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x24
  _QWORD *v4; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x0

  if ( a1 )
  {
    v1 = *(_QWORD **)a1;
    if ( *(_QWORD *)a1 != a1 )
    {
      do
      {
        v3 = (_QWORD *)*v1;
        v4 = (_QWORD *)*(v1 - 9);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v4, 0);
        else
          kvfree(v4);
        v5 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v5 == v1 && (v6 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
        {
          v6[1] = v5;
          *v5 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        v7 = v1 - 9;
        *v1 = 0xDEAD000000000100LL;
        v1[1] = 0xDEAD000000000122LL;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v7, 0);
        else
          kvfree(v7);
        v1 = v3;
      }
      while ( v3 != (_QWORD *)a1 );
    }
    *(_QWORD *)a1 = a1;
    *(_QWORD *)(a1 + 8) = a1;
    *(_DWORD *)(a1 + 16) = 0;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "delete_request",
      172,
      "FATAL:: Invalid argument");
    return 4294967274LL;
  }
}
