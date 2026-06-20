__int64 __fastcall sub_12E518(__int64 a1, _DWORD *a2)
{
  __int128 v2; // q16

  *a2 = HIDWORD(v2);
  return sde_connector_atomic_destroy_state(a1);
}
