__int64 __fastcall cam_ife_csid_ver2_put_evt_payload(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x8
  __int64 v8; // x0
  _QWORD *v9; // x8
  _QWORD *v10; // x1
  __int64 v11; // x9
  __int64 v14; // x0

  v4 = (_QWORD *)*a2;
  if ( *a2 )
  {
    v4[5] = 0;
    v4[6] = 0;
    v4[3] = 0;
    v4[4] = 0;
    v4[1] = 0;
    v4[2] = 0;
    *v4 = 0;
    v8 = raw_spin_lock_irqsave(a4);
    v9 = (_QWORD *)*a2;
    v10 = *(_QWORD **)(a3 + 8);
    v11 = v8;
    if ( *a2 == a3 || v10 == v9 || *v10 != a3 )
    {
      _list_add_valid_or_report(*a2);
    }
    else
    {
      *(_QWORD *)(a3 + 8) = v9;
      *v9 = a3;
      v9[1] = v10;
      *v10 = v9;
    }
    *a2 = 0;
    return raw_spin_unlock_irqrestore(a4, v11);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_put_evt_payload__rs, "cam_ife_csid_ver2_put_evt_payload") )
      v14 = 3;
    else
      v14 = 2;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             v14,
             8,
             1,
             "cam_ife_csid_ver2_put_evt_payload",
             784,
             "Invalid payload core %d",
             *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
  }
}
