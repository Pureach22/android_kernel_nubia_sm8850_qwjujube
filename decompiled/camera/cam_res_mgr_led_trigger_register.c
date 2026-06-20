__int64 __fastcall cam_res_mgr_led_trigger_register(const char *a1, __int64 *a2)
{
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 v6; // x23
  __int64 result; // x0
  __int64 v8; // x0
  _QWORD *v9; // x21
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x2
  _QWORD *v14; // x1

  if ( !cam_res )
    return led_trigger_register_simple(a1, a2);
  mutex_lock(cam_res + 536);
  v4 = cam_res;
  v5 = cam_res + 472;
  v6 = cam_res + 472;
  while ( 1 )
  {
    v6 = *(_QWORD *)v6;
    if ( v6 == v5 )
      break;
    if ( !strcmp(*(const char **)(v6 + 16), a1) )
    {
      result = mutex_unlock(v4 + 536);
      *a2 = *(_QWORD *)(v6 + 24);
      return result;
    }
  }
  mutex_unlock(v4 + 536);
  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(32, 0xCC0u, 0, "cam_res_mgr_led_trigger_register", 0x4Fu);
  else
    v8 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  v9 = (_QWORD *)v8;
  if ( v8 )
  {
    led_trigger_register_simple(a1, a2);
    *v9 = v9;
    v9[1] = v9;
    v10 = *a2;
    v11 = cam_res + 536;
    v9[2] = a1;
    v9[3] = v10;
    mutex_lock(v11);
    v12 = cam_res;
    v13 = cam_res + 472;
    v14 = *(_QWORD **)(cam_res + 480);
    if ( v9 == (_QWORD *)(cam_res + 472) || v14 == v9 || *v14 != v13 )
    {
      _list_add_valid_or_report(v9);
      v12 = cam_res;
    }
    else
    {
      *(_QWORD *)(cam_res + 480) = v9;
      *v9 = v13;
      v9[1] = v14;
      *v14 = v9;
    }
    return mutex_unlock(v12 + 536);
  }
  else
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x200000,
               1,
               "cam_res_mgr_led_trigger_register",
               83,
               "Failed to malloc memory for flash_res:%s",
               a1);
    *a2 = 0;
  }
  return result;
}
