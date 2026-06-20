__int64 __fastcall cam_irq_controller_deinit(__int64 *a1)
{
  __int64 v1; // x19
  _QWORD *v4; // x21
  _QWORD **v5; // x22
  _QWORD *v6; // x8
  __int64 v7; // x9
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  _QWORD *v11; // x0
  _QWORD *v12; // x0

  v1 = *a1;
  if ( *a1 )
  {
    if ( *(_DWORD *)(v1 + 64) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x800000,
        1,
        "cam_irq_controller_deinit",
        349,
        "Unbalanced dependent unregister for controller: %s dep_bitmap:0x%x",
        v1);
      return 4294967274LL;
    }
    else
    {
      v5 = (_QWORD **)(v1 + 72);
      v4 = *(_QWORD **)(v1 + 72);
      if ( v4 != (_QWORD *)(v1 + 72) )
      {
        do
        {
          v6 = (_QWORD *)v4[1];
          if ( (_QWORD *)*v6 == v4 && (v7 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
          {
            *(_QWORD *)(v7 + 8) = v6;
            *v6 = v7;
          }
          else
          {
            _list_del_entry_valid_or_report(v4);
          }
          *v4 = v4;
          v4[1] = v4;
          v8 = (_QWORD *)*(v4 - 8);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v8, 0);
          else
            kvfree(v8);
          v9 = v4 - 9;
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v9, 0);
          else
            kvfree(v9);
          v4 = *v5;
        }
        while ( *v5 != v5 );
      }
      v10 = *(_QWORD **)(v1 + 192);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      v11 = *(_QWORD **)(v1 + 40);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v11, 0);
      else
        kvfree(v11);
      v12 = *(_QWORD **)(v1 + 32);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v12, 0);
      else
        kvfree(v12);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v1, 0);
      else
        kvfree(v1);
      *a1 = 0;
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_deinit",
      342,
      "Null Pointer");
    return 4294967274LL;
  }
}
