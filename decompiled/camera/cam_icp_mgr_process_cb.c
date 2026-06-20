__int64 __fastcall cam_icp_mgr_process_cb(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  unsigned int *v4; // x27
  unsigned int v5; // w22
  int v6; // w8
  bool v7; // cf
  _QWORD *v8; // x0
  unsigned int v9; // w24
  unsigned int *v10; // x21
  size_t v11; // x2
  int v12; // w7
  int v13; // w6
  __int64 v14; // x23
  __int64 v15; // x28
  __int64 v16; // x24
  __int64 v17; // x1
  __int64 v18; // x6
  __int64 v19; // x4
  const char *v20; // x5
  __int64 v21; // x23
  __int64 v22; // x6
  __int64 v23; // x28
  int v24; // w8
  __int64 v25; // x1
  __int64 v26; // x6
  __int64 v27; // x24
  unsigned int v28; // w7
  __int64 v29; // x6
  __int64 v30; // x8
  __int64 v31; // x28
  __int64 v32; // x6
  __int64 v33; // x23
  int v34; // w7
  __int64 v35; // x28
  __int64 v36; // x23
  __int64 v37; // x24
  const char *v38; // x3
  __int64 v39; // x4
  __int64 v40; // x1
  const char *v41; // x3
  __int64 v42; // x4
  const char *v43; // x5
  const char *v44; // x3
  __int64 v45; // x4
  __int16 v46; // w8
  const char *v47; // x5
  int v48; // w6
  int v49; // w7
  __int64 v50; // x0
  __int64 v51; // x4
  const char *v52; // x5
  __int16 v53; // w24
  __int64 v54; // x1
  __int64 v55; // x6
  __int64 v56; // x4
  const char *v57; // x5
  unsigned int v58; // w6
  unsigned int v59; // w6
  int v60; // w7
  const char *v61; // x8
  const char *v62; // x3
  __int64 v63; // x4
  const char *v64; // x5
  unsigned int v65; // w6
  int v66; // w7
  const char *v67; // x8
  __int16 v68; // w24
  unsigned int v69; // w6
  __int64 v70; // x4
  const char *v71; // x5
  const char *v72; // x3
  __int64 v73; // x4
  const char *v74; // x5
  __int64 v75; // x20
  __int64 v76; // x0
  __int64 v78; // x0
  int v79; // [xsp+0h] [xbp-40h]
  __int64 v80; // [xsp+8h] [xbp-38h]
  __int64 v81; // [xsp+8h] [xbp-38h]
  unsigned int v82; // [xsp+18h] [xbp-28h]
  unsigned int v83; // [xsp+1Ch] [xbp-24h]
  __int64 v84; // [xsp+20h] [xbp-20h]
  unsigned int v86; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v87; // [xsp+38h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_cb",
      3626,
      "Invalid data");
    v9 = -22;
LABEL_333:
    _ReadStatusReg(SP_EL0);
    return v9;
  }
  v3 = 0;
  v4 = (unsigned int *)(a1 + 1016);
  v5 = 512;
  v86 = 0;
  v84 = a1 + 40960;
  while ( 1 )
  {
    if ( v3 >= 0x804 )
      __break(0x5512u);
    v8 = (_QWORD *)hfi_read_message(*(unsigned int *)(a1 + 156), (char *)v4 + (v3 & 0xFFFFFFFC), 1, v5, &v86);
    if ( (_DWORD)v8 )
    {
      v9 = (unsigned int)v8;
      if ( (_DWORD)v8 != -42 )
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_process_msg",
            3579,
            "Unable to read msg q rc %d",
            (_DWORD)v8);
          if ( v9 != -42 )
          {
LABEL_324:
            v75 = a2;
            if ( v9 )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_process_cb",
                3635,
                "Failed to process MSG");
            goto LABEL_328;
          }
        }
        else
        {
LABEL_323:
          if ( v9 != -42 )
            goto LABEL_324;
        }
      }
      v75 = a2;
