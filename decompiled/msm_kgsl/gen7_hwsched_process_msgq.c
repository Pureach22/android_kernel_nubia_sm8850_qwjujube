__int64 __fastcall gen7_hwsched_process_msgq(__int64 a1)
{
  __int64 v2; // x26
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  _QWORD *v6; // x21
  __int64 v7; // x22
  __int64 v8; // t1
  _DWORD *v9; // x8
  _QWORD **v10; // x24
  __int64 v11; // x21
  __int64 v12; // t1
  int v13; // w8
  int v14; // w21
  __int64 v15; // x21
  unsigned int *v16; // x23
  void *v17; // x0
  const char *v18; // x1
  void (__fastcall *v19)(_QWORD); // x8
  unsigned int *v20; // x0
  unsigned int v21; // w8
  unsigned int v23; // w21
  unsigned int v28; // w9
  __int64 v29; // x0
  _QWORD *v30; // x1
  unsigned int v31; // w25
  int v32; // w8
  __int64 v33; // x27
  unsigned int v34; // w22
  _QWORD *v35; // x21
  unsigned int v36; // w23
  unsigned int v37; // w8
  unsigned int v38; // w2
  int v39; // w3
  __int64 v40; // x21
  _QWORD *v41; // x0
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x8
  __int64 v45; // x21
  unsigned __int64 v46; // x22
  __int64 v47; // x23
  size_t v48; // x2
  void *v49; // x0
  const char *v50; // x1
  unsigned int v51; // w0
  void *v52; // x0
  const char *v53; // x1
  __int64 v54; // x1
  __int64 v55; // x2
  unsigned int v56; // w10
  _WORD *v57; // x0
  unsigned int v58; // w22
  void *v59; // x0
  const char *v60; // x1
  void *v61; // x0
  const char *v62; // x1
  void *v63; // x0
  const char *v64; // x1
  unsigned int v65; // w0
  __int64 v66; // x2
  __int64 v67; // x3
  void *v68; // x0
  const char *v69; // x1
  unsigned int v70; // w0
  unsigned int v71; // w8
  unsigned int v72; // w10
  _WORD *v73; // x0
  unsigned int v74; // w22
  void *v75; // x0
  const char *v76; // x1
  unsigned int v77; // w0
  unsigned int v78; // w0
  unsigned int v79; // w0
  unsigned int v80; // w0
  unsigned int v81; // w10
  _WORD *v82; // x0
  void *v83; // x0
  const char *v84; // x1
  unsigned int v85; // w0
  void *v86; // x0
  const char *v87; // x1
  unsigned int v88; // w0
  void *v89; // x0
  const char *v90; // x1
  void *v91; // x0
  const char *v92; // x1
  int v93; // w2
  __int64 v94; // x2
  __int64 v95; // x2
  const char *v97; // x1
  unsigned int v98; // w23
  int v99; // w27
  void *v100; // x0
  const char *v101; // x1
  const char *v102; // x2
  __int64 v103; // x0
  int v104; // w1
  unsigned int v105; // w0
  unsigned int v106; // w8
  unsigned int v107; // w10
  _WORD *v108; // x0
  int v110; // w8
  int v111; // [xsp+Ch] [xbp-184h]
  int payload_rb_key_legacy; // [xsp+10h] [xbp-180h]
  int payload_rb_key; // [xsp+14h] [xbp-17Ch]
  __int64 src; // [xsp+30h] [xbp-160h] BYREF
  __int64 v115; // [xsp+38h] [xbp-158h]
  __int64 v116; // [xsp+40h] [xbp-150h]
  __int64 v117; // [xsp+48h] [xbp-148h]
  __int64 v118; // [xsp+50h] [xbp-140h]
  __int64 v119; // [xsp+58h] [xbp-138h]
  __int64 v120; // [xsp+60h] [xbp-130h]
  __int64 v121; // [xsp+68h] [xbp-128h]
  __int64 v122; // [xsp+70h] [xbp-120h]
  int v123; // [xsp+78h] [xbp-118h]
  _QWORD v124[34]; // [xsp+80h] [xbp-110h] BYREF

  v2 = a1 + 20480;
  v124[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = to_gen7_gmu(a1);
  if ( (*(_BYTE *)(v2 + 4072) & 1) != 0 )
  {
    v4 = result;
    v123 = 0;
    v121 = 0;
    v122 = 0;
    v119 = 0;
    v120 = 0;
    v117 = 0;
    v118 = 0;
    v115 = 0;
    v116 = 0;
    src = 0;
    mutex_lock(a1 + 24640);
    v5 = *(_QWORD *)(v4 + 48);
    v8 = *(_QWORD *)(v5 + 8);
    v6 = (_QWORD *)(v5 + 8);
    v7 = v8;
    v9 = *(_DWORD **)(*(_QWORD *)(to_gen7_gmu(a1) + 48) + 8LL);
    if ( v9[18] )
    {
      v10 = (_QWORD **)(a1 + 24568);
      _ReadStatusReg(SP_EL0);
      do
      {
        if ( v9[28] == v9[29] )
          break;
        __dsb(0xDu);
        v13 = *(_DWORD *)(*v6 + 4LL * *(unsigned int *)(v7 + 112) + 4944);
        if ( !v13 )
          break;
        if ( (v13 & 0xF0000) == 0x10000 )
          v14 = 1;
        else
          v14 = (unsigned __int8)*(_DWORD *)(*v6 + 4LL * *(unsigned int *)(v7 + 112) + 4944);
        if ( v14 == 150 )
        {
          if ( (gen7_hfi_queue_read(v4, 1u, *(void **)(a1 + 22792), 0x400u) & 0x80000000) == 0 )
          {
            v15 = *(_QWORD *)(a1 + 1544);
            v16 = *(unsigned int **)(a1 + 22792);
            if ( (*(_WORD *)(a1 + 8282) & 0xFFE) != 0 )
            {
              if ( (adreno_hwsched_log_nonfatal_gpu_fault(a1, v15 + 16, v16[8]) & 1) == 0 )
              {
                switch ( v16[8] )
                {
                  case 0x259u:
                    v17 = &log_gpu_fault__rs_0;
                    v18 = "log_gpu_fault";
                    goto LABEL_37;
                  case 0x25Au:
                    v74 = gen7_hwsched_lookup_key_value(a1, 3, 1);
                    v98 = gen7_hwsched_lookup_key_value(a1, 3, 2);
                    payload_rb_key = adreno_hwsched_get_payload_rb_key(a1, v74, 2);
                    payload_rb_key_legacy = adreno_hwsched_get_payload_rb_key(a1, v74, 3);
                    v111 = adreno_hwsched_get_payload_rb_key(a1, v98, 2);
                    v99 = adreno_hwsched_get_payload_rb_key(a1, v98, 3);
                    v100 = &log_gpu_fault__rs_89;
                    v101 = "log_gpu_fault";
                    goto LABEL_229;
                  case 0x25Bu:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_83, "log_gpu_fault") )
                      goto LABEL_231;
                    v66 = v16[2];
                    v67 = v16[4];
                    goto LABEL_166;
                  case 0x25Cu:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_84, "log_gpu_fault") )
                      goto LABEL_231;
                    v80 = gen7_hwsched_lookup_key_value(a1, 1, 1);
                    goto LABEL_171;
                  case 0x25Du:
                    v58 = gen7_hwsched_lookup_key_value(a1, 1, 2);
                    v83 = &log_gpu_fault__rs_85;
                    v84 = "log_gpu_fault";
                    goto LABEL_150;
                  case 0x25Eu:
                    v68 = &log_gpu_fault__rs_86;
                    v69 = "log_gpu_fault";
                    goto LABEL_182;
                  case 0x25Fu:
                    v75 = &log_gpu_fault__rs_87;
                    v76 = "log_gpu_fault";
                    goto LABEL_191;
                  case 0x260u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_88, "log_gpu_fault") )
                      goto LABEL_231;
                    v77 = gen7_hwsched_lookup_key_value(a1, 1, 3);
                    goto LABEL_174;
                  case 0x261u:
                    v86 = &log_gpu_fault__rs_90;
                    v87 = "log_gpu_fault";
                    goto LABEL_203;
                  case 0x262u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_91, "log_gpu_fault") )
                      goto LABEL_231;
                    v85 = gen7_hwsched_lookup_key_value(a1, 1, 4);
                    goto LABEL_157;
                  case 0x263u:
                    v58 = gen7_hwsched_lookup_key_value(a1, 1, 5);
                    v59 = &log_gpu_fault__rs_92;
                    v60 = "log_gpu_fault";
                    goto LABEL_196;
                  case 0x264u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_93, "log_gpu_fault") )
                      goto LABEL_231;
                    v70 = gen7_hwsched_lookup_key_value(a1, 1, 6);
                    goto LABEL_148;
                  case 0x265u:
                    v63 = &log_gpu_fault__rs_95;
                    v64 = "log_gpu_fault";
                    goto LABEL_153;
                  case 0x266u:
                    v52 = &log_gpu_fault__rs_94;
                    v53 = "log_gpu_fault";
                    goto LABEL_188;
                  case 0x267u:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_96, "log_gpu_fault") )
                    {
                      v95 = (unsigned int)gen7_hwsched_lookup_key_value(a1, 1, 7);
                      dev_crit(v15 + 16, "CP LPAC opcode error | opcode=0x%8.8x\n", v95);
                    }
                    goto LABEL_231;
                  case 0x268u:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_104, "log_gpu_fault") )
                      dev_crit(v15 + 16, "CP LPAC ucode error interrupt\n");
                    goto LABEL_231;
                  case 0x269u:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_100, "log_gpu_fault") )
                    {
                      v94 = (unsigned int)gen7_hwsched_lookup_key_value(a1, 1, 9);
                      dev_crit(v15 + 16, "CP LPAC | Ringbuffer HW fault | status=0x%8.8x\n", v94);
                    }
                    goto LABEL_231;
                  case 0x26Au:
                    v58 = gen7_hwsched_lookup_key_value(a1, 1, 8);
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_98, "log_gpu_fault") )
                      goto LABEL_231;
                    _ZF = (v58 & 0x100000) == 0;
                    v97 = "CP LPAC | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_198;
                  case 0x26Bu:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_102, "log_gpu_fault") )
                      dev_crit(v15 + 16, "CP LPAC Illegal instruction error\n");
                    goto LABEL_231;
                  case 0x26Cu:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_106, "log_gpu_fault") )
                      dev_crit(v15 + 16, "LPAC: gpu timeout ctx %u ts %u\n", v16[5], v16[7]);
                    goto LABEL_231;
                  case 0x26Du:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_108, "log_gpu_fault") )
                      goto LABEL_231;
                    v78 = gen7_hwsched_lookup_key_value(a1, 1, 10);
                    goto LABEL_180;
                  case 0x26Eu:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_109, "log_gpu_fault") )
                      goto LABEL_231;
                    v79 = gen7_hwsched_lookup_key_value(a1, 1, 11);
                    goto LABEL_186;
                  case 0x26Fu:
                    v89 = &log_gpu_fault__rs_110;
                    v90 = "log_gpu_fault";
                    goto LABEL_209;
                  case 0x270u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_111, "log_gpu_fault") )
                      goto LABEL_231;
                    v88 = gen7_hwsched_lookup_key_value(a1, 1, 12);
                    goto LABEL_215;
                  case 0x271u:
                    v49 = &log_gpu_fault__rs_112;
                    v50 = "log_gpu_fault";
                    goto LABEL_162;
                  case 0x272u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_113, "log_gpu_fault") )
                      goto LABEL_231;
                    v65 = gen7_hwsched_lookup_key_value(a1, 1, 13);
                    goto LABEL_160;
                  case 0x273u:
                    v91 = &log_gpu_fault__rs_114;
                    v92 = "log_gpu_fault";
                    goto LABEL_224;
                  case 0x274u:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_115, "log_gpu_fault") )
                      goto LABEL_231;
                    v51 = gen7_hwsched_lookup_key_value(a1, 1, 14);
                    goto LABEL_141;
                  case 0x275u:
                    v61 = &log_gpu_fault__rs_116;
                    v62 = "log_gpu_fault";
                    goto LABEL_217;
                  case 0x276u:
                    if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_117, "log_gpu_fault") )
                      dev_crit(v15 + 16, "syncobj timeout ctx %d ts %u\n", v16[2], v16[4]);
                    v54 = v16[2];
                    v55 = v16[4];
                    goto LABEL_222;
                  default:
                    if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_118, "log_gpu_fault") )
                      goto LABEL_231;
                    v93 = v16[8];
                    goto LABEL_207;
                }
              }
              memset(*(void **)(a1 + 22792), 0, 0x400u);
              goto LABEL_5;
            }
            switch ( v16[4] )
            {
              case 0x259u:
                v17 = &log_gpu_fault_legacy__rs_0;
                v18 = "log_gpu_fault_legacy";
LABEL_37:
                if ( (unsigned int)__ratelimit(v17, v18) )
                  dev_crit(v15 + 16, "MISC: GPU hang detected\n");
                goto LABEL_231;
              case 0x25Au:
                v71 = *v16;
                if ( !*v16 || ((v71 >> 6) & 0x3FC) == 0x14 )
                {
                  v74 = 0;
                }
                else
                {
                  v72 = 0;
                  while ( 1 )
                  {
                    v73 = (_WORD *)((char *)v16 + v72 + 20);
                    if ( *v73 == 3 )
                      break;
                    v72 += 4 * (unsigned __int16)v73[1] + 4;
                    if ( v72 >= ((v71 >> 6) & 0x3FC) - 20 )
                    {
                      v74 = 0;
                      goto LABEL_243;
                    }
                  }
                  v105 = adreno_hwsched_parse_payload();
                  v16 = *(unsigned int **)(a1 + 22792);
                  v74 = v105;
                  v71 = *v16;
LABEL_243:
                  if ( v71 )
                  {
                    v106 = ((v71 >> 6) & 0x3FC) - 20;
                    if ( v106 )
                    {
                      v107 = 0;
                      while ( 1 )
                      {
                        v108 = (_WORD *)((char *)v16 + v107 + 20);
                        if ( *v108 == 3 )
                          break;
                        v107 += 4 * (unsigned __int16)v108[1] + 4;
                        if ( v107 >= v106 )
                          goto LABEL_227;
                      }
                      v98 = adreno_hwsched_parse_payload();
LABEL_228:
                      payload_rb_key = adreno_hwsched_get_payload_rb_key_legacy(a1, v74, 2);
                      payload_rb_key_legacy = adreno_hwsched_get_payload_rb_key_legacy(a1, v74, 3);
                      v111 = adreno_hwsched_get_payload_rb_key_legacy(a1, v98, 2);
                      v99 = adreno_hwsched_get_payload_rb_key_legacy(a1, v98, 3);
                      v100 = &log_gpu_fault_legacy__rs_37;
                      v101 = "log_gpu_fault_legacy";
LABEL_229:
                      if ( (unsigned int)__ratelimit(v100, v101) )
                        dev_crit(
                          v15 + 16,
                          "Preemption Fault: cur=%d R/W=0x%x/0x%x, next=%d R/W=0x%x/0x%x\n",
                          v74,
                          payload_rb_key,
                          payload_rb_key_legacy,
                          v98,
                          v111,
                          v99);
LABEL_231:
                      v103 = a1;
                      v104 = 2;
                      goto LABEL_232;
                    }
                  }
                }
LABEL_227:
                v98 = 0;
                goto LABEL_228;
              case 0x25Bu:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_23, "log_gpu_fault_legacy") )
                {
                  v66 = v16[1];
                  v67 = v16[3];
LABEL_166:
                  dev_crit(v15 + 16, "gpu timeout ctx %u ts %u\n", v66, v67);
                }
                goto LABEL_231;
              case 0x25Cu:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_25, "log_gpu_fault_legacy") )
                {
                  v80 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 1);
