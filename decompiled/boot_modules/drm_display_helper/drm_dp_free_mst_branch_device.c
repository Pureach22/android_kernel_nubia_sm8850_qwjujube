__int64 __fastcall drm_dp_free_mst_branch_device(__int64 a1)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 52);
  if ( v2 )
    drm_dp_mst_put_port_malloc(v2);
  return kfree(a1 - 4);
}
