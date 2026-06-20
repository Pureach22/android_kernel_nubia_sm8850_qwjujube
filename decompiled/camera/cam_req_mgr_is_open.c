bool cam_req_mgr_is_open()
{
  _BOOL4 v0; // w19

  mutex_lock(&unk_2FDAA8);
  v0 = dword_2FDA9C != 0;
  mutex_unlock(&unk_2FDAA8);
  return v0;
}
