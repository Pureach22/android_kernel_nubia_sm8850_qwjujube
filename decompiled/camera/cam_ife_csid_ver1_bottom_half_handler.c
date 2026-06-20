__int64 __fastcall cam_ife_csid_ver1_bottom_half_handler(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // x19
  int v4; // w8
  unsigned int ***v5; // x9
  __int64 v6; // x25
  char *v7; // x23
  unsigned int *v8; // x21
  unsigned int v9; // w10
  int v10; // w27
  __int64 v11; // x6
  __int64 v12; // x7
  int v13; // w26
  __int64 result; // x0
  int v15; // w8
  unsigned int v16; // w9
  __int16 v17; // w19
  int v18; // w19
  unsigned int v19; // w0
  __int64 v20; // x0
  int v21; // w21
  int v22; // w8
  _DWORD *v23; // x8
  __int64 v24; // x0
  void *v25; // x23
  __int64 v26; // x21
  __int64 v27; // x8
  __int64 v28; // x22
  _DWORD *v29; // x20
  __int64 *v30; // x8
  __int64 v31; // x8
  unsigned int v32; // w26
  char **irq_reg_tag_ptr; // x0
  __int64 v34; // x7
  char **v35; // x28
  unsigned __int64 v36; // x24
  __int64 *v37; // x19
  bool v38; // cc
  __int64 v39; // x9
  int *v40; // x10
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x0
  int v44; // w8
  _DWORD *v45; // x8
  __int64 v46; // x0
  unsigned __int16 v47; // w0
  __int64 v48; // x7
  const char *v49; // x7
  char v50; // [xsp+0h] [xbp-80h]
  __int64 *v51; // [xsp+8h] [xbp-78h]
  __int64 *v52; // [xsp+10h] [xbp-70h]
  __int64 v53; // [xsp+18h] [xbp-68h]
  _DWORD *v55; // [xsp+28h] [xbp-58h] BYREF
  int v56; // [xsp+34h] [xbp-4Ch] BYREF
  unsigned __int64 v57; // [xsp+38h] [xbp-48h] BYREF
  __int64 v58; // [xsp+40h] [xbp-40h] BYREF
  __int64 v59; // [xsp+48h] [xbp-38h]
  __int64 v60; // [xsp+50h] [xbp-30h]
  __int64 v61; // [xsp+58h] [xbp-28h]
  int *v62; // [xsp+60h] [xbp-20h]
  int v63; // [xsp+6Ch] [xbp-14h] BYREF
  __int64 v64; // [xsp+70h] [xbp-10h]
  __int64 v65; // [xsp+78h] [xbp-8h]

  v3 = a1;
  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = a2[5];
    v55 = a2;
    if ( !v4 )
    {
LABEL_44:
      v25 = v3 + 6810;
      v26 = 2;
      v27 = **((_QWORD **)v3 + 2);
      v28 = v27 + 24;
      v51 = (__int64 *)(v27 + 16);
      v52 = (__int64 *)(v27 + 8);
      v53 = v27 + 64;
      while ( 1 )
      {
        v29 = v55 + 4;
        if ( v55[v26 + 4] )
        {
          if ( (int)v26 > 6 )
          {
            if ( (unsigned int)(v26 - 9) < 3 )
            {
              v30 = (__int64 *)(v53 + 8 * v26 - 72);
LABEL_55:
              v31 = *v30;
              if ( v31 )
              {
                v57 = 0;
                if ( v55 )
                {
                  v32 = *(_DWORD *)(v31 + 300) & v29[v26];
                  memset(v25, 0, 0x400u);
                  irq_reg_tag_ptr = cam_ife_csid_get_irq_reg_tag_ptr();
                  if ( v32 )
                  {
                    v35 = irq_reg_tag_ptr;
                    v36 = 0;
                    v37 = (__int64 *)&ver1_path_irq_desc;
                    do
                    {
                      if ( (v32 & 1) != 0 )
                      {
                        if ( v36 > 0x16 )
                          __break(0x5512u);
                        v39 = v37[3];
                        v40 = (int *)v37[4];
                        v60 = v37[2];
                        v61 = v39;
                        v42 = *v37;
                        v41 = v37[1];
                        v62 = v40;
                        v58 = v42;
                        v59 = v41;
                        cam_print_to_buffer((__int64)v25, 0x400u, &v57, 1u, 8u, "%s\n", (__int64)&v58, v34, v50);
                      }
                      v38 = v32 > 1;
                      ++v36;
                      v37 += 5;
                      v32 >>= 1;
                    }
                    while ( v38 );
                    v3 = a1;
                    if ( v57 )
                    {
                      if ( (unsigned int)__ratelimit(
                                           &cam_ife_csid_ver1_path_bottom_half_handler__rs,
                                           "cam_ife_csid_ver1_path_bottom_half_handler") )
                        v43 = 3;
                      else
                        v43 = 2;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        v43,
                        8,
                        1,
                        "cam_ife_csid_ver1_path_bottom_half_handler",
                        4195,
                        "CSID[%u] %s: %s",
                        *(_DWORD *)(*(_QWORD *)a1 + 4LL),
                        v35[v26],
                        (const char *)v25);
                    }
                  }
                  if ( (v29[v26] & 4) != 0 )
                  {
                    v44 = v55[23];
                    v58 = 0;
                    LODWORD(v59) = 0;
                    v63 = 64;
                    HIDWORD(v59) = v44;
                    v64 = 0;
                    v60 = 0;
                    v61 = 0;
                    v62 = &v63;
                    if ( (debug_mdl & 8) != 0 && !debug_priority )
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 8,
                        4,
                        "cam_ife_csid_ver1_handle_event_err",
                        3939,
                        "CSID[%d] Error type %d",
                        *(_DWORD *)(*(_QWORD *)v3 + 4LL),
                        64);
                    v45 = *((_DWORD **)v3 + 3550);
                    v46 = *((_QWORD *)v3 + 4);
                    if ( *(v45 - 1) != 414296116 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, _QWORD, __int64 *))v45)(v46, 0, &v58);
                  }
                }
                else
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_ife_csid_ver1_path_bottom_half_handler",
                    4172,
                    "Invalid Param csid_hw %pK evt_payload %pK",
                    v3,
                    nullptr);
                }
              }
              goto LABEL_46;
            }
            v30 = v52;
            if ( (_DWORD)v26 == 7 )
              goto LABEL_55;
            v30 = v51;
            if ( (_DWORD)v26 == 8 )
              goto LABEL_55;
          }
          else if ( (unsigned int)(v26 - 2) < 5 )
          {
            v30 = (__int64 *)(v28 + 8 * v26 - 16);
            goto LABEL_55;
          }
        }
