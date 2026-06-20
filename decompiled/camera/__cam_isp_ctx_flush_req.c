__int64 __fastcall _cam_isp_ctx_flush_req(__int64 a1, unsigned int ***a2, __int64 a3)
{
  __int64 v5; // x20
  unsigned int **v6; // x9
  unsigned int *v8; // x22
  unsigned int ***v9; // x8
  unsigned int *v10; // x1
  __int64 result; // x0
  unsigned int ***v12; // x8
  unsigned int *v13; // x1
  unsigned int *v14; // x20
  __int64 v15; // x25
  int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x24
  unsigned int v19; // w7
  int v20; // w21
  __int64 v21; // x0
  signed int v22; // w0
  int v23; // w0
  unsigned int **v24; // x8
  unsigned int *v25; // x9
  __int64 v26; // x21
  unsigned int *v27; // x1
  unsigned int *v28; // [xsp+18h] [xbp-28h]
  unsigned int *v29; // [xsp+20h] [xbp-20h]
  unsigned int *v30; // [xsp+28h] [xbp-18h] BYREF
  unsigned int **v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 256);
  v30 = (unsigned int *)&v30;
  v31 = &v30;
  v6 = *a2;
  if ( *a2 != (unsigned int **)a2 )
  {
    if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000008,
        4,
        "__cam_isp_ctx_flush_req",
        6702,
        "Flush [%u] in progress for req_id %llu, ctx_id:%u link: 0x%x",
        *(_DWORD *)(a3 + 8),
        *(_QWORD *)(a3 + 16),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      v6 = *a2;
      if ( *a2 == (unsigned int **)a2 )
        goto LABEL_32;
      while ( 1 )
      {
LABEL_8:
        v8 = *v6;
        if ( *(_DWORD *)(a3 + 8) == 1 )
        {
          if ( v6[3] == *(unsigned int **)(a3 + 16) )
          {
            v12 = (unsigned int ***)v6[1];
            if ( *v12 == v6 && *((unsigned int ***)v8 + 1) == v6 )
            {
              *((_QWORD *)v8 + 1) = v12;
              *v12 = (unsigned int **)v8;
            }
            else
            {
              _list_del_entry_valid_or_report(v6);
            }
            *v6 = (unsigned int *)v6;
            v6[1] = (unsigned int *)v6;
            v13 = (unsigned int *)v31;
            if ( v6 == &v30 || v6 == v31 || *v31 != (unsigned int *)&v30 )
            {
              _list_add_valid_or_report(v6);
            }
            else
            {
              v31 = v6;
              *v6 = (unsigned int *)&v30;
              v6[1] = v13;
              *(_QWORD *)v13 = v6;
            }
            _cam_isp_ctx_update_state_monitor_array(v5, 7, (__int64)v6[3]);
            goto LABEL_32;
          }
        }
        else
        {
          v9 = (unsigned int ***)v6[1];
          if ( *v9 == v6 && *((unsigned int ***)v8 + 1) == v6 )
          {
            *((_QWORD *)v8 + 1) = v9;
            *v9 = (unsigned int **)v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v6);
          }
          *v6 = (unsigned int *)v6;
          v6[1] = (unsigned int *)v6;
          v10 = (unsigned int *)v31;
          if ( v6 == &v30 || v6 == v31 || *v31 != (unsigned int *)&v30 )
          {
            _list_add_valid_or_report(v6);
          }
          else
          {
            v31 = v6;
            *v6 = (unsigned int *)&v30;
            v6[1] = v10;
            *(_QWORD *)v10 = v6;
          }
          _cam_isp_ctx_update_state_monitor_array(v5, 7, (__int64)v6[3]);
        }
        v6 = (unsigned int **)v8;
        if ( v8 == (unsigned int *)a2 )
          goto LABEL_32;
      }
    }
    if ( v6 != (unsigned int **)a2 )
      goto LABEL_8;
