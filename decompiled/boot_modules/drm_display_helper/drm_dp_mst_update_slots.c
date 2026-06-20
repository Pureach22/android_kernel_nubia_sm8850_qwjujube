__int64 __fastcall drm_dp_mst_update_slots(_BYTE *a1, char a2)
{
  char v2; // w8
  const char *v3; // x4

  if ( a2 == 2 )
    v2 = 64;
  else
    v2 = 63;
  a1[72] = v2;
  if ( a2 == 2 )
    v3 = "128b/132b";
  else
    v3 = "8b/10b";
  a1[73] = a2 != 2;
  return _drm_dev_dbg(0, 0, 2, "%s encoding format on mst_state 0x%p\n", v3, a1);
}
