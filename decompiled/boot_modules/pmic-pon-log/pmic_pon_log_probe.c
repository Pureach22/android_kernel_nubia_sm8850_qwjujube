__int64 __fastcall pmic_pon_log_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x0
  unsigned __int64 v6; // x25
  unsigned __int64 *v7; // x0
  __int64 v8; // x22
  int v9; // w0
  int v10; // w2
  int v11; // w3
  bool v12; // cc
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 *v15; // x8
  __int64 v16; // x0
  int v17; // w0
  int v18; // w23
  int v19; // w8
  int v20; // w9
  int v21; // w22
  unsigned int v22; // w23
  __int64 v24; // x8
  __int64 v25; // x9
  int v26; // w11
  unsigned int v27; // w8
  unsigned int v28; // w24
  unsigned int v29; // w8
  __int64 v30; // x26
  __int64 v31; // x1
  __int64 v32; // x0
  __int64 v33; // x2
  char *v34; // x3
  unsigned int v35; // w26
  unsigned int v36; // w25
  __int64 v37; // x12
  unsigned int v38; // w24
  int v39; // w28
  _UNKNOWN **v40; // x8
  unsigned int v41; // w0
  __int64 v42; // x2
  unsigned int v43; // w25
  char v44; // w26
  void *v45; // x3
  unsigned int v46; // w8
  __int64 v47; // x2
  char **v48; // x3
  unsigned int v49; // w0
  __int64 v50; // x1
  char *v51; // x0
  unsigned int v52; // w0
  unsigned int v53; // w25
  char v54; // w26
  const char *v55; // x3
  _UNKNOWN **v56; // x8
  unsigned int v57; // w28
  int v58; // w24
  int v59; // w26
  char v60; // w8
  unsigned int v61; // w0
  unsigned int v62; // w25
  int v63; // w0
  const char *v64; // x3
  unsigned int v65; // w8
  const char *v66; // x24
  unsigned int v67; // w0
  __int64 v68; // x8
  char v69; // w11
  int v70; // w9
  __int64 v71; // x12
  __int64 v72; // x10
  int v73; // w13
  bool v74; // vf
  unsigned __int8 *v75; // x11
  __int64 v76; // x20
  int v77; // w13
  __int64 v78; // x2
  __int64 v79; // x8
  const char *v80; // x0
  int v81; // w8
  char v82; // [xsp+4h] [xbp-BCh]
  __int64 v83; // [xsp+8h] [xbp-B8h]
  _BYTE v84[4]; // [xsp+14h] [xbp-ACh] BYREF
  _BYTE v85[4]; // [xsp+18h] [xbp-A8h] BYREF
  int v86; // [xsp+1Ch] [xbp-A4h] BYREF
  __int64 v87; // [xsp+20h] [xbp-A0h] BYREF
  int v88; // [xsp+28h] [xbp-98h]
  char v89[128]; // [xsp+30h] [xbp-90h] BYREF
  __int64 v90; // [xsp+B0h] [xbp-10h]

  v1 = a1 + 16;
  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v88 = 0;
  v87 = 0;
  v84[0] = 0;
  v3 = devm_kmalloc(a1 + 16, 48, 3520);
  if ( !v3 )
    goto LABEL_27;
  v4 = (_QWORD *)v3;
  v5 = *(_QWORD *)(a1 + 760);
  *v4 = v1;
  LODWORD(v6) = of_count_phandle_with_args(v5, "nvmem", 0);
  if ( (v6 & 0x80000000) != 0 )
  {
    if ( (_DWORD)v6 != -517 )
    {
      dev_err(v1, "failed to get nvmem count, ret=%d\n", v6);
      goto LABEL_28;
    }
    goto LABEL_13;
  }
  if ( !(_DWORD)v6 )
  {
    dev_err(v1, "nvmem property empty\n");
    LODWORD(v6) = -22;
    goto LABEL_28;
  }
  *((_DWORD *)v4 + 10) = v6;
  v7 = (unsigned __int64 *)devm_kmalloc(v1, 8LL * (unsigned int)v6, 3520);
  v4[4] = v7;
  if ( !v7 )
    goto LABEL_27;
  if ( *((int *)v4 + 10) >= 1 )
  {
    scnprintf(&v87, 12, "pon_log%d", 0);
    *(_QWORD *)v4[4] = devm_nvmem_device_get(v1, &v87);
    v7 = (unsigned __int64 *)v4[4];
    v6 = *v7;
    if ( *v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)v4[4] = devm_nvmem_device_get(v1, "pon_log");
      v7 = (unsigned __int64 *)v4[4];
      v6 = *v7;
    }
    if ( v6 > 0xFFFFFFFFFFFFF000LL )
    {
      LODWORD(v8) = 0;
LABEL_10:
      if ( (_DWORD)v6 != -517 )
      {
        dev_err(v1, "failed to get nvmem device %d, ret=%d\n", v8, v6);
        goto LABEL_28;
      }
LABEL_13:
      LODWORD(v6) = -517;
      goto LABEL_28;
    }
    if ( *((int *)v4 + 10) >= 2 )
    {
      v8 = 1;
      do
      {
        scnprintf(&v87, 12, "pon_log%d", v8);
        *(_QWORD *)(v4[4] + 8 * v8) = devm_nvmem_device_get(v1, &v87);
        v7 = (unsigned __int64 *)v4[4];
        v6 = v7[v8];
        if ( v6 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_10;
      }
      while ( ++v8 < *((int *)v4 + 10) );
    }
  }
  v9 = nvmem_device_read(*v7, 69, 1, v84);
  if ( v9 < 0 )
  {
    LODWORD(v6) = v9;
    goto LABEL_28;
  }
  v10 = *((_DWORD *)v4 + 10);
  v11 = v84[0] + 1;
  v12 = v10 <= v84[0];
  *((_DWORD *)v4 + 11) = v11;
  if ( v12 )
  {
    dev_err(v1, "Missing nvmem handles; found %d, expected %d\n", v10, v11);
    LODWORD(v6) = -19;
    goto LABEL_28;
  }
  *((_DWORD *)v4 + 5) = (unsigned int)(117 * v11) >> 2;
  v13 = devm_kmalloc(v1, (117 * v11) & 0xFFFCLL, 3520);
  v4[1] = v13;
  if ( !v13 )
  {
LABEL_27:
    LODWORD(v6) = -12;
    goto LABEL_28;
  }
  v14 = ipc_log_context_create(3, "pmic_pon", 0);
  v15 = (__int64 *)v4[4];
  v4[3] = v14;
  *(_QWORD *)(a1 + 168) = v4;
  v16 = *v15;
  v86 = 0;
  v85[0] = 0;
  v17 = nvmem_device_read(v16, 70, 1, v85);
  if ( (v17 & 0x80000000) == 0 )
  {
    v18 = v85[0];
    if ( (unsigned int)v85[0] - 192 <= 0xFFFFFF8A )
    {
      dev_err(*v4, "unexpected PON log end address: %02X\n", v85[0]);
LABEL_198:
      LODWORD(v6) = -22;
      goto LABEL_199;
    }
    v17 = nvmem_device_read(*(_QWORD *)v4[4], 71, 1, v85);
    if ( (v17 & 0x80000000) == 0 )
    {
      v19 = *((_DWORD *)v4 + 11);
      if ( v19 > v85[0] )
      {
        v20 = *((_DWORD *)v4 + 5);
        if ( v20 >= 1 )
        {
          v21 = 0;
          v22 = ((117 * v19) & ((v18 + 117 * v85[0] - 4 * v20 - 75) >> 31)) + 117 * v85[0] + v18 - 4 * v20 - 75;
          do
          {
            v27 = v22 % (117 * *((_DWORD *)v4 + 11));
            v28 = v27 / 0x75;
            v29 = v27 % 0x75;
            if ( v29 < 0x72 )
            {
              v31 = v29 + 75;
              v34 = (char *)&v86;
              v33 = 4;
              v32 = *(_QWORD *)(v4[4] + 8LL * v28);
            }
            else
            {
              v30 = 117 - v29;
              v17 = nvmem_device_read(*(_QWORD *)(v4[4] + 8LL * v28), v29 + 75, v30, &v86);
              if ( v17 < 0 )
                goto LABEL_194;
              v31 = 75;
              v32 = *(_QWORD *)(v4[4] + 8LL * (unsigned int)((int)(v28 + 1) % *((_DWORD *)v4 + 11)));
              v33 = 4 - v30;
              v34 = (char *)&v86 + v30;
            }
            LODWORD(v6) = nvmem_device_read(v32, v31, v33, v34);
            if ( (v6 & 0x80000000) != 0 )
              goto LABEL_199;
            v35 = BYTE2(v86);
            v36 = HIBYTE(v86);
            if ( (_WORD)v86 || __PAIR16__(BYTE2(v86), 0) != HIBYTE(v86) )
            {
              v37 = v4[3];
              v89[0] = 0;
              if ( (unsigned __int8)(BYTE1(v86) - 16) >= 0x7Fu )
              {
                if ( BYTE1(v86) > 0xCu )
                  v38 = 0;
                else
                  v38 = 0x16C2u >> SBYTE1(v86);
              }
              else
              {
                v38 = 1;
              }
              v39 = HIBYTE(v86) | (BYTE2(v86) << 8);
              memset(&v89[1], 0, 127);
              v83 = v37;
              switch ( BYTE1(v86) )
              {
                case 1:
                  v82 = v38;
                  if ( v39 <= 1599 )
                  {
                    if ( v39 > 134 )
                    {
                      switch ( v39 )
                      {
                        case 135:
                          v40 = &off_7670;
                          goto LABEL_171;
                        case 514:
                          v40 = &off_7680;
                          goto LABEL_171;
                        case 1569:
                          v40 = (_UNKNOWN **)&unk_7690;
                          goto LABEL_171;
                      }
                    }
                    else
                    {
                      switch ( v39 )
                      {
                        case 132:
                          v40 = &pmic_pon_pon_trigger_map;
                          goto LABEL_171;
                        case 133:
                          v40 = &off_7650;
                          goto LABEL_171;
                        case 134:
                          v40 = &off_7660;
                          goto LABEL_171;
                      }
                    }
                  }
                  else if ( v39 <= 10082 )
                  {
                    switch ( v39 )
                    {
                      case 1600:
                        v40 = (_UNKNOWN **)&unk_76A0;
                        goto LABEL_171;
                      case 6304:
                        v40 = (_UNKNOWN **)&unk_76B0;
                        goto LABEL_171;
                      case 6336:
                        v40 = (_UNKNOWN **)&unk_76C0;
                        goto LABEL_171;
                    }
                  }
                  else if ( v39 > 29121 )
                  {
                    if ( v39 == 29122 )
                    {
                      v40 = (_UNKNOWN **)&unk_76F0;
                      goto LABEL_171;
                    }
                    if ( v39 == 34610 )
                    {
                      v40 = &off_7700;
                      goto LABEL_171;
                    }
                  }
                  else
                  {
                    if ( v39 == 10083 )
                    {
                      v40 = (_UNKNOWN **)&unk_76D0;
                      goto LABEL_171;
                    }
                    if ( v39 == 12738 )
                    {
                      v40 = (_UNKNOWN **)&unk_76E0;
LABEL_171:
                      v66 = (const char *)v40[1];
                      v67 = scnprintf(v89, 128, "PON Trigger: ");
                      goto LABEL_182;
                    }
                  }
                  v67 = scnprintf(v89, 128, "PON Trigger: ");
LABEL_186:
                  if ( v67 > 0x80 )
                    goto LABEL_226;
                  scnprintf(
                    &v89[v67],
                    128 - v67,
                    "SID=0x%X, PID=0x%02X, IRQ=0x%X",
                    (v35 >> 4) & 0xFFFFFFEF | (16 * ((v36 >> 3) & 1)),
                    (unsigned __int8)((unsigned int)v39 >> 4),
                    v36 & 7);
LABEL_188:
                  if ( (v82 & 1) != 0 )
LABEL_189:
                    printk(&unk_7AD8, v89);
LABEL_108:
                  if ( (unsigned __int8)v86 > 7uLL )
                    ipc_log_string(v83, "State=Unknown (0x%02X); %s\n", (unsigned __int8)v86, v89);
                  else
                    ipc_log_string(v83, "State=%s; %s\n", pmic_pon_state_label[(unsigned __int8)v86], v89);
                  v24 = *((int *)v4 + 4);
                  v25 = v4[1];
                  v26 = v86;
                  *((_DWORD *)v4 + 4) = v24 + 1;
                  *(_DWORD *)(v25 + 4 * v24) = v26;
                  break;
                case 2:
                  scnprintf(v89, 128, "OTP Copy Complete: last addr written=0x%04X", (unsigned int)v39);
                  goto LABEL_107;
                case 3:
                  scnprintf(v89, 128, "Trim Complete: %u bytes written", (unsigned int)v39);
                  goto LABEL_107;
                case 4:
                  scnprintf(v89, 128, "XVLO Check Complete");
                  if ( (v38 & 1) != 0 )
                    goto LABEL_189;
                  goto LABEL_108;
                case 5:
                  scnprintf(v89, 128, "PMICs Detected: SID Mask=0x%04X", (unsigned int)v39);
                  goto LABEL_107;
                case 6:
                  v82 = v38;
                  if ( v39 > 134 )
                  {
                    if ( v39 <= 8674 )
                    {
                      switch ( v39 )
                      {
                        case 135:
                          v56 = &off_7780;
                          break;
                        case 4560:
                          v56 = (_UNKNOWN **)&unk_77B0;
                          break;
                        case 8656:
                          v56 = (_UNKNOWN **)&unk_77C0;
                          break;
                        default:
                          goto LABEL_185;
                      }
                    }
                    else if ( v39 > 16847 )
                    {
                      if ( v39 == 16848 )
                      {
                        v56 = (_UNKNOWN **)&unk_77D0;
                      }
                      else
                      {
                        if ( v39 != 20944 )
                        {
LABEL_185:
                          v67 = scnprintf(v89, 128, "Reset Trigger: ");
                          goto LABEL_186;
                        }
                        v56 = (_UNKNOWN **)&unk_77E0;
                      }
                    }
                    else if ( v39 == 8675 )
                    {
                      v56 = (_UNKNOWN **)&unk_7790;
                    }
                    else
                    {
                      if ( v39 != 12789 )
                        goto LABEL_185;
                      v56 = (_UNKNOWN **)&unk_77A0;
                    }
                  }
                  else if ( v39 <= 130 )
                  {
                    switch ( v39 )
                    {
                      case 128:
                        v56 = &pmic_pon_reset_trigger_map;
                        break;
                      case 129:
                        v56 = &off_7720;
                        break;
                      case 130:
                        v56 = &off_7730;
                        break;
                      default:
                        goto LABEL_185;
                    }
                  }
                  else if ( v39 > 132 )
                  {
                    if ( v39 == 133 )
                      v56 = &off_7760;
                    else
                      v56 = &off_7770;
                  }
                  else if ( v39 == 131 )
                  {
                    v56 = &off_7740;
                  }
                  else
                  {
                    v56 = &off_7750;
                  }
                  v66 = (const char *)v56[1];
                  v67 = scnprintf(v89, 128, "Reset Trigger: ");
LABEL_182:
                  if ( !v66 )
                    goto LABEL_186;
                  if ( v67 > 0x80 )
                    goto LABEL_226;
                  scnprintf(&v89[v67], 128 - v67, "%s", v66);
                  goto LABEL_188;
                case 7:
                  if ( HIBYTE(v86) > 7u || ((0x6DuLL >> SHIBYTE(v86)) & 1) != 0 )
                  {
                    scnprintf(v89, 128, "Reset Type: UNKNOWN (%u)", HIBYTE(v86));
                    if ( (v38 & 1) == 0 )
                      goto LABEL_108;
                  }
                  else
                  {
                    scnprintf(v89, 128, "Reset Type: %s", *((const char **)&pmic_pon_reset_type_label + HIBYTE(v86)));
                    if ( (v38 & 1) == 0 )
                      goto LABEL_108;
                  }
                  goto LABEL_189;
                case 8:
                  scnprintf(v89, 128, "Warm Reset Count: %u", (unsigned int)v39);
                  goto LABEL_107;
                case 9:
                  if ( HIBYTE(v86) )
                  {
                    v57 = v38;
                    v58 = v38 ^ 1;
                  }
                  else
                  {
                    v59 = 1;
                    v57 = 0;
                    v60 = (BYTE2(v86) != 0) & v38;
                    v58 = 1;
                    if ( (v60 & 1) != 0 )
                      goto LABEL_131;
                  }
                  v61 = scnprintf(v89, 128, "FAULT_REASON1=");
                  if ( v61 > 0x80 )
                    goto LABEL_226;
                  v62 = v61;
                  v63 = pmic_pon_log_print_reason(&v89[v61], 128 - v61, HIBYTE(v86), pmic_pon_fault_reason1);
                  if ( ((BYTE2(v86) == 0) & ~v58) != 0 )
                  {
                    if ( (v57 & 1) == 0 )
                      goto LABEL_108;
                    goto LABEL_189;
                  }
                  v36 = v63 + v62;
                  if ( v36 > 0x80 )
                    goto LABEL_226;
                  v59 = v57;
                  v58 = HIBYTE(v86) == 0;
LABEL_131:
                  if ( (v58 & v59) != 0 )
                    v64 = (const char *)&unk_7A17;
                  else
                    v64 = "; ";
                  v65 = scnprintf(&v89[v36], 128 - v36, "%sFAULT_REASON2=", v64) + v36;
                  if ( v65 > 0x80 )
                    goto LABEL_226;
                  pmic_pon_log_print_reason(&v89[v65], 128 - v65, BYTE2(v86), pmic_pon_fault_reason2);
                  if ( (v59 & 1) == 0 )
                    goto LABEL_108;
                  goto LABEL_189;
                case 0xA:
                  v49 = scnprintf(v89, 128, "FAULT_REASON3=");
                  if ( v49 > 0x80 )
                    goto LABEL_226;
                  v47 = HIBYTE(v86);
                  v48 = pmic_pon_fault_reason3;
                  LOBYTE(v38) = (v36 != 0) & v38;
                  v50 = 128 - v49;
                  v51 = &v89[v49];
                  goto LABEL_89;
                case 0xB:
                  scnprintf(v89, 128, "PBS PC at Fault: 0x%04X", (unsigned int)v39);
LABEL_107:
                  if ( (v38 & 1) == 0 )
                    goto LABEL_108;
                  goto LABEL_189;
                case 0xC:
                  if ( !HIBYTE(v86) )
                    LOBYTE(v38) = (BYTE2(v86) != 0) & v38;
                  v41 = scnprintf(v89, 128, "Fundamental Reset: ");
                  v43 = v41;
                  if ( !BYTE2(v86) && (v38 & 1) != 0 )
                    goto LABEL_60;
                  if ( v41 > 0x80 )
                    goto LABEL_226;
                  v44 = v38;
                  v38 = scnprintf(&v89[v41], 128 - v41, "PON_PBL_STATUS=") + v41;
                  if ( v38 > 0x80 )
                    goto LABEL_226;
                  v43 = pmic_pon_log_print_reason(&v89[v38], 128 - v38, BYTE2(v86), pmic_pon_pon_pbl_status) + v38;
                  LOBYTE(v38) = v44;
LABEL_60:
                  if ( ((HIBYTE(v86) == 0) & (unsigned __int8)v38) != 0 )
                    goto LABEL_189;
                  if ( v43 > 0x80 )
                    goto LABEL_226;
                  v45 = ((BYTE2(v86) == 0) & (unsigned __int8)v38) != 0 ? &unk_7A17 : "; ";
                  v46 = scnprintf(&v89[v43], 128 - v43, "%sS3_RESET_REASON=", v45) + v43;
                  if ( v46 > 0x80 )
                    goto LABEL_226;
                  v47 = HIBYTE(v86);
                  v48 = pmic_pon_s3_reset_reason;
                  goto LABEL_88;
                case 0xD:
                  scnprintf(v89, 128, "Begin PON Sequence");
                  if ( (v38 & 1) != 0 )
                    goto LABEL_189;
                  goto LABEL_108;
                case 0xE:
                  scnprintf(v89, 128, "PON Successful");
                  if ( (v38 & 1) != 0 )
                    goto LABEL_189;
                  goto LABEL_108;
                case 0xF:
                  scnprintf(v89, 128, "Waiting on PS_HOLD");
                  if ( (v38 & 1) != 0 )
                    goto LABEL_189;
                  goto LABEL_108;
                default:
                  if ( (unsigned int)BYTE1(v86) - 16 >= 0x7F )
                  {
                    scnprintf(v89, 128, "Unknown Event (0x%02X): data=0x%04X", BYTE1(v86), v39);
                    if ( (v38 & 1) == 0 )
                      goto LABEL_108;
                  }
                  else
                  {
                    if ( !HIBYTE(v86) )
                      LOBYTE(v38) = (BYTE2(v86) != 0) & v38;
                    v52 = scnprintf(
                            v89,
                            128,
                            "PMIC bus%u SID%u ",
                            ((unsigned int)BYTE1(v86) - 15) >> 5,
                            (BYTE1(v86) - 15) & 0x1F);
                    v53 = v52;
                    if ( HIBYTE(v86) || (v38 & 1) == 0 )
                    {
                      if ( v52 > 0x80 )
                        goto LABEL_226;
                      v54 = v38;
                      v38 = scnprintf(&v89[v52], 128 - v52, "FAULT_REASON1=") + v52;
                      if ( v38 > 0x80 )
                        goto LABEL_226;
                      v53 = pmic_pon_log_print_reason(&v89[v38], 128 - v38, HIBYTE(v86), pmic_pon_fault_reason1) + v38;
                      LOBYTE(v38) = v54;
                    }
                    if ( ((BYTE2(v86) == 0) & (unsigned __int8)v38) == 0 )
                    {
                      if ( v53 > 0x80
                        || (((HIBYTE(v86) == 0) & (unsigned __int8)v38) == 0
                          ? (v55 = "; ")
                          : (v55 = (const char *)&unk_7A17),
                            v46 = scnprintf(&v89[v53], 128 - v53, "%sFAULT_REASON2=", v55) + v53,
                            v46 > 0x80) )
                      {
LABEL_226:
                        __break(0x5512u);
LABEL_227:
                        pmic_pon_log_print_reason(v89, 128, v42, pmic_pon_fault_reason2);
                        panic("PMIC SID0 FAULT; FAULT_REASON2=%s", v89);
                      }
                      v47 = BYTE2(v86);
                      v48 = pmic_pon_fault_reason2;
LABEL_88:
                      v51 = &v89[v46];
                      v50 = 128 - v46;
LABEL_89:
                      pmic_pon_log_print_reason(v51, v50, v47, v48);
                      if ( (v38 & 1) == 0 )
                        goto LABEL_108;
                    }
                  }
                  goto LABEL_189;
              }
            }
            ++v21;
            v22 += 4;
          }
          while ( v21 < *((_DWORD *)v4 + 5) );
        }
        LODWORD(v6) = 0;
        goto LABEL_200;
      }
      dev_err(*v4, "unexpected PON log end SDAM index: %d\n", v85[0]);
      goto LABEL_198;
    }
  }
