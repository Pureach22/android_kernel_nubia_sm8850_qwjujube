bool __fastcall qdf_periodic_work_stop_sync(__int64 a1)
{
  int v1; // w20

  v1 = *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 120) = 0;
  while ( (cancel_delayed_work_sync(a1) & 1) != 0 )
    ;
  return v1 != 0;
}
