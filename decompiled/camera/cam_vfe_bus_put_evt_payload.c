__int64 __fastcall cam_vfe_bus_put_evt_payload(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x8
  __int64 v5; // x22
  __int64 v6; // x9
  _QWORD *v7; // x0
  __int64 v8; // x2
  _QWORD *v9; // x1
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x4

  if ( !a1 )
  {
    v11 = "Invalid param core_info NULL";
    v12 = 8;
    v13 = 1;
    v14 = 296;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v12,
             v13,
             "cam_vfe_bus_put_evt_payload",
             v14,
             v11);
  }
  v2 = *a2;
  if ( !*a2 )
  {
    v11 = "No payload to put";
    v12 = 8;
    v13 = 1;
    v14 = 301;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v12,
             v13,
             "cam_vfe_bus_put_evt_payload",
             v14,
             v11);
  }
  v5 = a1 + 0x8000;
  v2[14] = 0;
  v2[15] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[4] = 0;
  v2[5] = 0;
  v2[2] = 0;
  v2[3] = 0;
  *v2 = 0;
  v2[1] = 0;
  v6 = raw_spin_lock_irqsave(a1 + 33528);
  if ( *(_BYTE *)(v5 + 840) == 1 )
  {
    v7 = *a2;
    v8 = v5 + 744;
    v9 = *(_QWORD **)(v5 + 752);
    if ( *a2 == (_QWORD *)(v5 + 744) || v9 == v7 || *v9 != v8 )
    {
      _list_add_valid_or_report(v7);
    }
    else
    {
      *(_QWORD *)(v5 + 752) = v7;
      *v7 = v8;
      v7[1] = v9;
      *v9 = v7;
    }
  }
  result = raw_spin_unlock_irqrestore(a1 + 33528, v6);
  *a2 = nullptr;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v11 = "Done";
    v12 = debug_mdl & 8;
    v13 = 4;
    v14 = 314;
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             v12,
             v13,
             "cam_vfe_bus_put_evt_payload",
             v14,
             v11);
  }
  return result;
}
