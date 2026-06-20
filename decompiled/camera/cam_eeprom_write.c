__int64 __fastcall cam_eeprom_write(__int64 a1)
{
  _QWORD **v2; // x22
  _QWORD *v3; // x21
  unsigned int v4; // w20
  _QWORD *v5; // x21
  _QWORD *v6; // x25
  _QWORD *v7; // x0
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  _QWORD *v10; // x0

  v2 = (_QWORD **)(a1 + 4344);
  if ( *(_DWORD *)(a1 + 4360) != 1 || (v3 = *v2, *v2 == v2) )
  {
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = camera_io_dev_write_continuous(a1 + 3664, v3 - 9, 1);
      if ( (v4 & 0x80000000) != 0 )
        break;
      v3 = (_QWORD *)*v3;
      if ( v3 == v2 )
        goto LABEL_7;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_write",
      1209,
      "Error in EEPROM write");
  }
LABEL_7:
  v5 = *v2;
  if ( *v2 != v2 )
  {
    do
    {
      v6 = (_QWORD *)*v5;
      v7 = (_QWORD *)*(v5 - 3);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v7, 0);
      else
        kvfree(v7);
      v8 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v8 == v5 && (v9 = (_QWORD *)*v5, *(_QWORD **)(*v5 + 8LL) == v5) )
      {
        v9[1] = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      v10 = v5 - 9;
      *v5 = 0xDEAD000000000100LL;
      v5[1] = 0xDEAD000000000122LL;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      v5 = v6;
    }
    while ( v6 != v2 );
  }
  *(_QWORD *)(a1 + 4344) = a1 + 4344;
  *(_QWORD *)(a1 + 4352) = v2;
  *(_DWORD *)(a1 + 4360) = 0;
  return v4;
}
