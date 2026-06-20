__int64 __fastcall cam_private_ioctl(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v6; // x1
  int v7; // w8
  int session; // w19
  __int64 v10; // x0
  char *v11; // x1
  __int64 v12; // x2
  __int64 v13; // x19
  int v15; // w8
  int v16; // w8
  int v17; // w0
  int v18; // w8
  __int64 v19; // x19
  int v21; // w8
  __int64 v22; // x19
  int v24; // w8
  int v25; // w8
  __int64 v26; // x19
  int v28; // w8
  int v29; // w8
  int v32; // w22
  unsigned int v33; // w19
  __int64 v34; // x0
  int v35; // w8
  int v36; // w8
  int v38; // w0
  int v39; // w8
  int v40; // w8
  int v41; // w8
  bool v42; // zf
  int v43; // w8
  int v44; // w8
  int v46; // w8
  int v48; // w0
  __int64 v49; // x0
  __int64 v50; // x20
  __int64 v51; // x21
  __int64 v52; // [xsp+10h] [xbp-480h] BYREF
  __int64 v53; // [xsp+18h] [xbp-478h]
  __int64 v54; // [xsp+20h] [xbp-470h]
  __int64 v55; // [xsp+28h] [xbp-468h]
  __int64 v56; // [xsp+30h] [xbp-460h]
  __int64 v57; // [xsp+38h] [xbp-458h]
  __int64 v58; // [xsp+40h] [xbp-450h]
  __int64 v59; // [xsp+48h] [xbp-448h]
  __int64 v60; // [xsp+50h] [xbp-440h]
  __int64 v61; // [xsp+58h] [xbp-438h]
  __int64 v62; // [xsp+60h] [xbp-430h]
  __int64 v63; // [xsp+68h] [xbp-428h]
  __int64 v64; // [xsp+70h] [xbp-420h]
  _QWORD s[131]; // [xsp+78h] [xbp-418h] BYREF

  result = -22;
  s[130] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 == -1072146752 )
  {
    if ( a5 )
    {
      v6 = *(_QWORD *)(a5 + 16);
      if ( v6 )
      {
        switch ( *(_DWORD *)a5 )
        {
          case 0x10C:
            v7 = *(_DWORD *)(a5 + 4);
            s[0] = 0;
            if ( v7 == 8 )
            {
              if ( inline_copy_from_user((int)s, v6, 8u) )
                goto LABEL_69;
              session = cam_req_mgr_create_session((unsigned int *)s);
              if ( !session )
              {
                v10 = *(_QWORD *)(a5 + 16);
                v11 = (char *)s;
                v12 = 8;
                goto LABEL_92;
              }
              goto LABEL_85;
            }
            break;
          case 0x10D:
            v28 = *(_DWORD *)(a5 + 4);
            s[0] = 0;
            if ( v28 == 8 )
            {
              if ( inline_copy_from_user((int)s, v6, 8u) )
                goto LABEL_69;
              session = cam_req_mgr_destroy_session((unsigned int *)s, 0);
              goto LABEL_85;
            }
            break;
          case 0x10E:
            v22 = *(_QWORD *)(a5 + 16);
            memset(s, 0, 0x410u);
            if ( *(_DWORD *)(a5 + 4) != 268 )
              goto LABEL_58;
            if ( inline_copy_from_user((int)s + 4, v22, 0x10Cu) )
              goto LABEL_69;
            LODWORD(s[0]) = 1;
            session = cam_req_mgr_link((unsigned int *)s);
            if ( session )
              goto LABEL_85;
            v10 = *(_QWORD *)(a5 + 16);
            v11 = (char *)s + 4;
            v12 = 268;
            goto LABEL_92;
          case 0x10F:
            v25 = *(_DWORD *)(a5 + 4);
            s[0] = 0;
            if ( v25 != 8 )
              break;
            if ( inline_copy_from_user((int)s, v6, 8u) )
              goto LABEL_69;
            session = cam_req_mgr_unlink((unsigned int *)s);
            goto LABEL_85;
          case 0x110:
            v18 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 32);
            if ( v18 != 32 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x20u) )
              goto LABEL_69;
            session = cam_req_mgr_schedule_request((__int64)s);
            goto LABEL_85;
          case 0x111:
            v35 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 24);
            if ( v35 != 24 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x18u) )
              goto LABEL_69;
            session = cam_req_mgr_flush_requests((unsigned int *)s);
            goto LABEL_85;
          case 0x112:
            v39 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 28);
            if ( v39 != 28 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x1Cu) )
              goto LABEL_69;
            session = cam_req_mgr_sync_config((unsigned int *)s);
            goto LABEL_85;
          case 0x113:
            v26 = *(_QWORD *)(a5 + 16);
            v63 = 0;
            v64 = 0;
            v61 = 0;
            v62 = 0;
            v59 = 0;
            v60 = 0;
            v57 = 0;
            v58 = 0;
            v55 = 0;
            v56 = 0;
            v53 = 0;
            v54 = 0;
            v52 = 0;
            memset(s, 0, 0x110u);
            if ( *(_DWORD *)(a5 + 4) != 104 )
              goto LABEL_58;
            if ( !inline_copy_from_user((int)&v52, v26, 0x68u) )
            {
              s[5] = v58;
              s[6] = v59;
              s[12] = 0x4E574F4E4B4E55LL;
              s[7] = v60;
              s[8] = v61;
              s[1] = v54;
              s[2] = v55;
              s[3] = v56;
              s[4] = v57;
              LODWORD(s[28]) = HIDWORD(v62);
              HIDWORD(s[0]) = v62;
              s[9] = v52;
              s[10] = v53;
              session = cam_mem_mgr_alloc_and_map(s);
              v63 = s[32];
              v64 = s[33];
              if ( session || !inline_copy_to_user(*(_QWORD *)(a5 + 16), &v52, 104) )
                goto LABEL_85;
            }
            goto LABEL_84;
          case 0x114:
            v44 = *(_DWORD *)(a5 + 4);
            v62 = 0;
            v63 = 0;
            v60 = 0;
            v61 = 0;
            v58 = 0;
            v59 = 0;
            v56 = 0;
            v57 = 0;
            v54 = 0;
            v55 = 0;
            v52 = 0;
            v53 = 0;
            memset(s, 0, 256);
            if ( v44 != 96 )
              break;
            if ( !inline_copy_from_user((int)&v52, v6, 0x60u) )
            {
              s[5] = v56;
              s[6] = v57;
              s[11] = 0x4E574F4E4B4E55LL;
              s[7] = v58;
              s[8] = v59;
              s[1] = v52;
              s[2] = v53;
              s[3] = v54;
              s[4] = v55;
              HIDWORD(s[0]) = v61;
              s[9] = v60;
              session = ((__int64 (__fastcall *)(_QWORD *))cam_mem_mgr_map)(s);
              v62 = s[30];
              v63 = s[31];
              if ( session || !inline_copy_to_user(*(_QWORD *)(a5 + 16), &v52, 96) )
                goto LABEL_85;
            }
            goto LABEL_84;
          case 0x115:
            v21 = *(_DWORD *)(a5 + 4);
            s[0] = 0;
            if ( v21 != 8 )
              break;
            if ( inline_copy_from_user((int)s, v6, 8u) )
              goto LABEL_84;
            session = cam_mem_mgr_release(s);
            goto LABEL_85;
          case 0x116:
            v43 = *(_DWORD *)(a5 + 4);
            s[0] = 0;
            if ( v43 != 8 )
              break;
            if ( inline_copy_from_user((int)s, v6, 8u) )
              goto LABEL_84;
            session = cam_mem_mgr_cache_ops(s);
            goto LABEL_85;
          case 0x117:
            v16 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 32);
            if ( v16 != 32 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x20u) )
              goto LABEL_84;
            v17 = ((__int64 (__fastcall *)(_QWORD *))cam_req_mgr_link_control)(s);
            goto LABEL_73;
          case 0x118:
            v19 = *(_QWORD *)(a5 + 16);
            memset(s, 0, 0x410u);
            if ( *(_DWORD *)(a5 + 4) != 1036 )
              goto LABEL_58;
            if ( inline_copy_from_user((int)s + 4, v19, 0x40Cu) )
              goto LABEL_69;
            LODWORD(s[0]) = 2;
            session = cam_req_mgr_link_v2((unsigned int *)s);
            if ( session )
              goto LABEL_85;
            v10 = *(_QWORD *)(a5 + 16);
            v11 = (char *)s + 4;
            v12 = 1036;
            goto LABEL_92;
          case 0x119:
            v36 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 40);
            if ( v36 != 40 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x28u) )
              goto LABEL_84;
            v38 = ((__int64 (__fastcall *)(_QWORD *))cam_req_mgr_dump_request)(s);
            if ( v38 )
            {
              session = v38;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                2,
                1,
                "cam_private_ioctl",
                773,
                "dump fail for dev %d req %llu rc %d",
                LODWORD(s[4]),
                s[0],
                v38);
              goto LABEL_85;
            }
            v10 = *(_QWORD *)(a5 + 16);
            v11 = (char *)s;
            v12 = 40;
            goto LABEL_92;
          case 0x11A:
            v15 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 72);
            if ( v15 != 72 )
              break;
            if ( !inline_copy_from_user((int)s, v6, 0x48u) )
            {
              session = ((__int64 (__fastcall *)(_QWORD *))cam_req_mgr_schedule_request_v2)(s);
              goto LABEL_85;
            }
