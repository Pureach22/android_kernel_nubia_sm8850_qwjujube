__int64 __fastcall _cam_req_mgr_check_sync_for_mslave(unsigned int *slot_for_req, _DWORD *a2, __int64 a3)
{
  int *v3; // x9
  __int64 v4; // x19
  int v5; // w24
  unsigned int v6; // w25
  _DWORD *v7; // x20
  _BYTE *v8; // x21
  __int64 result; // x0
  unsigned int *v10; // x10
  int v11; // w11
  __int64 v12; // x7
  const char *v13; // x5
  __int64 v14; // x1
  __int64 v15; // x4
  __int64 v16; // x6
  unsigned int *v17; // x27
  unsigned int *v18; // x26
  __int64 v19; // x7
  const char *v20; // x5
  __int64 v21; // x1
  unsigned int v22; // w20
  __int64 v23; // x4
  unsigned int *v24; // x26
  _DWORD *v25; // x27
  unsigned int *v26; // x25
  unsigned int *v27; // x8
  unsigned int v28; // w11
  unsigned int v29; // w10
  __int64 v30; // x11
  unsigned int *v31; // x8
  __int64 v32; // x20
  unsigned int v33; // w1
  __int64 v34; // x8
  __int64 v35; // x28
  _DWORD *v36; // x28
  int v37; // t1
  __int64 v38; // x7
  const char *v39; // x5
  __int64 v40; // x1
  unsigned int v41; // w19
  __int64 v42; // x4
  unsigned int v43; // w10
  __int64 v44; // x11
  int *v45; // x0
  unsigned int v46; // w28
  signed int v47; // w1
  int v48; // w27
  __int64 v49; // x8
  __int64 v50; // x7
  const char *v51; // x5
  __int64 v52; // x1
  __int64 v53; // x4
  _DWORD *v54; // x26
  unsigned int *v55; // x27
  __int64 v56; // x28
  int v57; // [xsp+0h] [xbp-40h]
  __int64 v58; // [xsp+8h] [xbp-38h]
  unsigned int v59; // [xsp+28h] [xbp-18h]
  _QWORD v60[2]; // [xsp+30h] [xbp-10h] BYREF

  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60[0] = 0;
  if ( !slot_for_req || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_check_sync_for_mslave",
      1692,
      "Sync link or link is null");
    result = 4294967274LL;
LABEL_37:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v3 = *((int **)a2 + 6);
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_check_sync_for_mslave",
      1700,
      "Link hdl %x in_q is NULL",
      *a2);
    result = 4294967274LL;
    goto LABEL_37;
  }
  v4 = *(_QWORD *)(a3 + 16);
  v5 = *v3;
  v6 = v3[866];
  v7 = a2 + 0x2000;
  v8 = slot_for_req + 0x2000;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v54 = a2;
    v55 = slot_for_req;
    v56 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_check_sync_for_mslave",
      1711,
      "link_hdl %x req %lld frame_skip_flag %d open_req_cnt:%u initial_sync_req [%lld,%lld] is_master:%d",
      *slot_for_req,
      v4,
      *((unsigned __int8 *)slot_for_req + 33252),
      slot_for_req[8314],
      *((_QWORD *)slot_for_req + 4160),
      *((_QWORD *)a2 + 4160),
      *((unsigned __int8 *)slot_for_req + 33276));
    a3 = v56;
    slot_for_req = v55;
    a2 = v54;
  }
  if ( *((_BYTE *)v7 + 484) == 1 )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_check_sync_for_mslave",
        1716,
        "No req applied on corresponding SOF on sync link: %x",
        *a2);
    *((_BYTE *)v7 + 484) = 0;
    result = 4294967285LL;
    goto LABEL_37;
  }
  if ( v8[510] == 1 && *((_BYTE *)v7 + 510) == 1 )
  {
    if ( v6 >= 0x30 )
      goto LABEL_87;
    if ( v4 - *(_QWORD *)(*((_QWORD *)a2 + 6) + 72LL * v6 + 24) > slot_for_req[2] - a2[2] )
    {
      v10 = slot_for_req;
      result = 4294967274LL;
      if ( (debug_mdl & 0x10) == 0 || debug_priority )
        goto LABEL_37;
      v11 = *a2;
      v12 = *v10;
      v13 = "Req: %lld on link:%x need to hold for link: %x req:%d";
      v58 = *(_QWORD *)(*((_QWORD *)a2 + 6) + 72LL * v6 + 24);
      v14 = debug_mdl & 0x10;
      v15 = 1730;
      v16 = v4;
      v57 = v11;
      goto LABEL_21;
    }
  }
  if ( v8[508] != 1 )
  {
    v17 = a2;
    if ( v8[509] == 1 )
      v8[509] = 0;
    v18 = slot_for_req;
    result = _cam_req_mgr_check_link_is_ready(slot_for_req, *(_DWORD *)a3, 1);
    if ( (_DWORD)result )
    {
      if ( (debug_mdl & 0x10) == 0 || debug_priority )
        goto LABEL_36;
      v19 = *v18;
      v20 = "Req: %lld [slave] not ready on link: %x, rc=%d";
      v21 = debug_mdl & 0x10;
      v22 = result;
      v23 = 1802;
LABEL_84:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
        3,
        v21,
        4,
        "__cam_req_mgr_check_sync_for_mslave",
        v23,
        v20,
        v4,
        v19,
        v22);
      result = v22;
      goto LABEL_36;
    }
    v27 = *((unsigned int **)v18 + 6);
    v28 = v18[2];
    v29 = *(_DWORD *)(*((_QWORD *)v17 + 6) + 3464LL);
    LODWORD(v60[0]) = v27[866];
    v59 = v29;
    slot_for_req = (unsigned int *)cam_common_inc_idx(v60, v17[2] - v28, *v27);
    if ( LODWORD(v60[0]) > 0x2F )
      goto LABEL_87;
    v30 = *((_QWORD *)v7 + 64);
    v31 = v18;
    if ( v30 != -1 )
    {
      v32 = *(_QWORD *)(*((_QWORD *)v18 + 6) + 72LL * LODWORD(v60[0]) + 24);
      if ( v30 <= v32 )
      {
        slot_for_req = (unsigned int *)_cam_req_mgr_find_slot_for_req(
                                         *((int **)v17 + 6),
                                         *(_QWORD *)(*((_QWORD *)v18 + 6) + 72LL * LODWORD(v60[0]) + 24));
        if ( (_DWORD)slot_for_req == -1 )
        {
          if ( (debug_mdl & 0x10) == 0 || debug_priority )
            goto LABEL_71;
          v50 = *v17;
          v51 = "Next Req: %lld [slave] not found on link: %x [master]";
          v52 = debug_mdl & 0x10;
          v53 = 1822;
          goto LABEL_86;
        }
        v33 = (unsigned int)slot_for_req;
        if ( (unsigned int)slot_for_req > 0x2F )
          goto LABEL_87;
        slot_for_req = v17;
        v34 = *((_QWORD *)v17 + 6) + 8LL;
        v35 = v34 + 72LL * v33;
        v37 = *(_DWORD *)(v35 + 8);
        v36 = (_DWORD *)(v35 + 8);
        if ( v37 != 4 && (int)(v5 - v59 + v33) % v5 >= 1 )
        {
          if ( v59 > 0x2F )
            goto LABEL_87;
          if ( *(_DWORD *)(v34 + 72LL * v59 + 8) != 4 )
          {
            result = 4294967274LL;
            if ( (debug_mdl & 0x10) == 0 || debug_priority )
              goto LABEL_37;
            v12 = *v17;
            v13 = "Next Req: %lld [slave] not next on link: %x [master]";
            v14 = debug_mdl & 0x10;
            v15 = 1835;
            goto LABEL_82;
          }
        }
        result = _cam_req_mgr_check_link_is_ready(v17, v33, 1);
        v31 = v18;
        if ( (_DWORD)result && *v36 != 4 )
        {
          if ( (debug_mdl & 0x10) == 0 || debug_priority )
            goto LABEL_36;
          v38 = *v17;
          v39 = "Next Req: %lld [slave] not ready on [master] link: %x, rc=%d";
          v40 = debug_mdl & 0x10;
          v41 = result;
          v42 = 1846;
LABEL_78:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
            3,
            v40,
            4,
            "__cam_req_mgr_check_sync_for_mslave",
            v42,
            v39,
            v32,
            v38,
            v41);
          result = v41;
          goto LABEL_36;
        }
      }
    }
