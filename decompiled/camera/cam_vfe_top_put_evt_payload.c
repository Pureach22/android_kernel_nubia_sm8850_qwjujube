__int64 __fastcall cam_vfe_top_put_evt_payload(__int64 a1, _QWORD *a2)
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
  __int64 v13; // x6
  __int64 v14; // x2
  __int64 v15; // x4

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_top_put_evt_payload",
             2126,
             "Invalid param core_info NULL");
  v2 = (_QWORD *)*a2;
  if ( !*a2 )
  {
    v11 = "VFE:%u No payload to put";
    v13 = *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL);
    v12 = 8;
    v14 = 1;
    v15 = 2130;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v12,
             v14,
             "cam_vfe_top_put_evt_payload",
             v15,
             v11,
             v13);
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
  v5 = raw_spin_lock_irqsave(a1 + 22664);
  v6 = (_QWORD *)*a2;
  v7 = *(_QWORD **)(a1 + 22656);
  v8 = a1 + 22648;
  v9 = v5;
  if ( *a2 == a1 + 22648 || v7 == v6 || *v7 != v8 )
  {
    _list_add_valid_or_report(*a2);
  }
  else
  {
    *(_QWORD *)(a1 + 22656) = v6;
    *v6 = v8;
    v6[1] = v7;
    *v7 = v6;
  }
  *a2 = 0;
  result = raw_spin_unlock_irqrestore(a1 + 22664, v9);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v11 = "VFE:%u Done";
    v12 = debug_mdl & 8;
    v13 = *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL);
    v14 = 4;
    v15 = 2140;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v12,
             v14,
             "cam_vfe_top_put_evt_payload",
             v15,
             v11,
             v13);
  }
  return result;
}
