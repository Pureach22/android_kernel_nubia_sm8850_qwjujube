__int64 __fastcall cvp_enqueue_pkt(__int64 a1, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  __int64 v6; // x8
  _DWORD *StatusReg; // x20
  __int64 v10; // x3
  int v11; // w26
  int v12; // w28
  int v13; // w9
  unsigned __int16 v14; // w9
  __int64 result; // x0
  char v16; // w9
  __int64 v17; // x8
  __int64 v18; // x24
  char *v19; // x0
  size_t v20; // x2
  char *v21; // x26
  __int64 v22; // x2
  __int64 v23; // x3
  char *v24; // x13
  __int64 v25; // x11
  int pkt_fenceoverride; // w0
  int v27; // w8
  unsigned int v28; // w26
  __int64 v29; // x0
  int v30; // w8
  _QWORD *v31; // x0
  unsigned __int64 v32; // x14
  int v33; // w8
  unsigned __int64 v34; // x26
  __int64 v35; // x3
  unsigned int v36; // w4
  unsigned int v37; // w10
  unsigned int *v38; // x8
  unsigned __int64 v39; // x11
  unsigned int v40; // w12
  unsigned int v41; // w12
  unsigned int v42; // w13
  int v43; // w8
  int v44; // w9
  unsigned __int64 v45; // x10
  unsigned int v46; // w11
  unsigned int *v47; // x12
  __int64 v48; // x9
  __int64 v49; // x10
  __int64 v50; // x10
  __int64 v51; // x9
  unsigned __int64 v52; // x8
  __int64 (__fastcall *v53)(__int64, unsigned int *); // x8
  __int64 v54; // x0
  unsigned int v55; // w0
  __int64 v56; // x1
  __int64 v57; // x2
  void *v58; // x0
  char v59; // w8
  unsigned int v60; // w9
  unsigned int v61; // w13
  unsigned int *v62; // x10
  unsigned int v63; // w11
  __int64 v64; // x12
  __int64 v65; // x3
  _DWORD *v66; // x8
  _QWORD *v67; // x26
  unsigned __int64 v68; // x26
  __int64 v69; // x9
  unsigned __int64 v70; // x8
  __int64 (__fastcall *v71)(__int64, unsigned int *); // x8
  __int64 v72; // x0
  unsigned __int64 v73; // x10
  unsigned __int64 v74; // x11
  unsigned int v75; // w21
  unsigned __int64 v76; // x10
  unsigned __int64 v77; // x11
  __int64 v78; // x0
  __int64 v79; // x25
  __int64 (__fastcall *v80)(__int64, __int64, _DWORD *, const char *, _QWORD); // x8
  __int64 v81; // x0
  __int64 v82; // t1
  __int64 v83; // x8
  unsigned int v90; // w9
  unsigned int v91; // w19
  unsigned int v94; // w10
  __int64 v95; // [xsp+8h] [xbp-148h]
  int v96; // [xsp+14h] [xbp-13Ch]
  __int64 v97; // [xsp+18h] [xbp-138h]
  char *v98; // [xsp+20h] [xbp-130h]
  unsigned __int64 v99; // [xsp+28h] [xbp-128h]
  int v100; // [xsp+34h] [xbp-11Ch]
  __int64 v101; // [xsp+38h] [xbp-118h]
  _QWORD v102[34]; // [xsp+40h] [xbp-110h] BYREF

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = (_DWORD *)_ReadStatusReg(SP_EL0);
  v102[32] = v6;
  while ( 1 )
  {
    if ( a3 > 0x258 || a4 >= 0x259 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8BE5D, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        result = 4294967274LL;
      }
      goto LABEL_175;
    }
    v10 = a2[1];
    v11 = 0;
    v12 = 1;
    if ( (int)v10 > 18878465 )
    {
      v13 = 0;
      if ( (_DWORD)v10 == 18878466 )
        goto LABEL_15;
      v14 = 4099;
    }
    else
    {
      v13 = 0;
      if ( (_DWORD)v10 == 18874480 )
        goto LABEL_15;
      v14 = 113;
    }
    v12 = 0;
    if ( (_DWORD)v10 == (v14 | 0x1200000) )
    {
      v13 = 0;
      v11 = 1;
    }
    else
    {
      v11 = 0;
      v13 = 1;
    }
LABEL_15:
    v100 = v13;
    v16 = msm_cvp_debug;
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 256LL);
    *((_QWORD *)a2 + 4) = 0;
    v101 = v17;
    if ( (v16 & 8) != 0 && !msm_cvp_debug_out )
      printk(&unk_83907, "cmd", "cvp_enqueue_pkt", v10);
    v18 = 15272;
    mutex_lock(a1 + 15272);
    if ( *(_DWORD *)(a1 + 15324) == 1 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        printk(&unk_8BE9B, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "warn");
      mutex_unlock(a1 + 15272);
      result = 4294967280LL;
      goto LABEL_175;
    }
    _X8 = (unsigned int *)(a1 + 15384);
    __asm { PRFM            #0x11, [X8] }
    do
      v90 = __ldxr(_X8);
    while ( __stxr(v90 + 1, _X8) );
    mutex_unlock(a1 + 15272);
    if ( !v12 )
    {
      if ( v11 )
        result = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD))msm_cvp_unmap_user_persist)(
                   a1,
                   a2,
                   a3,
                   a4);
      else
        result = msm_cvp_map_frame(a1, a2, a3, a4);
      v24 = nullptr;
      v99 = 0;
      if ( (_DWORD)result )
        goto LABEL_177;
      goto LABEL_33;
    }
    v99 = 4LL * a4;
    v19 = (char *)_kmalloc_noprof(v99, 3520);
    if ( !v19 )
      break;
    v20 = 4 * a4;
    if ( 4 * (unsigned __int64)a4 >= v20 )
    {
      v21 = v19;
      memset(v19, 255, v20);
      result = msm_cvp_map_user_persist(a1, a2, a3, a4, v21);
      v24 = v21;
      if ( (_DWORD)result )
        goto LABEL_177;
LABEL_33:
      v25 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 256LL);
      memset(v102, 0, 256);
      v98 = v24;
      if ( !a3 || !a4 )
        goto LABEL_121;
      if ( a3 <= 0xF )
      {
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_894FC, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
          v24 = v98;
          result = 4294967274LL;
        }
        goto LABEL_116;
      }
      v95 = v25;
      pkt_fenceoverride = get_pkt_fenceoverride(a2);
      v27 = msm_cvp_debug_out;
      v96 = pkt_fenceoverride;
      if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_923EB, "synx", "cvp_populate_fences", pkt_fenceoverride != 0);
        v27 = msm_cvp_debug_out;
        if ( (msm_cvp_debug & 0x80) != 0 )
        {
LABEL_43:
          if ( !v27 )
            printk(&unk_93C1F, "synx", "cvp_populate_fences", (unsigned int)cvp_kernel_fence_enabled);
        }
      }
      else if ( (msm_cvp_debug & 0x80) != 0 )
      {
        goto LABEL_43;
      }
      v28 = *a2;
      v29 = _kmalloc_cache_noprof(platform_driver_unregister, 3520, 320);
      v24 = v98;
      if ( v29 )
      {
        v97 = v29;
        if ( v28 <= 0x13C )
          v30 = 316;
        else
          v30 = v28;
        v31 = (_QWORD *)_kmalloc_noprof(v30, 3520);
        v32 = v97;
        *(_QWORD *)(v97 + 304) = v31;
        if ( v31 )
        {
          v33 = cvp_kernel_fence_enabled;
          *(_DWORD *)(v97 + 40) = a2[1];
          *(_QWORD *)(v97 + 24) = 0xFEEDFACE00000000LL;
          *(_QWORD *)(v97 + 32) = 0;
          if ( v33 )
          {
            if ( v33 == 1 )
              goto LABEL_54;
            if ( v33 != 2 )
            {
              if ( (msm_cvp_debug & 1) != 0 )
              {
                v18 = 4294967274LL;
                if ( !msm_cvp_debug_out )
                {
                  v56 = (unsigned int)StatusReg[450];
                  v57 = (unsigned int)StatusReg[451];
                  v58 = &unk_8B4A1;
                  goto LABEL_159;
                }
                goto LABEL_115;
              }
LABEL_89:
              v18 = 4294967274LL;
              goto LABEL_115;
            }
            if ( v96 )
            {
LABEL_54:
              v34 = a3;
              v35 = 0;
              v36 = 0;
              v37 = a4;
              v38 = &a2[a3 + 6];
              v39 = a3;
              do
              {
                if ( v39 > 0x258 )
                  goto LABEL_99;
                v41 = v38[1];
                if ( v41 )
                {
                  if ( (unsigned int)v35 > 0x3F )
                    goto LABEL_99;
                  v42 = *v38;
                  *((_DWORD *)v102 + (unsigned int)v35) = v41;
                  v35 = (unsigned int)(v35 + 1);
                  ++v36;
                  *(_DWORD *)(v97 + 32) = v35;
                  *(_QWORD *)v38 = v42 & 0xFFFFFFFE;
                }
                v40 = v38[2];
                v38 += 12;
                v39 += 12LL;
                if ( v40 )
                  ++v36;
                --v37;
              }
              while ( v37 );
              if ( v36 < 0x41 )
              {
                v59 = msm_cvp_debug;
                *(_DWORD *)(v97 + 36) = v35;
                if ( v59 < 0 && !msm_cvp_debug_out )
                {
                  printk(&unk_8BECA, "synx", "cvp_populate_fences", v35);
                  v32 = v97;
                }
                v60 = a4;
                while ( v34 <= 0x258 )
                {
                  v62 = &a2[v34];
                  v63 = v62[8];
                  if ( v63 )
                  {
                    v64 = *(unsigned int *)(v32 + 32);
                    if ( (unsigned int)v64 > 0x3F )
                      goto LABEL_99;
                    v61 = v62[6];
                    *((_DWORD *)v102 + v64) = v63;
                    *(_DWORD *)(v32 + 32) = v64 + 1;
                    v62[8] = 0;
                    v62[6] = v61 & 0xFFFFFFFD;
                  }
                  --v60;
                  v34 += 12LL;
                  if ( !v60 )
                    goto LABEL_100;
                }
                goto LABEL_99;
              }
              if ( (msm_cvp_debug & 1) != 0 )
              {
                v18 = 4294967274LL;
                if ( !msm_cvp_debug_out )
                {
                  printk(&unk_89EE5, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                  goto LABEL_160;
                }
                goto LABEL_115;
              }
              goto LABEL_89;
            }
          }
          v43 = 0;
          v44 = 0;
          v45 = a3;
          v46 = a4;
          do
          {
            if ( v45 >= 0x259 )
              goto LABEL_99;
            v47 = &a2[v45];
            if ( v47[7] )
            {
              ++v43;
              ++v44;
              *(_DWORD *)(v97 + 32) = v43;
              *(_DWORD *)(v97 + 36) = v44;
            }
            else if ( v47[8] )
            {
              *(_DWORD *)(v97 + 32) = ++v43;
            }
            --v46;
            v45 += 12LL;
          }
          while ( v46 );
          *(_DWORD *)(v97 + 28) = -1329939778;
          if ( !v43 )
            goto LABEL_114;
          v48 = *((_QWORD *)a2 + 7);
          v31[6] = *((_QWORD *)a2 + 6);
          v31[7] = v48;
          v49 = *((_QWORD *)a2 + 1);
          *v31 = *(_QWORD *)a2;
          v31[1] = v49;
          v50 = *((_QWORD *)a2 + 3);
          v31[2] = *((_QWORD *)a2 + 2);
          v31[3] = v50;
          v51 = *((_QWORD *)a2 + 5);
          v52 = *((_QWORD *)a2 + 4) | 0x8000000000000000LL;
          *((_QWORD *)a2 + 4) = v52;
          v31[4] = v52;
          v31[5] = v51;
          if ( !v95 )
            goto LABEL_112;
          v53 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v95 + 88);
          if ( !v53 )
            goto LABEL_112;
          v54 = *(_QWORD *)(a1 + 320);
          if ( *((_DWORD *)v53 - 1) != -1882757197 )
            __break(0x8228u);
          v55 = v53(v54, a2);
          v32 = v97;
          if ( !v55 )
            goto LABEL_112;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v18 = v55;
            printk(&unk_9707A, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            goto LABEL_160;
          }
          goto LABEL_108;
        }
        kfree(v97);
        v24 = v98;
      }
      result = 4294967284LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8DF1A, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        v24 = v98;
        result = 4294967284LL;
      }
      while ( 1 )
      {
LABEL_116:
        if ( (_DWORD)result )
        {
          LOBYTE(v69) = msm_cvp_debug;
          LODWORD(v70) = msm_cvp_debug_out;
          if ( (int)result >= 1 )
          {
            result = 0;
            if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8EB8C, "synx", v22, v23);
              v24 = v98;
              result = 0;
            }
            goto LABEL_177;
          }