LABEL_171:
                  dev_crit(v15 + 16, "CP opcode error interrupt | opcode=0x%8.8x\n", v80);
                }
                goto LABEL_231;
              case 0x25Du:
                if ( !*v16 || ((*v16 >> 6) & 0x3FC) == 0x14 )
                {
LABEL_128:
                  v58 = 0;
                }
                else
                {
                  v81 = 0;
                  while ( 1 )
                  {
                    v82 = (_WORD *)((char *)v16 + v81 + 20);
                    if ( *v82 == 1 )
                      break;
                    v81 += 4 * (unsigned __int16)v82[1] + 4;
                    if ( v81 >= ((*v16 >> 6) & 0x3FC) - 20 )
                      goto LABEL_128;
                  }
                  v58 = adreno_hwsched_parse_payload();
                }
                v83 = &log_gpu_fault_legacy__rs_27;
                v84 = "log_gpu_fault_legacy";
LABEL_150:
                if ( (unsigned int)__ratelimit(v83, v84) )
                {
                  _ZF = (v58 & 0x100000) == 0;
                  v97 = "CP | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                  goto LABEL_198;
                }
                goto LABEL_231;
              case 0x25Eu:
                v68 = &log_gpu_fault_legacy__rs_31;
                v69 = "log_gpu_fault_legacy";
