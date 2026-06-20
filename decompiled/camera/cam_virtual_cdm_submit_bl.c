__int64 __fastcall cam_virtual_cdm_submit_bl(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x23
  __int64 v7; // x26
  __int64 v8; // x8
  int v9; // w21
  __int64 v10; // x27
  __int64 v11; // x23
  int v12; // w6
  int *v13; // x25
  char *v14; // x7
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x2
  unsigned int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x28
  _QWORD *v22; // x0
  _QWORD *v23; // x1
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x28
  char v27; // w9
  char v28; // w8
  unsigned int v29; // w21
  unsigned int v30; // w22
  unsigned __int64 v32; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v33[2]; // [xsp+30h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 8);
  v7 = *(_QWORD *)(a1 + 3680);
  mutex_lock(a3 + 280);
  v8 = *(_QWORD *)(a2 + 8);
  if ( !*(_DWORD *)(v8 + 20) )
  {
LABEL_52:
    v29 = -22;
    goto LABEL_53;
  }
  v9 = 0;
  v10 = v6 + 48;
  v11 = v7 + 184;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v12 = *(_DWORD *)(v8 + 16);
    v13 = (int *)(v10 + 24LL * v9);
    v32 = 0;
    v33[0] = 0;
    if ( v12 != 2 )
    {
      if ( v12 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_virtual_cdm_submit_bl",
          120,
          "Only mem hdl/Kernel va type is supported %d",
          v12);
      }
      else
      {
        if ( !(unsigned int)cam_mem_get_cpu_buf(*v13, v33, &v32) )
        {
          v15 = v32;
          v14 = (char *)v33[0];
          if ( !v33[0] )
            goto LABEL_51;
          goto LABEL_12;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_virtual_cdm_submit_bl",
          110,
          "Falied to get CPU addr_i[%d] req_type %d",
          v9,
          *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL));
      }
      v15 = v32;
LABEL_51:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_virtual_cdm_submit_bl",
        156,
        "Sanity check failed for hdl=%x len=%zu:%d",
        *v13,
        v15,
        v13[2]);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_virtual_cdm_submit_bl",
        159,
        "Sanity check failed for cmd_count=%d cnt=%d",
        v9,
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL));
      goto LABEL_52;
    }
    v33[0] = *(_QWORD *)v13;
    v14 = (char *)v33[0];
    v15 = (unsigned int)(v13[3] + v13[2]);
    v32 = v15;
    if ( !v33[0] )
      goto LABEL_51;
LABEL_12:
    if ( !v15 )
      goto LABEL_51;
    v16 = (unsigned int)v13[2];
    if ( v15 < v16 )
      goto LABEL_51;
    v17 = (unsigned int)v13[3];
    if ( v15 - v16 < v17 )
      break;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_virtual_cdm_submit_bl",
        138,
        "hdl=%x vaddr=%pK offset=%d cmdlen=%d:%zu",
        *v13,
        v14,
        v16,
        v17,
        v15);
      LODWORD(v16) = v13[2];
      LODWORD(v17) = v13[3];
      v14 = (char *)v33[0];
    }
    v18 = cam_cdm_util_cmd_buf_write(
            (__int64 *)(a3 + 264),
            &v14[v16 & 0xFFFFFFFC],
            v17,
            a3 + 160,
            *(_DWORD *)(a3 + 152));
    if ( v18 )
    {
      v30 = v18;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_virtual_cdm_submit_bl",
        149,
        "write failed for cnt=%d:%d len %u",
        v9,
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL),
        v13[3]);
      v29 = v30;
      goto LABEL_45;
    }
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_virtual_cdm_submit_bl",
        168,
        "write BL success for cnt=%d with tag=%d",
        v9,
        *(unsigned __int8 *)(v7 + 4864));
    v19 = *(_QWORD *)(a2 + 8);
    if ( *(_BYTE *)v19 == 1 && v9 == *(_DWORD *)(v19 + 20) )
    {
      if ( mem_trace_en == 1 )
        v20 = cam_mem_trace_alloc(56, 0xCC0u, 0, "cam_virtual_cdm_submit_bl", 0xAEu);
      else
        v20 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
      v21 = v20;
      if ( !v20 )
      {
        v29 = -12;
        goto LABEL_53;
      }
      *(_DWORD *)(v20 + 4) = 1;
      *(_DWORD *)(v20 + 8) = *(_DWORD *)a2;
      *(_DWORD *)(v20 + 24) = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 32LL);
      *(_BYTE *)v20 = *(_BYTE *)(v7 + 4864);
      *(_QWORD *)(v20 + 16) = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
      mutex_lock(a1);
      v22 = (_QWORD *)(v21 + 32);
      v23 = *(_QWORD **)(v7 + 192);
      if ( v21 + 32 == v11 || v23 == v22 || *v23 != v11 )
      {
        _list_add_valid_or_report(v22);
      }
      else
      {
        *(_QWORD *)(v7 + 192) = v22;
        *(_QWORD *)(v21 + 32) = v11;
        *(_QWORD *)(v21 + 40) = v23;
        *v23 = v22;
      }
      mutex_unlock(a1);
      if ( mem_trace_en == 1 )
      {
        v24 = cam_mem_trace_alloc(64, 0x820u, 0, "cam_virtual_cdm_submit_bl", 0xBFu);
        if ( !v24 )
          goto LABEL_35;
LABEL_34:
        *(_DWORD *)(v24 + 8) = 2;
        v25 = *(unsigned __int8 *)(v7 + 4864);
        *(_QWORD *)(v24 + 32) = 0xFFFFFFFE00000LL;
        v26 = v24 + 32;
        *(_QWORD *)v24 = a1;
        *(_DWORD *)(v24 + 12) = v25;
        *(_QWORD *)(v24 + 40) = v24 + 40;
        *(_QWORD *)(v24 + 48) = v24 + 40;
        *(_QWORD *)(v24 + 56) = cam_virtual_cdm_work;
        *(_QWORD *)(v24 + 24) = ktime_get_with_offset(1);
        queue_work_on(32, *(_QWORD *)(v7 + 176), v26);
        goto LABEL_35;
      }
      v24 = _kvmalloc_node_noprof(64, 0, 2336, 0xFFFFFFFFLL);
      if ( v24 )
        goto LABEL_34;
    }
LABEL_35:
    v27 = debug_mdl;
    v28 = *(_BYTE *)(v7 + 4864) + 1;
    *(_BYTE *)(v7 + 4864) = v28;
    if ( (v27 & 1) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        4,
        "cam_virtual_cdm_submit_bl",
        207,
        "Now commit the BL nothing for virtual");
      v28 = *(_BYTE *)(v7 + 4864);
    }
    if ( v28 == 63 )
      *(_BYTE *)(v7 + 4864) = 0;
    v8 = *(_QWORD *)(a2 + 8);
    if ( !*(_DWORD *)(v8 + 16) )
    {
      cam_mem_put_cpu_buf(*v13);
      v8 = *(_QWORD *)(a2 + 8);
    }
    if ( (unsigned int)++v9 >= *(_DWORD *)(v8 + 20) )
    {
      v29 = 0;
      goto LABEL_53;
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    1,
    "cam_virtual_cdm_submit_bl",
    130,
    "Not enough buffer");
  v29 = -22;
LABEL_45:
  if ( !*(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL) )
    cam_mem_put_cpu_buf(*v13);
LABEL_53:
  mutex_unlock(a3 + 280);
  _ReadStatusReg(SP_EL0);
  return v29;
}
