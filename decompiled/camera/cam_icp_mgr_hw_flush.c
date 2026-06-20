__int64 __fastcall cam_icp_mgr_hw_flush(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  const char *v3; // x5
  __int64 v4; // x6
  __int64 v5; // x4
  __int64 v6; // x9
  int v7; // w8
  __int64 v8; // x8
  int v9; // w7
  __int64 *v10; // x21
  __int64 v11; // x20
  __int64 v13; // x8
  char v14; // w11
  __int64 v15; // x9
  __int64 v16; // x20
  __int64 *v17; // x21
  __int64 *v18; // x22
  unsigned __int64 v24; // x13
  __int64 v25; // x12
  int v26; // w11
  _DWORD *v27; // x12

  if ( a1 && a2 )
  {
    v2 = *a2;
    if ( *a2 )
    {
      if ( *((_DWORD *)a2 + 10) >= 2u )
      {
        v3 = "%s: Invalid lush type: %d";
        v4 = v2 + 29824;
        v5 = 8084;
LABEL_15:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_hw_flush",
          v5,
          v3,
          v4);
        return 4294967274LL;
      }
      v6 = *((unsigned int *)a2 + 11);
      v7 = debug_mdl;
      *(_QWORD *)(v2 + 29816) = v6;
      v8 = v7 & 0x1000100;
      if ( v8 && !debug_priority )
      {
        v16 = a1;
        v17 = a2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v8,
          4,
          "cam_icp_mgr_hw_flush",
          8091,
          "%s: Flush type %d last_flush_req %u",
          (const char *)(v2 + 29824),
          *((_DWORD *)a2 + 10),
          v6);
        a2 = v17;
        a1 = v16;
        v9 = *((_DWORD *)v17 + 10);
        if ( v9 )
          goto LABEL_11;
      }
      else
      {
        v9 = *((_DWORD *)a2 + 10);
        if ( v9 )
        {
LABEL_11:
          if ( v9 != 1 )
          {
            v3 = "%s: Invalid flush type: %d";
            v4 = v2 + 29824;
            v5 = 8124;
            goto LABEL_15;
          }
          v10 = a2;
          v11 = a1;
          mutex_lock(a1);
          if ( *(_DWORD *)(v11 + 44148) || !*((_DWORD *)v10 + 6) )
          {
            mutex_unlock(v11);
          }
          else
          {
            mutex_unlock(v11);
            cam_icp_mgr_flush_info_dump(v10, *(unsigned int *)(v2 + 29224));
            cam_icp_mgr_enqueue_abort(v2);
          }
          mutex_lock(*(_QWORD *)(v11 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
          cam_icp_cpas_deactivate_llcc(v2);
          v13 = 0;
          v14 = 0;
          v15 = 4504;
          do
          {
            v25 = v2 + 8 * v13;
            if ( *(_QWORD *)(v25 + 1784) )
            {
              *(_QWORD *)(v25 + 1784) = 0;
              v26 = *(_DWORD *)(v2 + v15);
              if ( v26 )
              {
                v27 = (_DWORD *)(v2 + v15);
                v27[40] = v26;
                *v27 = 0;
              }
              _X11 = *(unsigned __int64 **)(v2 + 1720);
              __asm { PRFM            #0x11, [X11] }
              do
                v24 = __ldxr(_X11);
              while ( __stxr(v24 & ~(1LL << v13), _X11) );
              v14 = 1;
            }
            ++v13;
            v15 += 4;
          }
          while ( v13 != 40 );
          if ( (v14 & 1) != 0 )
            cam_icp_mgr_delete_sync_obj(v2);
LABEL_35:
          mutex_unlock(*(_QWORD *)(v11 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
          return 0;
        }
      }
      v11 = a1;
      v18 = a2;
      mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
      if ( *((_DWORD *)v18 + 6) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_hw_flush",
          8114,
          "%s: Flush a specific active request id: %lld is not supported",
          (const char *)(v2 + 29824),
          **(_QWORD **)v18[4]);
        mutex_unlock(*(_QWORD *)(v11 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
        return 4294967274LL;
      }
      if ( *((_DWORD *)v18 + 2) )
        cam_icp_mgr_flush_req(v2, v18);
      goto LABEL_35;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_flush",
      8077,
      "[%s] ctx data is NULL",
      (const char *)(a1 + 112));
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_flush",
      8071,
      "Input params are Null:");
  }
  return 4294967274LL;
}
