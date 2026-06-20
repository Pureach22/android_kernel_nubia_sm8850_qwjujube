__int64 __fastcall _cam_isp_ctx_dump_in_top_state(__int64 a1, __int64 *a2)
{
  int v4; // w0
  unsigned int cpu_buf; // w0
  unsigned int v6; // w22
  _QWORD *v7; // x21
  __int64 v8; // x6
  unsigned int v9; // w22
  __int64 v10; // x6
  __int64 v11; // x6
  size_t v12; // x9
  __int64 v13; // x4
  __int64 *v15; // x23
  __int64 v16; // x24
  unsigned __int64 v17; // x24
  __int64 v18; // x6
  __int64 v19; // x7
  __int64 v20; // x11
  __int64 v21; // x8
  unsigned int v22; // w0
  __int64 v23; // x5
  __int64 v24; // x7
  unsigned __int64 v25; // x6
  __int64 v26; // x9
  unsigned int v27; // w0
  unsigned __int64 v28; // x6
  __int64 v29; // x8
  __int64 *v30; // x10
  __int64 (__fastcall *v31)(__int64, __int64 *); // x8
  __int64 v32; // x0
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned int v35; // w0
  unsigned int v36; // w0
  __int64 v37; // x10
  __int64 *v38; // x9
  __int64 (__fastcall *v39)(__int64, __int64 *); // x8
  int v40; // w12
  __int64 v41; // x10
  __int64 v42; // x0
  char v43; // [xsp+0h] [xbp-F0h]
  char v44; // [xsp+0h] [xbp-F0h]
  __int64 v45; // [xsp+10h] [xbp-E0h] BYREF
  _QWORD *v46; // [xsp+18h] [xbp-D8h]
  __int64 v47; // [xsp+20h] [xbp-D0h]
  __int64 v48; // [xsp+28h] [xbp-C8h]
  __int64 v49; // [xsp+30h] [xbp-C0h]
  __int64 v50; // [xsp+38h] [xbp-B8h]
  __int64 v51; // [xsp+40h] [xbp-B0h]
  __int64 v52; // [xsp+48h] [xbp-A8h]
  __int64 v53; // [xsp+50h] [xbp-A0h]
  __int64 v54; // [xsp+58h] [xbp-98h]
  __int64 v55; // [xsp+60h] [xbp-90h]
  __int64 v56; // [xsp+68h] [xbp-88h]
  __int64 v57; // [xsp+70h] [xbp-80h] BYREF
  __int64 v58; // [xsp+78h] [xbp-78h]
  __int64 *v59; // [xsp+80h] [xbp-70h]
  _QWORD v60[3]; // [xsp+88h] [xbp-68h] BYREF
  __int64 v61; // [xsp+A0h] [xbp-50h]
  __int64 v62; // [xsp+A8h] [xbp-48h]
  __int64 v63; // [xsp+B0h] [xbp-40h]
  __int64 v64; // [xsp+B8h] [xbp-38h] BYREF
  __int64 v65; // [xsp+C0h] [xbp-30h]
  __int64 v66; // [xsp+C8h] [xbp-28h]
  __int64 v67; // [xsp+D0h] [xbp-20h]
  __int64 v68; // [xsp+D8h] [xbp-18h] BYREF
  size_t v69[2]; // [xsp+E0h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_DWORD *)a2 + 5);
  v68 = 0;
  v69[0] = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v58 = 0;
  v59 = nullptr;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = nullptr;
  v47 = 0;
  v45 = 0;
  cpu_buf = cam_mem_get_cpu_buf(v4, &v68, v69);
  if ( cpu_buf )
  {
    v6 = cpu_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_dump_in_top_state",
      6416,
      "Invalid handle %u rc %d, ctx_idx: %u, link: 0x%x",
      *((_DWORD *)a2 + 5),
      cpu_buf,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  else
  {
    raw_spin_lock_bh(a1 + 120);
    v7 = (_QWORD *)(a1 + 128);
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == (_QWORD *)(a1 + 128) )
        break;
      v8 = v7[3];
      if ( v8 == *a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_dump_in_top_state",
          6425,
          "isp dump active list req: %lld, ctx_idx: %u, link: 0x%x",
          v8,
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        v9 = 97;
LABEL_15:
        v12 = a2[1];
        if ( v69[0] <= v12 )
        {
          raw_spin_unlock_bh(a1 + 120);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_dump_in_top_state",
            6460,
            "Dump buffer overshoot len %zu offset %zu, ctx_idx: %u, link: 0x%x",
            v69[0],
            a2[1],
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          goto LABEL_20;
        }
        if ( v69[0] - v12 <= 0xB7 )
        {
          v13 = 6472;
          goto LABEL_18;
        }
        v15 = *(__int64 **)(a1 + 256);
        v16 = v7[4];
        v17 = (*(_QWORD *)(v16 + 4464) - ktime_get_with_offset(1)) / 1000;
        _cam_isp_ctx_print_event_record(v15);
        if ( v17 >> 5 <= 0xC34 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "__cam_isp_ctx_dump_in_top_state",
            6487,
            "req %lld found no error, ctx_idx: %u, link: 0x%x",
            v7[3],
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        v20 = a2[1];
        v60[0] = *a2;
        v60[1] = v68;
        v21 = v15[4662];
        v60[2] = v69[0];
        v61 = v20;
        v62 = v21;
        v22 = cam_common_user_dump_helper(
                v60,
                (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_timer,
                (__int64)v7,
                8,
                "ISP_CTX_DUMP.%c:",
                v9,
                v18,
                v19,
                v43);
        if ( v22 )
        {
          v6 = v22;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_dump_in_top_state",
            6502,
            "Time dump fail %lld, rc: %d, ctx_idx: %u, link: 0x%x",
            v7[3],
            v22,
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64),
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59);
          goto LABEL_26;
        }
        v25 = v69[0] - v61;
        a2[1] = v61;
        if ( v25 <= 0xA3 )
        {
          v13 = 6513;
          goto LABEL_18;
        }
        v26 = *(_QWORD *)(a1 + 208);
        *(_QWORD *)(a1 + 264) = v15[4662];
        if ( *(_QWORD *)(v26 + 136) )
        {
          v27 = cam_common_user_dump_helper(
                  v60,
                  (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_stream_info,
                  a1,
                  4,
                  "ISP_STREAM_INFO_FROM_CTX:",
                  v23,
                  v25,
                  v24,
                  v44);
          if ( v27 )
          {
            v6 = v27;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_dump_in_top_state",
              6529,
              "ISP CTX stream info dump fail %lld, rc: %d, ctx: %u, link: 0x%x",
              v7[3],
              v27,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64),
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59);
            goto LABEL_26;
          }
          v28 = v69[0] - v61;
          a2[1] = v61;
          if ( v28 <= 0xA3 )
          {
            v13 = 6538;
LABEL_18:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              2,
              "__cam_isp_ctx_dump_in_top_state",
              v13,
              "Dump buffer exhaust remain %zu min %u, ctx_idx: %u, link: 0x%x");
            raw_spin_unlock_bh(a1 + 120);
LABEL_20:
            cam_mem_put_cpu_buf(*((_DWORD *)a2 + 5));
            v6 = -28;
            goto LABEL_21;
          }
          v29 = *(_QWORD *)(a1 + 264);
          v30 = *(__int64 **)(a1 + 208);
          LODWORD(v45) = 9;
          v57 = v29;
          LODWORD(v58) = 0;
          v46 = v60;
          v59 = &v45;
          v31 = (__int64 (__fastcall *)(__int64, __int64 *))v30[12];
          v32 = *v30;
          if ( *((_DWORD *)v31 - 1) != 1863972096 )
            __break(0x8228u);
          v33 = v31(v32, &v57);
          if ( v33 )
          {
            v6 = v33;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_dump_in_top_state",
              6555,
              "IFE HW MGR stream info dump fail %lld, rc: %d, ctx: %u, link: 0x%x",
              v7[3],
              v33,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64),
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59);
            goto LABEL_26;
          }
          a2[1] = v61;
        }
        v34 = _cam_isp_ctx_dump_event_record(v15, v60);
        if ( v34 )
        {
          v6 = v34;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_dump_in_top_state",
            6566,
            "Event record dump fail %lld, rc: %d, ctx_idx: %u, link: 0x%x",
            v7[3],
            v34,
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64),
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59);
          goto LABEL_26;
        }
        a2[1] = v61;
        if ( v17 >> 5 < 0xC35 )
        {
          v6 = 0;
          goto LABEL_26;
        }
        v35 = _cam_isp_ctx_user_dump_state_monitor_array(v15, v60);
        if ( v35 )
        {
          v6 = v35;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_dump_in_top_state",
            6578,
            "Dump event fail %lld, rc: %d, ctx_idx: %u, link: 0x%x",
            v7[3],
            v35,
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64),
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59);
          goto LABEL_26;
        }
        v36 = _cam_isp_ctx_dump_req_info(a1, v7, v60);
        if ( v36 )
        {
          v6 = v36;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, __int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_dump_in_top_state",
            6586,
            "Dump Req info fail %lld, rc: %d, ctx_idx: %u, link: 0x%x",
            v7[3],
            v36,
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64),
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59);
LABEL_26:
          raw_spin_unlock_bh(a1 + 120);
        }
        else
        {
          raw_spin_unlock_bh(a1 + 120);
          v37 = v61;
          a2[1] = v61;
          v38 = *(__int64 **)(a1 + 208);
          v39 = (__int64 (__fastcall *)(__int64, __int64 *))v38[17];
          if ( v39 )
          {
            v40 = *((_DWORD *)a2 + 5);
            v64 = *a2;
            v65 = v37;
            v41 = v15[4662];
            LODWORD(v66) = v40;
            v67 = v41;
            v42 = *v38;
            if ( *((_DWORD *)v39 - 1) != 1863972096 )
              __break(0x8228u);
            v6 = v39(v42, &v64);
            a2[1] = v65;
          }
          else
          {
            v6 = 0;
          }
        }
        cam_mem_put_cpu_buf(*((_DWORD *)a2 + 5));
        goto LABEL_21;
      }
    }
    v7 = (_QWORD *)(a1 + 160);
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == (_QWORD *)(a1 + 160) )
        break;
      v10 = v7[3];
      if ( v10 == *a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_dump_in_top_state",
          6434,
          "isp dump wait list req: %lld, ctx_idx: %u, link: 0x%x",
          v10,
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        v9 = 119;
        goto LABEL_15;
      }
    }
    v7 = (_QWORD *)(a1 + 144);
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == (_QWORD *)(a1 + 144) )
        break;
      v11 = v7[3];
      if ( v11 == *a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_dump_in_top_state",
          6444,
          "isp dump pending list req: %lld, ctx_idx: %u, link: 0x%x",
          v11,
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        v9 = 112;
        goto LABEL_15;
      }
    }
    _cam_isp_ctx_print_event_record(*(__int64 **)(a1 + 256));
    raw_spin_unlock_bh(a1 + 120);
    cam_mem_put_cpu_buf(*((_DWORD *)a2 + 5));
    v6 = 0;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v6;
}
