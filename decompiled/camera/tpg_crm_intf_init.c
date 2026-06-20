__int64 __fastcall tpg_crm_intf_init(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 4488) = -1;
  *(_DWORD *)(a1 + 4496) = -1;
  *(_QWORD *)(a1 + 4504) = cam_tpg_publish_dev_info;
  *(_QWORD *)(a1 + 4512) = cam_tpg_setup_link;
  *(_QWORD *)(a1 + 4520) = cam_tpg_apply_req;
  *(_QWORD *)(a1 + 4528) = cam_tpg_notify_frame_skip;
  *(_QWORD *)(a1 + 4536) = cam_tpg_flush_req;
  *(_QWORD *)(a1 + 4544) = cam_tpg_process_crm_evt;
  *(_QWORD *)(a1 + 4552) = cam_tpg_dump_req;
  return 0;
}
