__int64 __fastcall ipa3_wwan_ioctl(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 ipc_logbuf; // x0
  long double v8; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v12; // x9
  char v13; // w10
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v22; // x9
  __int64 v23; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int64 v31; // x9
  char v32; // w10
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x10
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x8
  unsigned __int64 v40; // x9
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned __int64 StatusReg; // x9
  char v44; // w10
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x10
  __int64 result; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 v54; // x10
  unsigned __int64 v56; // x9
  unsigned __int64 v57; // x8
  unsigned __int64 v59; // x9
  __int64 v60; // x0
  __int64 v61; // x0
  int v62; // w8
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x19
  size_t v70; // x0
  unsigned __int64 v71; // x2
  unsigned int v72; // w20
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x21
  int v76; // w0
  __int64 v77; // x0
  __int64 v78; // x0
  unsigned int v79; // w19
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  unsigned int v85; // w19
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x21
  int v89; // w0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x8
  __int64 v93; // x8
  __int64 v94; // t2
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x1
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x0
  int v105; // w0
  int v106; // w0
  __int64 v107; // x8
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x0
  int v112; // w20
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x8
  int v117; // w9
  __int64 v118; // x0
  __int64 v119; // x0
  int ep_mapping; // w0
  int v121; // w0
  __int64 v122; // x8
  __int64 v123; // x0
  __int64 v124; // x1
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x0
  __int64 v131; // x19
  __int64 v132; // x20
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  int v137; // w22
  __int64 v138; // x19
  __int64 v139; // x21
  __int64 v140; // x23
  unsigned __int16 *v141; // x23
  __int64 v142; // x0
  long double v143; // q0
  __int64 v144; // x0
  __int16 v145; // w8
  __int64 v146; // x3
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x0
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x19
  __int64 v158; // x23
  _DWORD *v159; // x22
  __int64 v160; // x9
  __int64 v161; // x0
  __int64 v162; // x0
  __int64 v163; // x19
  __int64 v164; // x0
  long double v165; // q0
  __int64 v166; // x0
  unsigned int v167; // w0
  unsigned int v168; // w23
  char v169; // w8
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x19
  __int64 v175; // x0
  __int64 v176; // x0
  __int64 v177; // x23
  unsigned __int16 *v178; // x23
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x0
  unsigned __int64 v188; // x20
  __int64 v189; // x21
  __int64 (__fastcall *v190)(_QWORD, _QWORD, _QWORD); // x0
  int v191; // [xsp+24h] [xbp-3Ch] BYREF
  __int64 v192; // [xsp+28h] [xbp-38h] BYREF
  __int64 v193; // [xsp+30h] [xbp-30h]
  int v194; // [xsp+3Ch] [xbp-24h] BYREF
  _QWORD v195[4]; // [xsp+40h] [xbp-20h] BYREF

  v195[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v194 = 0;
  memset(v195, 0, 24);
  v192 = 0;
  v193 = 0;
  v191 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d rmnet_ipa got ioctl number 0x%08x", "ipa3_wwan_ioctl", 2515, a4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v8 = ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d rmnet_ipa got ioctl number 0x%08x", "ipa3_wwan_ioctl", 2515, a4);
  }
  if ( a4 <= 35319 )
  {
    if ( a4 > 35316 )
    {
      if ( a4 != 35317 )
      {
        if ( a4 == 35318 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v44 = *(_BYTE *)(StatusReg + 70);
          v45 = *(_QWORD *)(a2 + 16);
          v191 = 0;
          if ( (v44 & 0x20) != 0 || (v46 = v45, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v46 = v45 & ((__int64)(v45 << 8) >> 8);
          if ( v46 <= 0x7FFFFFFFFCLL )
          {
            v54 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v56 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v56 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v56);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v54);
            v23 = _arch_copy_to_user(v45 & 0xFF7FFFFFFFFFFFFFLL, &v191, 4);
            v57 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v59 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v59 - 4096);
            _WriteStatusReg(TTBR1_EL1, v59);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v57);
LABEL_73:
            if ( v23 )
              result = 4294967282LL;
            else
              result = 0;
            goto LABEL_311;
          }
        }
        else
        {
          v12 = _ReadStatusReg(SP_EL0);
          v13 = *(_BYTE *)(v12 + 70);
          v14 = *(_QWORD *)(a2 + 16);
          v191 = 2;
          if ( (v13 & 0x20) != 0 || (v15 = v14, (*(_QWORD *)v12 & 0x4000000) != 0) )
            v15 = v14 & ((__int64)(v14 << 8) >> 8);
          if ( v15 <= 0x7FFFFFFFFCLL )
          {
            v16 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v22 = *(_QWORD *)(v12 + 8);
            _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v22);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v16);
            v23 = _arch_copy_to_user(v14 & 0xFF7FFFFFFFFFFFFFLL, &v191, 4);
            v24 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v26 - 4096);
            _WriteStatusReg(TTBR1_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v24);
            goto LABEL_73;
          }
        }
