__int64 __fastcall _cam_req_mgr_check_multi_sync_link_ready(
        unsigned int *a1,
        unsigned int **a2,
        unsigned int *a3,
        int a4,
        unsigned int a5)
{
  unsigned int *v6; // x24
  __int64 v11; // x6
  const char *v12; // x5
  __int64 v13; // x4
  unsigned int v14; // w23
  __int64 v15; // x27
  unsigned int *v16; // x8
  __int64 v17; // x7
  __int64 v18; // x9
  unsigned int v19; // w20
  __int64 slot_for_req; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  unsigned int *v23; // x28
  unsigned int v24; // w8
  unsigned int v25; // w9
  int *v26; // x8
  unsigned int v27; // w24
  int v28; // w23
  __int64 v29; // x14
  int *v30; // x17
  __int64 v31; // x16
  unsigned int *v32; // x15
  __int64 v33; // x8
  __int64 v34; // x9
  unsigned __int64 v35; // x23
  unsigned __int64 v36; // x25
  unsigned __int64 v37; // x10
  unsigned __int64 v38; // x11
  int *v39; // x20
  unsigned int v40; // w25
  int v41; // w8
  int v42; // w24
  __int64 v43; // x1
  int v44; // w25
  int v45; // w0
  __int64 v46; // x6
  __int64 v47; // x8
  bool v48; // vf
  __int64 v49; // x8
  unsigned int v50; // w0
  unsigned int v51; // w0
  __int64 v52; // x20
  int *v53; // x25
  int v54; // w0
  const char *v55; // x7
  __int64 v56; // x6
  __int64 v57; // x4
  __int64 v58; // x6
  const char *v59; // x5
  __int64 v60; // x1
  __int64 v61; // x4
  __int64 v62; // x7
  const char *v63; // x5
  __int64 v64; // x1
  __int64 v65; // x4
  unsigned int *v67; // x20
  __int64 v68; // [xsp+20h] [xbp-40h]
  int v69; // [xsp+2Ch] [xbp-34h]
  int v70; // [xsp+30h] [xbp-30h]
  int *v71; // [xsp+30h] [xbp-30h]
  unsigned int v72; // [xsp+3Ch] [xbp-24h]
  unsigned __int64 v73; // [xsp+40h] [xbp-20h]
  unsigned __int64 v74; // [xsp+48h] [xbp-18h]
  __int64 v75; // [xsp+50h] [xbp-10h]
  unsigned int *v76; // [xsp+58h] [xbp-8h]

  v6 = a1 + 0x2000;
  raw_spin_lock_bh(a1 + 8304);
  v76 = v6;
  LODWORD(v6) = v6[96];
  raw_spin_unlock_bh(a1 + 8304);
  if ( (_DWORD)v6 == 1 )
  {
    v11 = *a1;
    v12 = "link hdl %x is in idle state";
    v13 = 2110;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_check_multi_sync_link_ready",
      v13,
      v12,
      v11);
    return (unsigned int)-22;
  }
  if ( a4 >= 1 )
  {
    v15 = (unsigned int)a4;
    v72 = a5;
    do
    {
      v16 = *a2;
      if ( !*a2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          16777232,
          1,
          "__cam_req_mgr_check_multi_sync_link_ready",
          2174,
          "Sync link is null");
        return (unsigned int)-22;
      }
      v17 = *((_QWORD *)a3 + 2);
      v18 = *((_QWORD *)v16 + 4158);
      if ( v17 <= v18 )
      {
        if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10,
            4,
            "__cam_req_mgr_check_multi_sync_link_ready",
            2122,
            "link:0x%x req:%lld has been flushed in sync link:0x%x, last_flush_id:%lld",
            *a1,
            v17,
            *v16,
            v18);
        if ( (unsigned int)_cam_req_mgr_check_link_is_ready(a1, *a3, 1) )
        {
          v14 = -22;
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_check_multi_sync_link_ready",
              2128,
              "link %x not ready",
              *a1);
          return v14;
        }
      }
      else
      {
        raw_spin_lock_bh(v16 + 8304);
        v19 = (*a2)[8288];
        slot_for_req = raw_spin_unlock_bh(*a2 + 8304);
        if ( v19 == 1 )
        {
          v12 = "sync link hdl %x is idle";
          v11 = **a2;
          v13 = 2137;
          goto LABEL_3;
        }
        v23 = *a2;
        v24 = a1[2];
        v25 = (*a2)[2];
        if ( v24 == v25 )
        {
          if ( !a1 || !v23 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              16,
              1,
              "__cam_req_mgr_check_sync_req_is_ready",
              1889,
              "Sync link null");
            v14 = -22;
            goto LABEL_139;
          }
          v26 = *((int **)v23 + 6);
          if ( !v26 )
          {
            v56 = *v23;
            v57 = 1897;
LABEL_112:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              16,
              1,
              "__cam_req_mgr_check_sync_req_is_ready",
              v57,
              "Link hdl %x in_q is NULL",
              v56);
            v14 = -22;
            goto LABEL_139;
          }
          v27 = v26[866];
          if ( v27 >= 0x31 )
            goto LABEL_149;
          v28 = *v26;
          v29 = *((_QWORD *)a3 + 2);
          v30 = &v26[18 * v27];
          v31 = *((_QWORD *)v30 + 3);
          v68 = v31;
          if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
          {
            v52 = *((_QWORD *)a3 + 2);
            v53 = &v26[18 * v27];
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1000010,
              4,
              "__cam_req_mgr_check_sync_req_is_ready",
              1908,
              "link_hdl %x sync link_hdl %x req %lld",
              *a1,
              *v23,
              v29);
            v31 = v68;
            v30 = v53;
            v29 = v52;
          }
          v32 = v23 + 0x2000;
          if ( *((_BYTE *)v23 + 33277) == 1 && v29 > v31 )
          {
            v14 = -11;
            *((_BYTE *)v76 + 509) = 0;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            {
              v58 = *v23;
              v59 = "sync link %x not streamed on";
              v60 = debug_mdl & 0x10;
              v61 = 1915;
LABEL_135:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                v60,
                4,
                "__cam_req_mgr_check_sync_req_is_ready",
                v61,
                v59,
                v58);
            }
