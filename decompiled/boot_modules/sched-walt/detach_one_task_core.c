__int64 __fastcall detach_one_task_core(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v5; // x2
  __int64 result; // x0

  *(_DWORD *)(a1 + 144) = 2;
  deactivate_task(a2, a1, 0);
  v5 = *a3;
  result = a1 + 256;
  if ( *(__int64 **)(*a3 + 8) != a3 || result == (_QWORD)a3 || v5 == result )
    return _list_add_valid_or_report(result, a3, v5);
  *(_QWORD *)(v5 + 8) = result;
  *(_QWORD *)(a1 + 256) = v5;
  *(_QWORD *)(a1 + 264) = a3;
  *a3 = result;
  return result;
}