LABEL_182:
                if ( (unsigned int)__ratelimit(v68, v69) )
                  dev_crit(v15 + 16, "CP Illegal instruction error\n");
                goto LABEL_231;
              case 0x25Fu:
                v75 = &log_gpu_fault_legacy__rs_33;
                v76 = "log_gpu_fault_legacy";
LABEL_191:
                if ( (unsigned int)__ratelimit(v75, v76) )
                  dev_crit(v15 + 16, "CP ucode error interrupt\n");
                goto LABEL_231;
              case 0x260u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_35, "log_gpu_fault_legacy") )
                {
                  v77 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 3);
LABEL_174:
                  dev_crit(v15 + 16, "CP | Ringbuffer HW fault | status=0x%8.8x\n", v77);
                }
                goto LABEL_231;
              case 0x261u:
                v86 = &log_gpu_fault_legacy__rs_39;
                v87 = "log_gpu_fault_legacy";
LABEL_203:
                if ( (unsigned int)__ratelimit(v86, v87) )
                  dev_crit(v15 + 16, "RBBM: GPC error\n");
                goto LABEL_231;
              case 0x262u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_41, "log_gpu_fault_legacy") )
                {
                  v85 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 4);
LABEL_157:
                  dev_crit(v15 + 16, "CP BV opcode error | opcode=0x%8.8x\n", v85);
                }
                goto LABEL_231;
              case 0x263u:
                if ( !*v16 || ((*v16 >> 6) & 0x3FC) == 0x14 )
                {
LABEL_97:
                  v58 = 0;
                }
                else
                {
                  v56 = 0;
                  while ( 1 )
                  {
                    v57 = (_WORD *)((char *)v16 + v56 + 20);
                    if ( *v57 == 1 )
                      break;
                    v56 += 4 * (unsigned __int16)v57[1] + 4;
                    if ( v56 >= ((*v16 >> 6) & 0x3FC) - 20 )
                      goto LABEL_97;
                  }
                  v58 = adreno_hwsched_parse_payload();
                }
                v59 = &log_gpu_fault_legacy__rs_43;
                v60 = "log_gpu_fault_legacy";
