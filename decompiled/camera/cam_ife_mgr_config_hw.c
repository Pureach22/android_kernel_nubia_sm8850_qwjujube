__int64 __fastcall cam_ife_mgr_config_hw(char *a1, const void **a2)
{
  char *v3; // x21
  unsigned int *v4; // x19
  __int64 result; // x0
  char v6; // w8
  const void *v7; // x23
  __int64 v8; // x22
  char *v9; // x26
  const void *v10; // x9
  char *v11; // x21
  const void *v12; // x9
  char v13; // w8
  int v14; // w22
  __int64 v15; // x0
  unsigned int v16; // w22
  __int64 v17; // x0
  __int64 v18; // x0
  _BYTE *v19; // x23
  __int64 v20; // x0
  unsigned int v21; // w6
  unsigned int v22; // w19
  int v23; // w0
  unsigned int v24; // w0
  __int64 v25; // x7
  const char *v26; // x5
  __int64 v27; // x4
  unsigned int v28; // w0
  unsigned int v29; // w6
  unsigned int updated; // w0
  __int64 v31; // x0
  int v32; // w24
  unsigned int v33; // w0
  int v34; // w0
  unsigned int v35; // w22
  __int64 v36; // x0
  __int64 v37; // x22
  const void *v38; // x8
  char *v39; // x8
  int v40; // w8
  int v41; // w27
  int v42; // w24
  __int64 v43; // x8
  const char *v44; // x22
  unsigned int v45; // w8
  __int64 v46; // x26
  int v47; // w8
  int v48; // w6
  int v49; // w9
  int v50; // w9
  const char *v51; // x23
  __int64 v52; // x22
  int v53; // w8
  __int64 v54; // x0
  unsigned __int64 v55; // x7
  unsigned __int64 v56; // x8
  __int64 v57; // x0
  unsigned __int64 v58; // x8
  unsigned __int16 *v59; // x28
  int v60; // w6
  unsigned int v61; // w0
  const void *v62; // x6
  __int64 v63; // x7
  const char *v64; // x5
  __int64 v65; // x4
  char v66; // w8
  unsigned int v67; // w0
  unsigned int v68; // w8
  unsigned int v69; // w22
  __int64 v70; // x7
  unsigned int v71; // w0
  unsigned int v72; // w7
  unsigned __int16 *v73; // x19
  unsigned __int16 *v74; // x0
  __int64 v75; // x0
  unsigned int v76; // [xsp+0h] [xbp-60h]
  unsigned __int16 *v77; // [xsp+18h] [xbp-48h]
  int v78; // [xsp+2Ch] [xbp-34h]
  __int64 v79; // [xsp+30h] [xbp-30h]
  __int64 v80; // [xsp+40h] [xbp-20h]
  __int64 v81; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v82[2]; // [xsp+50h] [xbp-10h] BYREF

  v3 = a1;
  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  v82[0] = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      7885,
      "Invalid arguments, hw_mgr_priv=%pK, config_hw_args=%pK",
      a1,
      a2);
    goto LABEL_13;
  }
  v4 = (unsigned int *)*a2;
  if ( !*a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      7893,
      "Invalid context is used");
    goto LABEL_13;
  }
  if ( *((_BYTE *)v4 + 9376) != 1 || !*((_QWORD *)v4 + 1092) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      7900,
      "Invalid context parameters : ctx_index %u, ctx_in_use=%d, cdm_cmd=%pK",
      v4[14]);
    result = 0xFFFFFFFFLL;
    goto LABEL_14;
  }
  if ( v4[2211] )
  {
    result = 0xFFFFFFFFLL;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_config_hw",
        7907,
        "Ctx[%pK][%u] Overflow pending, cannot apply req %llu",
        *a2,
        v4[14],
        a2[6]);
      result = 0xFFFFFFFFLL;
    }
    goto LABEL_14;
  }
  if ( v4[2362] )
  {
    if ( (unsigned __int64)a2[6] > *((_QWORD *)v4 + 1182) + 1LL )
    {
      v6 = debug_mdl;
      v4[2362] = 0;
      *((_QWORD *)v4 + 1182) = 0;
      if ( (v6 & 8) != 0 && !debug_priority )
        a1 = (char *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       v6 & 8,
                       4,
                       "cam_ife_mgr_config_hw",
                       7922,
                       "Ctx[%pK][%u] Reset overflow recovery count for req %llu",
                       v4,
                       v4[14],
                       a2[6]);
    }
  }
  v7 = a2[6];
  v8 = 0;
  v9 = v3 + 81328;
  while ( 1 )
  {
    if ( v9[v8 + 8] == 1 )
    {
      v10 = *(const void **)&v9[v8];
      if ( v10 == v7 || v10 == (const void *)0xFFFFFFFFLL )
      {
        a1 = (char *)cam_ife_hw_mgr_irq_inject_or_dump_desc(v3, &v9[v8 - 16], 0);
        if ( (_DWORD)a1 )
          break;
      }
    }
    v8 += 40;
    if ( v8 == 400 )
      goto LABEL_28;
  }
  a1 = (char *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_mgr_config_hw",
                 7928,
                 "Failed to inject IRQ at req %d",
                 (unsigned int)a2[6]);
