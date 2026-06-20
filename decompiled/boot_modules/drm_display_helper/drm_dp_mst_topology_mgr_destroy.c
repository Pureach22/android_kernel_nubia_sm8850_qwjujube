__int64 __fastcall drm_dp_mst_topology_mgr_destroy(_QWORD *a1)
{
  __int64 result; // x0

  drm_dp_mst_topology_mgr_set_mst((__int64)a1, 0);
  flush_work(a1 + 128);
  if ( a1[146] )
  {
    destroy_workqueue();
    a1[146] = 0;
  }
  a1[13] = 0;
  a1[16] = 0;
  result = drm_atomic_private_obj_fini(a1);
  a1[116] = 0;
  return result;
}