LABEL_69:
            result = -14;
            break;
          case 0x11B:
            v24 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 48);
            if ( v24 != 48 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x30u) )
              goto LABEL_84;
            session = cam_req_mgr_link_properties((__int64)s);
            goto LABEL_85;
          case 0x11C:
            v13 = *(_QWORD *)(a5 + 16);
            memset(s, 0, 0x110u);
            if ( *(_DWORD *)(a5 + 4) != 272 )
              goto LABEL_58;
            if ( !inline_copy_from_user((int)s, v13, 0x110u) )
            {
              session = cam_mem_mgr_alloc_and_map(s);
              if ( session || !inline_copy_to_user(*(_QWORD *)(a5 + 16), s, 272) )
                goto LABEL_85;
            }
            goto LABEL_84;
          case 0x11D:
            v29 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 256);
            if ( v29 != 256 )
              break;
            if ( !inline_copy_from_user((int)s, v6, 0x100u) )
            {
              session = ((__int64 (__fastcall *)(_QWORD *))cam_mem_mgr_map)(s);
              if ( session || !inline_copy_to_user(*(_QWORD *)(a5 + 16), s, 256) )
                goto LABEL_85;
            }
            goto LABEL_84;
          case 0x11E:
            v40 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 40);
            if ( v40 != 40 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x28u) )
              goto LABEL_84;
            v17 = ((__int64 (__fastcall *)(_QWORD *))cam_mem_mgr_cpu_access_op)(s);