LABEL_28:
  v11 = (char *)a2[5];
  *(_QWORD *)v11 = v4;
  v12 = a2[6];
  v13 = debug_mdl;
  *((_QWORD *)v4 + 1177) = v11;
  *((_QWORD *)v4 + 1178) = v12;
  if ( (v13 & 8) != 0 && !debug_priority )
  {
    a1 = (char *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   v13 & 8,
                   4,
                   "cam_ife_mgr_config_hw",
                   7936,
                   "Ctx[%pK][%u] : Applying Req %lld, init_packet=%d",
                   v4,
                   v4[14],
                   a2[6],
                   *((unsigned __int8 *)a2 + 60));
    if ( !*((_DWORD *)a2 + 14) )
      goto LABEL_48;
  }
  else if ( !*((_DWORD *)a2 + 14) )
  {
    goto LABEL_48;
  }
  if ( *((_BYTE *)a2 + 61) == 1 )
  {
    if ( *((_QWORD *)v4 + 1107) >= (unsigned __int64)a2[6] )
    {
      if ( (unsigned int)__ratelimit(&cam_ife_mgr_config_hw__rs_853, "cam_ife_mgr_config_hw") )
        v18 = 3;
      else
        v18 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v18,
        8,
        1,
        "cam_ife_mgr_config_hw",
        7960,
        "CDM callback received, should wait for buf done for req: %lld, ctx_idx: %u",
        a2[6],
        v4[14]);
      result = 4294967182LL;
      goto LABEL_14;
    }
    v14 = cam_cdm_detect_hang_error(v4[2180]);
    if ( (unsigned int)__ratelimit(&cam_ife_mgr_config_hw__rs, "cam_ife_mgr_config_hw") )
      v15 = 3;
    else
      v15 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v15,
      8,
      1,
      "cam_ife_mgr_config_hw",
      7944,
      "ctx_idx: %u CDM callback not received for req: %lld, last_cdm_done_req: %lld, is_cdm_hung: %d",
      v4[14],
      a2[6],
      *((_QWORD *)v4 + 1107),
      v14 == 0);
    if ( v14 )
      cam_cdm_dump_debug_registers(v4[2180]);
    a1 = (char *)cam_cdm_reset_hw(v4[2180]);
    if ( (_DWORD)a1 )
    {
      v16 = (unsigned int)a1;
      if ( (unsigned int)__ratelimit(&cam_ife_mgr_config_hw__rs_851, "cam_ife_mgr_config_hw") )
        v17 = 3;
      else
        v17 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v17,
        8,
        1,
        "cam_ife_mgr_config_hw",
        7953,
        "CDM reset unsuccessful for req: %lld. ctx: %u, rc: %d",
        a2[6],
        v4[14],
        v16);
      result = v16;
      *((_QWORD *)v4 + 1107) = 0;
      goto LABEL_14;
    }
    *((_QWORD *)v4 + 1107) = 0;
  }