LABEL_328:
      cam_icp_mgr_process_dbg_buf(a1);
      if ( *(_BYTE *)(v75 + 16) == 1 )
      {
        if ( (unsigned int)__ratelimit(&cam_icp_mgr_process_cb__rs, "cam_icp_mgr_process_cb") )
          v76 = 3;
        else
          v76 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          v76,
          256,
          1,
          "cam_icp_mgr_process_cb",
          3640,
          "issuing device recovery...");
        v9 = cam_icp_mgr_trigger_recovery(a1);
      }
      goto LABEL_333;
    }
    v3 += 4 * v86;
    if ( v3 )
      break;
    v9 = 0;
LABEL_16:
    v6 = 512;
LABEL_5:
    v7 = v86 >= v5;
    v5 = v6;
    if ( !v7 )
      goto LABEL_323;
  }
  if ( v3 < *v4 )
  {
    v9 = 0;
    v10 = v4;
LABEL_12:
    v11 = v3;
    if ( v3 >= 0x801 && (cam_icp_mgr_process_msg___already_done & 1) == 0 )
    {
      cam_icp_mgr_process_msg___already_done = 1;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v3,
        "field \"hw_mgr->msg_buf\" at ../vendor/qcom/opensource/camera-kernel/drivers/cam_icp/icp_hw/icp_hw_mgr/cam_icp_hw_mgr.c:3597",
        0x800u);
      v11 = v3;
      __break(0x800u);
    }
    memcpy(v4, v10, v11);
    v6 = 512 - (v3 >> 2);
    goto LABEL_5;
  }
  v10 = v4;
  while ( 2 )
  {
    v12 = v10[1];
    if ( v12 > 16908297 )
    {
      if ( v12 <= 67239943 )
      {
        if ( v12 != 16908298 )
        {
          if ( v12 != 16908302 )
          {
            if ( v12 == 50464769 )
            {
              if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x100,
                  4,
                  "cam_icp_process_msg_pkt_type",
                  3546,
                  "received DBG_SYNX_TEST");
LABEL_58:
              v8 = (_QWORD *)complete(a1 + 44024);
              v9 = 0;
LABEL_308:
              v3 -= *v10;
              if ( !v3 )
                goto LABEL_16;
              v10 = (unsigned int *)((char *)v10 + (*v10 & 0xFFFFFFFC));
              if ( v3 < *v10 )
                goto LABEL_12;
              continue;
            }
LABEL_97:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_process_msg_pkt_type",
              3552,
              "[%s] invalid msg : %u",
              a1 + 112);
LABEL_306:
            v9 = -22;
LABEL_307:
            v8 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                             3,
                             256,
                             1,
                             "cam_icp_mgr_process_msg",
                             3605,
                             "Failed to process MSG");
            goto LABEL_308;
          }
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_process_msg_pkt_type",
              3515,
              "[%s] received IPE/BPS ASYNC_INDIRECT_ACK",
              (const char *)(a1 + 112));
          v13 = v10[2];
          if ( v13 > 4 )
          {
            if ( v13 == 6 )
              goto LABEL_114;
            if ( v13 != 5 )
              goto LABEL_136;
          }
          else if ( v13 != 1 )
          {
            if ( v13 != 2 )
            {
LABEL_136:
              v44 = "cam_icp_mgr_process_ipebps_indirect_ack_msg";
              v45 = 3053;
              goto LABEL_137;
            }
LABEL_114:
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              v40 = debug_mdl & 0x100;
              v41 = "cam_icp_mgr_process_ipebps_indirect_ack_msg";
              v42 = 3048;
              v43 = "received IPE/BPS_FRAME_PROCESS:";
              goto LABEL_318;
            }
            goto LABEL_121;
          }
          if ( (debug_mdl & 0x100) == 0 || debug_priority )
          {
            if ( v10 )
              goto LABEL_103;
LABEL_314:
            v51 = 2856;
            v52 = "msg ptr is NULL";
LABEL_315:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_mgr_process_msg_config_io",
              v51,
              v52);
