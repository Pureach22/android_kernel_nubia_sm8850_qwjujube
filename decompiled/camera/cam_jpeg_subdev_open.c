__int64 cam_jpeg_subdev_open()
{
  cam_req_mgr_rwsem_read_op(1);
  mutex_lock(&unk_3C37B0);
  ++dword_3C37E0;
  mutex_unlock(&unk_3C37B0);
  cam_req_mgr_rwsem_read_op(2);
  return 0;
}
