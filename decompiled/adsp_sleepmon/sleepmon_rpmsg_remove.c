__int64 sleepmon_rpmsg_remove()
{
  mutex_lock(&unk_B140);
  qword_A680 = 0;
  dword_A678 = 0;
  return mutex_unlock(&unk_B140);
}
