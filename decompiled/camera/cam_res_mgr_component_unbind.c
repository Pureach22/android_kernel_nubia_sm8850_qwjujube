void cam_res_mgr_component_unbind()
{
  __int64 v0; // x8
  _QWORD *v1; // x19
  __int64 v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x0
  int v5; // w8
  _QWORD *v6; // x22
  _QWORD *v7; // x0
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x24
  _QWORD *v12; // x9
  _QWORD *v13; // x8
  _QWORD *v14; // x19
  _QWORD *v15; // x9

  if ( cam_res )
  {
    mutex_lock(cam_res + 488);
    v0 = cam_res;
    v1 = *(_QWORD **)(cam_res + 456);
    if ( v1 != (_QWORD *)(cam_res + 456) )
    {
      do
      {
        v6 = (_QWORD *)*v1;
        v7 = (_QWORD *)v1[2];
        if ( v7 != v1 + 2 )
        {
          do
          {
            v11 = (_QWORD *)*v7;
            v10 = (_QWORD *)v7[1];
            if ( (_QWORD *)*v10 == v7 && (_QWORD *)v11[1] == v7 )
            {
              v11[1] = v10;
              *v10 = v11;
            }
            else
            {
              _list_del_entry_valid_or_report(v7);
              v7 = v12;
            }
            *v7 = v7;
            v7[1] = v7;
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v7, 0);
            else
              kvfree(v7);
            v7 = v11;
          }
          while ( v11 != v1 + 2 );
        }
        v8 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v8 == v1 && (v9 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
        {
          v9[1] = v8;
          *v8 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        *v1 = v1;
        v1[1] = v1;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v1, 0);
        else
          kvfree(v1);
        v0 = cam_res;
        v1 = v6;
      }
      while ( v6 != (_QWORD *)(cam_res + 456) );
    }
    mutex_unlock(v0 + 488);
    mutex_lock(cam_res + 536);
    v2 = cam_res;
    v3 = *(_QWORD **)(cam_res + 472);
    if ( v3 != (_QWORD *)(cam_res + 472) )
    {
      do
      {
        v14 = (_QWORD *)*v3;
        v13 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v13 == v3 && (_QWORD *)v14[1] == v3 )
        {
          v14[1] = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
          v3 = v15;
        }
        *v3 = v3;
        v3[1] = v3;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v3, 0);
        else
          kvfree(v3);
        v2 = cam_res;
        v3 = v14;
      }
      while ( v14 != (_QWORD *)(cam_res + 472) );
    }
    mutex_unlock(v2 + 536);
    v4 = cam_res;
    if ( *(_QWORD *)(cam_res + 208) )
    {
      devm_pinctrl_put(*(_QWORD *)(cam_res + 208));
      v4 = cam_res;
    }
    v5 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v4 + 208) = 0;
    *(_DWORD *)(v4 + 204) = 3;
    if ( v5 == 1 )
      cam_mem_trace_free((_QWORD *)v4, 0);
    else
      kvfree(v4);
    cam_res = 0;
  }
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_component_unbind",
      952,
      "Component unbound successfully");
}
