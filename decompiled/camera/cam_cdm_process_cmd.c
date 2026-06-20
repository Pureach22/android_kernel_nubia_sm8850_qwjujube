__int64 __fastcall cam_cdm_process_cmd(__int64 a1, int a2, unsigned int *a3, unsigned int a4)
{
  _DWORD *v4; // x27
  unsigned int v5; // w19
  const char *v6; // x19
  __int64 v7; // x7
  unsigned int v10; // w8
  int v11; // w21
  _DWORD *v12; // x20
  unsigned int v14; // w8
  __int64 v15; // x9
  __int64 v16; // x6
  const char *v17; // x5
  __int64 v18; // x4
  unsigned int v19; // w6
  int v20; // w8
  __int64 v21; // x9
  __int64 v22; // x6
  int v23; // w21
  __int64 v25; // x22
  int v26; // w7
  __int64 v27; // x21
  int v28; // w6
  int v29; // w21
  __int64 v31; // x9
  int v32; // w21
  __int64 v34; // x9
  const char *v36; // x5
  __int64 v37; // x4
  __int64 v38; // x6
  unsigned int free_client_slot; // w22
  __int64 v40; // x20
  unsigned int v43; // w0
  __int64 v44; // x4
  __int64 v45; // x4
  int v46; // w0
  __int64 v47; // x6
  __int64 v48; // x0
  const char *v49; // x5
  __int64 v50; // x4
  int v51; // w0
  int v52; // w0
  __int64 v54; // x0
  const char *v55; // x5
  __int64 v56; // x4
  _DWORD *v57; // x0
  char v58; // w8
  _DWORD *v59; // x23
  __int64 v60; // x9
  _UNKNOWN **ops; // x0
  char v62; // w8
  char v63; // w9
  int v64; // w8
  char v65; // w9
  int v66; // w8
  _QWORD *v67; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v69; // x24

  v5 = -22;
  if ( (unsigned int)a2 > 7 || !a1 || !a3 )
    return v5;
  v6 = *(const char **)(a1 + 3680);
  v7 = a4;
  if ( a2 != 1 && (*((_QWORD *)v6 + 607) & 0x100) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      579,
      "%s%u has encountered a page fault, unable to service cmd %u",
      v6 + 4,
      *((_DWORD *)v6 + 33),
      a2);
    return (unsigned int)-11;
  }
  if ( a2 > 3 )
  {
    if ( a2 > 5 )
    {
      if ( a2 == 6 )
      {
        v20 = *a3;
        if ( a4 == 4 )
        {
          v21 = *(_QWORD *)&v6[8 * (unsigned __int8)v20 + 248];
          if ( v21 )
          {
            v22 = *(unsigned int *)(v21 + 328);
            if ( v20 == (_DWORD)v22 )
              return (unsigned int)((__int64 (*)(void))cam_hw_cdm_hang_detect)();
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD))cam_print_log)(
              3,
              1,
              1,
              "cam_cdm_process_cmd",
              955,
              "handle mismatch, client handle %d index %d received handle %d",
              v22,
              (unsigned __int8)*a3,
              *a3);
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              1,
              1,
              "cam_cdm_process_cmd",
              948,
              "Client not present for handle %d",
              v20);
          }
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_process_cmd",
            939,
            "Invalid CDM cmd %d size=%x for handle=%x",
            6,
            a4,
            v20);
        }
      }
      else if ( a4 == 4 )
      {
        mutex_lock(a1);
        cam_hw_cdm_dump_core_debug_registers(a1, 1);
        mutex_unlock(a1);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          969,
          "Invalid CDM cmd %d size=%x for handle=0x%x",
          7,
          a4,
          *a3);
      }
      return (unsigned int)-22;
    }
    if ( a2 == 4 )
    {
      v11 = *a3;
      if ( a4 != 4 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          851,
          "Invalid CDM cmd %d size=%x for handle=%x",
          4,
          a4,
          v11);
        return (unsigned int)-22;
      }
      v12 = (_DWORD *)a1;
      mutex_lock(a1);
      v14 = *a3;
      v15 = *(_QWORD *)&v6[8 * (unsigned __int8)v11 + 248];
      if ( !v15 )
      {
        v44 = 860;
        goto LABEL_76;
      }
      if ( v14 != *(_DWORD *)(v15 + 328) )
      {
        v45 = 868;
        goto LABEL_82;
      }
      v5 = cam_hw_cdm_flush_hw(v12, v14);
      if ( !v5 )
      {
        v46 = __ratelimit(&cam_cdm_process_cmd__rs_67, "cam_cdm_process_cmd");
        v47 = *a3;
        if ( v46 )
          v48 = 3;
        else
          v48 = 2;
        v49 = "CDM HW flush done for handle 0x%x";
        v50 = 881;
        goto LABEL_98;
      }
      v16 = *a3;
      v17 = "CDM HW flush failed for handle 0x%x rc = %d";
      v18 = 877;
    }
    else
    {
      v29 = *a3;
      if ( a4 != 4 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          894,
          "Invalid CDM cmd %d size=%x for handle=%x",
          5,
          a4,
          v29);
        return (unsigned int)-22;
      }
      v12 = (_DWORD *)a1;
      mutex_lock(a1);
      v14 = *a3;
      v31 = *(_QWORD *)&v6[8 * (unsigned __int8)v29 + 248];
      if ( !v31 )
      {
        v44 = 904;
        goto LABEL_76;
      }
      if ( v14 != *(_DWORD *)(v31 + 328) )
      {
        v45 = 912;
        goto LABEL_82;
      }
      v5 = cam_hw_cdm_handle_error_info(v12, v14);
      if ( !v5 )
      {
        v51 = __ratelimit(&cam_cdm_process_cmd__rs_70, "cam_cdm_process_cmd");
        v47 = *a3;
        if ( v51 )
          v48 = 3;
        else
          v48 = 2;
        v49 = "CDM HW handle error done for handle 0x%x";
        v50 = 925;
        goto LABEL_98;
      }
      v16 = *a3;
      v17 = "CDM HW handle error failed for handle 0x%x rc = %d";
      v18 = 921;
    }