LABEL_196:
                if ( (unsigned int)__ratelimit(v59, v60) )
                {
                  _ZF = (v58 & 0x100000) == 0;
                  v97 = "CP BV | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
LABEL_198:
                  if ( _ZF )
                    v102 = "WRITE";
                  else
                    v102 = "READ";
                  dev_crit(v15 + 16, v97, v102, v58 & 0x3FFFF, v58);
                }
                goto LABEL_231;
              case 0x264u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_45, "log_gpu_fault_legacy") )
                {
                  v70 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 6);
LABEL_148:
                  dev_crit(v15 + 16, "CP BV | Ringbuffer HW fault | status=0x%8.8x\n", v70);
                }
                goto LABEL_231;
              case 0x265u:
                v63 = &log_gpu_fault_legacy__rs_49;
                v64 = "log_gpu_fault_legacy";
LABEL_153:
                if ( (unsigned int)__ratelimit(v63, v64) )
                  dev_crit(v15 + 16, "CP BV ucode error interrupt\n");
                goto LABEL_231;
              case 0x266u:
                v52 = &log_gpu_fault_legacy__rs_47;
                v53 = "log_gpu_fault_legacy";
LABEL_188:
                if ( (unsigned int)__ratelimit(v52, v53) )
                  dev_crit(v15 + 16, "CP BV Illegal instruction error\n");
                goto LABEL_231;
              case 0x26Du:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_51, "log_gpu_fault_legacy") )
                {
                  v78 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 10);