LABEL_194:
  LODWORD(v6) = v17;
LABEL_199:
  dev_err(v1, "PMIC PON log parsing failed, ret=%d\n", v6);
LABEL_200:
  if ( !of_find_property(*(_QWORD *)(a1 + 760), "qcom,pmic-fault-panic", 0) )
    goto LABEL_28;
  v68 = (unsigned int)(*((_DWORD *)v4 + 4) - 1);
  memset(v89, 0, sizeof(v89));
  if ( (int)v68 < 0 )
  {
LABEL_211:
    LODWORD(v71) = 0;
    if ( (int)v68 >= 0 )
      goto LABEL_215;
    goto LABEL_28;
  }
  v69 = 0;
  v70 = 0;
  v71 = v68;
  v72 = v4[1] + 4LL * (unsigned int)v68 + 3;
  while ( 1 )
  {
    v73 = *(unsigned __int8 *)(v72 - 2);
    if ( v73 != 8 )
      break;
    v70 = __rev16(*(unsigned __int16 *)(v72 - 1));
LABEL_204:
    v12 = v71-- <= 0;
    v72 -= 4;
    if ( v12 )
      goto LABEL_211;
  }
  if ( v73 != 14 )
    goto LABEL_204;
  if ( (v69 & 1) == 0 )
  {
    v69 = 1;
    LODWORD(v68) = v71;
    goto LABEL_204;
  }
  v74 = __OFSUB__(v70--, 1);
  if ( v70 < 0 == v74 )
  {
    v69 = 1;
    goto LABEL_204;
  }
  if ( (int)v71 <= (int)v68 )
  {
    do
    {
LABEL_215:
      v75 = (unsigned __int8 *)(v4[1] + 4LL * (int)v71);
      v76 = (int)v71;
      v77 = v75[1];
      if ( v77 == 10 )
      {
        if ( v75[3] )
        {
          pmic_pon_log_print_reason(v89, 128, v75[3], pmic_pon_fault_reason3);
          panic("PMIC SID0 FAULT; FAULT_REASON3=%s", v89);
        }
      }
      else if ( v77 == 9 )
      {
        if ( v75[3] )
        {
          pmic_pon_log_print_reason(v89, 128, v75[3], pmic_pon_fault_reason1);
          panic("PMIC SID0 FAULT; FAULT_REASON1=%s", v89);
        }
        v42 = v75[2];
        if ( (v42 & 0xB7) != 0 )
          goto LABEL_227;
      }
      else if ( (unsigned int)(v77 - 16) < 0x7F )
      {
        if ( v75[3] )
        {
          pmic_pon_log_print_reason(v89, 128, v75[3], pmic_pon_fault_reason1);
          v79 = v4[1];
          v80 = "PMIC bus%u SID%u FAULT; FAULT_REASON1=%s";
LABEL_231:
          v81 = *(unsigned __int8 *)(v79 + 4 * v76 + 1) - 15;
          panic(
            v80,
            (unsigned __int16)((unsigned int)(v81 + ((unsigned __int16)(v81 & 0xF800) >> 11)) >> 5),
            v81 - ((v81 + ((unsigned __int16)(v81 & 0xF800) >> 11)) & 0xFFFFFFE0),
            v89);
        }
        v78 = v75[2];
        if ( (v78 & 0xB7) != 0 )
        {
          pmic_pon_log_print_reason(v89, 128, v78, pmic_pon_fault_reason2);
          v79 = v4[1];
          v80 = "PMIC bus%u SID%u FAULT; FAULT_REASON2=%s";
          goto LABEL_231;
        }
      }
      LODWORD(v71) = v71 + 1;
    }
    while ( (int)v76 + 1 <= (int)v68 );
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