LABEL_53:
        result = 4294967282LL;
        goto LABEL_311;
      }
    }
    else if ( (unsigned int)(a4 - 35313) >= 2 )
    {
      if ( a4 != 35315 )
      {
        if ( a4 == 35316 )
        {
LABEL_71:
          result = 4294967274LL;
          goto LABEL_311;
        }
LABEL_66:
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_542, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3E2102, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_69:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v53 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v53,
                "ipa-wan %s:%d [%s] unsupported cmd[%d]",
                "ipa3_wwan_ioctl",
                2995,
                a1 + 296,
                (unsigned int)a4);
            }
            goto LABEL_71;
          }
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
          goto LABEL_69;
        }
        v52 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v52,
          "ipa-wan %s:%d [%s] unsupported cmd[%d]",
          "ipa3_wwan_ioctl",
          2995,
          (const char *)(a1 + 296),
          a4);
        goto LABEL_69;
      }
      v31 = _ReadStatusReg(SP_EL0);
      v32 = *(_BYTE *)(v31 + 70);
      v33 = *(_QWORD *)(a2 + 16);
      v191 = 2;
      if ( (v32 & 0x20) != 0 || (v34 = v33, (*(_QWORD *)v31 & 0x4000000) != 0) )
        v34 = v33 & ((__int64)(v33 << 8) >> 8);
      if ( v34 <= 0x7FFFFFFFFCLL )
      {
        v35 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v37 = *(_QWORD *)(v31 + 8);
        _WriteStatusReg(TTBR1_EL1, v37 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v37);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v35);
        v23 = _arch_copy_to_user(v33 & 0xFF7FFFFFFFFFFFFFLL, &v191, 4);
        v38 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v40 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v40 - 4096);
        _WriteStatusReg(TTBR1_EL1, v40);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v38);
        goto LABEL_73;
      }
      goto LABEL_53;
    }
