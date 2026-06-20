__int64 __fastcall cam_sfe_top_put_evt_payload(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v5; // x0
  _QWORD *v6; // x8
  _QWORD *v7; // x1
  __int64 v8; // x2
  __int64 v9; // x9
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x4

  if ( !a1 )
  {
    v11 = "Invalid param core_info NULL";
    v12 = 0x40000000;
    v13 = 1;
    v14 = 1647;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v12,
             v13,
             "cam_sfe_top_put_evt_payload",
             v14,
             v11);
  }
  v2 = (_QWORD *)*a2;
  if ( !*a2 )
  {
    v11 = "No payload to put";
    v12 = 0x40000000;
    v13 = 1;
    v14 = 1651;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v12,
             v13,
             "cam_sfe_top_put_evt_payload",
             v14,
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
  v5 = raw_spin_lock_irqsave(a1 + 32272);
  v6 = (_QWORD *)*a2;
  v7 = *(_QWORD **)(a1 + 22576);
  v8 = a1 + 22568;
  v9 = v5;
  if ( *a2 == a1 + 22568 || v7 == v6 || *v7 != v8 )
  {
    _list_add_valid_or_report(*a2);
  }
  else
  {
    *(_QWORD *)(a1 + 22576) = v6;
    *v6 = v8;
    v6[1] = v7;
    *v7 = v6;
  }
  *a2 = 0;
  result = raw_spin_unlock_irqrestore(a1 + 32272, v9);
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v11 = "Done";
    v12 = debug_mdl & 0x40000000;
    v13 = 4;
    v14 = 1661;
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             v12,
             v13,
             "cam_sfe_top_put_evt_payload",
             v14,
             v11);
  }
  return result;
}
