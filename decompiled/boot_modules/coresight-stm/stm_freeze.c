__int64 __fastcall stm_freeze(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x19
  _QWORD *i; // x20

  v1 = *(_QWORD *)(a1 + 152);
  coresight_disable_sysfs(*(_QWORD *)(v1 + 24));
  v2 = *(_QWORD *)(v1 + 72);
  if ( v2 )
  {
    for ( i = *(_QWORD **)(v2 + 1048); i != (_QWORD *)(v2 + 1048); i = (_QWORD *)*i )
      _pm_runtime_suspend(v2, 13);
  }
  return 0;
}
