__int64 __fastcall _dsc_ops_init(_DWORD *a1)
{
  *a1 = 0;
  return qdf_event_create(a1 + 2);
}
