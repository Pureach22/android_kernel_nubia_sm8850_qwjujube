unsigned int *__fastcall cam_context_sync_callback(int a1, int a2, __int64 *a3)
{
  unsigned int *result; // x0
  __int64 v4; // x19
  __int64 *v6; // x9
  __int64 v7; // x8
  __int64 **v8; // x9
  __int64 *v9; // x8
  __int64 *v10; // x10
  __int64 *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 *v14; // x1
  unsigned int v21; // w8
  unsigned int v22; // w8
  _QWORD v23[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v24; // [xsp+20h] [xbp-20h]
  _QWORD v25[3]; // [xsp+28h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  memset(v23, 0, sizeof(v23));
  if ( a3 )
  {
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
    {
      result = (unsigned int *)_warn_printk("Invalid execution context\n");
      __break(0x800u);
    }
    else
    {
      v4 = a3[13];
      if ( v4 )
      {
        _X9 = (unsigned int *)a3 + 21;
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v21 = __ldxr(_X9);
          v22 = v21 + 1;
        }
        while ( __stlxr(v22, _X9) );
        __dmb(0xBu);
        if ( v22 == *((_DWORD *)a3 + 16) )
        {
          if ( (unsigned int)(a2 - 3) <= 1 )
          {
            v6 = a3;
            if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x80000,
                4,
                "cam_context_sync_callback",
                380,
                "fence error: %d on obj %d",
                a2,
                a1);
              v6 = a3;
            }
            v7 = v6[3];
            v25[0] = v23;
            v25[1] = 0;
            v24 = v7;
            cam_context_flush_req_to_hw(v4, v25);
          }
          mutex_lock(v4 + 416);
          if ( *((_DWORD *)a3 + 24) )
          {
            *((_DWORD *)a3 + 24) = 0;
            a3[13] = 0;
            mutex_unlock(v4 + 416);
            raw_spin_lock(v4 + 120);
            v8 = (__int64 **)a3[1];
            v9 = a3;
            if ( *v8 == a3 && (v10 = (__int64 *)*a3, *(__int64 **)(*a3 + 8) == a3) )
            {
              v10[1] = (__int64)v8;
              *v8 = v10;
            }
            else
            {
              _list_del_entry_valid_or_report(a3);
              v9 = a3;
            }
            *v9 = (__int64)v9;
            v11 = v9;
            v9[1] = (__int64)v9;
            raw_spin_unlock(v4 + 120);
            v12 = v11[17];
            if ( v12 )
            {
              cam_common_mem_free(v12);
              a3[17] = 0;
            }
            raw_spin_lock(v4 + 120);
            v13 = v4 + 176;
            v14 = *(__int64 **)(v4 + 184);
            if ( (__int64 *)(v4 + 176) == a3 || v14 == a3 || *v14 != v13 )
            {
              _list_add_valid_or_report(a3);
            }
            else
            {
              *(_QWORD *)(v4 + 184) = a3;
              *a3 = v13;
              a3[1] = (__int64)v14;
              *v14 = (__int64)a3;
            }
            raw_spin_unlock(v4 + 120);
            if ( (*(_QWORD *)(v4 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x80000,
                3,
                "cam_context_sync_callback",
                413,
                "[%s][%d] : Moving req[%llu] from pending_list to free_list",
                (const char *)v4,
                *(_DWORD *)(v4 + 32),
                a3[3]);
          }
          else
          {
            cam_context_apply_req_to_hw(a3);
            mutex_unlock(v4 + 416);
          }
        }
        result = cam_context_putref(v4);
      }
      else
      {
        result = (unsigned int *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   0x80000,
                                   1,
                                   "cam_context_sync_callback",
                                   363,
                                   "Invalid ctx for req %llu",
                                   a3[3]);
      }
    }
  }
  else
  {
    result = (unsigned int *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                               3,
                               0x80000,
                               1,
                               "cam_context_sync_callback",
                               354,
                               "Invalid input param");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
