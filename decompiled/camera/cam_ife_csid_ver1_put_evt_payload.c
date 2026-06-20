__int64 __fastcall cam_ife_csid_ver1_put_evt_payload(__int64 a1, _QWORD *a2, __int64 a3)
{
  _QWORD *v3; // x8
  __int64 v7; // x0
  _QWORD *v8; // x8
  _QWORD *v9; // x1
  __int64 v10; // x9
  __int64 v12; // x0

  v3 = (_QWORD *)*a2;
  if ( *a2 )
  {
    v3[10] = 0;
    v3[11] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[2] = 0;
    v3[3] = 0;
    *v3 = 0;
    v3[1] = 0;
    v7 = raw_spin_lock_irqsave(a1 + 28396);
    v8 = (_QWORD *)*a2;
    v9 = *(_QWORD **)(a3 + 8);
    v10 = v7;
    if ( *a2 == a3 || v9 == v8 || *v9 != a3 )
    {
      _list_add_valid_or_report(*a2);
    }
    else
    {
      *(_QWORD *)(a3 + 8) = v8;
      *v8 = a3;
      v8[1] = v9;
      *v9 = v8;
    }
    *a2 = 0;
    return raw_spin_unlock_irqrestore(a1 + 28396, v10);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver1_put_evt_payload__rs, "cam_ife_csid_ver1_put_evt_payload") )
      v12 = 3;
    else
      v12 = 2;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             v12,
             8,
             1,
             "cam_ife_csid_ver1_put_evt_payload",
             3956,
             "Invalid payload core %d",
             *(_DWORD *)(*(_QWORD *)a1 + 4LL));
  }
}
