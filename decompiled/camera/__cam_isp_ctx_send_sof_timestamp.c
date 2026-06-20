__int64 __fastcall _cam_isp_ctx_send_sof_timestamp(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 *v6; // x23
  __int64 v7; // x9
  _DWORD *v8; // x24
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned int (*v11)(void); // x8
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 result; // x0
  unsigned __int64 v15; // x7
  unsigned __int64 v16; // x6
  _DWORD *v18; // x8
  unsigned int v19; // w10
  int v20; // w9
  _DWORD *v21; // x8
  unsigned __int64 v22; // x24
  int v23; // w9
  int v24; // w9
  unsigned __int64 v25; // x23
  _DWORD *v26; // x9
  unsigned __int64 v27; // x10
  int v28; // w8
  unsigned int v29; // w10
  unsigned int v30; // w8
  unsigned __int64 v31; // x25
  __int64 v32; // x8
  unsigned __int64 *v33; // t2
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v42; // x8
  __int64 v43; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v44; // [xsp+60h] [xbp-A0h]
  __int64 v45; // [xsp+68h] [xbp-98h]
  unsigned __int64 v46; // [xsp+70h] [xbp-90h]
  unsigned __int64 v47; // [xsp+78h] [xbp-88h]
  __int64 v48; // [xsp+80h] [xbp-80h]
  __int64 v49; // [xsp+88h] [xbp-78h]
  __int64 v50; // [xsp+90h] [xbp-70h]
  __int64 v51; // [xsp+98h] [xbp-68h] BYREF
  __int64 v52; // [xsp+A0h] [xbp-60h]
  __int64 v53; // [xsp+A8h] [xbp-58h]
  unsigned __int64 v54; // [xsp+B0h] [xbp-50h]
  unsigned __int64 v55; // [xsp+B8h] [xbp-48h]
  unsigned __int64 v56; // [xsp+C0h] [xbp-40h]
  __int64 v57; // [xsp+C8h] [xbp-38h]
  __int64 v58; // [xsp+D0h] [xbp-30h]
  __int64 v59; // [xsp+D8h] [xbp-28h]
  __int64 v60; // [xsp+E0h] [xbp-20h]
  __int64 v61; // [xsp+E8h] [xbp-18h]
  __int64 v62; // [xsp+F0h] [xbp-10h]
  __int64 v63; // [xsp+F8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (unsigned __int64 *)(a1 + 37304);
  v8 = *(_DWORD **)a1;
  v7 = *(_QWORD *)(a1 + 8);
  v9 = *(_QWORD *)(a1 + 37336);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  if ( v9 == v7 || *(_QWORD *)(a1 + 37368) >= *v6 )
  {
    v10 = *((_QWORD *)v8 + 26);
    v61 = 0;
    v62 = 0;
    v11 = *(unsigned int (**)(void))(v10 + 96);
    v59 = 0;
    v60 = 0;
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    v51 = 8;
    v52 = 0;
    if ( *((_DWORD *)v11 - 1) != 1863972096 )
      __break(0x8228u);
    if ( !v11() )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_get_hw_timestamp",
        1584,
        "ctx:%u link:0x%x prev timestamp greater than curr timestamp",
        v8[8],
        v8[16]);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_recover_sof_timestamp",
      1637,
      "ctx:%u link: 0x%x Failed to get timestamp from HW",
      v8[8],
      v8[16]);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_send_sof_timestamp",
      1795,
      "Missed SOF.No SOF timestamp recovery,ctx:%u,link:0x%x",
      v8[8],
      v8[16]);
  }
  v12 = *(_QWORD *)(a1 + 8);
  if ( a2 || v6[4] != v12 )
  {
    v15 = v6[8];
    v16 = *v6;
    v6[4] = v12;
    if ( v15 >= v16 )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "__cam_isp_ctx_send_sof_timestamp",
                 1812,
                 "SOF timestamp recovery fail, current timestamp:0x%llx, last timestamp:0x%llx, ctx:%u, link:0x%x",
                 v16,
                 v15,
                 v8[8],
                 v8[16]);
      goto LABEL_43;
    }
    _X25 = (unsigned __int64 *)(a1 + 42152);
    if ( (*(_BYTE *)(a1 + 45616) & 0x20) != 0 && (*(_BYTE *)(a1 + 45744) & 1) == 0 )
    {
      v26 = *(_DWORD **)a1;
      v57 = 0;
      v58 = 0;
      if ( a2 )
        v27 = v16;
      else
        v27 = 0;
      v51 = 0;
      v52 = a2;
      v22 = v6[1];
      v28 = v26[14];
      v53 = v12;
      v54 = v27;
      v29 = *(_DWORD *)(a1 + 16);
      v55 = v22;
      v56 = 0;
      LODWORD(v51) = v28;
      v30 = v26[16];
      v56 = __PAIR64__(v29, v30);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_send_unified_timestamp",
          1732,
          "link_hdl: 0x%x, request_id: %lld, frame number: %lld, ctx: %d, SOF qtimer timestamp: [%llu:%09llu], boot times"
          "tamp: [%llu:%09llu]",
          v30,
          a2,
          v12,
          v26[8],
          v16 / 0x3B9ACA00,
          v16 % 0x3B9ACA00,
          v22 / 0x3B9ACA00,
          v22 % 0x3B9ACA00);
        v33 = v6;
        v25 = *v6;
        v22 = v33[1];
        v12 = *(_QWORD *)(a1 + 8);
      }
      else
      {
        v25 = v16;
      }
      if ( (unsigned int)cam_req_mgr_notify_message(&v51, 5, 0x8000000) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_send_unified_timestamp",
          1742,
          "Error in notifying the sof and boot time for req id:%lld",
          a2);
      if ( a1 )
      {
        __asm { PRFM            #0x11, [X25] }
        do
        {
          v42 = __ldxr(_X25);
          v40 = v42 + 1;
        }
        while ( __stlxr(v40, _X25) );
        goto LABEL_46;
      }
    }
    else
    {
      if ( a2 && (*(_BYTE *)(a1 + 45744) & 1) == 0 )
      {
        v18 = *(_DWORD **)a1;
        v44 = a2;
        v45 = v12;
        v46 = v16;
        v19 = v18[16];
        LODWORD(v43) = v18[14];
        v20 = *(_DWORD *)(a1 + 16);
        v47 = __PAIR64__(a3, v19);
        LODWORD(v48) = v20;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_send_sof_timestamp",
            1836,
            "request id:%lld frame number:%lld SOF time stamp:0x%llx status:%u ctx_idx: %u, link: 0x%x",
            a2,
            v12,
            v16,
            a3,
            v8[8],
            v8[16]);
        if ( (unsigned int)cam_req_mgr_notify_message(&v43, 0, 0x8000000) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_send_sof_timestamp",
            1842,
            "Error in notifying the sof time for req id:%lld, ctx_idx: %u, link: 0x%x",
            a2,
            v8[8],
            v8[16]);
      }
      v21 = *(_DWORD **)a1;
      v12 = *(_QWORD *)(a1 + 8);
      v57 = 0;
      v58 = 0;
      v51 = 0;
      v52 = a2;
      v22 = v6[1];
      v55 = 0;
      v56 = 0;
      v23 = v21[14];
      v53 = v12;
      v54 = v22;
      LODWORD(v51) = v23;
      v24 = *(_DWORD *)(a1 + 16);
      HIDWORD(v55) = a3;
      LODWORD(v56) = v24;
      LODWORD(v55) = v21[16];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_send_sof_boot_timestamp",
          1693,
          "request id:%lld frame number:%lld boot time stamp:0x%llx status:%u",
          a2,
          v12,
          v22,
          a3);
        v12 = *(_QWORD *)(a1 + 8);
        v22 = v6[1];
      }
      v25 = *v6;
      if ( (unsigned int)cam_req_mgr_notify_message(&v51, 2, 0x8000000) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_send_sof_boot_timestamp",
          1704,
          "Error in notifying the boot time for req id:%lld",
          a2);
      if ( a1 )
      {
        __asm { PRFM            #0x11, [X25] }
        do
        {
          v39 = __ldxr(_X25);
          v40 = v39 + 1;
        }
        while ( __stlxr(v40, _X25) );
LABEL_46:
        __dmb(0xBu);
        v31 = v40 & 7;
        result = ktime_get_with_offset(1);
        v32 = a1 + (v31 << 6) + 44720;
        *(_DWORD *)(v32 + 16) = 5;
        *(_QWORD *)v32 = a2;
        *(_QWORD *)(v32 + 8) = result;
        *(_DWORD *)(v32 + 40) = a3;
        *(_QWORD *)(v32 + 24) = v12;
        *(_QWORD *)(v32 + 32) = a2;
        *(_QWORD *)(v32 + 48) = v22;
        *(_QWORD *)(v32 + 56) = v25;
        goto LABEL_43;
      }
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               8,
               1,
               "__cam_isp_ctx_update_event_record",
               98,
               "Invalid Args");
    goto LABEL_43;
  }
  if ( (unsigned int)__ratelimit(&_cam_isp_ctx_send_sof_timestamp__rs, "__cam_isp_ctx_send_sof_timestamp") )
    v13 = 3;
  else
    v13 = 2;
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             v13,
             8,
             2,
             "__cam_isp_ctx_send_sof_timestamp",
             1801,
             "Missed SOF Recovery for invalid req, Skip notificaiton to userspace Ctx: %u link: 0x%x frame_id %u",
             v8[8],
             v8[16],
             *(_QWORD *)(a1 + 8));
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
