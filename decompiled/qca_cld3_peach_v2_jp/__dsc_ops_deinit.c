__int64 __fastcall _dsc_ops_deinit(__int64 a1, __int64 a2)
{
  return qdf_event_destroy(a1 + 8, a2);
}
