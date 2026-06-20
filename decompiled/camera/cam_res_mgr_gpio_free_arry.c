__int64 __fastcall cam_res_mgr_gpio_free_arry(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v6; // x21
  unsigned int v7; // w25
  char v8; // w26
  _QWORD *v9; // x27
  _QWORD *v10; // x8
  int v11; // w9
  _QWORD *v12; // x10
  _QWORD *v13; // x0
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  _QWORD *v16; // x0
  _QWORD *v17; // x8
  __int64 v18; // x9
  _QWORD *v19; // x8
  _QWORD *v20; // x9
  unsigned int idx_from_shared_pctrl_gpio; // w0
  _QWORD *v22; // x9
  _QWORD *v23; // x9

  if ( a3 )
  {
    v4 = a3;
    v6 = result;
    do
    {
      --v4;
      v7 = *(_DWORD *)(a2 + 24 * v4);
      v8 = cam_res_mgr_gpio_is_in_shared_pctrl_gpio(v7, a2, a3, a4);
      mutex_lock(cam_res + 488);
      if ( cam_res && *(_BYTE *)(cam_res + 200) == 1 )
      {
        v9 = (_QWORD *)(cam_res + 456);
        while ( 1 )
        {
          v9 = (_QWORD *)*v9;
          if ( v9 == (_QWORD *)(cam_res + 456) )
            break;
          if ( *((_DWORD *)v9 + 8) == v7 )
          {
            v10 = v9 + 2;
            v11 = 2;
            v12 = v9 + 2;
            do
            {
              v12 = (_QWORD *)*v12;
              --v11;
            }
            while ( v12 != v10 );
            if ( v11 )
            {
              v13 = v9 + 2;
              while ( 1 )
              {
                v13 = (_QWORD *)*v13;
                if ( v13 == v10 )
                  goto LABEL_30;
                if ( v13[2] == v6 )
                {
                  v14 = (_QWORD *)v13[1];
                  if ( (_QWORD *)*v14 == v13 && (v15 = (_QWORD *)*v13, *(_QWORD **)(*v13 + 8LL) == v13) )
                  {
                    v15[1] = v14;
                    *v14 = v15;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v13);
                    v13 = v23;
                  }
                  *v13 = v13;
                  v13[1] = v13;
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free(v13, 0);
                  else
                    kvfree(v13);
                  goto LABEL_38;
                }
              }
            }
            v16 = (_QWORD *)*v10;
            v17 = *(_QWORD **)(*v10 + 8LL);
            if ( (_QWORD *)*v17 == v16 && (v18 = *v16, *(_QWORD **)(*v16 + 8LL) == v16) )
            {
              *(_QWORD *)(v18 + 8) = v17;
              *v17 = v18;
            }
            else
            {
              _list_del_entry_valid_or_report(v16);
              v16 = v22;
            }
            *v16 = v16;
            v16[1] = v16;
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v16, 0);
            else
              kvfree(v16);
            v19 = (_QWORD *)v9[1];
            if ( (_QWORD *)*v19 == v9 && (v20 = (_QWORD *)*v9, *(_QWORD **)(*v9 + 8LL) == v9) )
            {
              v20[1] = v19;
              *v19 = v20;
            }
            else
            {
              _list_del_entry_valid_or_report(v9);
            }
            *v9 = v9;
            v9[1] = v9;
            if ( mem_trace_en == 1 )
            {
              cam_mem_trace_free(v9, 0);
              break;
            }
            kvfree(v9);
            if ( (v8 & 1) != 0 )
              goto LABEL_31;
            goto LABEL_34;
          }
        }
      }
LABEL_30:
      if ( (v8 & 1) != 0 )
      {
LABEL_31:
        idx_from_shared_pctrl_gpio = cam_res_mgr_util_get_idx_from_shared_pctrl_gpio((_QWORD *)v7);
        if ( (idx_from_shared_pctrl_gpio & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000,
            1,
            "cam_res_mgr_gpio_free",
            642,
            "invalid pinctrl idx: %d",
            idx_from_shared_pctrl_gpio);
        else
          cam_res_mgr_shared_pinctrl_select_state(idx_from_shared_pctrl_gpio, 0);
      }
LABEL_34:
      if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000,
          4,
          "cam_res_mgr_gpio_free",
          646,
          "freeing gpio: %u",
          v7);
      gpio_free(v7);
LABEL_38:
      result = mutex_unlock(cam_res + 488);
    }
    while ( v4 );
  }
  return result;
}
