__int64 cam_isp_subdev_open()
{
  cam_req_mgr_rwsem_read_op(1);
  mutex_lock(&unk_3A8B38);
  ++dword_3A8B68;
  mutex_unlock(&unk_3A8B38);
  cam_req_mgr_rwsem_read_op(2);
  return 0;
}
