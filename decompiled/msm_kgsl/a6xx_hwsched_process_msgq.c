__int64 __fastcall a6xx_hwsched_process_msgq(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  _DWORD *v4; // x8
  _QWORD **v5; // x28
  int v6; // w8
  __int64 v7; // x22
  unsigned int *v8; // x24
  int v9; // w8
  __int64 v10; // x22
  unsigned int v11; // w25
  unsigned int v12; // w21
  _QWORD *v13; // x27
  unsigned int v14; // w24
  unsigned int v15; // w8
  int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w10
  _WORD *v19; // x0
  unsigned int v20; // w21
  __int64 v21; // x21
  unsigned __int64 v22; // x24
  __int64 v23; // x25
  unsigned int v24; // w8
  unsigned int v25; // w10
  _WORD *v26; // x0
  size_t v27; // x2
  _DWORD *v28; // x9
  unsigned int v29; // w8
  unsigned int v30; // w10
  _DWORD *v31; // x9
  _WORD *v32; // x0
  __int64 v33; // x2
  unsigned int v34; // w0
  int v35; // w2
  int v36; // w3
  unsigned int v37; // w10
  _WORD *v38; // x0
  int v39; // w21
  _DWORD *v40; // x9
  unsigned int v41; // w8
  unsigned int v42; // w10
  _DWORD *v43; // x9
  _WORD *v44; // x0
  __int64 v45; // x2
  __int64 v46; // x2
  unsigned int v47; // w24
  int v48; // w27
  int v49; // w25
  unsigned int v50; // w10
  _WORD *v51; // x0
  const char *v52; // x2
  unsigned int v53; // w0
  unsigned int v54; // w0
  unsigned int v55; // w8
  unsigned int v56; // w10
  _WORD *v57; // x0
  unsigned int v58; // w0
  unsigned int v59; // w8
  unsigned int v60; // w10
  _WORD *v61; // x0
  unsigned int v68; // w9
  int payload_rb_key_legacy; // [xsp+0h] [xbp-170h]
  int payload_rb_key; // [xsp+4h] [xbp-16Ch]
  __int64 src; // [xsp+10h] [xbp-160h] BYREF
  __int64 v72; // [xsp+18h] [xbp-158h]
  __int64 v73; // [xsp+20h] [xbp-150h]
  __int64 v74; // [xsp+28h] [xbp-148h]
  __int64 v75; // [xsp+30h] [xbp-140h]
  __int64 v76; // [xsp+38h] [xbp-138h]
  __int64 v77; // [xsp+40h] [xbp-130h]
  __int64 v78; // [xsp+48h] [xbp-128h]
  __int64 v79; // [xsp+50h] [xbp-120h]
  int v80; // [xsp+58h] [xbp-118h]
  _QWORD v81[34]; // [xsp+60h] [xbp-110h] BYREF

  v81[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = to_a6xx_gmu(a1);
  if ( (*(_BYTE *)(a1 + 24544) & 1) != 0 )
  {
    v3 = result;
    v80 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    src = 0;
    mutex_lock(a1 + 24632);
    v4 = *(_DWORD **)(*(_QWORD *)(v3 + 40) + 8LL);
    if ( v4[18] )
    {
      v5 = (_QWORD **)(a1 + 24560);
      while ( 1 )
      {
        if ( v4[28] == v4[29] )
          goto LABEL_175;
        v6 = v4[v4[28] + 1236];
        if ( !v6 )
          goto LABEL_175;
        if ( (unsigned __int8)v6 == 150 )
          break;
        a6xx_hfi_queue_read(v3, 1u, &src, 0x4Cu);
        if ( (src & 0xF0000) != 0x10000 )
        {
          if ( (unsigned __int8)src == 111 )
          {
            adreno_perfcounter_put(a1, HIDWORD(src), (unsigned int)v72, 1);
          }
          else if ( (unsigned __int8)src == 133 )
          {
            kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
            adreno_hwsched_log_profiling_info(a1, &src);
          }
          goto LABEL_5;
        }
        v10 = *(_QWORD *)(a1 + 1544);
        v11 = HIDWORD(src);
        v12 = ((unsigned int)src >> 6) & 0x3FC;
        if ( v12 >= 0x4D && (unsigned int)__ratelimit(&a6xx_receive_ack_async__rs, "a6xx_receive_ack_async") )
          dev_err(v10 + 16, "Ack result too big: %d Truncating to: %ld\n", v12, 76);
        memset(v81, 0, 256);
        raw_read_lock(a1 + 24548);
        v13 = *v5;
        if ( *v5 != v5 )
        {
          v14 = 0;
          v11 &= ~0x80000u;
          while ( 1 )
          {
            v15 = *(_DWORD *)(v13 - 14) & 0xFFF7FFFF;
            *((_DWORD *)v13 - 28) = v15;
            if ( v15 == v11 )
              break;
            if ( v14 <= 0x3F )
              *((_DWORD *)v81 + v14++) = v15;
            v13 = (_QWORD *)*v13;
            if ( v13 == v5 )
              goto LABEL_47;
          }
          if ( v12 >= 0x4C )
            v27 = 76;
          else
            v27 = v12;
          memcpy((char *)v13 - 108, &src, v27);
          complete(v13 - 4);
          raw_read_unlock(a1 + 24548);
          goto LABEL_5;
        }
        v14 = 0;
LABEL_47:
        raw_read_unlock(a1 + 24548);
        if ( (unsigned int)__ratelimit(&a6xx_receive_ack_async__rs_44, "a6xx_receive_ack_async") )
        {
          if ( v14 >= 5 )
            LODWORD(v21) = 5;
          else
            LODWORD(v21) = v14;
          dev_err(
            v10 + 16,
            "Unexpectedly got id %d seqnum %d. Total waiters: %d Top %d Waiters:\n",
            (unsigned __int8)v11,
            v11 >> 20,
            v14,
            v21);
          if ( v14 )
          {
LABEL_52:
            v22 = 0;
            v23 = 0;
            v21 = (unsigned int)v21;
            do
            {
              if ( (unsigned int)__ratelimit(&a6xx_receive_ack_async__rs_46, "a6xx_receive_ack_async") )
              {
                if ( (v23 & 0x3FFFFFFFFFFFFFC0LL) != 0 || v22 > 0x100 )
                  __break(1u);
                dev_err(
                  v10 + 16,
                  " id %d seqnum %d\n",
                  (unsigned __int8)*(_DWORD *)((char *)v81 + v22),
                  *(_DWORD *)((char *)v81 + v22) >> 20);
              }
              --v21;
              ++v23;
              v22 += 4LL;
            }
            while ( v21 );
          }
        }
        else
        {
          if ( v14 >= 5 )
            LODWORD(v21) = 5;
          else
            LODWORD(v21) = v14;
          if ( v14 )
            goto LABEL_52;
        }
LABEL_5:
        v4 = *(_DWORD **)(*(_QWORD *)(v3 + 40) + 8LL);
        if ( !v4[18] )
          goto LABEL_175;
      }
      a6xx_hfi_queue_read(v3, 1u, *(void **)(a1 + 22792), 0x400u);
      v7 = *(_QWORD *)(a1 + 1544);
      v8 = *(unsigned int **)(a1 + 22792);
      if ( (*(_WORD *)(a1 + 8282) & 0xFFE) != 0 )
      {
        v9 = v8[8];
        if ( v9 > 604 )
        {
          if ( v9 > 606 )
          {
            if ( v9 != 607 )
            {
              if ( v9 != 608 )
              {
                if ( v9 == 609 )
                {
                  if ( (unsigned int)__ratelimit(&log_gpu_fault__rs_39, "log_gpu_fault") )
                    goto LABEL_36;
                  goto LABEL_172;
                }
                goto LABEL_111;
              }
              if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_37, "log_gpu_fault") )
                goto LABEL_172;
              v40 = *(_DWORD **)(a1 + 22792);
              if ( !*v40 || (v41 = ((*v40 >> 6) & 0x3FC) - 36, ((*v40 >> 6) & 0x3FC) == 0x24) )
              {
LABEL_110:
                v45 = 0;
LABEL_138:
                dev_crit(v7 + 16, "CP | Ringbuffer HW fault | status=0x%8.8x\n", v45);
                goto LABEL_172;
              }
              v42 = 0;
              v43 = v40 + 9;
              while ( 1 )
              {
                v44 = (_WORD *)((char *)v43 + v42);
                if ( *v44 == 1 )
                  break;
                v42 += 4 * (unsigned __int16)v44[1] + 4;
                if ( v42 >= v41 )
                  goto LABEL_110;
              }
              v53 = adreno_hwsched_parse_payload();
LABEL_137:
              v45 = v53;
              goto LABEL_138;
            }
            if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_36, "log_gpu_fault") )
              goto LABEL_172;
LABEL_123:
            dev_crit(v7 + 16, "CP ucode error interrupt\n");
            goto LABEL_172;
          }
          if ( v9 != 605 )
          {
            if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_35, "log_gpu_fault") )
              goto LABEL_172;
            goto LABEL_89;
          }
          if ( !*v8 || ((*v8 >> 6) & 0x3FC) == 0x24 )
          {
LABEL_101:
            v39 = 0;
          }
          else
          {
            v37 = 0;
            while ( 1 )
            {
              v38 = (_WORD *)((char *)v8 + v37 + 36);
              if ( *v38 == 1 )
                break;
              v37 += 4 * (unsigned __int16)v38[1] + 4;
              if ( v37 >= ((*v8 >> 6) & 0x3FC) - 36 )
                goto LABEL_101;
            }
            v39 = adreno_hwsched_parse_payload();
          }
          if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_34, "log_gpu_fault") )
            goto LABEL_172;
          goto LABEL_131;
        }
        if ( v9 <= 602 )
        {
          if ( v9 != 601 )
          {
            if ( v9 != 602 )
            {
LABEL_111:
              if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_40, "log_gpu_fault") )
                goto LABEL_172;
              v46 = v8[8];
              goto LABEL_141;
            }
            v17 = *v8;
            if ( !*v8 || ((v17 >> 6) & 0x3FC) == 0x24 )
            {
              v20 = 0;
            }
            else
            {
              v18 = 0;
              while ( 1 )
              {
                v19 = (_WORD *)((char *)v8 + v18 + 36);
                if ( *v19 == 3 )
                  break;
                v18 += 4 * (unsigned __int16)v19[1] + 4;
                if ( v18 >= ((v17 >> 6) & 0x3FC) - 36 )
                {
                  v20 = 0;
                  goto LABEL_152;
                }
              }
              v54 = adreno_hwsched_parse_payload();
              v8 = *(unsigned int **)(a1 + 22792);
              v20 = v54;
              v17 = *v8;
LABEL_152:
              if ( v17 )
              {
                v55 = ((v17 >> 6) & 0x3FC) - 36;
                if ( v55 )
                {
                  v56 = 0;
                  while ( 1 )
                  {
                    v57 = (_WORD *)((char *)v8 + v56 + 36);
                    if ( *v57 == 3 )
                      break;
                    v56 += 4 * (unsigned __int16)v57[1] + 4;
                    if ( v56 >= v55 )
                      goto LABEL_114;
                  }
                  v47 = adreno_hwsched_parse_payload();
LABEL_115:
                  payload_rb_key = adreno_hwsched_get_payload_rb_key(a1, v20, 2);
                  payload_rb_key_legacy = adreno_hwsched_get_payload_rb_key(a1, v20, 3);
                  v48 = adreno_hwsched_get_payload_rb_key(a1, v47, 2);
                  v49 = adreno_hwsched_get_payload_rb_key(a1, v47, 3);
                  if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_38, "log_gpu_fault") )
                    goto LABEL_172;
                  goto LABEL_167;
                }
              }
            }
