__int64 __fastcall tpg_hw_add_request(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  _QWORD *v6; // x1

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 48);
    if ( *(_DWORD *)(a1 + 244) > 0x20u )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_add_request",
        1305,
        "waiting queue size is exceed");
    }
    else
    {
      v4 = (_QWORD *)(a2 + 104);
      v5 = a1 + 208;
      v6 = *(_QWORD **)(a1 + 216);
      if ( a2 + 104 == a1 + 208 || v6 == v4 || *v6 != v5 )
      {
        _list_add_valid_or_report(v4);
      }
      else
      {
        *(_QWORD *)(a1 + 216) = v4;
        *(_QWORD *)(a2 + 104) = v5;
        *(_QWORD *)(a2 + 112) = v6;
        *v6 = v4;
      }
      ++*(_DWORD *)(a1 + 244);
    }
    mutex_unlock(a1 + 48);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_add_request",
      1297,
      "Invalid params");
    return 4294967274LL;
  }
}
