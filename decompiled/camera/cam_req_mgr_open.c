__int64 __fastcall cam_req_mgr_open(__int64 a1)
{
  unsigned int v2; // w19
  unsigned int v3; // w0
  __int64 v4; // x0

  down_write(&rwsem_lock);
  mutex_lock(&unk_2FDAA8);
  if ( dword_2FDA9C <= 0 )
  {
    v3 = v4l2_fh_open(a1);
    if ( v3 )
    {
      v2 = v3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_req_mgr_open",
        158,
        "v4l2_fh_open failed: %d",
        v3);
    }
    else
    {
      raw_spin_lock_bh(&dword_2FDAE0);
      qword_2FDAD8 = *(_QWORD *)(a1 + 32);
      v4 = raw_spin_unlock_bh(&dword_2FDAE0);
      ++dword_2FDA9C;
      v2 = cam_mem_mgr_init(v4);
      if ( v2 )
      {
        --dword_2FDA9C;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_open",
          170,
          "mem mgr init failed");
        v4l2_fh_release(a1);
      }
    }
  }
  else
  {
    v2 = -114;
  }
  mutex_unlock(&unk_2FDAA8);
  up_write(&rwsem_lock);
  return v2;
}
