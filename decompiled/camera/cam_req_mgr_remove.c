__int64 __fastcall cam_req_mgr_remove(__int64 a1)
{
  return component_master_del(a1 + 16, cam_req_mgr_component_master_ops);
}
