__int64 __fastcall _cam_isp_ctx_start_dev_in_ready(_DWORD *a1, int *a2)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 *v6; // x20
  __int64 v7; // x25
  __int64 v8; // x6
  __int64 v9; // x21
  _DWORD *v10; // x22
  int v11; // w10
  __int64 v12; // x26
  int v13; // w9
  char v14; // w9
  int v15; // w9
  __int64 result; // x0
  __int64 v17; // x6
  __int64 v18; // x7
  const char *v19; // x5
  __int64 v20; // x4
  __int64 **v21; // x8
  __int64 v22; // x9
  int v23; // w8
  __int64 v24; // x7
  __int64 v25; // x2
  __int64 *v26; // x1
  __int64 *v27; // x8
  __int64 (__fastcall *v28)(__int64, __int64 *); // x9
  __int64 v29; // x0
  unsigned int v30; // w23
  __int64 *v31; // x8
  __int64 v32; // x9
  __int64 *v33; // x2
  unsigned int v34; // w9
  __int64 v35; // x27
  unsigned int v36; // w9
  __int64 v37; // x27
  __int64 v38; // [xsp+20h] [xbp-50h] BYREF
  __int64 v39; // [xsp+28h] [xbp-48h]
  __int64 v40; // [xsp+30h] [xbp-40h]
  __int64 v41; // [xsp+38h] [xbp-38h]
  __int64 v42; // [xsp+40h] [xbp-30h]
  __int64 v43; // [xsp+48h] [xbp-28h]
  __int64 v44; // [xsp+50h] [xbp-20h]
  __int64 v45; // [xsp+58h] [xbp-18h]
  __int64 v46; // [xsp+60h] [xbp-10h]
  __int64 v47; // [xsp+68h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v3 = a1[14];
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  if ( v2 != v3 || a2[1] != a1[15] )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_21;
  }
  v4 = *((_QWORD *)a1 + 32);
  v5 = (__int64)(a1 + 36);
  v6 = *((__int64 **)a1 + 18);
  if ( v6 == (__int64 *)(a1 + 36) )
  {
    v17 = (unsigned int)a1[8];
    v18 = (unsigned int)a1[16];
    v19 = "Start device with empty configuration, ctx: %u, link: 0x%x";
    v20 = 9440;
LABEL_24:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_start_dev_in_ready",
      v20,
      v19,
      v17,
      v18);
    result = 4294967282LL;
    goto LABEL_21;
  }
  v7 = v4 + 37296;
  if ( !*(_QWORD *)(v4 + 37296) )
  {
    v17 = (unsigned int)a1[8];
    v18 = (unsigned int)a1[16];
    v19 = "Wrong hw context pointer.ctx_idx: %u, link: 0x%x";
    v20 = 9451;
    goto LABEL_24;
  }
  v8 = v6[3];
  v9 = v6[4];
  v38 = *(_QWORD *)(v4 + 37296);
  v10 = a1;
  v44 = v8;
  v40 = *(_QWORD *)(v9 + 8);
  v11 = *(_DWORD *)(v9 + 16);
  BYTE4(v45) = 1;
  LODWORD(v45) = 0;
  v12 = v4 + 42112;
  v13 = *(_DWORD *)(v9 + 48);
  LODWORD(v39) = v11;
  v43 = v9 + 80;
  if ( v13 || *(_DWORD *)(v9 + 32) )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v35 = v4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_start_dev_in_ready",
        9471,
        "IO buffers are detected in INIT packet during start dev, need to program AUP during CSID start, req_id: %lld, ct"
        "x_idx: %u, link: 0x%x",
        v8,
        a1[8],
        a1[16]);
      v4 = v35;
      a1 = v10;
    }
    BYTE2(v46) = 1;
  }
  if ( (*(_BYTE *)(v12 + 3626) & 1) == 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v37 = v4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_start_dev_in_ready",
        9482,
        "VFPS is not set, thus enabling dynamic EOF, ctx_idx: %u, link: 0x%x",
        a1[8],
        a1[16]);
      v4 = v37;
      a1 = v10;
    }
    BYTE3(v46) = 1;
  }
  *(_QWORD *)(v7 + 56) = v6[3];
  if ( a1[60] == 4 )
    BYTE1(v46) = 1;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v12 + 3472) = 0;
  *(_DWORD *)(v12 + 3460) = 0;
  *(_QWORD *)(v4 + 37304) = 0;
  *(_QWORD *)(v4 + 37312) = 0;
  *(_DWORD *)(v4 + 37320) = 0;
  *(_QWORD *)(v4 + 37328) = 0;
  *(_QWORD *)(v4 + 37336) = 0;
  *(_QWORD *)(v4 + 37376) = 0;
  *(_QWORD *)(v4 + 37384) = 0;
  v14 = *(_BYTE *)(v12 + 3624);
  *(_QWORD *)(v4 + 8) = 0;
  *(_QWORD *)(v7 + 64) = 0;
  *(_BYTE *)(v12 + 3634) = 0;
  *(_DWORD *)(v12 + 3588) = 0;
  *(_BYTE *)(v12 + 3641) = 0;
  *(_QWORD *)(v4 + 45656) = 0;
  *(_QWORD *)(v4 + 45664) = 0;
  if ( (v14 & 1) != 0 )
    v15 = 1;
  else
    v15 = 2 * (*(_DWORD *)(v9 + 32) != 0);
  *(_DWORD *)(v4 + 20) = v15;
  *(_QWORD *)(v7 + 104) = -1;
  *(_QWORD *)(v12 + 3120) = -1;
  *(_QWORD *)v12 = -1;
  *(_QWORD *)(v12 + 8) = -1;
  *(_QWORD *)(v12 + 16) = -1;
  *(_QWORD *)(v12 + 24) = -1;
  *(_QWORD *)(v12 + 32) = -1;
  *(_QWORD *)(v12 + 40) = -1;
  v21 = (__int64 **)v6[1];
  if ( *v21 == v6 && (v22 = *v6, *(__int64 **)(*v6 + 8) == v6) )
  {
    *(_QWORD *)(v22 + 8) = v21;
    *v21 = (__int64 *)v22;
  }
  else
  {
    _list_del_entry_valid_or_report(v6);
    a1 = v10;
  }
  *v6 = (__int64)v6;
  v6[1] = (__int64)v6;
  if ( *(_BYTE *)(v12 + 3625) == 1 && !*(_DWORD *)(v9 + 32) )
  {
    cam_smmu_buffer_tracker_putref((unsigned int *)v6 + 28);
    _cam_isp_ctx_move_req_to_free_list((__int64)v10, v6);
    a1 = v10;
    *(_DWORD *)(v12 + 3472) = 1;
    if ( (debug_mdl & 0x1000008) == 0 || debug_priority )
      goto LABEL_47;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "__cam_isp_ctx_start_dev_in_ready",
      9519,
      "Move pending req: %lld to free list(cnt: %d) offline ctx %u link: 0x%x",
      v6[3],
      *(unsigned int *)(v7 + 24),
      v10[8],
      v10[16]);
  }
  else if ( (*(_BYTE *)(v12 + 3624) & 1) != 0 || !*(_DWORD *)(v9 + 32) )
  {
    v25 = (__int64)(a1 + 40);
    v26 = *((__int64 **)a1 + 21);
    if ( v6 == (__int64 *)(a1 + 40) || v6 == v26 || *v26 != v25 )
    {
      _list_add_valid_or_report(v6);
      a1 = v10;
    }
    else
    {
      *((_QWORD *)a1 + 21) = v6;
      *v6 = v25;
      v6[1] = (__int64)v26;
      *v26 = (__int64)v6;
    }
    if ( (debug_mdl & 0x1000008) == 0 || debug_priority )
      goto LABEL_47;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "__cam_isp_ctx_start_dev_in_ready",
      9524,
      "Move pending req: %lld to wait list(cnt: %d) ctx %u link: 0x%x",
      v6[3],
      *(unsigned int *)(v7 + 24),
      a1[8],
      a1[16]);
  }
  else
  {
    _list_add(v6, *((_QWORD **)a1 + 17), (__int64)(a1 + 32));
    v23 = *(_DWORD *)(v12 + 3644);
    v24 = (unsigned int)(*(_DWORD *)(v7 + 24) + 1);
    *(_DWORD *)(v7 + 24) = v24;
    if ( v23 )
      *(_DWORD *)(v12 + 3644) = v23 - 1;
    a1 = v10;
    if ( (debug_mdl & 0x1000008) == 0 || debug_priority )
      goto LABEL_47;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _DWORD, _DWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "__cam_isp_ctx_start_dev_in_ready",
      9534,
      "Move pending req: %lld to active list(cnt: %d) ctx %u link: 0x%x offline %d",
      v6[3],
      v24,
      v10[8],
      v10[16],
      *(unsigned __int8 *)(v12 + 3625));
  }
  a1 = v10;
