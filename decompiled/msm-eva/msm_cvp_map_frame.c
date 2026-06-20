__int64 __fastcall msm_cvp_map_frame(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  char **v4; // x11
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x27
  __int64 result; // x0
  __int64 v10; // x21
  unsigned __int64 v11; // x8
  __int64 v12; // x22
  unsigned int v13; // w19
  __int64 v14; // x0
  int *v15; // x26
  __int64 v16; // x24
  int v17; // w25
  unsigned __int64 v18; // x21
  int v19; // w28
  __int64 v20; // x22
  __int64 v21; // x8
  int v22; // w19
  __int64 smem; // x0
  int v24; // w8
  __int64 v25; // x28
  __int64 v26; // x3
  __int64 v27; // x22
  unsigned int v28; // w27
  unsigned int v29; // w9
  unsigned __int64 v30; // t2
  unsigned int v31; // w8
  int v32; // w9
  __int64 v34; // x21
  __int64 *v35; // x1
  void *v36; // x0
  unsigned __int64 v37; // x8
  int v38; // w8
  int v39; // w9
  __int64 v40; // x23
  unsigned __int64 v41; // x8
  _QWORD *i; // x22
  __int64 **v43; // x0
  __int64 *v44; // x20
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned int v54; // [xsp+0h] [xbp-30h]
  unsigned __int64 v55; // [xsp+8h] [xbp-28h]
  __int64 v56; // [xsp+10h] [xbp-20h]
  __int64 v57; // [xsp+18h] [xbp-18h]
  __int64 v58; // [xsp+20h] [xbp-10h]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v4 = off_6C000;
  v5 = *(_QWORD *)(cvp_driver + 48);
  if ( !v5 )
    return 4294967274LL;
  StatusReg = *(_QWORD *)(a1 + 128);
  v8 = a1;
LABEL_86:
  _X9 = (unsigned __int64 *)(StatusReg + 1296);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v52 = __ldxr(_X9);
    v53 = v52 + 1;
  }
  while ( __stlxr(v53, _X9) );
  __dmb(0xBu);
  result = 0;
  v10 = v53 & 0x7FFFFFFFFFFFFFFFLL;
  *(_QWORD *)(a2 + 32) = v53 & 0x7FFFFFFFFFFFFFFFLL;
  if ( a3 && a4 )
  {
    if ( a3 > 0xF )
    {
      v12 = a2;
      v13 = a3;
      if ( (msm_cvp_debug & 8) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8AAC8, "cmd", "msm_cvp_map_frame", *(unsigned int *)(a2 + 4));
        v4 = off_6C000;
      }
      v14 = cvp_kmem_cache_zalloc(v4[145] + 88, 3264);
      if ( v14 )
      {
        *(_QWORD *)(v14 + 2584) = v10;
        v15 = (int *)(v12 + 4LL * v13);
        *(_DWORD *)(v14 + 2576) = 0;
        v16 = v14;
        v17 = 0;
        v58 = v14 + 16;
        v59 = v12;
        v4 = off_6C000;
        v56 = v5;
        v57 = v10;
        v18 = v13;
        *(_DWORD *)(v14 + 2592) = *(_DWORD *)(v12 + 4);
        StatusReg = _ReadStatusReg(SP_EL0);
        v55 = StatusReg;
        do
        {
          if ( v18 >= 0x259 )
          {
LABEL_85:
            __break(0x5512u);
            goto LABEL_86;
          }
          StatusReg = (unsigned int)v15[1];
          if ( (_DWORD)StatusReg )
          {
            StatusReg = *(_QWORD *)(cvp_driver + 48);
            if ( StatusReg && (StatusReg = *(_QWORD *)(StatusReg + 256)) != 0 && (StatusReg = *(_QWORD *)StatusReg) != 0 )
            {
              if ( !v8 )
              {
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v36 = &unk_912BD;
                  v37 = _ReadStatusReg(SP_EL0);
                  goto LABEL_65;
                }
LABEL_66:
                v38 = msm_cvp_debug_out;
                v39 = msm_cvp_debug & 1;
                if ( (msm_cvp_debug & 1) != 0 )
                {
                  v40 = v56;
                  if ( !msm_cvp_debug_out )
                  {
                    v41 = _ReadStatusReg(SP_EL0);
                    printk(&unk_8D2A4, *(unsigned int *)(v41 + 1800), *(unsigned int *)(v41 + 1804), &unk_8E7CE);
                    v38 = msm_cvp_debug_out;
                    v39 = msm_cvp_debug & 1;
                  }
                }
                else
                {
                  v40 = v56;
                }
                if ( v39 && !v38 )
                {
                  v45 = _ReadStatusReg(SP_EL0);
                  printk(&unk_9037D, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), &unk_8E7CE);
                }
                mutex_lock(v40);
                for ( i = *(_QWORD **)(v40 + 280); i != (_QWORD *)(v40 + 280); i = (_QWORD *)*i )
                  ((void (__fastcall *)(_QWORD *, _QWORD))msm_cvp_print_inst_bufs)(i, 0);
                mutex_unlock(v40);
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v46 = _ReadStatusReg(SP_EL0);
                  printk(&unk_95B4E, *(unsigned int *)(v46 + 1800), *(unsigned int *)(v46 + 1804), &unk_8E7CE);
                }
                mutex_lock(&unk_6CF58);
                v43 = (__int64 **)qword_6CF48;
                if ( (__int64 *)qword_6CF48 != &qword_6CF48 && qword_6CF48 )
                {
                  do
                  {
                    v44 = *v43;
                    msm_cvp_print_frpc_bufs();
                    if ( v44 == &qword_6CF48 )
                      break;
                    v43 = (__int64 **)v44;
                  }
                  while ( v44 );
                }
                mutex_unlock(&unk_6CF58);
                msm_cvp_unmap_frame_buf(v8, v16);
                return 4294967274LL;
              }
              v20 = *(unsigned int *)(v16 + 2576);
              if ( (_DWORD)v20 == 40 )
              {
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v36 = &unk_932BF;
                  v37 = _ReadStatusReg(SP_EL0);
LABEL_65:
                  printk(v36, *(unsigned int *)(v37 + 1800), *(unsigned int *)(v37 + 1804), &unk_8E7CE);
                }
                goto LABEL_66;
              }
              v21 = *(_QWORD *)(StatusReg + 2208);
              v5 = *(unsigned int *)(v21 + 44);
              v22 = *(_DWORD *)(v21 + 36);
              smem = msm_cvp_session_get_smem(v8, v15, 0, *(unsigned int *)(v59 + 4));
              if ( !smem )
                goto LABEL_66;
              v24 = *(_DWORD *)(smem + 88);
              v25 = smem;
              switch ( v24 )
              {
                case 68:
                  StatusReg = 7;
                  break;
                case 36:
                  StatusReg = 3;
                  break;
                case 20:
                  StatusReg = 4;
                  break;
                default:
                  StatusReg = 0;
                  break;
              }
              v15[11] = StatusReg;
              *(_DWORD *)(smem + 96) = v17;
              if ( (unsigned int)v20 >= 0x28 )
                goto LABEL_85;
              v26 = v58 + (v20 << 6);
              v27 = v8;
              *(_DWORD *)(v26 + 16) = *v15;
              *(_QWORD *)(v26 + 56) = smem;
              *(_DWORD *)(v26 + 20) = v15[1];
              *(_DWORD *)(v26 + 24) = v15[2];
              print_internal_buffer(64, (__int64)"map cpu", v8, v26);
              ++*(_DWORD *)(v16 + 2576);
              v28 = v15[2];
              if ( (msm_cvp_cacheop_disabled & 1) == 0 )
              {
                v29 = v15[1];
                if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
                {
                  v54 = v15[1];
                  printk(&unk_8D211, &unk_84256, "msm_cvp_cache_operations", *(_QWORD *)(v25 + 48));
                  v29 = v54;
                }
                msm_cvp_smem_cache_operations(*(_QWORD *)(v25 + 48), 2, v28, v29);
                v28 = v15[2];
              }
              v4 = off_6C000;
              StatusReg = (unsigned __int8)trigger_smmu_fault;
              v19 = *(_DWORD *)(v25 + 64) + v28;
              if ( trigger_smmu_fault == 1 )
              {
                v8 = v27;
                StatusReg = (unsigned int)(frame_count + 1);
                frame_count = StatusReg;
                HIDWORD(v30) = -1030792151 * StatusReg;
                LODWORD(v30) = -1030792151 * StatusReg;
                if ( (unsigned int)(v30 >> 3) <= 0x147AE14 )
                {
                  v31 = v19 - 0x1000000;
                  v32 = 2 * v22;
                  frame_count = 0;
                  if ( v19 - 0x1000000 > (unsigned int)(v22 + v5) || v31 < (unsigned int)v5 )
                    v32 = 0;
                  v19 = v32 + v31;
                  StatusReg = (unsigned __int64)off_6C000;
                  trigger_smmu_fault = 0;
                  if ( (msm_cvp_debug & 1) != 0 )
                  {
                    StatusReg = (unsigned int)msm_cvp_debug_out;
                    if ( !msm_cvp_debug_out )
                    {
                      printk(&unk_9251A, *(unsigned int *)(v55 + 1800), *(unsigned int *)(v55 + 1804), &unk_8E7CE);
                      v4 = off_6C000;
                    }
                  }
                }
              }
              else
              {
                v8 = v27;
              }
              if ( !v19 )
                goto LABEL_66;
            }
            else
            {
              v19 = -22;
            }
          }
          else
          {
            v19 = 0;
          }
          ++v17;
          v18 += 12LL;
          *v15 = v19;
          v15 += 12;
        }
        while ( a4 != v17 );
        v34 = v8 + 664;
        mutex_lock(v8 + 680);
        v35 = *(__int64 **)(v8 + 672);
        if ( v16 == v8 + 664 || v35 == (__int64 *)v16 || *v35 != v34 )
        {
          _list_add_valid_or_report(v16, v35, v8 + 664);
        }
        else
        {
          *(_QWORD *)(v8 + 672) = v16;
          *(_QWORD *)v16 = v34;
          *(_QWORD *)(v16 + 8) = v35;
          *v35 = v16;
        }
        mutex_unlock(v8 + 680);
        result = 0;
        if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_95B79, &unk_84256, "msm_cvp_map_frame", v57);
          return 0;
        }
      }
      else
      {
        return 4294967284LL;
      }
    }
    else
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_894FC, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
    }
  }
  return result;
}