LABEL_316:
            v9 = -22;
            goto LABEL_307;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_process_ipebps_indirect_ack_msg",
            3043,
            "received IPE/BPS_CONFIG_IO:");
          if ( !v10 )
            goto LABEL_314;
LABEL_103:
          v35 = *(_QWORD *)(v10 + 3);
          if ( !v35 )
          {
            v51 = 2865;
            v52 = "wrong ctx info from IPE/BPS config io response";
            goto LABEL_315;
          }
          v36 = *(int *)(v35 + 4);
          if ( (*(_BYTE *)v35 & 1) != 0 )
            mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * (int)v36);
          v37 = *(_QWORD *)(v35 + 16);
          if ( v37 != *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v36) )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              2,
              "cam_icp_mgr_process_msg_config_io",
              2875,
              "ctx data is released before accessing it, ctx_id: %u",
              v36);
            goto LABEL_108;
          }
          v58 = v10[2];
          if ( v58 == 1 )
          {
            v69 = v10[8];
            if ( v69 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_process_msg_config_io",
                2911,
                "rc : %u, opcode :%u",
                v69,
                1);
              goto LABEL_108;
            }
            if ( v37 )
            {
              if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100,
                  4,
                  "cam_icp_mgr_process_msg_config_io",
                  2923,
                  "%s: received BPS config io response",
                  (const char *)(v37 + 29824));
              goto LABEL_235;
            }
            v70 = 2917;
            v71 = "wrong ctx data from BPS config io response";
          }
          else
          {
            if ( v58 != 5 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_process_msg_config_io",
                2925,
                "Invalid OPCODE: %u",
                v58);
              v9 = -22;
              goto LABEL_109;
            }
            v59 = v10[8];
            if ( v59 )
            {
              v60 = v10[7];
              if ( v60 > 999 )
              {
                if ( v60 > 1001 )
                {
                  if ( v60 == 1002 )
                  {
                    v61 = "HFI_QUEUE_EMPTY";
                  }
                  else if ( v60 == 1003 )
                  {
                    v61 = "HFI_QUEUE_FULL";
                  }
                  else
                  {
LABEL_295:
                    v61 = nullptr;
                  }
                }
                else if ( v60 == 1000 )
                {
                  v61 = "HFI_ERR_COMMAND_SIZE";
                }
                else
                {
                  v61 = "HFI_ERR_MESSAGE_SIZE";
                }
              }
              else
              {
                v61 = "SUCCESS";
                switch ( v60 )
                {
                  case 0:
                    break;
                  case 1:
                    v61 = "EFAILED";
                    break;
                  case 2:
                    v61 = "ENOMEMORY";
                    break;
                  case 3:
                    v61 = "EBADSTATE";
                    break;
                  case 4:
                    v61 = "EBADPARM";
                    break;
                  case 5:
                    v61 = "EBADITEM";
                    break;
                  case 6:
                    v61 = "EINVALIDFORMAT";
                    break;
                  case 7:
                    v61 = "EUNSUPPORTED";
                    break;
                  case 8:
                    v61 = "EOUTOFBOUND";
                    break;
                  case 9:
                    v61 = "ETIMEDOUT";
                    break;
                  case 10:
                    v61 = "EABORTED";
                    break;
                  case 11:
                    v61 = "EHWVIOLATION";
                    break;
                  case 12:
                    v61 = "ECDMERROR";
                    break;
                  default:
                    goto LABEL_295;
                }
              }
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_process_msg_config_io",
                2890,
                "rc = %d failed with\nerr_no = [%u] err_type = [%s]",
                v59,
                v60,
                v61);
LABEL_108:
              v9 = 0;
LABEL_109:
              if ( *(_BYTE *)v35 == 1 )
                mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v36);
              if ( mem_trace_en == 1 )
                v8 = cam_mem_trace_free((_QWORD *)v35, 0);
              else
                v8 = (_QWORD *)kvfree(v35);
              if ( !v9 )
                goto LABEL_308;
              goto LABEL_307;
            }
            if ( v37 )
            {
              if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100,
                  4,
                  "cam_icp_mgr_process_msg_config_io",
                  2902,
                  "%s: received IPE config io response",
                  (const char *)(v37 + 29824));
              *(_DWORD *)(v37 + 76) = v10[9];