LABEL_63:
    result = 0;
    if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000010,
        4,
        "__cam_req_mgr_check_sync_for_mslave",
        1855,
        "Req: %lld ready to apply on link: %x [validation successful]",
        v4,
        *v31);
      result = 0;
    }
    goto LABEL_37;
  }
  if ( *((_BYTE *)v7 + 509) == 1 )
  {
    result = 4294967285LL;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_check_sync_for_mslave",
        1737,
        "Link 0x%x [slave] not streamed on",
        *a2);
      result = 4294967285LL;
    }
    goto LABEL_37;
  }
  v24 = a2;
  v25 = (_DWORD *)a3;
  v26 = slot_for_req;
  result = _cam_req_mgr_check_link_is_ready(slot_for_req, *(_DWORD *)a3, 1);
  if ( (_DWORD)result )
  {
    if ( (debug_mdl & 0x10) == 0 || debug_priority )
      goto LABEL_36;
    v19 = *v26;
    v20 = "Req: %lld [master] not ready on link: %x, rc=%d";
    v21 = debug_mdl & 0x10;
    v22 = result;
    v23 = 1745;
    goto LABEL_84;
  }
  v43 = v24[2];
  HIDWORD(v60[0]) = *v25;
  slot_for_req = (unsigned int *)cam_common_dec_idx((char *)v60 + 4, v26[2] - v43);
  if ( HIDWORD(v60[0]) > 0x2F )
    goto LABEL_87;
  v44 = *((_QWORD *)v7 + 64);
  v31 = v26;
  if ( v44 == -1 )
    goto LABEL_63;
  v32 = *(_QWORD *)(*((_QWORD *)v26 + 6) + 72LL * HIDWORD(v60[0]) + 24);
  if ( v44 > v32 )
    goto LABEL_63;
  v45 = *((int **)v24 + 6);
  v46 = v45[866];
  slot_for_req = (unsigned int *)_cam_req_mgr_find_slot_for_req(
                                   v45,
                                   *(_QWORD *)(*((_QWORD *)v26 + 6) + 72LL * HIDWORD(v60[0]) + 24));
  if ( (_DWORD)slot_for_req == -1 )
  {
    if ( (debug_mdl & 0x10) == 0 || debug_priority )
      goto LABEL_71;
    v50 = *v24;
    v51 = "Prev Req: %lld [master] not found on link: %x [slave]";
    v52 = debug_mdl & 0x10;
    v53 = 1764;
LABEL_86:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      v52,
      4,
      "__cam_req_mgr_check_sync_for_mslave",
      v53,
      v51,
      v32,
      v50);
