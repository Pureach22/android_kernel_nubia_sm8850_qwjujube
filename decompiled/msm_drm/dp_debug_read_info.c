__int64 __fastcall dp_debug_read_info(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x24
  __int64 result; // x0
  char *v9; // x0
  char *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w3
  __int64 v14; // x8
  int v15; // w3
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  size_t v20; // x21
  __int64 v21; // x25
  const char *test_name; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned __int64 v28; // x8
  __int64 v29; // x21
  __int64 ipc_log_context; // x0
  unsigned int v31; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    result = -19;
    goto LABEL_26;
  }
  if ( !*a4 )
  {
    v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
    v10 = v9;
    if ( (unsigned __int64)v9 < 0x11 )
    {
      result = -12;
      goto LABEL_26;
    }
    v11 = snprintf(v9, 0x1000u, "\tstate=0x%x\n", **(_DWORD **)(v4 + 128));
    if ( (int)v11 >= 4096
      || (v12 = *(_QWORD *)(v4 + 120),
          v32 = v11,
          v13 = *(_DWORD *)(v12 + 76),
          v31 = 4096 - v11,
          v11 = snprintf(&v10[(unsigned int)v11], (unsigned int)(4096 - v11), "\tlink_rate=%u\n", v13),
          (int)v31 <= (int)v11) )
    {
      ipc_log_context = get_ipc_log_context(v11);
      ipc_log_string(ipc_log_context, "[e][%-4d]buffer overflow\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_27296B, "dp_debug_check_buffer_overflow");
    }
    else
    {
      v14 = v32 + (unsigned int)v11;
      v15 = *(_DWORD *)(*(_QWORD *)(v4 + 120) + 80LL);
      v31 = 4096 - v14;
      v32 += v11;
      v16 = snprintf(&v10[v14], (unsigned int)(4096 - v14), "\tnum_lanes=%u\n", v15);
      if ( !(unsigned int)dp_debug_check_buffer_overflow(v16, &v31, &v32) )
      {
        v17 = snprintf(
                &v10[v32],
                v31,
                "\tresolution=%dx%d@%dHz\n",
                *(_DWORD *)(*(_QWORD *)(v4 + 120) + 104LL),
                *(_DWORD *)(*(_QWORD *)(v4 + 120) + 108LL),
                *(_DWORD *)(*(_QWORD *)(v4 + 120) + 148LL));
        if ( !(unsigned int)dp_debug_check_buffer_overflow(v17, &v31, &v32) )
        {
          v18 = snprintf(&v10[v32], v31, "\tpclock=%dKHz\n", *(_DWORD *)(*(_QWORD *)(v4 + 120) + 152LL));
          if ( !(unsigned int)dp_debug_check_buffer_overflow(v18, &v31, &v32) )
          {
            v19 = snprintf(&v10[v32], v31, "\tbpp=%d\n", *(_DWORD *)(*(_QWORD *)(v4 + 120) + 156LL));
            if ( !(unsigned int)dp_debug_check_buffer_overflow(v19, &v31, &v32) )
            {
              v20 = v31;
              v21 = v32;
              test_name = (const char *)dp_link_get_test_name(**(unsigned int **)(v4 + 112));
              v23 = snprintf(&v10[v21], v20, "\ttest_req=%s\n", test_name);
              if ( !(unsigned int)dp_debug_check_buffer_overflow(v23, &v31, &v32) )
              {
                v24 = snprintf(&v10[v32], v31, "\tlane_count=%d\n", *(_DWORD *)(*(_QWORD *)(v4 + 112) + 128LL));
                if ( !(unsigned int)dp_debug_check_buffer_overflow(v24, &v31, &v32) )
                {
                  v25 = snprintf(&v10[v32], v31, "\tbw_code=%d\n", *(_DWORD *)(*(_QWORD *)(v4 + 112) + 132LL));
                  if ( !(unsigned int)dp_debug_check_buffer_overflow(v25, &v31, &v32) )
                  {
                    v26 = snprintf(
                            &v10[v32],
                            v31,
                            "\tv_level=%d\n",
                            *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 124LL));
                    if ( !(unsigned int)dp_debug_check_buffer_overflow(v26, &v31, &v32) )
                    {
                      v27 = snprintf(
                              &v10[v32],
                              v31,
                              "\tp_level=%d\n",
                              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 125LL));
                      if ( !(unsigned int)dp_debug_check_buffer_overflow(v27, &v31, &v32) )
                      {
                        v28 = v32;
                        if ( v32 >= a3 )
                          v28 = a3;
                        v29 = v28;
                        if ( v28 > 0x1000 )
                        {
                          _copy_overflow(4096, v28);
                        }
                        else
                        {
                          _check_object_size(v10, v28, 1);
                          if ( !inline_copy_to_user(a2, v10, v29) )
                          {
                            *a4 += v29;
LABEL_25:
                            kfree(v10);
                            result = v29;
                            goto LABEL_26;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v29 = -22;
    goto LABEL_25;
  }
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