LABEL_46:
        if ( ++v26 == 16 )
        {
          cam_ife_csid_ver1_put_evt_payload((__int64)v3, &v55, (__int64)(v3 + 478));
          result = 1;
          goto LABEL_77;
        }
      }
    }
    v6 = *((_QWORD *)a1 + 1);
    v5 = *((unsigned int ****)a1 + 2);
    v7 = (char *)(a1 + 6144);
    v57 = 0;
    v8 = **v5;
    v9 = v8[73];
    v56 = a1[7066];
    v10 = v9 & v4;
    memset(a1 + 6810, 0, 0x400u);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver1_rx_bottom_half_handler",
      4026,
      "IRQ_Status: 0x%x",
      a2[5]);
    if ( !v10 )
    {
      v13 = 0;
      goto LABEL_22;
    }
    cam_print_to_buffer((__int64)(v3 + 6810), 0x400u, &v57, 1u, 8u, "Fatal Errors:\n", v11, v12, v50);
    if ( (v10 & 0x8000) != 0 )
    {
      cam_print_to_buffer(
        (__int64)(v3 + 6810),
        0x400u,
        &v57,
        1u,
        8u,
        "RX_ERROR_LANE0_FIFO_OVERFLOW: Skew/Less Data on lanes/ Slow csid clock:%luHz\n",
        *(_QWORD *)(v6 + 2896),
        v12,
        v50);
      v13 = 512;
      if ( (v10 & 0x10000) == 0 )
        goto LABEL_12;
    }
    else
    {
      v13 = 0;
      if ( (v10 & 0x10000) == 0 )
      {
LABEL_12:
        if ( (v10 & 0x20000) != 0 )
        {
          cam_print_to_buffer(
            (__int64)(v3 + 6810),
            0x400u,
            &v57,
            1u,
            8u,
            "RX_ERROR_LANE2_FIFO_OVERFLOW: Skew/Less Data on lanes/ Slow csid clock:%luHz\n",
            *(_QWORD *)(v6 + 2896),
            v12,
            v50);
          v13 = 512;
          if ( (v10 & 0x40000) == 0 )
          {
LABEL_14:
            if ( (v10 & 0x4000000) == 0 )
              goto LABEL_15;
            goto LABEL_80;
          }
        }
        else if ( (v10 & 0x40000) == 0 )
        {
          goto LABEL_14;
        }
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "RX_ERROR_LANE3_FIFO_OVERFLOW: Skew/Less Data on lanes/ Slow csid clock:%luHz\n",
          *(_QWORD *)(v6 + 2896),
          v12,
          v50);
        v13 = 512;
        if ( (v10 & 0x4000000) == 0 )
        {
LABEL_15:
          if ( (v10 & 0x2000) == 0 )
            goto LABEL_16;
          goto LABEL_81;
        }
LABEL_80:
        v13 |= 0x40u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "RX_ERROR_TPG_FIFO_OVERFLOW: Backpressure from IFE\n",
          v11,
          v12,
          v50);
        if ( (v10 & 0x2000) == 0 )
        {
LABEL_16:
          if ( (v10 & 0x800000) == 0 )
            goto LABEL_17;
          goto LABEL_82;
        }