LABEL_310:
    result = 0;
    goto LABEL_311;
  }
  if ( a4 <= 35323 )
  {
    if ( (unsigned int)(a4 - 35320) < 2 )
      goto LABEL_310;
    if ( a4 != 35322 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_476, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3D96DA, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_17;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_17:
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_53;
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v11, "ipa-wan %s:%d RMNET_IOCTL_FLOW_DISABLE not supported\n", "ipa3_wwan_ioctl", 2563);
LABEL_65:
        result = 4294967282LL;
        goto LABEL_311;
      }
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa-wan %s:%d RMNET_IOCTL_FLOW_DISABLE not supported\n", "ipa3_wwan_ioctl", 2563);
      goto LABEL_17;
    }
    if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs, "ipa3_wwan_ioctl") )
    {
      printk(&unk_3E79EA, "ipa3_wwan_ioctl");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_47;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_47:
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_53;
      v42 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v42, "ipa-wan %s:%d RMNET_IOCTL_FLOW_ENABLE not supported\n", "ipa3_wwan_ioctl", 2558);
      goto LABEL_65;
    }
    v41 = ipa3_get_ipc_logbuf();
    ipc_log_string(v41, "ipa-wan %s:%d RMNET_IOCTL_FLOW_ENABLE not supported\n", "ipa3_wwan_ioctl", 2558);
    goto LABEL_47;
  }
  if ( a4 == 35324 )
    goto LABEL_310;
  if ( a4 != 35325 )
  {
    if ( a4 != 35326 )
      goto LABEL_66;
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa-wan %s:%d RMNET_IOCTL_EXTENDED_V2 received\n", "ipa3_wwan_ioctl", 2957);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v28, "ipa-wan %s:%d RMNET_IOCTL_EXTENDED_V2 received\n", "ipa3_wwan_ioctl", 2957);
    }
    if ( inline_copy_from_user_2((int)&v192, *(_QWORD *)(a2 + 16), 0x10u) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_532, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3B0B97, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_37;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_37:
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_53;
        v30 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v30, "ipa-wan %s:%d failed to copy extended ioctl data\n", "ipa3_wwan_ioctl", 2961);
        goto LABEL_65;
      }
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(v29, "ipa-wan %s:%d failed to copy extended ioctl data\n", "ipa3_wwan_ioctl", 2961);
      goto LABEL_37;
    }
    if ( HIDWORD(v193) != 1 )
    {
      if ( !HIDWORD(v193) )
      {
        if ( (_DWORD)v193 == 16 )
        {
          result = handle3_egress_format_v2(a1, v192);
          goto LABEL_311;
        }
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_533, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3DF4D1, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_97;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_97:
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_53;
          v66 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v66, "ipa-wan %s:%d Egress ioctl v2 format size mismatch\n", "ipa3_wwan_ioctl", 2969);
          goto LABEL_65;
        }
        v65 = ipa3_get_ipc_logbuf();
        ipc_log_string(v65, "ipa-wan %s:%d Egress ioctl v2 format size mismatch\n", "ipa3_wwan_ioctl", 2969);
        goto LABEL_97;
      }
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_539, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3DF507, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_92:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v64 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v64,
              "ipa-wan %s:%d %d is Unsupported extended ioctl v2\n",
              "ipa3_wwan_ioctl",
              2988,
              HIDWORD(v193));
          }
          goto LABEL_71;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_92;
      }
      v63 = ipa3_get_ipc_logbuf();
      ipc_log_string(v63, "ipa-wan %s:%d %d is Unsupported extended ioctl v2\n", "ipa3_wwan_ioctl", 2988, HIDWORD(v193));
      goto LABEL_92;
    }
    if ( (_DWORD)v193 == 16 )
    {
      result = handle3_ingress_format_v2(a1, v192);
      goto LABEL_311;
    }
    if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_536, "ipa3_wwan_ioctl") )
    {
      printk(&unk_3C83CB, "ipa3_wwan_ioctl");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_102;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_102:
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_53;
      v68 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v68, "ipa-wan %s:%d ingress ioctl v2 format size mismatch\n", "ipa3_wwan_ioctl", 2979);
      goto LABEL_65;
    }
    v67 = ipa3_get_ipc_logbuf();
    ipc_log_string(v67, "ipa-wan %s:%d ingress ioctl v2 format size mismatch\n", "ipa3_wwan_ioctl", 2979);
    goto LABEL_102;
  }
  if ( (ns_capable(*(_QWORD *)(*(_QWORD *)(a1 + 280) + 80LL), 12, v8) & 1) == 0 )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_311;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v48 = ipa3_get_ipc_logbuf();
    ipc_log_string(v48, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_EXTENDED\n", "ipa3_wwan_ioctl", 2574);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v49 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v49, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_EXTENDED\n", "ipa3_wwan_ioctl", 2574);
  }
  if ( inline_copy_from_user_2((int)v195, *(_QWORD *)(a2 + 16), 0x18u) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_480, "ipa3_wwan_ioctl") )
    {
      printk(&unk_3B0B97, "ipa3_wwan_ioctl");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_63;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_63:
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_53;
      v51 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v51, "ipa-wan %s:%d failed to copy extended ioctl data\n", "ipa3_wwan_ioctl", 2578);
      goto LABEL_65;
    }
    v50 = ipa3_get_ipc_logbuf();
    ipc_log_string(v50, "ipa-wan %s:%d failed to copy extended ioctl data\n", "ipa3_wwan_ioctl", 2578);
    goto LABEL_63;
  }
  result = 0;
  switch ( LODWORD(v195[0]) )
  {
    case 0:
      if ( ipa3_get_ipc_logbuf() )
      {
        v60 = ipa3_get_ipc_logbuf();
        ipc_log_string(v60, "ipa-wan %s:%d get RMNET_IOCTL_GET_SUPPORTED_FEATURES\n", "ipa3_wwan_ioctl", 2585);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v61 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v61, "ipa-wan %s:%d get RMNET_IOCTL_GET_SUPPORTED_FEATURES\n", "ipa3_wwan_ioctl", 2585);
      }
      v62 = 7;
      goto LABEL_164;
    case 1:
      if ( ipa3_get_ipc_logbuf() )
      {
        v110 = ipa3_get_ipc_logbuf();
        ipc_log_string(v110, "ipa-wan %s:%d get MRU size %d\n", "ipa3_wwan_ioctl", 2599, HIDWORD(v195[0]));
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        goto LABEL_311;
      v111 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v111, "ipa-wan %s:%d get MRU size %d\n", "ipa3_wwan_ioctl", 2599, HIDWORD(v195[0]));
      goto LABEL_310;
    case 2:
      v62 = 1000;
      goto LABEL_164;
    case 3:
      if ( ipa3_get_ipc_logbuf() )
      {
        v96 = ipa3_get_ipc_logbuf();
        ipc_log_string(v96, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EPID\n", "ipa3_wwan_ioctl", 2620);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v97 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v97, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EPID\n", "ipa3_wwan_ioctl", 2620);
      }
      v98 = *(_QWORD *)(a2 + 16);
      HIDWORD(v195[0]) = 1;
      v99 = inline_copy_to_user_0(v98, v195, 24);
      v100 = *(_QWORD *)(a2 + 16);
      if ( v99 )
        v85 = -14;
      else
        v85 = 0;
      if ( inline_copy_from_user_2((int)v195, v100, 0x18u) )
      {
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_486, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3F038F, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_179;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_179:
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_53;
          v102 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v102, "ipa-wan %s:%d copy extended ioctl data failed\n", "ipa3_wwan_ioctl", 2629);
          goto LABEL_65;
        }
        v101 = ipa3_get_ipc_logbuf();
        ipc_log_string(v101, "ipa-wan %s:%d copy extended ioctl data failed\n", "ipa3_wwan_ioctl", 2629);
        goto LABEL_179;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v147 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v147,
          "ipa-wan %s:%d RMNET_IOCTL_GET_EPID return %d\n",
          "ipa3_wwan_ioctl",
          2634,
          HIDWORD(v195[0]));
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_325;
      v148 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v148, "ipa-wan %s:%d RMNET_IOCTL_GET_EPID return %d\n", "ipa3_wwan_ioctl", 2634, HIDWORD(v195[0]));