LABEL_141:
          if ( (v69 & 1) != 0 && !(_DWORD)v70 )
          {
            v18 = (unsigned int)result;
            printk(&unk_96608, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v24 = v98;
            result = (unsigned int)v18;
            if ( v100 )
            {
LABEL_144:
              v75 = result;
              msm_cvp_unmap_frame(a1, *((_QWORD *)a2 + 4));
              v24 = v98;
              result = v75;
              goto LABEL_177;
            }
          }
          else if ( v100 )
          {
            goto LABEL_144;
          }
          if ( !v12 )
            goto LABEL_177;
          v32 = v99;
          v70 = 0;
          v69 = 4LL * a4;
          v76 = a3;
          v77 = v99;
          while ( v76 <= 0x258 )
          {
            if ( a2[v76 + 1] )
            {
              if ( v99 < v70 || v77 < 4 )
                goto LABEL_140;
              a2[v76] = *(_DWORD *)&v24[v70];
            }
            v70 += 4LL;
            v77 -= 4LL;
            v76 += 12LL;
            if ( v69 == v70 )
              goto LABEL_156;
          }
        }
        else
        {
LABEL_121:
          if ( v101 && (v71 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v101 + 88)) != nullptr )
          {
            v72 = *(_QWORD *)(a1 + 320);
            if ( *((_DWORD *)v71 - 1) != -1882757197 )
              __break(0x8228u);
            result = v71(v72, a2);
            v24 = v98;
          }
          else
          {
            result = 0;
          }
          if ( !(_DWORD)result )
            goto LABEL_177;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v18 = (unsigned int)result;
            printk(&unk_9707A, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v24 = v98;
            result = (unsigned int)v18;
            if ( v100 )
              goto LABEL_144;
          }
          else if ( v100 )
          {
            goto LABEL_144;
          }
          if ( !v12 )
            goto LABEL_177;
          v32 = v99;
          if ( !a4 )
          {
LABEL_156:
            result = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD))msm_cvp_unmap_user_persist)(
                       a1,
                       a2,
                       a3,
                       a4);
            v24 = v98;
            goto LABEL_177;
          }
          v70 = 0;
          v73 = a3;
          v69 = 4LL * a4;
          v74 = v99;
          while ( v73 <= 0x258 )
          {
            if ( a2[v73 + 1] )
            {
              if ( v99 < v70 || v74 < 4 )
              {
LABEL_140:
                __break(1u);
                goto LABEL_141;
              }
              a2[v73] = *(_DWORD *)&v24[v70];
            }
            v70 += 4LL;
            v74 -= 4LL;
            v73 += 12LL;
            if ( v69 == v70 )
              goto LABEL_156;
          }
        }