LABEL_47:
  a1[60] = 5;
  v27 = *((__int64 **)a1 + 26);
  v28 = (__int64 (__fastcall *)(__int64, __int64 *))v27[5];
  v29 = *v27;
  if ( *((_DWORD *)v28 - 1) != 1863972096 )
    __break(0x8229u);
  result = v28(v29, &v38);
  if ( (_DWORD)result )
  {
    v30 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_start_dev_in_ready",
      9548,
      "Start HW failed, ctx %u link: 0x%x",
      v10[8],
      v10[16]);
    result = v30;
    v10[60] = 3;
    if ( v30 == -110 && byte_3A8B90 )
      result = cam_isp_ctx_dump_req(v9);
    v31 = (__int64 *)v6[1];
    if ( (__int64 *)*v31 == v6 && (v32 = *v6, *(__int64 **)(*v6 + 8) == v6) )
    {
      *(_QWORD *)(v32 + 8) = v31;
      *v31 = v32;
    }
    else
    {
      _list_del_entry_valid_or_report(v6);
      result = v34;
    }
    *v6 = (__int64)v6;
    v6[1] = (__int64)v6;
    v33 = *(__int64 **)v5;
    if ( *(_QWORD *)(*(_QWORD *)v5 + 8LL) != v5 || v6 == v33 )
    {
      _list_add_valid_or_report(v6);
      result = v36;
    }
    else
    {
      v33[1] = (__int64)v6;
      *v6 = (__int64)v33;
      v6[1] = v5;
      *(_QWORD *)v5 = v6;
    }
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_start_dev_in_ready",
      9559,
      "start device success ctx %u link: 0x%x",
      v10[8],
      v10[16]);
    result = 0;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