LABEL_32:
    v14 = v30;
    if ( v30 != (unsigned int *)&v30 )
    {
      v28 = (unsigned int *)(a1 + 176);
      while ( 1 )
      {
        v29 = *(unsigned int **)v14;
        cam_smmu_buffer_tracker_putref(v14 + 28);
        v15 = *((_QWORD *)v14 + 4);
        if ( *(_DWORD *)(v15 + 32) )
        {
          v16 = 0;
          do
          {
            v17 = *(_QWORD *)(v15 + 24);
            v18 = v16;
            v19 = *(_DWORD *)(v17 + ((__int64)v16 << 6) + 16);
            if ( v19 != -1 )
            {
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "__cam_isp_ctx_flush_req",
                  6744,
                  "Flush req 0x%llx, fence %d, ctx_id:%u link: 0x%x",
                  *((_QWORD *)v14 + 3));
                v19 = *(_DWORD *)(*(_QWORD *)(v15 + 24) + (v18 << 6) + 16);
              }
              if ( (unsigned int)cam_sync_signal(v19, 4u, 0x39u) )
              {
                v20 = *(_DWORD *)(*(_QWORD *)(v15 + 24) + (v18 << 6) + 16);
                if ( (unsigned int)__ratelimit(&_cam_isp_ctx_flush_req__rs, "__cam_isp_ctx_flush_req") )
                  v21 = 3;
                else
                  v21 = 2;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  v21,
                  8,
                  1,
                  "__cam_isp_ctx_flush_req",
                  6753,
                  "signal fence %d failed, ctx_id:%u link: 0x%x",
                  v20,
                  *(_DWORD *)(a1 + 32),
                  *(_DWORD *)(a1 + 64));
              }
              *(_DWORD *)(*(_QWORD *)(v15 + 24) + (v18 << 6) + 16) = -1;
              v17 = *(_QWORD *)(v15 + 24);
            }
            v22 = *(_DWORD *)(v17 + (v18 << 6) + 20);
            if ( v22 >= 1 )
            {
              v23 = cam_sync_signal(v22, 4u, 0x39u);
              if ( v23 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_flush_req",
                  6769,
                  "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                  *(_DWORD *)(*(_QWORD *)(v15 + 24) + (v18 << 6) + 20),
                  *((_QWORD *)v14 + 3),
                  v23,
                  *(_DWORD *)(a1 + 32),
                  *(_DWORD *)(a1 + 64));
              *(_DWORD *)(*(_QWORD *)(v15 + 24) + (v18 << 6) + 20) = -1;
            }
            v16 = v18 + 1;
          }
          while ( (unsigned int)(v18 + 1) < *(_DWORD *)(v15 + 32) );
        }
        *(_DWORD *)(v15 + 4448) = 0;
        *(_BYTE *)(v15 + 4505) = 0;
        v24 = *((unsigned int ***)v14 + 1);
        if ( *v24 == v14 && (v25 = *(unsigned int **)v14, *(unsigned int **)(*(_QWORD *)v14 + 8LL) == v14) )
        {
          *((_QWORD *)v25 + 1) = v24;
          *v24 = v25;
        }
        else
        {
          _list_del_entry_valid_or_report(v14);
        }
        *(_QWORD *)v14 = v14;
        *((_QWORD *)v14 + 1) = v14;
        v26 = *((_QWORD *)v14 + 4);
        if ( (debug_mdl & 8) == 0 || debug_priority )
          break;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_move_req_to_free_list",
          1404,
          "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
          *((_QWORD *)v14 + 3),
          *((_QWORD *)v14 + 17),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        if ( *((_QWORD *)v14 + 17) )
          goto LABEL_57;
LABEL_58:
        v27 = *(unsigned int **)(a1 + 184);
        if ( v28 == v14 || v27 == v14 || *(unsigned int **)v27 != v28 )
        {
          _list_add_valid_or_report(v14);
        }
        else
        {
          *(_QWORD *)(a1 + 184) = v14;
          *(_QWORD *)v14 = v28;
          *((_QWORD *)v14 + 1) = v27;
          *(_QWORD *)v27 = v14;
        }
        v14 = v29;
        if ( v29 == (unsigned int *)&v30 )
          goto LABEL_69;
      }
      if ( !*((_QWORD *)v14 + 17) )
        goto LABEL_58;
LABEL_57:
      cam_mem_put_kref(*(_DWORD *)(v26 + 4328));
      cam_common_mem_free(*((_QWORD *)v14 + 17));
      *((_QWORD *)v14 + 17) = 0;
      goto LABEL_58;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_flush_req",
      6730,
      "flush list is empty, flush type %d for req %llu, ctx_id:%u link: 0x%x",
      *(_DWORD *)(a3 + 8),
      *(_QWORD *)(a3 + 16),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_69;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_flush_req",
      6690,
      "request list is empty, ctx_id:%u link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  if ( *(_DWORD *)(a3 + 8) != 1 )
  {
LABEL_69:
    result = 0;
    goto LABEL_70;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "__cam_isp_ctx_flush_req",
    6695,
    "no request to cancel(lastapplied:%lld cancel:%lld),ctx:%u link:0x%x",
    *(_QWORD *)(v5 + 37352),
    *(_QWORD *)(a3 + 16),
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 64));
  result = 4294967274LL;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