LABEL_71:
    result = 4294967274LL;
LABEL_36:
    v8[484] = 1;
    goto LABEL_37;
  }
  v47 = (int)slot_for_req;
  if ( (unsigned int)slot_for_req <= 0x2F )
  {
    v48 = (int)slot_for_req;
    slot_for_req = v24;
    v49 = *((_QWORD *)v24 + 6) + 8LL;
    if ( *(_DWORD *)(v49 + 72LL * v47 + 8) == 4 || (int)(v5 - v46 + v47) % v5 < 1 )
      goto LABEL_61;
    if ( v46 <= 0x2F )
    {
      if ( *(_DWORD *)(v49 + 72LL * v46 + 8) == 4 )
      {
LABEL_61:
        result = _cam_req_mgr_check_link_is_ready(v24, v47, 1);
        v31 = v26;
        if ( !(_DWORD)result || *(_DWORD *)(*((_QWORD *)v24 + 6) + 72LL * v48 + 16) == 4 )
          goto LABEL_63;
        if ( (debug_mdl & 0x10) == 0 || debug_priority )
          goto LABEL_36;
        v38 = *v24;
        v39 = "Req: %lld not ready on [slave] link: %x, rc=%d";
        v40 = debug_mdl & 0x10;
        v41 = result;
        v42 = 1789;
        goto LABEL_78;
      }
      result = 4294967274LL;
      if ( (debug_mdl & 0x10) == 0 || debug_priority )
        goto LABEL_37;
      v12 = *v24;
      v13 = "Prev Req: %lld [master] not next on link: %x [slave]";
      v14 = debug_mdl & 0x10;
      v15 = 1778;
LABEL_82:
      v16 = v32;
LABEL_21:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, __int64))cam_print_log)(
        3,
        v14,
        4,
        "__cam_req_mgr_check_sync_for_mslave",
        v15,
        v13,
        v16,
        v12,
        v57,
        v58);
      result = 4294967274LL;
      goto LABEL_37;
    }
  }
LABEL_87:
  __break(0x5512u);
  return _cam_req_mgr_traverse(slot_for_req);
}