LABEL_260:
      result = v85;
      goto LABEL_311;
    case 4:
      if ( rmnet_ipa3_ctx )
      {
        if ( *(_QWORD *)rmnet_ipa3_ctx )
        {
          v92 = **(_QWORD **)rmnet_ipa3_ctx;
          if ( v92 )
          {
            v94 = v92 + 296;
            v93 = *(_QWORD *)(v92 + 296);
            v95 = *(_QWORD *)(a2 + 16);
            *(_QWORD *)((char *)&v195[1] + 4) = *(_QWORD *)(v94 + 8);
            *(_QWORD *)((char *)v195 + 4) = v93;
            BYTE3(v195[2]) = 0;
LABEL_165:
            if ( inline_copy_to_user_0(v95, v195, 24) )
              result = 4294967282LL;
            else
              result = 0;
            goto LABEL_311;
          }
        }
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v129 = ipa3_get_ipc_logbuf();
        ipc_log_string(v129, "ipa-wan %s:%d IPA_NETDEV is NULL\n", "ipa3_wwan_ioctl", 2723);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v130 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v130, "ipa-wan %s:%d IPA_NETDEV is NULL\n", "ipa3_wwan_ioctl", 2723);
        goto LABEL_65;
      }
      goto LABEL_53;
    case 5:
      v79 = HIDWORD(v195[0]);
      if ( (int)ipa3_find_mux_channel_index(SHIDWORD(v195[0])) <= 14 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v80 = ipa3_get_ipc_logbuf();
          ipc_log_string(v80, "ipa-wan %s:%d already setup mux(%d)\n", "ipa3_wwan_ioctl", 2733, v79);
        }
        result = ipa3_get_ipc_logbuf_low();
        if ( result )
        {
          v81 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v81, "ipa-wan %s:%d already setup mux(%d)\n", "ipa3_wwan_ioctl", 2733, v79);
          goto LABEL_310;
        }
        goto LABEL_311;
      }
      mutex_lock(rmnet_ipa3_ctx + 1136);
      if ( *(int *)(rmnet_ipa3_ctx + 1044) >= 15 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_504, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3BF245, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_244;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_244:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v136 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v136,
              "ipa-wan %s:%d Exceed mux_channel limit(%d)\n",
              "ipa3_wwan_ioctl",
              2740,
              *(_DWORD *)(rmnet_ipa3_ctx + 1044));
          }
          mutex_unlock(rmnet_ipa3_ctx + 1136);
          result = 4294967282LL;
          goto LABEL_311;
        }
        v135 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v135,
          "ipa-wan %s:%d Exceed mux_channel limit(%d)\n",
          "ipa3_wwan_ioctl",
          2740,
          *(_DWORD *)(rmnet_ipa3_ctx + 1044));
        goto LABEL_244;
      }
      HIBYTE(v195[2]) = 0;
      if ( ipa3_get_ipc_logbuf() )
      {
        v155 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v155,
          "ipa-wan %s:%d ADD_MUX_CHANNEL(%d, name: %s)\n",
          "ipa3_wwan_ioctl",
          2749,
          HIDWORD(v195[0]),
          (const char *)&v195[1]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v156 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v156,
          "ipa-wan %s:%d ADD_MUX_CHANNEL(%d, name: %s)\n",
          "ipa3_wwan_ioctl",
          2749,
          HIDWORD(v195[0]),
          (const char *)&v195[1]);
      }
      v157 = *(int *)(rmnet_ipa3_ctx + 1044);
      v158 = rmnet_ipa3_ctx + 32 * v157;
      *(_DWORD *)(v158 + 556) = HIDWORD(v195[0]);
      v159 = (_DWORD *)(v158 + 556);
      v160 = v195[1];
      *(_QWORD *)(v158 + 568) = v195[2];
      *(_QWORD *)(v158 + 560) = v160;
      *(_BYTE *)(v158 + 575) = 0;
      if ( ipa3_get_ipc_logbuf() )
      {
        v161 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v161,
          "ipa-wan %s:%d cashe device[%s:%d] in IPA_wan[%d]\n",
          "ipa3_wwan_ioctl",
          2766,
          (const char *)(v158 + 560),
          *v159,
          v157);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v162 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v162,
          "ipa-wan %s:%d cashe device[%s:%d] in IPA_wan[%d]\n",
          "ipa3_wwan_ioctl",
          2766,
          (const char *)(v158 + 560),
          *v159,
          v157);
      }
      v163 = rmnet_ipa3_ctx;
      if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1036) && *(_BYTE *)(rmnet_ipa3_ctx + 1992) != 1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v185 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v185,
            "ipa-wan %s:%d dev(%s) haven't registered to IPA\n",
            "ipa3_wwan_ioctl",
            2790,
            (const char *)&v195[1]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v186 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v186,
            "ipa-wan %s:%d dev(%s) haven't registered to IPA\n",
            "ipa3_wwan_ioctl",
            2790,
            (const char *)&v195[1]);
        }
        v169 = 0;
        v168 = 0;
        goto LABEL_339;
      }
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_511, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3F385F, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_291:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v166 = ipa3_get_ipc_logbuf_low();
            v165 = ipc_log_string(
                     v166,
                     "ipa-wan %s:%d dev(%s) register to IPA\n",
                     "ipa3_wwan_ioctl",
                     2775,
                     (const char *)&v195[1]);
          }
          v167 = ipa3_wwan_register_to_ipa(*(unsigned int *)(rmnet_ipa3_ctx + 1044), v165);
          if ( (v167 & 0x80000000) == 0 )
          {
            v168 = v167;
            v169 = 1;
LABEL_339:
            *((_BYTE *)v159 + 21) = v169;
            *((_BYTE *)v159 + 20) = 1;
            v187 = rmnet_ipa3_ctx + 1136;
            ++*(_DWORD *)(rmnet_ipa3_ctx + 1044);
            mutex_unlock(v187);
            result = v168;
            goto LABEL_311;
          }
          if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_514, "ipa3_wwan_ioctl") )
          {
            printk(&unk_3B341F, "ipa3_wwan_ioctl");
            if ( !ipa3_get_ipc_logbuf() )
              goto LABEL_329;
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_329:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v184 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v184,
                "ipa-wan %s:%d device %s reg IPA failed\n",
                "ipa3_wwan_ioctl",
                2780,
                (const char *)&v195[1]);
            }
            mutex_unlock(v163 + 1136);
            result = 4294967277LL;
            goto LABEL_311;
          }
          v183 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v183,
            "ipa-wan %s:%d device %s reg IPA failed\n",
            "ipa3_wwan_ioctl",
            2780,
            (const char *)&v195[1]);
          goto LABEL_329;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_291;
      }
      v164 = ipa3_get_ipc_logbuf();
      ipc_log_string(v164, "ipa-wan %s:%d dev(%s) register to IPA\n", "ipa3_wwan_ioctl", 2775, (const char *)&v195[1]);
      goto LABEL_291;
    case 6:
      result = handle3_egress_format(a1, v195);
      goto LABEL_311;
    case 7:
      result = handle3_ingress_format(a1, v195);
      goto LABEL_311;
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
      goto LABEL_311;
    case 0x10:
      if ( ipa3_get_ipc_logbuf() )
      {
        v118 = ipa3_get_ipc_logbuf();
        ipc_log_string(v118, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EP_PAIR\n", "ipa3_wwan_ioctl", 2638);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v119 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v119, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EP_PAIR\n", "ipa3_wwan_ioctl", 2638);
      }
      ep_mapping = ipa_get_ep_mapping(35);
      if ( ep_mapping != -1 )
      {
        LODWORD(v195[1]) = ep_mapping;
        v121 = ipa_get_ep_mapping(34);
        if ( v121 != -1 )
        {
          v122 = *(_QWORD *)(a2 + 16);
          HIDWORD(v195[0]) = v121;
          v123 = inline_copy_to_user_0(v122, v195, 24);
          v124 = *(_QWORD *)(a2 + 16);
          if ( v123 )
            v85 = -14;
          else
            v85 = 0;
          if ( !inline_copy_from_user_2((int)v195, v124, 0x18u) )
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              v181 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v181,
                "ipa-wan %s:%d RMNET_IOCTL_GET_EP_PAIR c: %d p: %d\n",
                "ipa3_wwan_ioctl",
                2669,
                HIDWORD(v195[0]),
                LODWORD(v195[1]));
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v182 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v182,
                "ipa-wan %s:%d RMNET_IOCTL_GET_EP_PAIR c: %d p: %d\n",
                "ipa3_wwan_ioctl",
                2669,
                HIDWORD(v195[0]),
                LODWORD(v195[1]));
            }
            goto LABEL_325;
          }
          if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_493, "ipa3_wwan_ioctl") )
          {
            printk(&unk_3F038F, "ipa3_wwan_ioctl");
            if ( !ipa3_get_ipc_logbuf() )
              goto LABEL_220;
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_220:
            if ( !ipa3_get_ipc_logbuf_low() )
              goto LABEL_53;
            v126 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v126, "ipa-wan %s:%d copy extended ioctl data failed\n", "ipa3_wwan_ioctl", 2663);
            goto LABEL_65;
          }
          v125 = ipa3_get_ipc_logbuf();
          ipc_log_string(v125, "ipa-wan %s:%d copy extended ioctl data failed\n", "ipa3_wwan_ioctl", 2663);
          goto LABEL_220;
        }
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_492, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3CDD4E, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_303;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_303:
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_53;
          v173 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v173, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2650);
          goto LABEL_65;
        }
        v172 = ipa3_get_ipc_logbuf();
        ipc_log_string(v172, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2650);
        goto LABEL_303;
      }
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_491, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3CDD4E, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_276;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_276:
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_53;
        v154 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v154, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2641);
        goto LABEL_65;
      }
      v153 = ipa3_get_ipc_logbuf();
      ipc_log_string(v153, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2641);
      goto LABEL_276;
    case 0x14:
      mutex_lock(rmnet_ipa3_ctx + 2000);
      v112 = HIDWORD(v195[0]);
      v113 = ipa3_get_ipc_logbuf();
      if ( v112 )
      {
        if ( v113 )
        {
          v114 = ipa3_get_ipc_logbuf();
          ipc_log_string(v114, "ipa-wan %s:%d ioctl: unvote IPA clock\n", "ipa3_wwan_ioctl", 2869);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v115 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v115, "ipa-wan %s:%d ioctl: unvote IPA clock\n", "ipa3_wwan_ioctl", 2869);
        }
        v116 = rmnet_ipa3_ctx;
        v117 = *(_DWORD *)(rmnet_ipa3_ctx + 2048);
        if ( v117 )
        {
          *(_DWORD *)(rmnet_ipa3_ctx + 2048) = v117 - 1;
          ipa3_dec_client_disable_clks();
          v116 = rmnet_ipa3_ctx;
        }
      }
      else
      {
        if ( v113 )
        {
          v151 = ipa3_get_ipc_logbuf();
          ipc_log_string(v151, "ipa-wan %s:%d ioctl: vote IPA clock\n", "ipa3_wwan_ioctl", 2876);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v152 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v152, "ipa-wan %s:%d ioctl: vote IPA clock\n", "ipa3_wwan_ioctl", 2876);
        }
        v116 = rmnet_ipa3_ctx;
        if ( (unsigned int)(*(_DWORD *)(rmnet_ipa3_ctx + 2048) + 1) <= 0x1F4 )
        {
          ipa3_inc_client_enable_clks();
          v116 = rmnet_ipa3_ctx;
          ++*(_DWORD *)(rmnet_ipa3_ctx + 2048);
        }
      }
      mutex_unlock(v116 + 2000);
      goto LABEL_310;
    case 0x15:
      v69 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
      if ( !v69 )
        goto LABEL_366;
      while ( 2 )
      {
        BYTE3(v195[2]) = 0;
        v70 = strnlen((const char *)v195 + 4, 0x10u);
        if ( v70 >= 0x11 )
        {
          _fortify_panic(2, 16, v70 + 1);
        }
        else
        {
          if ( v70 == 16 )
            v71 = 16;
          else
            v71 = v70 + 1;
          if ( v71 < 0x21 )
          {
            sized_strscpy(v69, (char *)v195 + 4);
            *(_BYTE *)(v69 + 15) = 0;
            v194 = 5767186;
            result = ipa_send_msg((unsigned __int8 *)&v194, (_WORD *)v69, ipa3_wwan_msg_free_cb);
            if ( !(_DWORD)result )
              goto LABEL_311;
            v72 = result;
            if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_518, "ipa3_wwan_ioctl") )
            {
              printk(&unk_3D978D, "ipa3_wwan_ioctl");
              if ( !ipa3_get_ipc_logbuf() )
                goto LABEL_126;
            }
            else if ( !ipa3_get_ipc_logbuf() )
            {
LABEL_126:
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v74 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v74, "ipa-wan %s:%d Failed to send XLAT_CONNECT msg\n", "ipa3_wwan_ioctl", 2824);
              }
              kfree(v69);
              result = v72;
              goto LABEL_311;
            }
            v73 = ipa3_get_ipc_logbuf();
            ipc_log_string(v73, "ipa-wan %s:%d Failed to send XLAT_CONNECT msg\n", "ipa3_wwan_ioctl", 2824);
            goto LABEL_126;
          }
        }
        _fortify_panic(7, 32, v71);
        v188 = _ReadStatusReg(SP_EL0);
        v189 = *(_QWORD *)(v188 + 80);
        v190 = _kmalloc_cache_noprof;
        *(_QWORD *)(v188 + 80) = &ipa3_wwan_ioctl__alloc_tag;
        v69 = _kmalloc_cache_noprof(v190, 3520, 88);
        *(_QWORD *)(v188 + 80) = v189;
        if ( !v69 )
        {
LABEL_366:
          result = 4294967284LL;
          goto LABEL_311;
        }
        continue;
      }
    case 0x17:
      v62 = (unsigned __int8)byte_2018C1;