LABEL_235:
              complete(v37 + 29192);
              goto LABEL_108;
            }
            v70 = 2896;
            v71 = "wrong ctx data from IPE config io response";
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_process_msg_config_io",
            v70,
            v71);
          v9 = -22;
          goto LABEL_109;
        }
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          v8 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           debug_mdl & 0x100,
                           4,
                           "cam_icp_process_msg_pkt_type",
                           3532,
                           "[%s] received ASYNC_DIRECT_ACK",
                           (const char *)(a1 + 112));
          if ( !v10 )
            goto LABEL_306;
        }
        else if ( !v10 )
        {
          goto LABEL_306;
        }
        v31 = *(_QWORD *)(v10 + 3);
        if ( !v31 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_process_direct_ack_msg",
            3230,
            "Invalid ctx_info, opcode: %d",
            v10[2]);
          goto LABEL_316;
        }
        v32 = *(unsigned int *)(v31 + 4);
        v33 = *(_QWORD *)(v31 + 16);
        v34 = v10[2];
        if ( v33 != *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v32) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_mgr_process_direct_ack_msg",
            3240,
            "ctx data is released before accessing it, ctx_id: %uopcode: %d",
            v32,
            v34);
          goto LABEL_241;
        }
        if ( v34 > 7 )
        {
          switch ( v34 )
          {
            case 8:
              goto LABEL_194;
            case 14:
              v68 = debug_mdl;
              if ( (debug_mdl & 0x100) == 0 || debug_priority )
                goto LABEL_240;
              v82 = v10[7];
              v83 = *(_DWORD *)(v33 + 104);
              v81 = cam_icp_error_handle_id_to_type();
              v54 = v68 & 0x100;
              v55 = v33 + 29824;
              v56 = 3282;
              v57 = "%s: received\nMAP ACK:ctx_state =%d\nfailed with err_no = [%u] err_type = [%s]";
              break;
            case 15:
              v53 = debug_mdl;
              if ( (debug_mdl & 0x100) == 0 || debug_priority )
                goto LABEL_240;
              v82 = v10[7];
              v83 = *(_DWORD *)(v33 + 104);
              v81 = cam_icp_error_handle_id_to_type();
              v54 = v53 & 0x100;
              v55 = v33 + 29824;
              v56 = 3290;
              v57 = "%s: received UNMAP ACK:ctx_state =%d\nfailed with err_no = [%u] err_type = [%s]";
              break;
            default:
              goto LABEL_199;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, __int64))cam_print_log)(
            3,
            v54,
            4,
            "cam_icp_mgr_process_direct_ack_msg",
            v56,
            v57,
            v55,
            v83,
            v82,
            v81);
        }
        else
        {
          switch ( v34 )
          {
            case 3:
LABEL_154:
              if ( (cam_presil_mode_enabled(v8) & 1) != 0 && *(_DWORD *)(v84 + 3208) )
              {
                if ( *(_DWORD *)(v84 + 3212) == *(_DWORD *)(v33 + 29224) )
                {
                  if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x8000000,
                      4,
                      "cam_icp_mgr_process_direct_ack_msg",
                      3251,
                      "%s: presil: frame process abort",
                      (const char *)(v33 + 29824));
                  *(_DWORD *)(v84 + 3212) = -1;
                  *(_DWORD *)(v84 + 3208) = 0;
                  up_write(&frame_in_process_sem);
                }
                else
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                    3,
                    0x8000000,
                    2,
                    "cam_icp_mgr_process_direct_ack_msg",
                    3259,
                    "%s: presil: abort mismatch frame_in_process_ctx_id: %d",
                    v33 + 29824);
                }
              }
              if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, __int64))cam_print_log)(
                  3,
                  debug_mdl & 0x100,
                  4,
                  "cam_icp_mgr_process_direct_ack_msg",
                  3265,
                  "%s: received ABORT: ctx_state =%d",
                  v33 + 29824,
                  *(unsigned int *)(v33 + 104),
                  v79,
                  v80);
              break;
            case 4:
