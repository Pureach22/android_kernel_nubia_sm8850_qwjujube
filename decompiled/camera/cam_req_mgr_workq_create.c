__int64 __fastcall cam_req_mgr_workq_create(
        const char *a1,
        unsigned int a2,
        __int64 *a3,
        int a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned int v14; // w22
  size_t v15; // x0
  size_t v16; // x23
  size_t v17; // x0
  __int64 v18; // x9
  bool v19; // cf
  size_t v20; // x2
  char *v21; // x0
  __int64 v22; // x23
  __int64 v23; // x0
  size_t v24; // x0
  unsigned __int64 v25; // x2
  char v26; // w8
  int v27; // w8
  __int64 v28; // x0
  __int64 v29; // x8
  unsigned int v30; // w20
  _QWORD *v31; // x0
  size_t v32; // x2
  unsigned __int64 StatusReg; // x22
  __int64 v34; // x23
  char string[12]; // [xsp+18h] [xbp-88h] BYREF
  int v38; // [xsp+24h] [xbp-7Ch]
  __int64 v39; // [xsp+28h] [xbp-78h]
  __int64 v40; // [xsp+30h] [xbp-70h]
  __int64 v41; // [xsp+38h] [xbp-68h]
  __int64 v42; // [xsp+40h] [xbp-60h]
  __int64 v43; // [xsp+48h] [xbp-58h]
  __int64 v44; // [xsp+50h] [xbp-50h]
  __int64 v45; // [xsp+58h] [xbp-48h]
  __int64 v46; // [xsp+60h] [xbp-40h]
  __int64 v47; // [xsp+68h] [xbp-38h]
  __int64 v48; // [xsp+70h] [xbp-30h]
  __int64 v49; // [xsp+78h] [xbp-28h]
  __int64 v50; // [xsp+80h] [xbp-20h]
  __int64 v51; // [xsp+88h] [xbp-18h]
  __int64 v52; // [xsp+90h] [xbp-10h]
  __int64 v53; // [xsp+98h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  strcpy(string, "crm_workq-");
  string[11] = 0;
  v38 = 0;
  v6 = *a3;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  if ( v6 )
  {
LABEL_2:
    result = 0;
    goto LABEL_46;
  }
  if ( mem_trace_en == 1 )
    v12 = cam_mem_trace_alloc(312, 0xCC0u, 0, "cam_req_mgr_workq_create", 0xD2u);
  else
    v12 = _kvmalloc_node_noprof(312, 0, 3520, 0xFFFFFFFFLL);
  v13 = v12;
  if ( !v12 )
  {
LABEL_45:
    result = 4294967284LL;
    goto LABEL_46;
  }
  while ( 1 )
  {
    v14 = (a5 & 1) != 0 ? 18 : 2;
    v15 = strnlen(string, 0x80u);
    v16 = v15;
    if ( v15 < 0x81 )
      break;
    v32 = v15 + 1;
LABEL_49:
    _fortify_panic(2, 128, v32);
LABEL_50:
    _fortify_panic(7, 128, v25);
    StatusReg = _ReadStatusReg(SP_EL0);
    v34 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_req_mgr_workq_create__alloc_tag;
    v13 = _kvmalloc_node_noprof(312, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v34;
    if ( !v13 )
      goto LABEL_45;
  }
  a5 = (a5 >> 1) & 1;
  if ( v15 != 128 )
  {
    v17 = strlen(a1);
    v18 = v17 + v16;
    v19 = v17 + v16 >= 0x80;
    if ( v17 + v16 >= 0x80 )
      v20 = 127 - v16;
    else
      v20 = v17;
    v21 = &string[v16];
    if ( v19 )
      v22 = 127;
    else
      v22 = v18;
    memcpy(v21, a1, v20);
    string[v22] = 0;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_workq_create",
      222,
      "create workque crm_workq-%s",
      a1);
  v23 = alloc_workqueue(string, v14, a5, 0);
  *(_QWORD *)(v13 + 32) = v23;
  if ( !v23 )
    goto LABEL_42;
  v24 = strnlen(string, 0x80u);
  if ( v24 >= 0x81 )
  {
    v32 = v24 + 1;
    goto LABEL_49;
  }
  if ( v24 == 128 )
    v25 = 128;
  else
    v25 = v24 + 1;
  if ( v25 >= 0x81 )
    goto LABEL_50;
  sized_strscpy(v13 + 60, string);
  *(_QWORD *)v13 = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v13 + 8) = v13 + 8;
  *(_QWORD *)(v13 + 16) = v13 + 8;
  v26 = debug_mdl;
  *(_QWORD *)(v13 + 24) = a6;
  *(_DWORD *)(v13 + 40) = 0;
  if ( (v26 & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v26 & 0x10,
      4,
      "cam_req_mgr_workq_create",
      235,
      "LOCK_DBG workq %s lock %pK",
      a1,
      (const void *)(v13 + 40));
  *(_DWORD *)(v13 + 240) = 0;
  *(_DWORD *)(v13 + 244) = 0;
  *(_QWORD *)(v13 + 248) = v13 + 248;
  *(_QWORD *)(v13 + 256) = v13 + 248;
  *(_QWORD *)(v13 + 264) = v13 + 264;
  *(_QWORD *)(v13 + 272) = v13 + 264;
  *(_QWORD *)(v13 + 280) = v13 + 280;
  *(_QWORD *)(v13 + 288) = v13 + 280;
  *(_DWORD *)(v13 + 56) = 0;
  v27 = (unsigned __int8)mem_trace_en;
  *(_DWORD *)(v13 + 44) = a4;
  *(_DWORD *)(v13 + 304) = a2;
  if ( v27 == 1 )
    v28 = cam_mem_trace_alloc(72LL * a2, 0xCC0u, 0, "cam_req_mgr_workq_create", 0xF7u);
  else
    v28 = _kvmalloc_node_noprof(72LL * *(unsigned int *)(v13 + 304), 0, 3520, 0xFFFFFFFFLL);
  v29 = *(unsigned int *)(v13 + 304);
  *(_QWORD *)(v13 + 296) = v28;
  if ( !v28 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "cam_req_mgr_workq_create",
      251,
      "Insufficient memory %zu",
      72 * v29);
LABEL_42:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v13, 0);
    else
      kvfree(v13);
    goto LABEL_45;
  }
  if ( (_DWORD)v29 )
  {
    v30 = 0;
    do
    {
      v31 = (_QWORD *)(*(_QWORD *)(v13 + 296) + 72LL * (int)v30);
      v31[3] = v13;
      v31[4] = v31 + 4;
      v31[5] = v31 + 4;
      cam_req_mgr_workq_put_task((__int64)v31);
      ++v30;
    }
    while ( v30 < *(_DWORD *)(v13 + 304) );
  }
  result = 0;
  *a3 = v13;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_workq_create",
      265,
      "free tasks %d",
      *(_DWORD *)(v13 + 244));
    goto LABEL_2;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
