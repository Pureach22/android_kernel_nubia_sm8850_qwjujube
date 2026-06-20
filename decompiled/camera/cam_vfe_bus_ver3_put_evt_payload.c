__int64 __fastcall cam_vfe_bus_ver3_put_evt_payload(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x8
  __int64 v5; // x9
  _QWORD *v6; // x0
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 result; // x0
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x4

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_bus_ver3_put_evt_payload",
             367,
             "Invalid param common_data NULL");
  v2 = *a2;
  if ( !*a2 )
  {
    v10 = *(unsigned int *)(a1 + 8);
    v11 = "VFE:%u No payload to put";
    v12 = 8;
    v13 = 1;
    v14 = 372;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v12,
             v13,
             "cam_vfe_bus_ver3_put_evt_payload",
             v14,
             v11,
             v10);
  }
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
  v5 = raw_spin_lock_irqsave(a1 + 34560);
  if ( *(_BYTE *)(a1 + 34666) == 1 )
  {
    v6 = *a2;
    v7 = a1 + 34544;
    v8 = *(_QWORD **)(a1 + 34552);
    if ( *a2 == (_QWORD *)(a1 + 34544) || v8 == v6 || *v8 != v7 )
    {
      _list_add_valid_or_report(v6);
    }
    else
    {
      *(_QWORD *)(a1 + 34552) = v6;
      *v6 = v7;
      v6[1] = v8;
      *v8 = v6;
    }
  }
  result = raw_spin_unlock_irqrestore(a1 + 34560, v5);
  *a2 = nullptr;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v10 = *(unsigned int *)(a1 + 8);
    v11 = "VFE:%u Done";
    v12 = debug_mdl & 8;
    v13 = 4;
    v14 = 384;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v12,
             v13,
             "cam_vfe_bus_ver3_put_evt_payload",
             v14,
             v11,
             v10);
  }
  return result;
}