LABEL_47:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      v18,
      v17,
      v16,
      v5);
LABEL_99:
    mutex_unlock(v12);
    return v5;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      if ( a4 == 16 )
      {
        v19 = *(_DWORD *)(*((_QWORD *)a3 + 1) + 16LL);
        if ( v19 >= 3 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_process_cmd",
            598,
            "Invalid req bl cmd addr type=%d",
            v19);
          return (unsigned int)-22;
        }
        v40 = *(_QWORD *)&v6[8 * (unsigned __int8)*a3 + 248];
        if ( !v40 || *a3 != *(_DWORD *)(v40 + 328) )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_process_cmd",
            605,
            "Invalid client %pK hdl=%x",
            v40);
          return (unsigned int)-22;
        }
        cam_cdm_get_client_refcount(v40);
        if ( **((_BYTE **)a3 + 1) == 1 && !*(_QWORD *)(v40 + 144) )
        {
          v55 = "CDM request cb without registering cb";
          v56 = 612;
        }
        else
        {
          if ( *(_DWORD *)(v40 + 272) == 1 )
          {
            if ( *((_DWORD *)v6 + 33) )
              v43 = cam_hw_cdm_submit_bl(a1, a3, v40);
            else
              v43 = cam_virtual_cdm_submit_bl(a1, a3, v40);
            v5 = v43;
            cam_cdm_put_client_refcount(v40);
            return v5;
          }
          v55 = "Invalid CDM needs to be streamed ON first";
          v56 = 618;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          v56,
          v55);
        cam_cdm_put_client_refcount(v40);
        return (unsigned int)-22;
      }
      v36 = "Invalid CDM cmd %d arg size=%x";
      v37 = 591;
      v38 = 2;