LABEL_99:
        __break(0x5512u);
LABEL_100:
        v65 = *(unsigned int *)(v32 + 32);
        if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_93234, "synx", "cvp_populate_fences", v65);
          v32 = v97;
          if ( !*(_DWORD *)(v97 + 32) )
          {
LABEL_114:
            v18 = 0;
            goto LABEL_115;
          }
        }
        else if ( !(_DWORD)v65 )
        {
          goto LABEL_114;
        }
        v66 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL) + 24LL);
        if ( *(v66 - 1) != 1503184185 )
          __break(0x8228u);
        v55 = ((__int64 (__fastcall *)(__int64, unsigned __int64, _QWORD *))v66)(a1, v32, v102);
        if ( v55 )
        {
          v32 = v97;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v56 = (unsigned int)StatusReg[450];
            v57 = (unsigned int)StatusReg[451];
            v18 = v55;
            v58 = &unk_86D8D;
LABEL_159:
            printk(v58, v56, v57, &unk_8E7CE);
LABEL_160:
            v32 = v97;
          }
          else
          {
LABEL_108:
            v18 = v55;
          }
LABEL_115:
          v68 = v32;
          kfree(*(_QWORD *)(v32 + 304));
          *(_QWORD *)(v68 + 304) = 0;
          kfree(v68);
          v24 = v98;
          result = (unsigned int)v18;
        }
        else
        {
          memcpy(*(void **)(v97 + 304), a2, *a2);
          v32 = v97;
          *(_QWORD *)(*(_QWORD *)(v97 + 304) + 32LL) |= 0x8000000000000000LL;
LABEL_112:
          v67 = (_QWORD *)v32;
          LODWORD(v97) = *(_DWORD *)(v32 + 32);
          mutex_lock(a1 + v18);
          list_add_tail(v67, (_QWORD *)(a1 + 15328));
          mutex_unlock(a1 + v18);
          _wake_up(a1 + 15344, 3, 1, 0);
          trace_tracing_mark_write_0();
          result = (unsigned int)v97;
          v24 = v98;
        }
      }
    }
    v78 = _fortify_panic(15);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)(unsigned int)StatusReg[10] >> 3) & 0x1FFFFFF8)) >> StatusReg[10])
        & 1) != 0 )
    {
      ++StatusReg[4];
      v79 = qword_977D8;
      if ( qword_977D8 )
      {
        do
        {
          v80 = *(__int64 (__fastcall **)(__int64, __int64, _DWORD *, const char *, _QWORD))v79;
          v81 = *(_QWORD *)(v79 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v79 - 4LL) != -641035679 )
            __break(0x8228u);
          v78 = v80(v81, 66, StatusReg, "cvp_enqueue_pkt", 0);
          v82 = *(_QWORD *)(v79 + 24);
          v79 += 24;
        }
        while ( v82 );
      }
      v83 = *((_QWORD *)StatusReg + 2) - 1LL;
      StatusReg[4] = v83;
      if ( !v83 || !*((_QWORD *)StatusReg + 2) )
        preempt_schedule_notrace(v78);
    }
  }
  v24 = nullptr;
  result = 4294967284LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_931FC, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
    v24 = nullptr;
    result = 4294967284LL;
  }
LABEL_177:
  _X8 = (unsigned int *)(a1 + 15384);
  __asm { PRFM            #0x11, [X8] }
  do
    v94 = __ldxr(_X8);
  while ( __stxr(v94 - 1, _X8) );
  if ( v12 )
  {
    v91 = result;
    kfree(v24);
    result = v91;
  }
LABEL_175:
  _ReadStatusReg(SP_EL0);
  return result;
}