LABEL_180:
                  dev_crit(v15 + 16, "RBBM: SW Feature Fuse violation status=0x%8.8x\n", v78);
                }
                goto LABEL_231;
              case 0x26Eu:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_53, "log_gpu_fault_legacy") )
                {
                  v79 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 11);
LABEL_186:
                  dev_crit(v15 + 16, "AQE0 opcode error | opcode=0x%8.8x\n", v79);
                }
                goto LABEL_231;
              case 0x26Fu:
                v89 = &log_gpu_fault_legacy__rs_55;
                v90 = "log_gpu_fault_legacy";
LABEL_209:
                if ( (unsigned int)__ratelimit(v89, v90) )
                  dev_crit(v15 + 16, "AQE0 ucode error interrupt\n");
                goto LABEL_231;
              case 0x270u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_57, "log_gpu_fault_legacy") )
                {
                  v88 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 12);
LABEL_215:
                  dev_crit(v15 + 16, "AQE0 HW fault | status=0x%8.8x\n", v88);
                }
                goto LABEL_231;
              case 0x271u:
                v49 = &log_gpu_fault_legacy__rs_59;
                v50 = "log_gpu_fault_legacy";
LABEL_162:
                if ( (unsigned int)__ratelimit(v49, v50) )
                  dev_crit(v15 + 16, "AQE0 Illegal instruction error\n");
                goto LABEL_231;
              case 0x272u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_61, "log_gpu_fault_legacy") )
                {
                  v65 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 13);