LABEL_81:
        v13 |= 0x400u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "CPHY_PH_CRC: Pkt Hdr CRC mismatch\n",
          v11,
          v12,
          v50);
        if ( (v10 & 0x800000) == 0 )
        {
LABEL_17:
          if ( (v10 & 0x100000) == 0 )
            goto LABEL_18;
          goto LABEL_83;
        }
LABEL_82:
        v13 |= 0x800u;
        v47 = cam_io_r_mb(*(_QWORD *)(v6 + 384) + v8[14]);
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "ERROR_STREAM_UNDERFLOW: Fewer bytes rcvd than WC:%d in pkt hdr\n",
          v47,
          v48,
          v50);
        if ( (v10 & 0x100000) == 0 )
        {
LABEL_18:
          if ( (v10 & 0x1000000) == 0 )
            goto LABEL_19;
          goto LABEL_84;
        }
LABEL_83:
        v13 |= 0x400u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "DPHY_ERROR_ECC: Pkt hdr errors unrecoverable\n",
          v11,
          v12,
          v50);
        if ( (v10 & 0x1000000) == 0 )
        {
LABEL_19:
          if ( (v10 & 0x800) == 0 )
            goto LABEL_20;
          goto LABEL_85;
        }
LABEL_84:
        v13 |= 0x2000u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "UNBOUNDED_FRAME: Frame started with EOF or No EOF\n",
          v11,
          v12,
          v50);
        if ( (v10 & 0x800) == 0 )
        {
LABEL_20:
          if ( (v10 & 0x80000) == 0 )
            goto LABEL_22;
          goto LABEL_21;
        }
LABEL_85:
        if ( v3[7067] )
          v49 = "cphy";
        else
          v49 = "dphy";
        v13 |= 0x8000u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "CPHY_EOT_RECEPTION: No EOT on lane/s, is_EPD: %d, PHY_Type: %s(%u)\n",
          (unsigned int)v3[7073],
          (__int64)v49,
          *((_DWORD *)v7 + 923));
        if ( (v10 & 0x80000) == 0 )
          goto LABEL_22;