LABEL_48:
  if ( v11[3988] == 1 )
  {
    a1 = (char *)cam_isp_blob_path_exp_order_update(v4, a2[6], v11);
    if ( (_DWORD)a1 )
      a1 = (char *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_ife_mgr_config_hw",
                     7970,
                     "Exp order update failed for req: %llu rc:%d ctx_idx=%u",
                     a2[6],
                     (_DWORD)a1,
                     v4[14]);
  }
  v19 = v11 + 4096;
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_mgr_config_hw",
      7975,
      "Presil Mode - Skipping CLK BW Update");
    goto LABEL_53;
  }
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000008,
      4,
      "cam_ife_mgr_config_hw",
      7984,
      "ctx_idx=%u, bw_config_version=%d config_valid[BW VFE_CLK SFE_CLK]:[%d %d %d]",
      v4[14],
      v4[2358],
      (unsigned __int8)v11[1800],
      (unsigned __int8)v11[1872],
      (unsigned __int8)v11[1944]);
    if ( (v4[2350] & 1) == 0 )
    {
LABEL_58:
      if ( v11[1992] != 1 )
        goto LABEL_61;
    }
  }
  else if ( (v4[2350] & 1) == 0 )
  {
    goto LABEL_58;
  }
  v23 = cam_isp_mgr_drv_config(v4, a2[6], (unsigned __int8)v11[4290], v11);
  if ( v23 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      7993,
      "DRV config failed for req: %llu rc:%d ctx_idx=%u",
      a2[6],
      v23,
      v4[14]);
LABEL_61:
  if ( v11[1872] == 1 )
  {
    v24 = cam_isp_blob_ife_clock_update(v11 + 1808, v4);
    if ( v24 )
    {
      v25 = v4[14];
      v26 = "Clock Update Failed, rc=%d, ctx_idx=%u";
      v22 = v24;
      v27 = 8007;
LABEL_82:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_ife_mgr_config_hw",
        v27,
        v26,
        v22,
        v25);
      goto LABEL_153;
    }
  }
  if ( v11[1944] == 1 )
  {
    v28 = cam_isp_blob_sfe_clock_update(v11 + 1880, v4);
    if ( v28 )
    {
      v25 = v4[14];
      v26 = "Clock Update Failed, rc=%d, ctx_idx=%u";
      v22 = v28;
      v27 = 8017;
      goto LABEL_82;
    }
  }
  if ( v11[1800] == 1 )
  {
    v29 = v4[2358];
    if ( v29 - 2 >= 2 )
    {
      if ( v29 == 1 )
      {
        v33 = cam_isp_blob_bw_update(v11 + 40, v4);
        if ( v33 )
        {
          v25 = v4[14];
          v26 = "Bandwidth Update Failed rc: %d, ctx_idx=%u";
          v22 = v33;
          v27 = 8029;
          goto LABEL_82;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          1,
          "cam_ife_mgr_config_hw",
          8043,
          "Invalid bw config version: %d, ctx_idx=%u",
          v29,
          v4[14]);
      }
    }
    else
    {
      updated = cam_isp_blob_bw_update_v2(v11 + 192, v4);
      if ( updated )
      {
        v25 = v4[14];
        v26 = "Bandwidth Update Failed rc: %d, ctx_idx=%u";
        v22 = updated;
        v27 = 8038;
        goto LABEL_82;
      }
    }
  }
  v34 = cam_ife_mgr_finish_clk_bw_update(v4, a2[6], 0);
  if ( v34 )
  {
    v35 = v34;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      8051,
      "Failed in finishing clk/bw update rc: %d, ctx_idx=%u",
      v34,
      v4[14]);
    cam_ife_mgr_print_blob_info(v4, a2[6], v11);
    result = v35;
    goto LABEL_14;
  }