LABEL_101:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_process_cmd",
        v37,
        v36,
        v38,
        v7);
      return (unsigned int)-22;
    }
    v32 = *a3;
    if ( a4 != 4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_process_cmd",
        809,
        "Invalid CDM cmd %d size=%x for handle=%x",
        3,
        a4,
        v32);
      return (unsigned int)-22;
    }
    v12 = (_DWORD *)a1;
    mutex_lock(a1);
    v14 = *a3;
    v34 = *(_QWORD *)&v6[8 * (unsigned __int8)v32 + 248];
    if ( v34 )
    {
      if ( v14 == *(_DWORD *)(v34 + 328) )
      {
        v5 = cam_hw_cdm_reset_hw(v12, v14);
        if ( v5 )
        {
          v16 = *a3;
          v17 = "CDM HW reset failed for handle 0x%x rc = %d";
          v18 = 834;
          goto LABEL_47;
        }
        v52 = __ratelimit(&cam_cdm_process_cmd__rs, "cam_cdm_process_cmd");
        v47 = *a3;
        if ( v52 )
          v48 = 3;
        else
          v48 = 2;
        v49 = "CDM HW reset done for handle 0x%x";
        v50 = 838;
LABEL_98:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          v48,
          1,
          3,
          "cam_cdm_process_cmd",
          v50,
          v49,
          v47);
        goto LABEL_99;
      }
      v45 = 826;
LABEL_82:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_process_cmd",
        v45,
        "handle mismatch, client handle %d index %d received handle %d");
      goto LABEL_83;
    }
    v44 = 818;
LABEL_76:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      v44,
      "Client not present for handle %d",
      v14);
    goto LABEL_83;
  }
  if ( a2 )
  {
    v23 = *a3;
    if ( a4 != 4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_process_cmd",
        749,
        "Invalid CDM cmd %d size=%x for handle=%x",
        1,
        a4,
        v23);
      return (unsigned int)-22;
    }
    v12 = (_DWORD *)a1;
    mutex_lock(a1);
    v25 = (unsigned __int8)v23;
    v26 = *a3;
    v27 = *(_QWORD *)&v6[8 * (unsigned __int8)v23 + 248];
    if ( v27 && v26 == *(_DWORD *)(v27 + 328) )
    {
      cam_cdm_put_client_refcount(v27);
      mutex_lock(v27 + 280);
      v28 = *(_DWORD *)(v27 + 276);
      if ( v28 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          765,
          "CDM Client refcount not zero %d",
          v28);
        mutex_unlock(v27 + 280);
        mutex_unlock(v12);
        return (unsigned int)-1;
      }
      *(_QWORD *)&v6[8 * v25 + 248] = 0;
      mutex_unlock(v27 + 280);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v27, 0);
      else
        kvfree(v27);
      if ( v6[4876] )
      {
        v57 = v12;
        v58 = v6[4876] - 1;
        *((_BYTE *)v6 + 4876) = v58;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_process_cmd",
          780,
          "Invalid active client decrement %u for %s%u",
          0,
          v6 + 4,
          *((_DWORD *)v6 + 33));
        v58 = v6[4876];
        v57 = v12;
      }
      if ( !v58 )
      {
        if ( (debug_mdl & 1) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            4,
            "cam_cdm_process_cmd",
            783,
            "Clear cdm status bits for %s%u",
            v6 + 4,
            *((_DWORD *)v6 + 33));
          v57 = v12;
        }
        *((_QWORD *)v6 + 607) = 0;
      }
LABEL_130:
      mutex_unlock(v57);
      return 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      757,
      "Invalid client %pK hdl=%x",
      (const void *)v27,
      v26);
