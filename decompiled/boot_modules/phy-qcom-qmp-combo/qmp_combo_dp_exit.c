__int64 __fastcall qmp_combo_dp_exit(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x22
  int v3; // w8
  unsigned int v4; // w19
  __int64 v5; // x20

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 208);
  v2 = *(_QWORD *)(v1 + 8);
  v3 = *(_DWORD *)(v1 + 256) - 1;
  *(_DWORD *)(v1 + 256) = v3;
  if ( !v3 )
  {
    v4 = *(_DWORD *)(v1 + 168);
    v5 = *(_QWORD *)(v1 + 160);
    clk_bulk_disable(v4, v5);
    clk_bulk_unprepare(v4, v5);
    regulator_bulk_disable(*(unsigned int *)(v2 + 272), *(_QWORD *)(v1 + 200));
  }
  --*(_DWORD *)(v1 + 344);
  mutex_unlock(v1 + 208);
  return 0;
}
