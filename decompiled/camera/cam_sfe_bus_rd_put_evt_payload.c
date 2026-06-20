__int64 __fastcall cam_sfe_bus_rd_put_evt_payload(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v5; // x0
  _QWORD *v6; // x8
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 v9; // x9
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x4

  if ( !a1 )
  {
    v11 = "Invalid param common_data NULL";
    v12 = 338;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x40000000,
             1,
             "cam_sfe_bus_rd_put_evt_payload",
             v12,
             v11);
  }
  v2 = (_QWORD *)*a2;
  if ( !*a2 )
  {
    v11 = "No payload to put";
    v12 = 343;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x40000000,
             1,
             "cam_sfe_bus_rd_put_evt_payload",
             v12,
             v11);
  }
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
  v5 = raw_spin_lock_irqsave(a1 + 392);
  v6 = (_QWORD *)*a2;
  v7 = a1 + 400;
  v8 = *(_QWORD **)(a1 + 408);
  v9 = v5;
  if ( *a2 == a1 + 400 || v8 == v6 || *v8 != v7 )
  {
    _list_add_valid_or_report(*a2);
  }
  else
  {
    *(_QWORD *)(a1 + 408) = v6;
    *v6 = v7;
    v6[1] = v8;
    *v8 = v6;
  }
  result = raw_spin_unlock_irqrestore(a1 + 392, v9);
  *a2 = 0;
  return result;
}
