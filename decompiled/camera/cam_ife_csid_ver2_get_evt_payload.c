__int64 __fastcall cam_ife_csid_ver2_get_evt_payload(__int64 a1, _QWORD *a2, _QWORD **a3, __int64 a4)
{
  _QWORD *v8; // x9
  _QWORD *v9; // x8
  __int64 v10; // x10
  __int64 v12; // x0

  raw_spin_lock(a4);
  v8 = *a3;
  if ( *a3 == a3 )
  {
    *a2 = 0;
    raw_spin_unlock(a4);
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_get_evt_payload__rs, "cam_ife_csid_ver2_get_evt_payload") )
      v12 = 3;
    else
      v12 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v12,
      8,
      1,
      "cam_ife_csid_ver2_get_evt_payload",
      762,
      "No free payload core %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
    return 4294967284LL;
  }
  else
  {
    *a2 = v8;
    v9 = (_QWORD *)v8[1];
    if ( (_QWORD *)*v9 == v8 && (v10 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v10 + 8) = v9;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v8);
    }
    *v8 = v8;
    v8[1] = v8;
    raw_spin_unlock(a4);
    return 0;
  }
}
