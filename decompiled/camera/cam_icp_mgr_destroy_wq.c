_QWORD *__fastcall cam_icp_mgr_destroy_wq(_QWORD *a1)
{
  cam_req_mgr_workq_destroy(a1 + 126);
  cam_req_mgr_workq_destroy(a1 + 125);
  return cam_req_mgr_workq_destroy(a1 + 124);
}