LABEL_53:
  v20 = cam_ife_mgr_apply_fcg_update(v4, v11, a2);
  if ( (_DWORD)v20 )
  {
    v21 = v4[14];
    v22 = v20;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      8059,
      "Failed in updating FCG values %u",
      v21);
    goto LABEL_153;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v36 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_config_hw",
            8065,
            "Enter ctx id:%u num_hw_upd_entries %d request id: %llu",
            v4[14],
            *((_DWORD *)a2 + 2),
            a2[6]);
    v31 = cam_presil_mode_enabled(v36);
    if ( (v31 & 1) != 0 )
      goto LABEL_91;
  }
  else
  {
    v31 = cam_presil_mode_enabled(v20);
    if ( (v31 & 1) != 0 )
      goto LABEL_91;
  }
  if ( (*((_BYTE *)a2 + 60) & 1) == 0 && (v11[4288] & 1) == 0 && (byte_3A857E & 1) == 0 && (v4[2329] & 2) == 0 )
  {
    v32 = 0;
    goto LABEL_92;
  }
LABEL_91:
  v32 = 1;
LABEL_92:
  if ( !*((_DWORD *)a2 + 2) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_config_hw",
      8303,
      "No commands to config, ctx_index %u",
      v4[14]);
    result = 0;
LABEL_173:
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_14;
    v70 = v4[14];
    v22 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const void *, __int64, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_config_hw",
      8306,
      "Exit: Config Done: %llu, ctx_index %u rc %d",
      a2[6],
      v70,
      result);
