__int64 __fastcall stm_restore(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *i; // x20

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 72LL);
  if ( v1 )
  {
    for ( i = *(_QWORD **)(v1 + 1048); i != (_QWORD *)(v1 + 1048); i = (_QWORD *)*i )
      _pm_runtime_resume(v1, 5);
  }
  return 0;
}
