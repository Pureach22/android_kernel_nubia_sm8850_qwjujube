bool __fastcall qdf_periodic_work_stop_async(__int64 a1)
{
  int v1; // w8
  _BOOL4 v2; // w19

  v1 = *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 120) = 0;
  v2 = v1 != 0;
  cancel_delayed_work();
  return v2;
}