LABEL_153:
    result = v22;
    goto LABEL_14;
  }
  v37 = *((_QWORD *)v4 + 1092);
  *(_DWORD *)(v37 + 16) = 0;
  *(_QWORD *)(v37 + 8) = v4;
  v38 = a2[6];
  *(_BYTE *)(v37 + 1) = 0;
  *(_BYTE *)v37 = v32;
  *(_QWORD *)(v37 + 24) = v11 + 4248;
  *(_QWORD *)(v37 + 32) = v38;
  v39 = (char *)(v4 + 2216);
  if ( !v32 )
    v39 = nullptr;
  *(_QWORD *)(v37 + 40) = v39;
  v40 = *((_DWORD *)a2 + 2);
  if ( !v40 )
  {
    v46 = 0;
LABEL_143:
    *(_DWORD *)(v37 + 20) = v40;
    if ( (cam_presil_mode_enabled(v31) & 1) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_mgr_config_hw",
        8203,
        "Sending relevant buffers for request:%llu to presil, ctx_idx=%u",
        a2[6],
        v4[14]);
      v61 = cam_presil_send_buffers_from_packet(*((unsigned int **)v11 + 530), dword_394938, dword_394940);
      if ( v61 )
      {
        v62 = a2[6];
        v63 = v4[14];
        v64 = "Error sending buffers for request:%llu to presil, ctx=%u";
        v22 = v61;
        v65 = 8210;
LABEL_152:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const void *, __int64, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_config_hw",
          v65,
          v64,
          v62,
          v63,
          v76);
        goto LABEL_153;
      }
    }
    v4[2216] = 0;
    v66 = debug_mdl;
    *((_QWORD *)v4 + 1163) = a2[6];
    if ( (v66 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v66 & 8,
        4,
        "cam_ife_mgr_config_hw",
        8218,
        "Submit to CDM, ctx_idx=%u",
        v4[14]);
      if ( !v32 )
      {
LABEL_150:
        v67 = cam_cdm_submit_bls(v4[2180], v37);
        if ( v67 )
        {
          v68 = v4[14];
          v62 = a2[6];
          v22 = v67;
          v64 = "Failed to apply the configs for req %llu, rc %d ctx_idx=%u";
          v65 = 8227;
          v63 = v67;
          v76 = v68;
          goto LABEL_152;
        }
        if ( v32 )
        {
          if ( cam_common_wait_for_completion_timeout((__int64)(v4 + 2216)) )
          {
            if ( *(_QWORD *)(v37 + 40) )
            {
              *((_QWORD *)v4 + 1107) = *(_QWORD *)(v37 + 32);
              v4[2212] = 1;
              ktime_get_clocktai_ts64((__int64 *)v4 + 1186);
              ktime_get_boottime_ts64((__int64 *)v4 + 1188);
            }
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_config_hw",
                8270,
                "config done Success for req_id=%llu ctx_index %u",
                a2[6],
                v4[14]);
            if ( v19[192] == 1 )
            {
              v4[2360] = *((_DWORD *)v11 + 1070);
              v4[2361] = *((_DWORD *)v11 + 1071);
              v4[2497] = *((_DWORD *)v11 + 1073);
            }
            v19[192] = 0;
            v69 = 0;
            if ( *((_BYTE *)a2 + 60) != 1 )
              goto LABEL_167;
            if ( (byte_3A8575 & 1) == 0 )
              cam_ife_mgr_handle_reg_dump(v4, v11 + 3992, *((unsigned int *)v11 + 1058), 13);
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_config_hw",
              8238,
              "config done completion timeout for req_id=%llu ctx_index %u",
              a2[6],
              v4[14]);
            v71 = cam_cdm_detect_hang_error(v4[2180]);
            if ( (v71 & 0x80000000) == 0 )
            {
              v69 = v71;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_mgr_config_hw",
                  8252,
                  "Wq delayed but IRQ CDM done, ctx_index %u",
                  v4[14]);
              goto LABEL_167;
            }
            v75 = cam_cdm_dump_debug_registers(v4[2180]);
            v69 = -110;
            if ( (cam_presil_mode_enabled(v75) & 1) == 0
              || !v46
              || (v69 = 0, (debug_mdl & 0x400000) == 0)
              || debug_priority )
            {
LABEL_167:
              cam_ife_mgr_send_frame_event(a2[6], v4[14]);
              if ( !dword_3A88C8 )
                goto LABEL_171;
              if ( v4[15] != 8 )
                cam_ife_hw_mgr_print_debug_reg(v4, 0, 7);
              if ( v4[16] != 8 )
              {
                cam_ife_hw_mgr_print_debug_reg(v4, 0, 7);
                result = v69;
              }
              else
              {
LABEL_171:
                result = v69;
              }
              goto LABEL_173;
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x400000,
              4,
              "cam_ife_mgr_config_hw",
              8245,
              "PRESIL-HACK for CSIM config_hw always times out %u",
              *(_DWORD *)(v46 + 12));
          }
        }
        v69 = 0;
        goto LABEL_167;
      }
    }
    else if ( !v32 )
    {
      goto LABEL_150;
    }
    v4[2212] = 0;
    goto LABEL_150;
  }
  v78 = v32;
  v41 = 0;
  v42 = 0;
  v79 = v37;
  v43 = v37 + 48;
  v44 = "cam_ife_mgr_config_hw";
  v80 = v43;
  while ( 1 )
  {
    v46 = (__int64)a2[2] + 32 * v42;
    v47 = *((_DWORD *)a2 + 14);
    v48 = *(_DWORD *)(v46 + 12);
    if ( v47 == 1 )
    {
      if ( v48 == 3 )
        goto LABEL_97;
    }
    else if ( v47 == 2 && v48 == 2 )
    {
      goto LABEL_97;
    }
    if ( v48 == 5 )
    {
      if ( (*((_BYTE *)a2 + 60) & 1) == 0 )
        goto LABEL_97;
    }
    else if ( (unsigned int)(v48 - 6) <= 0xFFFFFFFA )
    {
      v31 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              v44,
              8108,
              "Unexpected BL type %d, ctx_idx=%u",
              v48,
              v4[14]);
    }
    if ( v19[266] == 1 && v42 == *((_DWORD *)v11 + 1082) )
    {
      v49 = (unsigned __int8)v19[264];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v31 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                v44,
                8115,
                "IFE/MC_TFE FCG hw entry is detected, num_ent: %d, ctx_idx: %u, request id: %llu, use current cfg: %d",
                v42,
                v4[14],
                a2[6],
                v49);
        if ( (v19[264] & 1) != 0 )
          goto LABEL_97;
      }
      else if ( (v49 & 1) != 0 )
      {
        goto LABEL_97;
      }
    }
    if ( v19[265] != 1 || v42 != *((_DWORD *)v11 + 1075) )
      goto LABEL_119;
    v50 = (unsigned __int8)v19[264];
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      break;
    if ( (v50 & 1) == 0 )
      goto LABEL_119;
