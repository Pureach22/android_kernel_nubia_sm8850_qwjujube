__int64 __fastcall smmu_aspace_add_to_active(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  __int64 v8; // x11
  _QWORD *v9; // x1

  result = mutex_is_locked(a1 + 320);
  if ( (result & 1) == 0 )
    __break(0x800u);
  v5 = *(_QWORD **)(a2 + 600);
  v6 = (_QWORD *)(a2 + 592);
  v7 = (_QWORD *)(a1 + 288);
  if ( *v5 == a2 + 592 && (v8 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    *(_QWORD *)(v8 + 8) = v5;
    *v5 = v8;
  }
  else
  {
    result = _list_del_entry_valid_or_report(a2 + 592);
  }
  v9 = *(_QWORD **)(a1 + 296);
  if ( v6 == v7 || v9 == v6 || (_QWORD *)*v9 != v7 )
  {
    result = _list_add_valid_or_report(v6, v9);
  }
  else
  {
    *(_QWORD *)(a1 + 296) = v6;
    *(_QWORD *)(a2 + 592) = v7;
    *(_QWORD *)(a2 + 600) = v9;
    *v9 = v6;
  }
  *(_BYTE *)(a2 + 616) = 1;
  return result;
}