LABEL_114:
            v47 = 0;
            goto LABEL_115;
          }
          if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs, "log_gpu_fault") )
            goto LABEL_172;
LABEL_118:
          dev_crit(v7 + 16, "MISC: GPU hang detected\n");
          goto LABEL_172;
        }
        if ( v9 != 603 )
        {
          if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_33, "log_gpu_fault") )
            goto LABEL_172;
          v28 = *(_DWORD **)(a1 + 22792);
          if ( !*v28 || (v29 = ((*v28 >> 6) & 0x3FC) - 36, ((*v28 >> 6) & 0x3FC) == 0x24) )
          {
LABEL_78:
            v33 = 0;
LABEL_86:
            dev_crit(v7 + 16, "CP opcode error interrupt | opcode=0x%8.8x\n", v33);
            goto LABEL_172;
          }
          v30 = 0;
          v31 = v28 + 9;
          while ( 1 )
          {
            v32 = (_WORD *)((char *)v31 + v30);
            if ( *v32 == 1 )
              break;
            v30 += 4 * (unsigned __int16)v32[1] + 4;
            if ( v30 >= v29 )
              goto LABEL_78;
          }
          v34 = adreno_hwsched_parse_payload();
LABEL_85:
          v33 = v34;
          goto LABEL_86;
        }
        if ( !(unsigned int)__ratelimit(&log_gpu_fault__rs_32, "log_gpu_fault") )
          goto LABEL_172;
        v35 = v8[2];
        v36 = v8[4];
        goto LABEL_121;
      }
      v16 = v8[4];
      if ( v16 > 604 )
      {
        if ( v16 <= 606 )
        {
          if ( v16 != 605 )
          {
            if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_20, "log_gpu_fault_legacy") )
              goto LABEL_172;
LABEL_89:
            dev_crit(v7 + 16, "CP Illegal instruction error\n");
            goto LABEL_172;
          }
          if ( !*v8 || ((*v8 >> 6) & 0x3FC) == 0x14 )
          {
LABEL_129:
            v39 = 0;
          }
          else
          {
            v50 = 0;
            while ( 1 )
            {
              v51 = (_WORD *)((char *)v8 + v50 + 20);
              if ( *v51 == 1 )
                break;
              v50 += 4 * (unsigned __int16)v51[1] + 4;
              if ( v50 >= ((*v8 >> 6) & 0x3FC) - 20 )
                goto LABEL_129;
            }
            v39 = adreno_hwsched_parse_payload();
          }
          if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_16, "log_gpu_fault_legacy") )
            goto LABEL_172;
