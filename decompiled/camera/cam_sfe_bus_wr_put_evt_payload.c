__int64 __fastcall cam_sfe_bus_wr_put_evt_payload(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x8
  __int64 v5; // x9
  _QWORD *v6; // x0
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 result; // x0
  const char *v10; // x5
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x4

  if ( !a1 )
  {
    v10 = "Invalid param common_data NULL";
    v11 = 0x40000000;
    v12 = 1;
    v13 = 1479;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v11,
             v12,
             "cam_sfe_bus_wr_put_evt_payload",
             v13,
             v10);
  }
  v2 = *a2;
  if ( !*a2 )
  {
    v10 = "No payload to put";
    v11 = 0x40000000;
    v12 = 1;
    v13 = 1484;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v11,
             v12,
             "cam_sfe_bus_wr_put_evt_payload",
             v13,
             v10);
  }
  v2[11] = 0;
  v2[12] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[3] = 0;
  v2[4] = 0;
  v2[1] = 0;
  v2[2] = 0;
  *v2 = 0;
  v5 = raw_spin_lock_irqsave(a1 + 744);
  if ( *(_BYTE *)(a1 + 27448) == 1 )
  {
    v6 = *a2;
    v7 = a1 + 728;
    v8 = *(_QWORD **)(a1 + 736);
    if ( *a2 == (_QWORD *)(a1 + 728) || v8 == v6 || *v8 != v7 )
    {
      _list_add_valid_or_report(v6);
    }
    else
    {
      *(_QWORD *)(a1 + 736) = v6;
      *v6 = v7;
      v6[1] = v8;
      *v8 = v6;
    }
  }
  result = raw_spin_unlock_irqrestore(a1 + 744, v5);
  *a2 = nullptr;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v10 = "Exit";
    v11 = debug_mdl & 0x40000000;
    v12 = 4;
    v13 = 1497;
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             v11,
             v12,
             "cam_sfe_bus_wr_put_evt_payload",
             v13,
             v10);
  }
  return result;
}