LABEL_139:
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "__cam_req_mgr_check_multi_sync_link_ready",
                2148,
                "link %x not ready",
                *a1);
            return v14;
          }
          v33 = *((_QWORD *)v23 + 4163);
          v34 = *((_QWORD *)v23 + 4162);
          v69 = v28;
          v35 = *((_QWORD *)v30 + 8) + v34;
          v36 = *((_QWORD *)a3 + 7) + *((_QWORD *)v76 + 66);
          v75 = v29;
          if ( v33 )
            v37 = v34 - v33;
          else
            v37 = 33333333;
          if ( v36 >= v35 )
            v38 = v36 - v35;
          else
            v38 = v35 - v36;
          v73 = v38;
          v74 = v37;
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            v71 = v30;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_check_sync_req_is_ready",
              1935,
              "sync link %x last frame_duration is %d ns sof_timestamp_delta:%llu ns",
              *v23,
              v37,
              v38);
            v37 = v74;
            v29 = v75;
            v30 = v71;
            v32 = v23 + 0x2000;
          }
          if ( *((_BYTE *)v76 + 509) == 1 )
          {
            *((_BYTE *)v76 + 509) = 0;
            if ( v36 > v35 && v35 && v36 - v35 < v37 >> 1 )
            {
              v14 = -11;
              if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              {
                v58 = *v23;
                v59 = "This frame sync with previous sync_link %x frame";
                v60 = debug_mdl & 0x10;
                v61 = 1951;
                goto LABEL_135;
              }
              goto LABEL_139;
            }
            if ( v36 <= v35 )
            {
              v14 = -11;
              if ( (debug_mdl & 0x10) != 0 && !debug_priority )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x10,
                  4,
                  "__cam_req_mgr_check_sync_req_is_ready",
                  1962,
                  "The previous frame of sync link is skipped");
              goto LABEL_139;
            }
          }
          if ( *((_BYTE *)v32 + 484) == 1 )
          {
            if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
            {
              v67 = v32;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x1000010,
                4,
                "__cam_req_mgr_check_sync_req_is_ready",
                1970,
                "No req applied on corresponding SOF on sync link: %x",
                *v23);
              v32 = v67;
            }
            *((_BYTE *)v32 + 484) = 0;
            v14 = -11;
            goto LABEL_139;
          }
          v39 = v30;
          slot_for_req = _cam_req_mgr_find_slot_for_req(*((int **)v23 + 6), v29);
          if ( (_DWORD)slot_for_req == -1 )
          {
            v14 = -11;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            {
              v62 = *v23;
              v63 = "Req: %lld not found on link: %x [other link]";
              v64 = debug_mdl & 0x10;
              v65 = 1979;
              goto LABEL_125;
            }
            goto LABEL_139;
          }
          v40 = slot_for_req;
          if ( (unsigned int)slot_for_req > 0x2F )
          {
LABEL_149:
            __break(0x5512u);
            return _cam_req_mgr_check_link_is_ready(slot_for_req, v21, v22);
          }
          v70 = slot_for_req;
          if ( *(_DWORD *)(*((_QWORD *)v23 + 6) + 72LL * (int)slot_for_req + 16) != 4 )
          {
            v41 = (int)(v69 - v27 + slot_for_req) % v69;
            if ( v41 > 1 || v41 == 1 && v39[4] != 4 )
            {
              v14 = -11;
              if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              {
                v62 = *v23;
                v63 = "Req: %lld [other link] not next req to be applied on link: %x";
                v64 = debug_mdl & 0x10;
                v65 = 1993;
LABEL_125:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                  3,
                  v64,
                  4,
                  "__cam_req_mgr_check_sync_req_is_ready",
                  v65,
                  v63,
                  v75,
                  v62);
              }
              goto LABEL_139;
            }
          }
          v42 = _cam_req_mgr_check_link_is_ready(a1, *a3, 1);
          if ( v42 && (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_check_sync_req_is_ready",
              2001,
              "Req: %lld [My link] not ready on link: %x, rc=%d",
              v75,
              *a1,
              v42);
            if ( !*((_QWORD *)v23 + 6) )
            {
LABEL_111:
              v56 = *v23;
              v57 = 2020;
              goto LABEL_112;
            }
          }
          else if ( !*((_QWORD *)v23 + 6) )
          {
            goto LABEL_111;
          }
          v43 = v40;
          v44 = 1;
          v45 = _cam_req_mgr_check_link_is_ready(v23, v43, 1);
          if ( v45 )
          {
            if ( (unsigned int)(*(_DWORD *)(*((_QWORD *)v23 + 6) + 72LL * v70 + 16) - 3) >= 2 )
            {
              v44 = 0;
              if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x10,
                  4,
                  "__cam_req_mgr_check_sync_req_is_ready",
                  2015,
                  "Req: %lld not ready on link: %x, rc=%d",
                  v75,
                  *v23,
                  v45);
                v44 = 0;
              }
            }
          }
          if ( v44 != (v42 == 0) )
          {
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "__cam_req_mgr_check_sync_req_is_ready",
                2031,
                "Req: %lld ready %d sync_ready %d, ignore sync link next SOF",
                v75);
            if ( v73 > v74 >> 1 )
              *((_BYTE *)v76 + 484) = 1;
            v14 = -22;
            goto LABEL_139;
          }
          if ( v42 )
          {
            v14 = -22;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            {
              v62 = *a1;
              v63 = "Req: %lld not ready on link: %x";
              v64 = debug_mdl & 0x10;
              v65 = 2043;
              goto LABEL_125;
            }
            goto LABEL_139;
          }
          a5 = v72;
          v46 = v75;
          if ( v72 == 1 )
          {
            if ( v35 )
            {
              if ( v73 < v74 / 5 && v39[8] == 1 )
              {
                v47 = *((_QWORD *)v76 + 64);
                v48 = __OFSUB__(v75, v47);
                v49 = v75 - v47;
                if ( v49 < 0 == v48 && v49 >= a1[2] + 5 )
                {
                  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x10,
                      4,
                      "__cam_req_mgr_check_sync_req_is_ready",
                      2071,
                      "link %x req_id %lld, sync_link %x req_id %lld",
                      *a1,
                      v75,
                      *v23,
                      v68);
                    v46 = v75;
                  }
                  if ( v46 > v68 )
                  {
                    v14 = -11;
                    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
                    {
                      v58 = *a1;
                      v59 = "link %x too quickly, skip this frame";
                      v60 = debug_mdl & 0x10;
                      v61 = 2076;
                      goto LABEL_135;
                    }
                    goto LABEL_139;
                  }
                  if ( v46 >= v68 )
                  {
                    if ( *(_DWORD *)(*((_QWORD *)v23 + 6) + 72LL * v70 + 16) != 4 && (*((_BYTE *)v23 + 33362) & 1) == 0 )
                    {
                      v14 = -11;
                      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
                      {
                        v58 = *a1;
                        v59 = "link %x other not applied";
                        v60 = debug_mdl & 0x10;
                        v61 = 2086;
                        goto LABEL_135;
                      }
                      goto LABEL_139;
                    }
                  }
                  else
                  {
                    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x10,
                        4,
                        "__cam_req_mgr_check_sync_req_is_ready",
                        2081,
                        "sync link %x too quickly, skip next frame of sync link",
                        *v23);
                      v46 = v75;
                    }
                    *((_BYTE *)v76 + 484) = 1;
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1000010,
              4,
              "__cam_req_mgr_check_sync_req_is_ready",
              2092,
              "Req: %lld ready to apply on link: %x [validation successful]",
              v46,
              *a1);
        }
        else if ( v24 > v25 )
        {
          *((_BYTE *)v76 + 508) = 1;
          *((_BYTE *)*a2 + 33276) = 0;
          v50 = _cam_req_mgr_check_sync_for_mslave(a1, *a2, a3);
          if ( (v50 & 0x80000000) != 0 )
          {
            v14 = v50;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "__cam_req_mgr_check_multi_sync_link_ready",
                2159,
                "link%x not ready",
                *a1);
            return v14;
          }
        }
        else
        {
          *((_BYTE *)v76 + 508) = 0;
          *((_BYTE *)*a2 + 33276) = 1;
          v51 = _cam_req_mgr_check_sync_for_mslave(a1, *a2, a3);
          if ( (v51 & 0x80000000) != 0 )
          {
            v14 = v51;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "__cam_req_mgr_check_multi_sync_link_ready",
                2169,
                "link %x not ready",
                *a1);
            return v14;
          }
        }
      }
      --v15;
      ++a2;
    }
    while ( v15 );
  }
  if ( (_cam_req_mgr_inject_delay(*((_QWORD *)a1 + 7), *a3, a5) & 0x80000000) != 0 )
  {
    v14 = -22;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      if ( a5 == 1 )
        v55 = "SOF";
      else
        v55 = "EOF";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_check_multi_sync_link_ready",
        2185,
        "Req: %lld needs to inject delay at %s",
        *((_QWORD *)a3 + 2),
        v55);
    }
  }
  else
  {
    v54 = _cam_req_mgr_check_link_is_ready(a1, *a3, 0);
    if ( v54 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        2,
        "__cam_req_mgr_check_multi_sync_link_ready",
        2196,
        "Unexpected return value rc: %d",
        v54);
    return 0;
  }
  return v14;
}