LABEL_131:
          if ( (v39 & 0x100000) != 0 )
            v52 = "READ";
          else
            v52 = "WRITE";
          dev_crit(v7 + 16, "CP | Protected mode error | %s | addr=0x%5.5x | status=0x%8.8x\n", v52, v39 & 0x3FFFF, v39);
          goto LABEL_172;
        }
        switch ( v16 )
        {
          case 607:
            if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_22, "log_gpu_fault_legacy") )
              goto LABEL_172;
            goto LABEL_123;
          case 608:
            if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_24, "log_gpu_fault_legacy") )
              goto LABEL_172;
            v53 = a6xx_hwsched_lookup_key_value_legacy(a1, 1, 3);
            goto LABEL_137;
          case 609:
            if ( (unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_28, "log_gpu_fault_legacy") )
LABEL_36:
              dev_crit(v7 + 16, "RBBM: GPC error\n");
LABEL_172:
            _X8 = (unsigned int *)(a1 + 24448);
            __asm { PRFM            #0x11, [X8] }
            do
              v68 = __ldxr(_X8);
            while ( __stxr(v68 | 2, _X8) );
            __dmb(0xAu);
            kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
            goto LABEL_5;
        }
        goto LABEL_139;
      }
      if ( v16 > 602 )
      {
        if ( v16 != 603 )
        {
          if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_14, "log_gpu_fault_legacy") )
            goto LABEL_172;
          v34 = a6xx_hwsched_lookup_key_value_legacy(a1, 1, 1);
          goto LABEL_85;
        }
        if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_12, "log_gpu_fault_legacy") )
          goto LABEL_172;
        v35 = v8[1];
        v36 = v8[3];
