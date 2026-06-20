__int64 __fastcall cam_flash_work_queue_handler(_DWORD *a1)
{
  return cam_req_mgr_process_workq(a1);
}
