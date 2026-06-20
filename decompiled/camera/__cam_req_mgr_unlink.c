__int64 __fastcall _cam_req_mgr_unlink(__int64 a1, unsigned int *a2)
{
  unsigned int *v4; // x21
  int v5; // w8
  unsigned int v6; // w9
  __int64 v7; // x26
  __int64 v8; // x27
  int v9; // w23
  __int64 v10; // x25
  __int64 v11; // x28
  __int64 v12; // x8
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x0
  unsigned int v15; // w20
  _DWORD v17[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v18; // [xsp+8h] [xbp-28h]
  __int64 v19; // [xsp+10h] [xbp-20h]
  __int64 v20; // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v4 = a2 + 0x2000;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock_bh(a2 + 8304);
  v4[96] = 1;
  raw_spin_unlock_bh(a2 + 8304);
  if ( (v4[131] & 1) == 0 )
  {
    mutex_lock(a2 + 8264);
    v6 = *a2;
    v5 = a2[1];
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v17[0] = 0;
    v17[1] = v6;
    if ( v5 > 0 )
    {
      v7 = 0;
      v8 = 0;
      v9 = 0;
      do
      {
        v10 = *((_QWORD *)a2 + 5);
        v11 = v10 + v7;
        LODWORD(v18) = *(_DWORD *)(v10 + v7);
        v12 = *(_QWORD *)(v10 + v7 + 304);
        if ( v12 )
        {
          v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 8);
          if ( v13 )
          {
            if ( *((_DWORD *)v13 - 1) != -240797397 )
              __break(0x8228u);
            v9 = v13(v17);
            if ( v9 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                16,
                1,
                "__cam_req_mgr_disconnect_link",
                2875,
                "Unlink failed dev name %s hdl %x",
                (const char *)(v10 + v7 + 28),
                *(_DWORD *)(v10 + v7));
          }
        }
        *(_DWORD *)v11 = 0;
        ++v8;
        v7 += 320;
        *(_QWORD *)(v11 + 304) = 0;
        *(_QWORD *)(v11 + 312) = 0;
      }
      while ( v8 < (int)a2[1] );
      if ( v9 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          2,
          1,
          "__cam_req_mgr_unlink",
          4979,
          "Unlink for all devices was not successful");
    }
    mutex_unlock(a2 + 8264);
  }
  mutex_lock(a2 + 8292);
  raw_spin_lock_bh(a2 + 8304);
  crm_timer_exit(a2 + 8278);
  raw_spin_unlock_bh(a2 + 8304);
  mutex_unlock(a1 + 56);
  cam_req_mgr_workq_destroy(a2 + 6);
  mutex_lock(a1 + 56);
  _cam_req_mgr_destroy_link_info(a2);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_destroy_subdev",
      2839,
      "*l_device %pK",
      *((const void **)a2 + 5));
    v14 = *((_QWORD *)a2 + 5);
    if ( !v14 )
      goto LABEL_21;
  }
  else
  {
    v14 = *((_QWORD *)a2 + 5);
    if ( !v14 )
      goto LABEL_21;
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v14, 0);
  else
    kvfree(v14);
  *((_QWORD *)a2 + 5) = 0;
LABEL_21:
  v15 = cam_destroy_link_hdl(*a2);
  if ( (v15 & 0x80000000) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_unlink",
      5004,
      "error destroying link hdl %x rc %d",
      *a2,
      v15);
  else
    *a2 = -1;
  mutex_unlock(a2 + 8292);
  _ReadStatusReg(SP_EL0);
  return v15;
}