LABEL_164:
      v95 = *(_QWORD *)(a2 + 16);
      HIDWORD(v195[0]) = v62;
      goto LABEL_165;
    case 0x18:
      result = rmnet_ipa_send_coalesce_notification(
                 LOBYTE(v195[1]),
                 (v195[0] & 0x300000000LL) != 0,
                 BYTE4(v195[0]) & 1,
                 (HIDWORD(v195[0]) >> 1) & 1);
      goto LABEL_311;
    case 0x19:
      BYTE3(v195[2]) = 0;
      v75 = rmnet_ipa3_ctx;
      v76 = ((__int64 (__fastcall *)(char *))find_vchannel_name_index)((char *)v195 + 4);
      if ( v76 == 15 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_524, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3F9288, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_133;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_133:
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_255;
          v78 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v78, "ipa-wan %s:%d %s is an invalid iface name\n", "ipa3_wwan_ioctl", 2895, (char *)v195 + 4);
          goto LABEL_158;
        }
        v77 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v77,
          "ipa-wan %s:%d %s is an invalid iface name\n",
          "ipa3_wwan_ioctl",
          2895,
          (const char *)v195 + 4);
        goto LABEL_133;
      }
      LODWORD(v131) = v76;
      v132 = v75 + 556;
      if ( ipa3_get_ipc_logbuf() )
      {
        v133 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v133,
          "ipa-wan %s:%d getting v4 MTU = %d\n",
          "ipa3_wwan_ioctl",
          2899,
          *(unsigned __int16 *)(v132 + 32LL * (int)v131 + 28));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v134 = ipa3_get_ipc_logbuf_low();
        v131 = (int)v131;
        ipc_log_string(
          v134,
          "ipa-wan %s:%d getting v4 MTU = %d\n",
          "ipa3_wwan_ioctl",
          2899,
          *(unsigned __int16 *)(v132 + 32LL * (int)v131 + 28));
      }
      else
      {
        v131 = (int)v131;
      }
      v174 = v132 + 32 * v131;
      WORD2(v195[2]) = *(_WORD *)(v174 + 28);
      if ( ipa3_get_ipc_logbuf() )
      {
        v175 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v175,
          "ipa-wan %s:%d getting v6 MTU = %d\n",
          "ipa3_wwan_ioctl",
          2903,
          *(unsigned __int16 *)(v174 + 30));
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v176 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v176,
          "ipa-wan %s:%d getting v6 MTU = %d\n",
          "ipa3_wwan_ioctl",
          2903,
          *(unsigned __int16 *)(v174 + 30));
        goto LABEL_310;
      }
      goto LABEL_311;
    case 0x20:
      BYTE3(v195[2]) = 0;
      v88 = rmnet_ipa3_ctx;
      v89 = ((__int64 (__fastcall *)(char *))find_vchannel_name_index)((char *)v195 + 4);
      if ( v89 != 15 )
      {
        v137 = WORD2(v195[2]);
        LODWORD(v138) = v89;
        v139 = v88 + 556;
        if ( WORD2(v195[2]) )
        {
          v140 = v139 + 32LL * v89;
          *(_WORD *)(v140 + 28) = WORD2(v195[2]);
          v141 = (unsigned __int16 *)(v140 + 28);
          if ( ipa3_get_ipc_logbuf() )
          {
            v142 = ipa3_get_ipc_logbuf();
            ipc_log_string(v142, "ipa-wan %s:%d Set v4 MTU = %d\n", "ipa3_wwan_ioctl", 2926, *v141);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v144 = ipa3_get_ipc_logbuf_low();
            v143 = ipc_log_string(v144, "ipa-wan %s:%d Set v4 MTU = %d\n", "ipa3_wwan_ioctl", 2926, *v141);
          }
          v145 = HIWORD(v195[2]);
          if ( !HIWORD(v195[2]) )
          {
            if ( !v137 )
              goto LABEL_310;
            v146 = 0;
            v138 = (int)v138;
            goto LABEL_320;
          }
        }
        else
        {
          v145 = HIWORD(v195[2]);
          if ( !HIWORD(v195[2]) )
            goto LABEL_310;
        }
        v138 = (int)v138;
        v177 = v139 + 32LL * (int)v138;
        *(_WORD *)(v177 + 30) = v145;
        v178 = (unsigned __int16 *)(v177 + 30);
        if ( ipa3_get_ipc_logbuf() )
        {
          v179 = ipa3_get_ipc_logbuf();
          ipc_log_string(v179, "ipa-wan %s:%d Set v6 MTU = %d\n", "ipa3_wwan_ioctl", 2934, *v178);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v180 = ipa3_get_ipc_logbuf_low();
          v143 = ipc_log_string(v180, "ipa-wan %s:%d Set v6 MTU = %d\n", "ipa3_wwan_ioctl", 2934, *v178);
        }
        if ( v137 )
          v146 = 2;
        else
          v146 = 1;
LABEL_320:
        result = rmnet_ipa_send_set_mtu_notification(
                   (char *)v195 + 4,
                   *(unsigned __int16 *)(v139 + 32 * v138 + 28),
                   *(unsigned __int16 *)(v139 + 32 * v138 + 30),
                   v146,
                   v143);
        goto LABEL_311;
      }
      if ( !(unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_525, "ipa3_wwan_ioctl") )
      {
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_156;
        goto LABEL_155;
      }
      printk(&unk_3F9288, "ipa3_wwan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
LABEL_155:
        v90 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v90,
          "ipa-wan %s:%d %s is an invalid iface name\n",
          "ipa3_wwan_ioctl",
          2917,
          (const char *)v195 + 4);
      }