LABEL_160:
                  dev_crit(v15 + 16, "AQE1 opcode error | opcode=0x%8.8x\n", v65);
                }
                goto LABEL_231;
              case 0x273u:
                v91 = &log_gpu_fault_legacy__rs_63;
                v92 = "log_gpu_fault_legacy";
LABEL_224:
                if ( (unsigned int)__ratelimit(v91, v92) )
                  dev_crit(v15 + 16, "AQE1 ucode error interrupt\n");
                goto LABEL_231;
              case 0x274u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_65, "log_gpu_fault_legacy") )
                {
                  v51 = gen7_hwsched_lookup_key_value_legacy(a1, 1, 14);
LABEL_141:
                  dev_crit(v15 + 16, "AQE1 HW fault | status=0x%8.8x\n", v51);
                }
                goto LABEL_231;
              case 0x275u:
                v61 = &log_gpu_fault_legacy__rs_67;
                v62 = "log_gpu_fault_legacy";
LABEL_217:
                if ( (unsigned int)__ratelimit(v61, v62) )
                  dev_crit(v15 + 16, "AQE1 Illegal instruction error\n");
                goto LABEL_231;
              case 0x276u:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_69, "log_gpu_fault_legacy") )
                  dev_crit(v15 + 16, "syncobj timeout ctx %d ts %u\n", v16[1], v16[3]);
                v54 = v16[1];
                v55 = v16[3];
