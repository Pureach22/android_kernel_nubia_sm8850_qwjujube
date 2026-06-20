__int64 __fastcall cam_vfe_bus_ver3_get_evt_payload(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x22
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  __int64 v7; // x10
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x0

  v3 = a1 + 0x8000;
  raw_spin_lock(a1 + 34560);
  if ( (*(_BYTE *)(v3 + 1898) & 1) != 0 )
  {
    v5 = *(_QWORD **)(v3 + 1776);
    if ( v5 == (_QWORD *)(v3 + 1776) )
    {
      *a2 = 0;
      if ( (unsigned int)__ratelimit(&cam_vfe_bus_ver3_get_evt_payload__rs_69, "cam_vfe_bus_ver3_get_evt_payload") )
        v10 = 3;
      else
        v10 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v10,
        8,
        1,
        "cam_vfe_bus_ver3_get_evt_payload",
        346,
        "VFE:%u No free BUS event payload",
        *(_DWORD *)(a1 + 8));
      v8 = -19;
    }
    else
    {
      *a2 = v5;
      v6 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v6 == v5 && (v7 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
      {
        *(_QWORD *)(v7 + 8) = v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      v8 = 0;
      *v5 = v5;
      v5[1] = v5;
    }
  }
  else
  {
    *a2 = 0;
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_ver3_get_evt_payload__rs, "cam_vfe_bus_ver3_get_evt_payload") )
      v9 = 3;
    else
      v9 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v9,
      8,
      1,
      "cam_vfe_bus_ver3_get_evt_payload",
      338,
      "VFE:%u Bus uninitialized",
      *(_DWORD *)(a1 + 8));
    v8 = -1;
  }
  raw_spin_unlock(a1 + 34560);
  return v8;
}