LABEL_156:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v91 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v91, "ipa-wan %s:%d %s is an invalid iface name\n", "ipa3_wwan_ioctl", 2917, (char *)v195 + 4);
LABEL_158:
        result = 4294967277LL;
      }
      else
      {
LABEL_255:
        result = 4294967277LL;
      }
LABEL_311:
      _ReadStatusReg(SP_EL0);
      return result;
    case 0x21:
      if ( ipa3_get_ipc_logbuf() )
      {
        v82 = ipa3_get_ipc_logbuf();
        ipc_log_string(v82, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EPID_LL\n", "ipa3_wwan_ioctl", 2673);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v83 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v83, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EPID_LL\n", "ipa3_wwan_ioctl", 2673);
      }
      v84 = *(_QWORD *)(a2 + 16);
      HIDWORD(v195[0]) = 5;
      if ( inline_copy_to_user_0(v84, v195, 24) )
        v85 = -14;
      else
        v85 = 0;
      if ( ipa3_get_ipc_logbuf() )
      {
        v86 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v86,
          "ipa-wan %s:%d RMNET_IOCTL_GET_EPID_LL return %d\n",
          "ipa3_wwan_ioctl",
          2680,
          HIDWORD(v195[0]));
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_325;
      v87 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v87,
        "ipa-wan %s:%d RMNET_IOCTL_GET_EPID_LL return %d\n",
        "ipa3_wwan_ioctl",
        2680,
        HIDWORD(v195[0]));
      goto LABEL_260;
    case 0x22:
      if ( ipa3_get_ipc_logbuf() )
      {
        v103 = ipa3_get_ipc_logbuf();
        ipc_log_string(v103, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EP_PAIR_LL\n", "ipa3_wwan_ioctl", 2684);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v104 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v104, "ipa-wan %s:%d get ioctl: RMNET_IOCTL_GET_EP_PAIR_LL\n", "ipa3_wwan_ioctl", 2684);
      }
      v105 = ipa_get_ep_mapping(121);
      if ( v105 != -1 )
      {
        LODWORD(v195[1]) = v105;
        v106 = ipa_get_ep_mapping(120);
        if ( v106 != -1 )
        {
          v107 = *(_QWORD *)(a2 + 16);
          HIDWORD(v195[0]) = v106;
          if ( inline_copy_to_user_0(v107, v195, 24) )
            v85 = -14;
          else
            v85 = 0;
          if ( ipa3_get_ipc_logbuf() )
          {
            v108 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v108,
              "ipa-wan %s:%d RMNET_IOCTL_GET_EP_PAIR_LL c: %d p: %d\n",
              "ipa3_wwan_ioctl",
              2710,
              HIDWORD(v195[0]),
              LODWORD(v195[1]));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v109 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v109,
              "ipa-wan %s:%d RMNET_IOCTL_GET_EP_PAIR_LL c: %d p: %d\n",
              "ipa3_wwan_ioctl",
              2710,
              HIDWORD(v195[0]),
              LODWORD(v195[1]));
          }
LABEL_325:
          result = v85;
          goto LABEL_311;
        }
        if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_499, "ipa3_wwan_ioctl") )
        {
          printk(&unk_3CDD4E, "ipa3_wwan_ioctl");
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_298;
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_298:
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_53;
          v171 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v171, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2698);
          goto LABEL_65;
        }
        v170 = ipa3_get_ipc_logbuf();
        ipc_log_string(v170, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2698);
        goto LABEL_298;
      }
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_498, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3CDD4E, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_264;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_264:
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_53;
        v150 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v150, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2688);
        goto LABEL_65;
      }
      v149 = ipa3_get_ipc_logbuf();
      ipc_log_string(v149, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_wwan_ioctl", 2688);
      goto LABEL_264;
    default:
      if ( (unsigned int)__ratelimit(&ipa3_wwan_ioctl__rs_528, "ipa3_wwan_ioctl") )
      {
        printk(&unk_3C8399, "ipa3_wwan_ioctl");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_226:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v128 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v128,
              "ipa-wan %s:%d [%s] unsupported extended cmd[%d]",
              "ipa3_wwan_ioctl",
              2952,
              a1 + 296,
              LODWORD(v195[0]));
          }
          goto LABEL_71;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_226;
      }
      v127 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v127,
        "ipa-wan %s:%d [%s] unsupported extended cmd[%d]",
        "ipa3_wwan_ioctl",
        2952,
        (const char *)(a1 + 296),
        LODWORD(v195[0]));
      goto LABEL_226;
  }
}
