__int64 __fastcall dummy_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  _pm_runtime_disable(a1 + 16, 1);
  return coresight_unregister(*(_QWORD *)(v1 + 8));
}