LABEL_194:
              if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100,
                  4,
                  "cam_icp_mgr_process_direct_ack_msg",
                  3271,
                  "%s: received DESTROY: ctx_state =%d",
                  (const char *)(v33 + 29824),
                  *(_DWORD *)(v33 + 104));
              if ( (*(_DWORD *)(v33 + 104) | 2) != 3 )
              {
LABEL_241:
                v9 = 0;
                goto LABEL_242;
              }
              break;
            case 7:
              goto LABEL_154;
            default:
LABEL_199:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_process_direct_ack_msg",
                3295,
                "Invalid opcode : %u",
                v34);
              v9 = -22;
LABEL_242:
              if ( mem_trace_en == 1 )
                v8 = cam_mem_trace_free((_QWORD *)v31, 0);
              else
                v8 = (_QWORD *)kvfree(v31);
              if ( !v9 )
                goto LABEL_308;
              goto LABEL_307;
          }
        }
LABEL_240:
        complete(v33 + 29192);
        goto LABEL_241;
      }
      if ( v12 != 67239944 )
      {
        if ( v12 != 67239946 )
        {
          if ( v12 != 67239950 )
            goto LABEL_97;
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_process_msg_pkt_type",
              3527,
              "[%s] received OFE ASYNC INDIRECT COMMAND ACK",
              (const char *)(a1 + 112));
          v13 = v10[2];
          if ( v13 == 2 )
          {
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              v40 = debug_mdl & 0x100;
              v41 = "cam_icp_mgr_process_ofe_indirect_ack_msg";
              v42 = 3200;
              v43 = "received OFE_FRAME_PROCESS:";
LABEL_318:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                v40,
                4,
                v41,
                v42,
                v43);
            }
LABEL_121:
            v8 = (_QWORD *)cam_icp_mgr_process_msg_frame_process(a1, v10);
            v9 = (unsigned int)v8;
            if ( !(_DWORD)v8 )
              goto LABEL_308;
            goto LABEL_307;
          }
          if ( v13 != 1 )
          {
            v44 = "cam_icp_mgr_process_ofe_indirect_ack_msg";
            v45 = 3205;
LABEL_137:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              v44,
              v45,
              "Invalid opcode : %u",
              v13);
            goto LABEL_306;
          }
          v14 = *(_QWORD *)(v10 + 3);
          if ( v14 )
          {
            v15 = *(_QWORD *)(v14 + 16);
            v16 = *(int *)(v14 + 4);
            if ( v15 )
            {
              if ( (*(_BYTE *)v14 & 1) != 0 )
                mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * (int)v16);
              if ( v15 == *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v16) )
              {
                v65 = v10[8];
                if ( v65 )
                {
                  v66 = v10[7];
                  if ( v66 > 999 )
                  {
                    if ( v66 > 1001 )
                    {
                      if ( v66 == 1002 )
                      {
                        v67 = "HFI_QUEUE_EMPTY";
                      }
                      else if ( v66 == 1003 )
                      {
                        v67 = "HFI_QUEUE_FULL";
                      }
                      else
                      {
LABEL_269:
                        v67 = nullptr;
                      }
                    }
                    else if ( v66 == 1000 )
                    {
                      v67 = "HFI_ERR_COMMAND_SIZE";
                    }
                    else
                    {
                      v67 = "HFI_ERR_MESSAGE_SIZE";
                    }
                  }
                  else
                  {
                    v67 = "SUCCESS";
                    switch ( v66 )
                    {
                      case 0:
                        break;
                      case 1:
                        v67 = "EFAILED";
                        break;
                      case 2:
                        v67 = "ENOMEMORY";
                        break;
                      case 3:
                        v67 = "EBADSTATE";
                        break;
                      case 4:
                        v67 = "EBADPARM";
                        break;
                      case 5:
                        v67 = "EBADITEM";
                        break;
                      case 6:
                        v67 = "EINVALIDFORMAT";
                        break;
                      case 7:
                        v67 = "EUNSUPPORTED";
                        break;
                      case 8:
                        v67 = "EOUTOFBOUND";
                        break;
                      case 9:
                        v67 = "ETIMEDOUT";
                        break;
                      case 10:
                        v67 = "EABORTED";
                        break;
                      case 11:
                        v67 = "EHWVIOLATION";
                        break;
                      case 12:
                        v67 = "ECDMERROR";
                        break;
                      default:
                        goto LABEL_269;
                    }
                  }
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    256,
                    1,
                    "cam_icp_mgr_process_msg_ofe_config_io",
                    3100,
                    "rc : %u, error type: %u error: [%s] opcode :%u",
                    v65,
                    v66,
                    v67,
                    v10[2]);
                }
                else
                {
                  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x100,
                      4,
                      "cam_icp_mgr_process_msg_ofe_config_io",
                      3105,
                      "%s: received OFE config io response",
                      (const char *)(v15 + 29824));
                  complete(v15 + 29192);
                }
              }
              else
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  256,
                  2,
                  "cam_icp_mgr_process_msg_ofe_config_io",
                  3092,
                  "ctx data is released before accessing it, ctx_id: %u",
                  v16);
              }
              if ( *(_BYTE *)v14 == 1 )
                mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v16);
              if ( mem_trace_en == 1 )
                v8 = cam_mem_trace_free((_QWORD *)v14, 0);
              else
                v8 = (_QWORD *)kvfree(v14);
              v9 = 0;
              goto LABEL_308;
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_mgr_process_msg_ofe_config_io",
              3083,
              "wrong ctx data from OFE config io response, ctx_id: %u",
              v16);
            v9 = -22;
            goto LABEL_307;
          }
          v38 = "cam_icp_mgr_process_msg_ofe_config_io";
          v39 = 3075;
          v47 = "wrong ctx info from OFE config io response";