LABEL_121:
        dev_crit(v7 + 16, "gpu timeout ctx %u ts %u\n", v35, v36);
        goto LABEL_172;
      }
      if ( v16 == 601 )
      {
        if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs, "log_gpu_fault_legacy") )
          goto LABEL_172;
        goto LABEL_118;
      }
      if ( v16 != 602 )
      {
LABEL_139:
        if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_30, "log_gpu_fault_legacy") )
          goto LABEL_172;
        v46 = v8[4];
LABEL_141:
        dev_crit(v7 + 16, "Unknown GPU fault: %u\n", v46);
        goto LABEL_172;
      }
      v24 = *v8;
      if ( !*v8 || ((v24 >> 6) & 0x3FC) == 0x14 )
      {
        v20 = 0;
      }
      else
      {
        v25 = 0;
        while ( 1 )
        {
          v26 = (_WORD *)((char *)v8 + v25 + 20);
          if ( *v26 == 3 )
            break;
          v25 += 4 * (unsigned __int16)v26[1] + 4;
          if ( v25 >= ((v24 >> 6) & 0x3FC) - 20 )
          {
            v20 = 0;
            goto LABEL_160;
          }
        }
        v58 = adreno_hwsched_parse_payload();
        v8 = *(unsigned int **)(a1 + 22792);
        v20 = v58;
        v24 = *v8;
LABEL_160:
        if ( v24 )
        {
          v59 = ((v24 >> 6) & 0x3FC) - 20;
          if ( v59 )
          {
            v60 = 0;
            while ( 1 )
            {
              v61 = (_WORD *)((char *)v8 + v60 + 20);
              if ( *v61 == 3 )
                break;
              v60 += 4 * (unsigned __int16)v61[1] + 4;
              if ( v60 >= v59 )
                goto LABEL_143;
            }
            v47 = adreno_hwsched_parse_payload();
LABEL_144:
            payload_rb_key = adreno_hwsched_get_payload_rb_key_legacy(a1, v20, 2);
            payload_rb_key_legacy = adreno_hwsched_get_payload_rb_key_legacy(a1, v20, 3);
            v48 = adreno_hwsched_get_payload_rb_key_legacy(a1, v47, 2);
            v49 = adreno_hwsched_get_payload_rb_key_legacy(a1, v47, 3);
            if ( !(unsigned int)__ratelimit(&log_gpu_fault_legacy__rs_26, "log_gpu_fault_legacy") )
              goto LABEL_172;
LABEL_167:
            dev_crit(
              v7 + 16,
              "Preemption Fault: cur=%d R/W=0x%x/0x%x, next=%d R/W=0x%x/0x%x\n",
              v20,
              payload_rb_key,
              payload_rb_key_legacy,
              v47,
              v48,
              v49);
            goto LABEL_172;
          }
        }
      }
LABEL_143:
      v47 = 0;
      goto LABEL_144;
    }
LABEL_175:
    result = mutex_unlock(a1 + 24632);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