LABEL_83:
    mutex_unlock(v12);
    return (unsigned int)-22;
  }
  if ( a4 != 264 )
  {
    v36 = "Invalid CDM cmd %d arg size=%x";
    v37 = 637;
    v38 = 0;
    goto LABEL_101;
  }
  mutex_lock(a1);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_process_cmd",
      644,
      "Trying to acquire client=%s in hw idx=%d",
      (const char *)a3,
      *(_DWORD *)v6);
  v10 = a3[56];
  if ( v10 >= 4 )
  {
    mutex_unlock(a1);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      650,
      "Invalid priority requested %d",
      a3[56]);
    return (unsigned int)-22;
  }
  if ( *((_DWORD *)v6 + 33) && !*(_DWORD *)&v6[640 * v10 + 2404] )
  {
    mutex_unlock(a1);
    v38 = a3[56];
    v7 = *((unsigned int *)v6 + 33);
    v36 = "FIFO %d not supported for core %d";
    v37 = 661;
    goto LABEL_101;
  }
  free_client_slot = cam_cdm_find_free_client_slot((__int64)v6);
  if ( (free_client_slot & 0x80000000) != 0 )
  {
LABEL_64:
    mutex_unlock(a1);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_process_cmd",
      671,
      "Fail to client slots, client=%s in hw idx=%d",
      (const char *)a3,
      *(_DWORD *)v6);
    return (unsigned int)-22;
  }
  if ( free_client_slot > 0xFF )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v69 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_cdm_process_cmd__alloc_tag;
    v54 = _kvmalloc_node_noprof(336, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v69;
  }
  else
  {
    v4 = v6 + 248;
    if ( *(_QWORD *)&v6[8 * free_client_slot + 248] )
      goto LABEL_64;
    if ( mem_trace_en == 1 )
      v54 = cam_mem_trace_alloc(336, 0xCC0u, 0, "cam_cdm_process_cmd", 0x2A3u);
    else
      v54 = _kvmalloc_node_noprof(336, 0, 3520, 0xFFFFFFFFLL);
  }
  *(_QWORD *)&v4[2 * free_client_slot] = v54;
  if ( !v54 )
  {
    mutex_unlock(a1);
    return (unsigned int)-12;
  }
  ++v6[4876];
  mutex_unlock(a1);
  v59 = *(_DWORD **)&v4[2 * free_client_slot];
  _mutex_init(v59 + 70, "&client->lock", &cam_cdm_process_cmd___key);
  *((_QWORD *)a3 + 31) = *((_QWORD *)v6 + 30);
  if ( *((_DWORD *)v6 + 33) )
  {
    mutex_lock(a1);
    v60 = *((_QWORD *)v6 + 25);
    *(_QWORD *)(a3 + 59) = *((_QWORD *)v6 + 26);
    *(_QWORD *)(a3 + 57) = v60;
    mutex_unlock(a1);
    goto LABEL_126;
  }
  *(_QWORD *)(a3 + 57) = 1;
  *(_QWORD *)(a3 + 59) = 0;
  ops = cam_cdm_get_ops(0, a3 + 57, 1);
  *((_QWORD *)a3 + 31) = ops;
  if ( ops )
  {
LABEL_126:
    cam_cdm_get_client_refcount((__int64)v59);
    mutex_lock(v59 + 70);
    memcpy(v59, a3, 0x108u);
    v62 = a3[56];
    v63 = *(_DWORD *)v6;
    v59[68] = 0;
    v64 = ((v62 & 0xF) << 8) | ((v63 & 0xF) << 16);
    v65 = debug_mdl;
    v66 = v64 | free_client_slot;
    v59[82] = v66;
    a3[64] = v66;
    if ( (v65 & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_process_cmd",
        736,
        "Acquired client=%s in hwidx=%d",
        (const char *)a3,
        *(_DWORD *)v6);
    v57 = v59 + 70;
    goto LABEL_130;
  }
  mutex_lock(a1);
  v67 = *(_QWORD **)&v4[2 * free_client_slot];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v67, 0);
  else
    kvfree(v67);
  *(_QWORD *)&v4[2 * free_client_slot] = 0;
  --v6[4876];
  mutex_unlock(a1);
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_process_cmd",
    716,
    "Invalid ops for virtual cdm");
  return (unsigned int)-1;
}
