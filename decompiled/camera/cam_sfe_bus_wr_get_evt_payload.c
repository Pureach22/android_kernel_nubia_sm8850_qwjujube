__int64 __fastcall cam_sfe_bus_wr_get_evt_payload(__int64 a1, _QWORD *a2)
{
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  __int64 v6; // x10
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x0

  raw_spin_lock(a1 + 744);
  if ( (*(_BYTE *)(a1 + 27448) & 1) != 0 )
  {
    v4 = *(_QWORD **)(a1 + 728);
    if ( v4 == (_QWORD *)(a1 + 728) )
    {
      if ( (unsigned int)__ratelimit(&cam_sfe_bus_wr_get_evt_payload__rs_49, "cam_sfe_bus_wr_get_evt_payload") )
        v9 = 3;
      else
        v9 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v9,
        0x40000000,
        1,
        "cam_sfe_bus_wr_get_evt_payload",
        1457,
        "No free BUS event payload");
      *a2 = 0;
      v7 = -19;
    }
    else
    {
      *a2 = v4;
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (v6 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      v7 = 0;
      *v4 = v4;
      v4[1] = v4;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_sfe_bus_wr_get_evt_payload__rs, "cam_sfe_bus_wr_get_evt_payload") )
      v8 = 3;
    else
      v8 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v8,
      0x40000000,
      1,
      "cam_sfe_bus_wr_get_evt_payload",
      1450,
      "SFE:%d Bus uninitialized",
      *(_DWORD *)a1);
    *a2 = 0;
    v7 = -1;
  }
  raw_spin_unlock(a1 + 744);
  return v7;
}