LABEL_97:
    ++v41;
LABEL_98:
    v45 = *((_DWORD *)a2 + 2);
    if ( ++v42 >= v45 )
    {
      v37 = v79;
      v32 = v78;
      v40 = v45 - v41;
      goto LABEL_143;
    }
  }
  v31 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          v44,
          8127,
          "SFE FCG hw entry is detected, num_ent: %d, ctx_idx: %u, request id: %llu, use current cfg: %d",
          v42,
          v4[14],
          a2[6],
          v50);
  if ( (v19[264] & 1) != 0 )
    goto LABEL_97;
LABEL_119:
  if ( *(_BYTE *)(v46 + 24) == 1 )
    goto LABEL_97;
  v51 = v44;
  if ( *(_DWORD *)(v46 + 12) == 4 )
    *(_BYTE *)(v46 + 24) = 1;
  v52 = v80 + 24LL * (v42 - v41);
  *(_DWORD *)v52 = *(_DWORD *)v46;
  *(_DWORD *)(v52 + 8) = *(_DWORD *)(v46 + 4);
  v53 = *(_DWORD *)(v46 + 8);
  *(_BYTE *)(v52 + 17) = 0;
  *(_DWORD *)(v52 + 12) = v53;
  if ( byte_3A857C != 1 )
    goto LABEL_134;
  if ( (unsigned int)__ratelimit(&cam_ife_mgr_config_hw__rs_868, v51) )
    v54 = 3;
  else
    v54 = 2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    v54,
    8,
    3,
    v51,
    8148,
    "Enter cdm cmd_buf validation");
  if ( (unsigned int)cam_packet_util_get_cmd_mem_addr(*(_DWORD *)v52, &v81, v82) )
  {
    v31 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            v51,
            8156,
            "Failed to get buf_addr and len for mem_handle: %d ctx id: %u request id: %llu",
            *(_DWORD *)v52,
            v4[14],
            a2[6]);
    v44 = v51;
LABEL_135:
    v19 = v11 + 4096;
    goto LABEL_98;
  }
  v56 = *(unsigned int *)(v52 + 8);
  v55 = *(unsigned int *)(v52 + 12);
  if ( v82[0] <= v56 || v82[0] - v56 < v55 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_ife_mgr_config_hw",
      8165,
      "invalid mem len:%u cmd_inplen:%u off:%u",
      LODWORD(v82[0]),
      v55,
      *(_DWORD *)(v52 + 8));
    goto LABEL_184;
  }
  v57 = v81 + v56;
  v58 = v81 + v56 + v55;
  v59 = (unsigned __int16 *)(v58 - 1);
  if ( !v42 )
  {
    v60 = *(unsigned __int8 *)(v57 + 3);
    if ( v60 != 8 )
    {
      v72 = v4[14];
      v73 = (unsigned __int16 *)v57;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_config_hw",
        8179,
        "first cmd in cmd_buf is not change_base, cmd_type: %u ctx id: %u request id: %llu",
        v60,
        v72,
        a2[6]);
      v74 = v73;
      goto LABEL_183;
    }
  }
  v77 = (unsigned __int16 *)v57;
  if ( (cam_cdm_util_validate_cmd_buf((_DWORD *)v57, v58 - 1) & 1) == 0 )
  {
    v31 = cam_mem_put_cpu_buf(*(_DWORD *)v52);
LABEL_134:
    v44 = v51;
    goto LABEL_135;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_config_hw",
    8189,
    "found invalid cmd in cmd_buf, ctx id: %u request id: %llu",
    v4[14],
    a2[6]);
  v74 = v77;
LABEL_183:
  cam_cdm_util_dump_cmd_buf(v74, v59);
LABEL_184:
  cam_mem_put_cpu_buf(*(_DWORD *)v52);
LABEL_13:
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