LABEL_21:
        v13 |= 0x10000u;
        cam_print_to_buffer(
          (__int64)(v3 + 6810),
          0x400u,
          &v57,
          1u,
          8u,
          "CPHY_ERROR_CRC: Long pkt payload CRC mismatch\n",
          v11,
          v12,
          v50);
LABEL_22:
        v15 = a2[5];
        v16 = v8[74];
        v17 = v16 & v15;
        if ( (v16 & v15) != 0 )
        {
          cam_print_to_buffer((__int64)(a1 + 6810), 0x400u, &v57, 1u, 8u, "Recoverable-errors:\n", v11, v12, v50);
          if ( (v17 & 0x1000) != 0 )
            cam_print_to_buffer(
              (__int64)(a1 + 6810),
              0x400u,
              &v57,
              1u,
              8u,
              "CPHY_SOT_RECEPTION: Less SOTs on lane/s\n",
              v11,
              v12,
              v50);
        }
        v18 = v8[75] & a2[5];
        if ( v18 )
        {
          cam_print_to_buffer((__int64)(a1 + 6810), 0x400u, &v57, 1u, 8u, "Non-fatal errors:\n", v11, v12, v50);
          if ( (v18 & 0x200000) != 0 )
          {
            v19 = cam_io_r_mb(*(_QWORD *)(v6 + 384) + v8[14]);
            cam_print_to_buffer(
              (__int64)(a1 + 6810),
              0x400u,
              &v57,
              1u,
              8u,
              "MMAPPED_VC_DT: VC:%d DT:%d mapped to more than 1 csid paths\n",
              v19 >> 22,
              HIWORD(v19) & 0x3F,
              v50);
          }
        }
        v3 = a1;
        if ( v57 )
        {
          if ( (unsigned int)__ratelimit(
                               &cam_ife_csid_ver1_rx_bottom_half_handler__rs,
                               "cam_ife_csid_ver1_rx_bottom_half_handler") )
            v20 = 3;
          else
            v20 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v20,
            8,
            1,
            "cam_ife_csid_ver1_rx_bottom_half_handler",
            4140,
            "CSID[%u] %s",
            *(_DWORD *)(*(_QWORD *)a1 + 4LL),
            (const char *)a1 + 27240);
        }
        if ( (v7[3745] & 1) == 0 && v7[3741] == 1 )
        {
          if ( v13 )
            v21 = v13;
          else
            v21 = 32;
          cam_subdev_notify_message(65544, 1u, (__int64)&v56);
          v22 = a2[23];
          v58 = 0;
          LODWORD(v59) = 0;
          v64 = 0;
          HIDWORD(v59) = v22;
          v60 = 0;
          v61 = 0;
          v63 = v21;
          v62 = &v63;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver1_handle_event_err",
              3939,
              "CSID[%d] Error type %d",
              *(_DWORD *)(*(_QWORD *)a1 + 4LL),
              v21);
          v23 = *((_DWORD **)a1 + 3550);
          v24 = *((_QWORD *)a1 + 4);
          if ( *(v23 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 *))v23)(v24, 0, &v58);
          v7[3745] = 1;
          v3 = a1;
        }
        goto LABEL_44;
      }
    }
    cam_print_to_buffer(
      (__int64)(v3 + 6810),
      0x400u,
      &v57,
      1u,
      8u,
      "RX_ERROR_LANE1_FIFO_OVERFLOW: Skew/Less Data on lanes/ Slow csid clock:%luHz\n",
      *(_QWORD *)(v6 + 2896),
      v12,
      v50);
    v13 = 512;
    goto LABEL_12;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver1_bottom_half_handler",
    4219,
    "Invalid Param handler_priv %pK evt_payload_priv %pK",
    a1,
    a2);
  result = 4294967274LL;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