LABEL_73:
            v41 = -22;
            v42 = v17 == 0;
            goto LABEL_93;
          case 0x11F:
            v46 = *(_DWORD *)(a5 + 4);
            memset(s, 0, 48);
            if ( v46 != 48 )
              break;
            if ( inline_copy_from_user((int)s, v6, 0x30u) )
            {
LABEL_84:
              session = -14;
            }
            else
            {
              s[1] = 0;
              v48 = cam_mem_mgr_check_for_supported_heaps(&s[1]);
              if ( v48 )
              {
                session = v48;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  16,
                  1,
                  "cam_private_ioctl",
                  815,
                  "Failed to retrieve heap capability rc: %d",
                  v48);
              }
              else
              {
                v10 = *(_QWORD *)(a5 + 16);
                v11 = (char *)s;
                v12 = 48;
LABEL_92:
                v49 = inline_copy_to_user(v10, v11, v12);
                v41 = -14;
                v42 = v49 == 0;
LABEL_93:
                if ( v42 )
                  session = 0;
                else
                  session = v41;
              }
            }
            goto LABEL_85;
          case 0x120:
            memset(s, 0, 64);
            if ( inline_copy_from_user((int)s, v6, 0x40u) )
              goto LABEL_69;
            v32 = s[3];
            if ( LODWORD(s[3]) <= 4 && (v33 = (4 * LODWORD(s[3])) | 0x40, *(_DWORD *)(a5 + 4) == v33) )
            {
              if ( mem_trace_en == 1 )
                v34 = cam_mem_trace_alloc((4LL * LODWORD(s[3])) | 0x40, 3264, 0, "cam_private_ioctl", 524);
              else
                v34 = _kvmalloc_node_noprof(v33, 0, 3520, 0xFFFFFFFFLL);
              v50 = v34;
              if ( v34 )
              {
                v51 = *(_QWORD *)(a5 + 16);
                _check_object_size(v34, v33, 0);
                if ( inline_copy_from_user(v50, v51, v33) )
                {
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free(v50, 0);
                  else
                    kvfree(v50);
                  result = -14;
                }
                else
                {
                  LODWORD(s[3]) = v32;
                  session = cam_req_mgr_schedule_request_v3(v50);
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free(v50, 0);
                  else
                    kvfree(v50);
LABEL_85:
                  result = session;
                }
              }
              else
              {
                result = -12;
              }
            }
            else
            {
LABEL_58:
              result = -22;
            }
            break;
          default:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              16,
              1,
              "cam_private_ioctl",
              826,
              "Invalid Opcode %d",
              *(_DWORD *)a5);
            session = -515;
            goto LABEL_85;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
