__int64 __fastcall cam_vfe_bus_get_evt_payload(_DWORD *a1, _QWORD *a2)
{
  _DWORD *v3; // x22
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  __int64 v7; // x10
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x0

  v3 = a1 + 0x2000;
  raw_spin_lock(a1 + 8382);
  if ( (v3[210] & 1) != 0 )
  {
    v5 = *((_QWORD **)v3 + 93);
    if ( v5 == (_QWORD *)(v3 + 186) )
    {
      *a2 = 0;
      if ( (unsigned int)__ratelimit(&cam_vfe_bus_get_evt_payload__rs_63, "cam_vfe_bus_get_evt_payload") )
        v10 = 3;
      else
        v10 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v10,
        8,
        1,
        "cam_vfe_bus_get_evt_payload",
        231,
        "No free payload");
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
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_get_evt_payload__rs, "cam_vfe_bus_get_evt_payload") )
      v9 = 3;
    else
      v9 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v9,
      8,
      1,
      "cam_vfe_bus_get_evt_payload",
      224,
      "VFE:%d Bus uninitialized",
      *a1);
    v8 = -1;
  }
  raw_spin_unlock(a1 + 8382);
  return v8;
}