LABEL_222:
                find_timeout_syncobj(a1, v54, v55);
                goto LABEL_231;
              default:
                if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_71, "log_gpu_fault_legacy") )
                {
                  v93 = v16[4];
LABEL_207:
                  dev_crit(v15 + 16, "Unknown GPU fault: %u\n", v93);
                }
                goto LABEL_231;
            }
          }
        }
        else
        {
          if ( (gen7_hfi_queue_read(v4, 1u, &src, 0x4Cu) & 0x80000000) != 0 )
            break;
          if ( v14 <= 132 )
          {
            if ( v14 != 1 )
            {
              if ( v14 == 111 )
              {
                adreno_perfcounter_put(a1, HIDWORD(src), (unsigned int)v115, 1);
                gmu_core_mark_for_coldboot(a1);
              }
              goto LABEL_5;
            }
            v31 = HIDWORD(src);
            if ( BYTE4(src) == 151 )
            {
              raw_spin_lock(a1 + 23152);
              v32 = hw_fence_ack;
              if ( (_DWORD)hw_fence_ack )
              {
                LODWORD(hw_fence_ack) = hw_fence_ack & 0xFFF7FFFF;
                HIDWORD(src) &= ~0x80000u;
                if ( (v32 & 0xFFF7FFFF) == HIDWORD(src) )
                {
                  raw_spin_unlock(a1 + 23152);
                  complete(&qword_17BDD8);
                  goto LABEL_5;
                }
              }
              v38 = *(_DWORD *)(v2 + 2676) - 1;
              *(_DWORD *)(v2 + 2676) = v38;
              if ( v38 >= 0x15 )
              {
                dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "unexpected hardware fence unack count:%d\n", v38);
                v39 = v115;
                if ( (_DWORD)v115 )
                {
LABEL_235:
                  dev_err(
                    *(_QWORD *)(a1 + 1544) + 16LL,
                    "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n",
                    HIDWORD(src),
                    v39);
                  raw_spin_unlock(a1 + 23152);
                  v103 = a1;
                  v104 = 14;
LABEL_232:
                  gen7_hwsched_fault(v103, v104);
                  goto LABEL_5;
                }
              }
              else
              {
                v39 = v115;
                if ( (_DWORD)v115 )
                  goto LABEL_235;
              }
              if ( (*(_QWORD *)(a1 + 23200) & 2) == 0 || *(_DWORD *)(v2 + 2676) != 10 )
              {
                raw_spin_unlock(a1 + 23152);
                goto LABEL_5;
              }
              v40 = *(_QWORD *)(a1 + 23184);
              raw_spin_unlock(a1 + 23152);
              timer_delete_sync(a1 + 24688);
              if ( !v40 )
              {
                disable_hw_fence_throttle(a1, 0);
                goto LABEL_5;
              }
              v30 = (_QWORD *)(a1 + 24776);
              *(_QWORD *)(a1 + 24800) = 0;
              *(_QWORD *)(a1 + 24808) = 0;
              *(_QWORD *)(a1 + 24776) = a1 + 24776;
              *(_QWORD *)(a1 + 24784) = a1 + 24776;
              v29 = *(_QWORD *)(a1 + 24400);
              *(_QWORD *)(a1 + 24792) = gen7_defer_hw_fence_work;
              goto LABEL_40;
            }
            v33 = *(_QWORD *)(a1 + 1544);
            v34 = 4 * BYTE1(src);
            if ( v34 >= 0x4D && (unsigned int)__ratelimit(&gen7_receive_ack_async__rs, "gen7_receive_ack_async") )
              dev_err(v33 + 16, "Ack result too big: %d Truncating to: %ld\n", v34, 76);
            memset(v124, 0, 256);
            raw_read_lock(a1 + 24556);
            v35 = *v10;
            if ( *v10 != v10 )
            {
              v36 = 0;
              v31 &= ~0x80000u;
              while ( 1 )
              {
                v37 = *(_DWORD *)(v35 - 14) & 0xFFF7FFFF;
                *((_DWORD *)v35 - 28) = v37;
                if ( v37 == v31 )
                  break;
                if ( v36 <= 0x3F )
                  *((_DWORD *)v124 + v36++) = v37;
                v35 = (_QWORD *)*v35;
                if ( v35 == v10 )
                  goto LABEL_69;
              }
              if ( v34 >= 0x4C )
                v48 = 76;
              else
                v48 = v34;
              memcpy((char *)v35 - 108, &src, v48);
              complete(v35 - 4);
              raw_read_unlock(a1 + 24556);
              goto LABEL_5;
            }
            v36 = 0;
LABEL_69:
            raw_read_unlock(a1 + 24556);
            if ( (unsigned int)__ratelimit(&gen7_receive_ack_async__rs_18, "gen7_receive_ack_async") )
            {
              if ( v36 >= 5 )
                LODWORD(v45) = 5;
              else
                LODWORD(v45) = v36;
              dev_err(
                v33 + 16,
                "Unexpectedly got id %d seqnum %d. Total waiters: %d Top %d Waiters:\n",
                (unsigned __int8)v31,
                v31 >> 20,
                v36,
                v45);
              if ( v36 )
              {
LABEL_74:
                v46 = 0;
                v47 = 0;
                v45 = (unsigned int)v45;
                do
                {
                  if ( (unsigned int)__ratelimit(&gen7_receive_ack_async__rs_20, "gen7_receive_ack_async") )
                  {
                    if ( (v47 & 0x3FFFFFFFFFFFFFC0LL) != 0 || v46 > 0x100 )
                      __break(1u);
                    dev_err(
                      v33 + 16,
                      " id %d seqnum %d\n",
                      (unsigned __int8)*(_DWORD *)((char *)v124 + v46),
                      *(_DWORD *)((char *)v124 + v46) >> 20);
                  }
                  --v45;
                  ++v47;
                  v46 += 4LL;
                }
                while ( v45 );
              }
            }
            else
            {
              if ( v36 >= 5 )
                LODWORD(v45) = 5;
              else
                LODWORD(v45) = v36;
              if ( v36 )
                goto LABEL_74;
            }
          }
          else
          {
            if ( v14 == 133 )
            {
              adreno_hwsched_log_profiling_info(a1, &src);
              v29 = *(_QWORD *)(a1 + 24400);
              v30 = (_QWORD *)(a1 + 24408);
LABEL_40:
              kthread_queue_work(v29, v30);
              goto LABEL_5;
            }
            if ( v14 == 153 )
            {
              v19 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
              if ( *((_DWORD *)v19 - 1) != -944375624 )
                __break(0x8228u);
              v19(a1);
              raw_read_lock(a1 + 11208);
              v20 = (unsigned int *)idr_find(a1 + 11184, (unsigned int)v115);
              if ( !v20 )
              {
                raw_read_unlock(a1 + 11208);
                goto LABEL_5;
              }
              v21 = *v20;
              _X22 = v20;
              if ( *v20 )
              {
                do
                {
                  __asm { PRFM            #0x11, [X22] }
                  do
                    v28 = __ldxr(v20);
                  while ( v28 == v21 && __stxr(v21 + 1, v20) );
                  v23 = v21;
                  if ( v28 == v21 )
                    break;
                  v23 = 0;
                  v21 = v28;
                }
                while ( v28 );
              }
              else
              {
                v23 = 0;
              }
              if ( (((v23 + 1) | v23) & 0x80000000) != 0 )
                refcount_warn_saturate(v20, 0);
              raw_read_unlock(a1 + 11208);
              if ( !v23 )
                goto LABEL_5;
              v41 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
              if ( !v41 )
              {
                __asm { PRFM            #0x11, [X22] }
                do
                  v110 = __ldxr(_X22);
                while ( __stlxr(v110 - 1, _X22) );
                if ( v110 == 1 )
                {
                  __dmb(9u);
                  kgsl_context_destroy(_X22);
                }
                else if ( v110 <= 0 )
                {
                  refcount_warn_saturate(_X22, 3);
                }
                goto LABEL_5;
              }
              v30 = v41 + 5;
              v41[8] = 0;
              v41[9] = 0;
              v41[5] = v41 + 5;
              v41[6] = v41 + 5;
              v41[7] = gen7_process_syncobj_query_work;
              v42 = src;
              v43 = v115;
              v41[4] = _X22;
              *v41 = v42;
              v41[1] = v43;
              v44 = v117;
              v41[2] = v116;
              v41[3] = v44;
              v29 = *(_QWORD *)(a1 + 24400);
              goto LABEL_40;
            }
          }
        }
LABEL_5:
        v11 = *(_QWORD *)(v4 + 48);
        v12 = *(_QWORD *)(v11 + 8);
        v6 = (_QWORD *)(v11 + 8);
        v7 = v12;
        v9 = *(_DWORD **)(*(_QWORD *)(to_gen7_gmu(a1) + 48) + 8LL);
      }
      while ( v9[18] );
    }
    result = mutex_unlock(a1 + 24640);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
