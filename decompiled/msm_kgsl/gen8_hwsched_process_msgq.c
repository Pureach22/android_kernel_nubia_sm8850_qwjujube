__int64 __fastcall gen8_hwsched_process_msgq(__int64 a1)
{
  __int64 v2; // x28
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  _QWORD *v6; // x21
  __int64 v7; // x22
  __int64 v8; // t1
  _DWORD *v9; // x8
  _QWORD **v10; // x26
  __int64 v11; // x21
  __int64 v12; // t1
  int v13; // w8
  int v14; // w21
  unsigned int *v15; // x22
  __int64 v16; // x21
  unsigned int v17; // w24
  int v18; // w8
  void (__fastcall *v19)(_QWORD); // x8
  unsigned int *v20; // x0
  unsigned int v21; // w8
  unsigned int v23; // w21
  unsigned int v28; // w9
  __int64 v29; // x25
  unsigned int v30; // w22
  _QWORD *v31; // x21
  unsigned int v32; // w27
  unsigned int v33; // w8
  unsigned int v34; // w2
  int v35; // w3
  __int64 v36; // x21
  __int64 v37; // x0
  _QWORD *v38; // x0
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 v41; // x8
  __int64 v42; // x21
  unsigned __int64 v43; // x22
  __int64 v44; // x24
  size_t v45; // x2
  __int64 v46; // x2
  __int64 v47; // x2
  __int64 v48; // x2
  __int64 v49; // x2
  __int64 v50; // x2
  __int64 v51; // x2
  __int64 v52; // x2
  __int64 v53; // x2
  unsigned int v54; // w22
  const char *v56; // x1
  __int64 v57; // x2
  __int64 v58; // x2
  __int64 v59; // x2
  __int64 v60; // x2
  __int64 v61; // x2
  __int64 v62; // x2
  __int64 v63; // x2
  unsigned int v64; // w22
  unsigned int v65; // w27
  __int64 v66; // x2
  __int64 v67; // x2
  __int64 v68; // x2
  __int64 v69; // x2
  __int64 v70; // x2
  __int64 v71; // x2
  __int64 v72; // x2
  const char *v73; // x2
  _DWORD *v74; // x9
  unsigned int v75; // w8
  unsigned int v76; // w10
  _DWORD *v77; // x9
  _WORD *v78; // x0
  int v79; // w0
  int v81; // w8
  int v82; // [xsp+8h] [xbp-188h]
  int v83; // [xsp+Ch] [xbp-184h]
  int v84; // [xsp+10h] [xbp-180h]
  int payload_rb_key; // [xsp+14h] [xbp-17Ch]
  __int64 v86; // [xsp+28h] [xbp-168h]
  __int64 src; // [xsp+30h] [xbp-160h] BYREF
  __int64 v88; // [xsp+38h] [xbp-158h]
  __int64 v89; // [xsp+40h] [xbp-150h]
  __int64 v90; // [xsp+48h] [xbp-148h]
  __int64 v91; // [xsp+50h] [xbp-140h]
  __int64 v92; // [xsp+58h] [xbp-138h]
  __int64 v93; // [xsp+60h] [xbp-130h]
  __int64 v94; // [xsp+68h] [xbp-128h]
  __int64 v95; // [xsp+70h] [xbp-120h]
  int v96; // [xsp+78h] [xbp-118h]
  _QWORD v97[34]; // [xsp+80h] [xbp-110h] BYREF

  v2 = a1 + 23156;
  v97[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = to_gen8_gmu(a1);
  if ( (*(_BYTE *)(v2 + 1460) & 1) != 0 )
  {
    v4 = result;
    v96 = 0;
    v94 = 0;
    v95 = 0;
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
    v88 = 0;
    v89 = 0;
    src = 0;
    mutex_lock(a1 + 24696);
    v5 = *(_QWORD *)(v4 + 48);
    v8 = *(_QWORD *)(v5 + 8);
    v6 = (_QWORD *)(v5 + 8);
    v7 = v8;
    v9 = *(_DWORD **)(*(_QWORD *)(to_gen8_gmu(a1) + 48) + 8LL);
    if ( v9[18] )
    {
      v10 = (_QWORD **)(a1 + 24632);
      v86 = a1 + 24832;
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
          if ( (gen8_hfi_queue_read(v4, 1u, *(void **)(a1 + 22792), 0x400u) & 0x80000000) == 0 )
          {
            v15 = *(unsigned int **)(a1 + 22792);
            v16 = *(_QWORD *)(a1 + 1544);
            if ( (adreno_hwsched_log_nonfatal_gpu_fault(a1, v16 + 16, v15[8]) & 1) != 0 )
            {
              memset(*(void **)(a1 + 22792), 0, 0x400u);
            }
            else
            {
              switch ( v15[8] )
              {
                case 0x259u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_1, "log_gpu_fault") )
                    dev_crit(v16 + 16, "MISC: GPU hang detected\n");
                  break;
                case 0x25Au:
                  v64 = gen8_hwsched_lookup_key_value(a1, 3, 1);
                  v65 = gen8_hwsched_lookup_key_value(a1, 3, 2);
                  payload_rb_key = adreno_hwsched_get_payload_rb_key(a1, v64, 2);
                  v84 = adreno_hwsched_get_payload_rb_key(a1, v64, 3);
                  v83 = adreno_hwsched_get_payload_rb_key(a1, v65, 2);
                  v82 = adreno_hwsched_get_payload_rb_key(a1, v65, 3);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_44, "log_gpu_fault") )
                    dev_crit(
                      v16 + 16,
                      "Preemption Fault: cur=%d R/W=0x%x/0x%x, next=%d R/W=0x%x/0x%x\n",
                      v64,
                      payload_rb_key,
                      v84,
                      v65,
                      v83,
                      v82);
                  break;
                case 0x25Bu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_30, "log_gpu_fault") )
                    dev_crit(v16 + 16, "gpu timeout ctx %u ts %u\n", v15[2], v15[4]);
                  break;
                case 0x25Cu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_32_0, "log_gpu_fault") )
                  {
                    v62 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 1);
                    dev_crit(v16 + 16, "CP opcode error interrupt | opcode=0x%8.8x\n", v62);
                  }
                  break;
                case 0x25Du:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 2);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_34_0, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x25Eu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_38_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP Illegal instruction error\n");
                  break;
                case 0x25Fu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_40_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP ucode error interrupt\n");
                  break;
                case 0x260u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_42, "log_gpu_fault") )
                  {
                    v63 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 3);
                    dev_crit(v16 + 16, "CP | Ringbuffer HW fault | status=0x%8.8x\n", v63);
                  }
                  break;
                case 0x261u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_46, "log_gpu_fault") )
                    dev_crit(v16 + 16, "RBBM: GPC error\n");
                  break;
                case 0x262u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_48, "log_gpu_fault") )
                  {
                    v60 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 4);
                    dev_crit(v16 + 16, "CP BV opcode error | opcode=0x%8.8x\n", v60);
                  }
                  break;
                case 0x263u:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 5);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_50, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP BV | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x264u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_52, "log_gpu_fault") )
                  {
                    v58 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 6);
                    dev_crit(v16 + 16, "CP BV | Ringbuffer HW fault | status=0x%8.8x\n", v58);
                  }
                  break;
                case 0x265u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_56, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP BV ucode error interrupt\n");
                  break;
                case 0x266u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_54, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP BV Illegal instruction error\n");
                  break;
                case 0x267u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_58, "log_gpu_fault") )
                  {
                    v53 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 7);
                    dev_crit(v16 + 16, "CP LPAC opcode error | opcode=0x%8.8x\n", v53);
                  }
                  break;
                case 0x268u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_66, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP LPAC ucode error interrupt\n");
                  break;
                case 0x269u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_62, "log_gpu_fault") )
                  {
                    v51 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 9);
                    dev_crit(v16 + 16, "CP LPAC | Ringbuffer HW fault | status=0x%8.8x\n", v51);
                  }
                  break;
                case 0x26Au:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 8);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_60, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP LPAC | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x26Bu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_64, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP LPAC Illegal instruction error\n");
                  break;
                case 0x26Cu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_68, "log_gpu_fault") )
                    dev_crit(v16 + 16, "LPAC: gpu timeout ctx %u ts %u\n", v15[5], v15[7]);
                  break;
                case 0x26Du:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_70, "log_gpu_fault") )
                  {
                    v68 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 10);
                    dev_crit(v16 + 16, "RBBM: SW Feature Fuse violation status=0x%8.8x\n", v68);
                  }
                  break;
                case 0x26Eu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_72, "log_gpu_fault") )
                  {
                    v69 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 11);
                    dev_crit(v16 + 16, "AQE0 opcode error | opcode=0x%8.8x\n", v69);
                  }
                  break;
                case 0x26Fu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_74, "log_gpu_fault") )
                    dev_crit(v16 + 16, "AQE0 ucode error interrupt\n");
                  break;
                case 0x270u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_76, "log_gpu_fault") )
                  {
                    v72 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 12);
                    dev_crit(v16 + 16, "AQE0 HW fault | status=0x%8.8x\n", v72);
                  }
                  break;
                case 0x271u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_78, "log_gpu_fault") )
                    dev_crit(v16 + 16, "AQE0 Illegal instruction error\n");
                  break;
                case 0x272u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_80, "log_gpu_fault") )
                  {
                    v61 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 13);
                    dev_crit(v16 + 16, "AQE1 opcode error | opcode=0x%8.8x\n", v61);
                  }
                  break;
                case 0x273u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_82, "log_gpu_fault") )
                    dev_crit(v16 + 16, "AQE1 ucode error interrupt\n");
                  break;
                case 0x274u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_84_0, "log_gpu_fault") )
                  {
                    v50 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 14);
                    dev_crit(v16 + 16, "AQE1 HW fault | status=0x%8.8x\n", v50);
                  }
                  break;
                case 0x275u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_86_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "AQE1 Illegal instruction error\n");
                  break;
                case 0x276u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_88_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "syncobj timeout ctx %d ts %u\n", v15[2], v15[4]);
                  find_timeout_syncobj_0(a1, v15[2], v15[4]);
                  break;
                case 0x277u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_90_0, "log_gpu_fault") )
                  {
                    v70 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 24);
                    dev_crit(v16 + 16, "CP DDE BR | Ringbuffer HW fault | status=0x%8.8x\n", v70);
                  }
                  break;
                case 0x278u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_92_0, "log_gpu_fault") )
                  {
                    v66 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 22);
                    dev_crit(v16 + 16, "CP DDE BR opcode error | opcode=0x%8.8x\n", v66);
                  }
                  break;
                case 0x279u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_94_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP DDE BR ucode error\n");
                  break;
                case 0x27Au:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 23);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_96_0, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP DDE BR | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x27Bu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_98_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP DDEBR Illegal instruction error\n");
                  break;
                case 0x27Cu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_100_0, "log_gpu_fault") )
                  {
                    v48 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 28);
                    dev_crit(v16 + 16, "CP DDE BV | Ringbuffer HW fault | status=0x%8.8x\n", v48);
                  }
                  break;
                case 0x27Du:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_102_0, "log_gpu_fault") )
                  {
                    v49 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 26);
                    dev_crit(v16 + 16, "CP DDE BV opcode error | opcode=0x%8.8x\n", v49);
                  }
                  break;
                case 0x27Eu:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_104_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP DDE BV ucode error\n");
                  break;
                case 0x27Fu:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 27);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_106_0, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP DDE BV | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x280u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_108_0, "log_gpu_fault") )
                    dev_crit(v16 + 16, "CP DDE BV Illegal instruction error\n");
                  break;
                case 0x281u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_110_0, "log_gpu_fault") )
                  {
                    v59 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 15);
                    dev_crit(v16 + 16, "CP BR | SW fault | status=0x%8.8x\n", v59);
                  }
                  break;
                case 0x282u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_112_0, "log_gpu_fault") )
                  {
                    v67 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 16);
                    dev_crit(v16 + 16, "CP BV | SW fault | status=0x%8.8x\n", v67);
                  }
                  break;
                case 0x283u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_114_0, "log_gpu_fault") )
                  {
                    v71 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 17);
                    dev_crit(v16 + 16, "CP LPAC | SW fault | status=0x%8.8x\n", v71);
                  }
                  break;
                case 0x284u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_116_0, "log_gpu_fault") )
                  {
                    v46 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 18);
                    dev_crit(v16 + 16, "CP AQE0 | SW fault | status=0x%8.8x\n", v46);
                  }
                  break;
                case 0x285u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_118_0, "log_gpu_fault") )
                  {
                    v52 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 20);
                    dev_crit(v16 + 16, "CP AQE1 | SW fault | status=0x%8.8x\n", v52);
                  }
                  break;
                case 0x286u:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 19);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_120, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP AQE0 | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
                    goto LABEL_182;
                  }
                  break;
                case 0x287u:
                  v54 = gen8_hwsched_lookup_key_value(a1, 1, 21);
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_122, "log_gpu_fault") )
                  {
                    _ZF = (v54 & 0x100000) == 0;
                    v56 = "CP AQE1 | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n";
LABEL_182:
                    if ( _ZF )
                      v73 = "WRITE";
                    else
                      v73 = "READ";
                    dev_crit(v16 + 16, v56, v73, v54 & 0x3FFFF, v54);
                  }
                  break;
                case 0x288u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_124, "log_gpu_fault") )
                  {
                    v47 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 25);
                    dev_crit(v16 + 16, "CP DDE BR | SW fault | status=0x%8.8x\n", v47);
                  }
                  break;
                case 0x289u:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_126, "log_gpu_fault") )
                  {
                    v57 = (unsigned int)gen8_hwsched_lookup_key_value(a1, 1, 29);
                    dev_crit(v16 + 16, "CP DDE BV | SW fault | status=0x%8.8x\n", v57);
                  }
                  break;
                default:
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_128, "log_gpu_fault") )
                    dev_crit(v16 + 16, "Unknown GPU fault: %u\n", v15[8]);
                  break;
              }
              v74 = *(_DWORD **)(a1 + 22792);
              if ( !*v74 || (v75 = ((*v74 >> 6) & 0x3FC) - 36, ((*v74 >> 6) & 0x3FC) == 0x24) )
              {
LABEL_193:
                v79 = 0;
              }
              else
              {
                v76 = 0;
                v77 = v74 + 9;
                while ( 1 )
                {
                  v78 = (_WORD *)((char *)v77 + v76);
                  if ( *v78 == 4 )
                    break;
                  v76 += 4 * (unsigned __int16)v78[1] + 4;
                  if ( v76 >= v75 )
                    goto LABEL_193;
                }
                v79 = adreno_hwsched_parse_payload();
              }
              *(_DWORD *)(v2 + 284) = v79;
              gen8_hwsched_fault(a1, 2);
            }
          }
          goto LABEL_5;
        }
        if ( (gen8_hfi_queue_read(v4, 1u, &src, 0x4Cu) & 0x80000000) != 0 )
          break;
        if ( v14 > 149 )
        {
          if ( v14 == 153 )
          {
            v19 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
            if ( *((_DWORD *)v19 - 1) != -944375624 )
              __break(0x8228u);
            v19(a1);
            raw_read_lock(a1 + 11208);
            v20 = (unsigned int *)idr_find(a1 + 11184, (unsigned int)v88);
            if ( v20 )
            {
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
              if ( v23 )
              {
                v38 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
                if ( v38 )
                {
                  v38[8] = 0;
                  v38[9] = 0;
                  v38[5] = v38 + 5;
                  v38[6] = v38 + 5;
                  v38[7] = gen8_process_syncobj_query_work;
                  v39 = src;
                  v40 = v88;
                  v38[4] = _X22;
                  *v38 = v39;
                  v38[1] = v40;
                  v41 = v90;
                  v38[2] = v89;
                  v38[3] = v41;
                  kthread_queue_work(*(_QWORD *)(a1 + 24400), v38 + 5);
                }
                else
                {
                  __asm { PRFM            #0x11, [X22] }
                  do
                    v81 = __ldxr(_X22);
                  while ( __stlxr(v81 - 1, _X22) );
                  if ( v81 == 1 )
                  {
                    __dmb(9u);
                    kgsl_context_destroy(_X22);
                  }
                  else if ( v81 <= 0 )
                  {
                    refcount_warn_saturate(_X22, 3);
                  }
                }
              }
            }
            else
            {
              raw_read_unlock(a1 + 11208);
            }
          }
          else if ( v14 == 200 && !HIDWORD(src) && (_DWORD)v88 && (unsigned int)v88 <= *(_DWORD *)(a1 + 8388) )
          {
            gmu_core_clock_set_rate(a1, (unsigned int)(v88 - 1));
          }
          goto LABEL_5;
        }
        if ( v14 != 1 )
        {
          if ( v14 == 111 )
          {
            adreno_perfcounter_put(a1, HIDWORD(src), (unsigned int)v88, 1);
            gmu_core_mark_for_coldboot(a1);
          }
          else if ( v14 == 133 )
          {
            adreno_hwsched_log_profiling_info(a1, &src);
            kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
          }
          goto LABEL_5;
        }
        v17 = HIDWORD(src);
        if ( BYTE4(src) == 151 )
        {
          raw_spin_lock(a1 + 23152);
          v18 = gen8_hw_fence_ack;
          if ( (_DWORD)gen8_hw_fence_ack
            && (LODWORD(gen8_hw_fence_ack) = gen8_hw_fence_ack & 0xFFF7FFFF,
                HIDWORD(src) &= ~0x80000u,
                (v18 & 0xFFF7FFFF) == HIDWORD(src)) )
          {
            raw_spin_unlock(a1 + 23152);
            complete(&qword_17C200);
          }
          else
          {
            v34 = *(_DWORD *)v2 - 1;
            *(_DWORD *)v2 = v34;
            if ( v34 >= 0x15 )
            {
              dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "unexpected hardware fence unack count:%d\n", v34);
              v35 = v88;
              if ( !(_DWORD)v88 )
              {
LABEL_57:
                if ( (*(_QWORD *)(a1 + 23200) & 2) != 0 && *(_DWORD *)v2 == 10 )
                {
                  v36 = *(_QWORD *)(a1 + 23184);
                  raw_spin_unlock(a1 + 23152);
                  timer_delete_sync(a1 + 24744);
                  if ( v36 )
                  {
                    *(_QWORD *)(a1 + 24856) = 0;
                    *(_QWORD *)(a1 + 24864) = 0;
                    *(_QWORD *)(a1 + 24832) = a1 + 24832;
                    *(_QWORD *)(a1 + 24840) = v86;
                    v37 = *(_QWORD *)(a1 + 24400);
                    *(_QWORD *)(a1 + 24848) = gen8_defer_hw_fence_work;
                    kthread_queue_work(v37, v86);
                  }
                  else
                  {
                    disable_hw_fence_throttle_0(a1, 0);
                  }
                }
                else
                {
                  raw_spin_unlock(a1 + 23152);
                }
                goto LABEL_5;
              }
            }
            else
            {
              v35 = v88;
              if ( !(_DWORD)v88 )
                goto LABEL_57;
            }
            dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", HIDWORD(src), v35);
            raw_spin_unlock(a1 + 23152);
            gen8_hwsched_fault(a1, 14);
          }
        }
        else
        {
          v29 = *(_QWORD *)(a1 + 1544);
          v30 = 4 * BYTE1(src);
          if ( v30 >= 0x4D && (unsigned int)__ratelimit(&gen8_receive_ack_async__rs, "gen8_receive_ack_async") )
            dev_err(v29 + 16, "Ack result too big: %d Truncating to: %ld\n", v30, 76);
          memset(v97, 0, 256);
          raw_read_lock(a1 + 24620);
          v31 = *v10;
          if ( *v10 != v10 )
          {
            v32 = 0;
            v17 &= ~0x80000u;
            while ( 1 )
            {
              v33 = *(_DWORD *)(v31 - 14) & 0xFFF7FFFF;
              *((_DWORD *)v31 - 28) = v33;
              if ( v33 == v17 )
                break;
              if ( v32 <= 0x3F )
                *((_DWORD *)v97 + v32++) = v33;
              v31 = (_QWORD *)*v31;
              if ( v31 == v10 )
                goto LABEL_69;
            }
            if ( v30 >= 0x4C )
              v45 = 76;
            else
              v45 = v30;
            memcpy((char *)v31 - 108, &src, v45);
            complete(v31 - 4);
            raw_read_unlock(a1 + 24620);
            goto LABEL_5;
          }
          v32 = 0;
LABEL_69:
          raw_read_unlock(a1 + 24620);
          if ( (unsigned int)__ratelimit(&gen8_receive_ack_async__rs_25, "gen8_receive_ack_async") )
          {
            if ( v32 >= 5 )
              LODWORD(v42) = 5;
            else
              LODWORD(v42) = v32;
            dev_err(
              v29 + 16,
              "Unexpectedly got id %d seqnum %d. Total waiters: %d Top %d Waiters:\n",
              (unsigned __int8)v17,
              v17 >> 20,
              v32,
              v42);
            if ( v32 )
            {
LABEL_74:
              v43 = 0;
              v44 = 0;
              v42 = (unsigned int)v42;
              do
              {
                if ( (unsigned int)__ratelimit(&gen8_receive_ack_async__rs_27, "gen8_receive_ack_async") )
                {
                  if ( (v44 & 0x3FFFFFFFFFFFFFC0LL) != 0 || v43 > 0x100 )
                    __break(1u);
                  dev_err(
                    v29 + 16,
                    " id %d seqnum %d\n",
                    (unsigned __int8)*(_DWORD *)((char *)v97 + v43),
                    *(_DWORD *)((char *)v97 + v43) >> 20);
                }
                --v42;
                ++v44;
                v43 += 4LL;
              }
              while ( v42 );
            }
          }
          else
          {
            if ( v32 >= 5 )
              LODWORD(v42) = 5;
            else
              LODWORD(v42) = v32;
            if ( v32 )
              goto LABEL_74;
          }
        }
LABEL_5:
        v11 = *(_QWORD *)(v4 + 48);
        v12 = *(_QWORD *)(v11 + 8);
        v6 = (_QWORD *)(v11 + 8);
        v7 = v12;
        v9 = *(_DWORD **)(*(_QWORD *)(to_gen8_gmu(a1) + 48) + 8LL);
      }
      while ( v9[18] );
    }
    result = mutex_unlock(a1 + 24696);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
