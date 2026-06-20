__int64 __fastcall cam_req_mgr_close(__int64 a1)
{
  __int64 v2; // x0
  __int64 *v3; // x25
  __int64 v4; // x26
  void (*v5)(void); // x9
  __int64 v6; // x8
  void (*v7)(void); // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w19

  down_write(&rwsem_lock);
  mutex_lock(&unk_2FDAA8);
  v2 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
         3,
         16,
         2,
         "cam_req_mgr_close",
         217,
         "release invoked associated userspace process has died, open_cnt: %d",
         dword_2FDA9C);
  vi530x_resources_close(v2);
  if ( dword_2FDA9C < 1 )
  {
    v10 = -22;
  }
  else
  {
    cam_req_mgr_handle_core_shutdown();
    v3 = (__int64 *)cam_req_mgr_ordered_sd_list;
    byte_2FDAE4 = 1;
    if ( (__int64 *)cam_req_mgr_ordered_sd_list != &cam_req_mgr_ordered_sd_list )
    {
      v4 = v4l2_subdev_call_wrappers;
      do
      {
        if ( (*((_BYTE *)v3 - 292) & 4) != 0 && *(v3 - 34) )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_close",
              235,
              "Invoke subdev close for device %s",
              (const char *)v3 - 256);
            if ( v3 != (__int64 *)&unk_1B8 )
            {
LABEL_14:
              v6 = *(_QWORD *)*(v3 - 35);
              if ( v6 )
              {
                v7 = *(void (**)(void))(v6 + 56);
                if ( v7 )
                {
                  if ( !v4 || (v5 = *(void (**)(void))(v4 + 56)) == nullptr )
                    v5 = v7;
                  if ( *((_DWORD *)v5 - 1) != 1356305480 )
                    __break(0x8229u);
                  v5();
                }
              }
            }
          }
          else if ( v3 != (__int64 *)&unk_1B8 )
          {
            goto LABEL_14;
          }
        }
        v3 = (__int64 *)*v3;
      }
      while ( v3 != &cam_req_mgr_ordered_sd_list );
    }
    byte_2FDAE4 = 0;
    --dword_2FDA9C;
    v4l2_fh_release(a1);
    raw_spin_lock_bh(&dword_2FDAE0);
    qword_2FDAD8 = 0;
    v8 = raw_spin_unlock_bh(&dword_2FDAE0);
    v9 = cam_req_mgr_util_free_hdls(v8);
    cam_mem_mgr_deinit(v9);
    v10 = 0;
  }
  mutex_unlock(&unk_2FDAA8);
  up_write(&rwsem_lock);
  return v10;
}