LABEL_133:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            v38,
            v39,
            v47);
LABEL_134:
          v9 = -22;
          goto LABEL_307;
        }
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          v8 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           debug_mdl & 0x100,
                           4,
                           "cam_icp_process_msg_pkt_type",
                           3521,
                           "[%s] received OFE ASYNC DIRECT COMMAND ACK",
                           (const char *)(a1 + 112));
          if ( !v10 )
            goto LABEL_306;
        }
        else if ( !v10 )
        {
          goto LABEL_306;
        }
        v21 = *(_QWORD *)(v10 + 3);
        if ( !v21 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_process_ofe_direct_ack_msg",
            3134,
            "Invalid ctx_info, opcode: %d",
            v10[2]);
          goto LABEL_134;
        }
        v26 = *(unsigned int *)(v21 + 4);
        v27 = *(_QWORD *)(v21 + 16);
        v28 = v10[2];
        if ( v27 != *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v26) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_mgr_process_ofe_direct_ack_msg",
            3143,
            "ctx data is released before accessing it, ctx_id: %u opcode: %d",
            v26,
            v28);
          goto LABEL_217;
        }
        if ( v28 != 4 )
        {
          if ( v28 == 3 )
          {
            if ( (cam_presil_mode_enabled(v8) & 1) != 0 && *(_DWORD *)(v84 + 3208) )
            {
              v48 = *(_DWORD *)(v84 + 3212);
              v49 = *(_DWORD *)(v27 + 29224);
              if ( v48 == v49 )
              {
                if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x8000000,
                    4,
                    "cam_icp_mgr_process_ofe_direct_ack_msg",
                    3153,
                    "presil: frame process abort ctx %d",
                    v48);
                *(_DWORD *)(v84 + 3212) = -1;
                *(_DWORD *)(v84 + 3208) = 0;
                up_write(&frame_in_process_sem);
              }
              else
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x8000000,
                  2,
                  "cam_icp_mgr_process_ofe_direct_ack_msg",
                  3160,
                  "presil: abort mismatch %d %d",
                  v48,
                  v49);
              }
            }
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_mgr_process_ofe_direct_ack_msg",
                3166,
                "received OFE Abort done msg ctx_state: %u",
                *(_DWORD *)(v27 + 104));
            goto LABEL_215;
          }
          v62 = "cam_icp_mgr_process_ofe_direct_ack_msg";
          v63 = 3179;
          v64 = "Invalid opcode : %u";
          v29 = v28;
