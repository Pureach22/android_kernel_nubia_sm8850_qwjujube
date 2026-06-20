__int64 __fastcall dp_mst_duplicate_bridge_state(__int64 a1)
{
  __int64 v2; // x20

  v2 = kmemdup_noprof(*(_QWORD *)(a1 + 88), 40, 3264);
  if ( v2 )
    _drm_atomic_helper_private_obj_duplicate_state(a1, v2);
  return v2;
}