LABEL_193:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            256,
            1,
            v62,
            v63,
            v64,
            v29);
          v9 = -22;
LABEL_218:
          if ( mem_trace_en == 1 )
          {
            v8 = cam_mem_trace_free((_QWORD *)v21, 0);
            if ( !v9 )
              goto LABEL_308;
          }
          else
          {
            v8 = (_QWORD *)kvfree(v21);
            if ( !v9 )
              goto LABEL_308;
          }
          goto LABEL_307;
        }
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_process_ofe_direct_ack_msg",
            3171,
            "received OFE destroy done msg: %u",
            *(_DWORD *)(v27 + 104));
        if ( (*(_DWORD *)(v27 + 104) | 2) != 3 )
        {
LABEL_217:
          v9 = 0;
          goto LABEL_218;
        }
LABEL_215:
        v50 = v27 + 29192;
        goto LABEL_216;
      }
LABEL_50:
      if ( (debug_mdl & 0x100) == 0 || debug_priority )
      {
        if ( v10 )
          goto LABEL_53;
LABEL_281:
        v72 = "cam_icp_mgr_process_msg_create_handle";
        v73 = 2949;
        v74 = "Invalid create_handle_ack";
LABEL_305:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          v72,
          v73,
          v74);
        goto LABEL_306;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_process_msg_pkt_type",
        3509,
        "[%s] received IPE/BPS/OFE CREATE_HANDLE_ACK",
        (const char *)(a1 + 112));
      if ( !v10 )
        goto LABEL_281;
LABEL_53:
      v21 = *((_QWORD *)v10 + 2);
      if ( v21 )
      {
        v22 = *(unsigned int *)(v21 + 4);
        v23 = *(_QWORD *)(v21 + 16);
        if ( v23 == *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v22) )
        {
          if ( v23 )
          {
            if ( *(_DWORD *)(v23 + 104) == 1 )
            {
              v46 = debug_mdl;
              v9 = 0;
              *(_DWORD *)(v23 + 72) = v10[3];
              if ( (v46 & 0x100) != 0 && !debug_priority )
              {
                ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                  3,
                  v46 & 0x100,
                  4,
                  "cam_icp_mgr_process_msg_create_handle",
                  2976,
                  "%s: fw_handle = %x",
                  v23 + 29824);
                v9 = 0;
              }
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                256,
                2,
                "cam_icp_mgr_process_msg_create_handle",
                2980,
                "%s: This ctx is no longer in use current state: %d",
                v23 + 29824);
              v9 = -1;
              *(_DWORD *)(v23 + 72) = 0;
            }
            complete(v23 + 29192);
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_mgr_process_msg_create_handle",
              2968,
              "Invalid ctx_data, ctx_id: %d",
              v22);
            v9 = -22;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_mgr_process_msg_create_handle",
            2962,
            "ctx data is released before accessing it, ctx_id: %u",
            v22);
          v9 = 0;
        }
        goto LABEL_218;
      }
      v38 = "cam_icp_mgr_process_msg_create_handle";
      v39 = 2956;
LABEL_132:
      v47 = "Invalid ctx_info";
      goto LABEL_133;
    }
    break;
  }
  if ( v12 <= 131077 )
  {
    if ( v12 == 131073 )
    {
      if ( (debug_mdl & 0x100) == 0 || debug_priority )
        goto LABEL_58;
      v17 = debug_mdl & 0x100;
      v18 = a1 + 112;
      v19 = 3491;
      v20 = "[%s] received SYS_INIT_DONE";
    }
    else
    {
      if ( v12 != 131074 )
        goto LABEL_97;
      if ( (debug_mdl & 0x100) == 0 || debug_priority )
        goto LABEL_58;
      v17 = debug_mdl & 0x100;
      v18 = a1 + 112;
      v19 = 3497;
      v20 = "[%s] HFI_MSG_SYS_PC_PREP_DONE is received\n";
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v17,
      4,
      "cam_icp_process_msg_pkt_type",
      v19,
      v20,
      v18);
    goto LABEL_58;
  }
  if ( v12 == 131078 )
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_process_msg_pkt_type",
        3502,
        "[%s] received SYS_PING_ACK",
        (const char *)(a1 + 112));
      if ( v10 )
        goto LABEL_88;
    }
    else if ( v10 )
    {
LABEL_88:
      v21 = *((_QWORD *)v10 + 1);
      if ( v21 )
      {
        v29 = *(unsigned int *)(v21 + 4);
        v30 = *(_QWORD *)(v21 + 16);
        if ( v30 != *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v29) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_mgr_process_msg_ping_ack",
            3015,
            "ctx data is released before accessing it, ctx_id: %u",
            v29);
          goto LABEL_217;
        }
        if ( !v30 )
        {
          v62 = "cam_icp_mgr_process_msg_ping_ack";
          v63 = 3021;
          v64 = "Invalid ctx_data, ctx_id: %d";
          goto LABEL_193;
        }
        if ( *(_DWORD *)(v30 + 104) != 1 )
          goto LABEL_217;
        v50 = v30 + 29192;
LABEL_216:
        complete(v50);
        goto LABEL_217;
      }
      v38 = "cam_icp_mgr_process_msg_ping_ack";
      v39 = 3009;
      goto LABEL_132;
    }
    v72 = "cam_icp_mgr_process_msg_ping_ack";
    v73 = 3002;
    v74 = "Empty ping ack message";
    goto LABEL_305;
  }
  if ( v12 != 131080 )
  {
    if ( v12 != 16908296 )
      goto LABEL_97;
    goto LABEL_50;
  }
  v24 = debug_priority;
  v25 = debug_mdl & 0x100;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v8 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     v25,
                     4,
                     "cam_icp_process_msg_pkt_type",
                     3537,
                     "[%s] received EVENT_NOTIFY",
                     (const char *)(a1 + 112));
    v24 = debug_priority;
    v25 = debug_mdl & 0x100;
    if ( (debug_mdl & 0x100) != 0 )
      goto LABEL_62;
  }
  else if ( (debug_mdl & 0x100) != 0 )
  {
LABEL_62:
    if ( !v24 )
      v8 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       v25,
                       4,
                       "cam_icp_mgr_process_fatal_error",
                       3377,
                       "%s: Enter",
                       (const char *)(a1 + 112));
  }
  if ( !v10 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_fatal_error",
      3381,
      "[%s] Empty event message",
      (const char *)(a1 + 112));
    v9 = -22;
LABEL_118:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_process_msg_pkt_type",
      3542,
      "[%s] failed in processing evt notify and failed in triggering recovery",
      (const char *)(a1 + 112));
    goto LABEL_307;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    v8 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 0x100,
                     4,
                     "cam_icp_mgr_process_fatal_error",
                     3387,
                     "[%s] evt_id: %u evt_data1: %u evt_data2: %u",
                     (const char *)(a1 + 112),
                     v10[3],
                     v10[4],
                     v10[5]);
  if ( v10[3] != 1 )
  {
    v9 = 0;
    goto LABEL_308;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    3,
    "cam_icp_mgr_process_fatal_error",
    3391,
    "[%s] received HFI_EVENT_SYS_ERROR",
    (const char *)(a1 + 112));
  if ( v10[4] != 1 )
  {
    v8 = (_QWORD *)cam_icp_mgr_trigger_recovery(a1);
    v9 = (unsigned int)v8;
    if ( !(_DWORD)v8 )
      goto LABEL_308;
    goto LABEL_118;
  }
  v78 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_process_fatal_error",
          3394,
          "[%s] received HFI_ERR_SYS_FATAL",
          (const char *)(a1 + 112));
  __break(0x800u);
  return cam_icp_mgr_trigger_recovery(v78);
}
