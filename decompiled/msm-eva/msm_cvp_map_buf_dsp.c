__int64 __fastcall msm_cvp_map_buf_dsp(_QWORD *a1, _DWORD *a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x2
  void *v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8
  __int64 *v12; // x23
  int v13; // w23
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x3
  unsigned __int64 v17; // x8
  __int64 v18; // x19
  _QWORD *v19; // x25
  unsigned int v20; // w19
  unsigned __int64 v21; // x8
  __int64 v22; // x19
  unsigned __int64 v23; // x9
  __int64 v24; // x0
  __int64 v25; // x23
  __int64 v26; // x0
  char v27; // w9
  __int64 v28; // x24
  unsigned int v29; // w0
  unsigned int v30; // w0
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  __int64 v33; // x24
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned int v42; // w9
  __int64 v43; // [xsp+8h] [xbp-18h]
  int v44; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1[20] )
  {
    result = 4294967274LL;
    goto LABEL_70;
  }
  v2 = a1[18];
  if ( !v2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_70;
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(unsigned int *)(StatusReg + 1800);
    v6 = *(unsigned int *)(StatusReg + 1804);
    v7 = &unk_948BC;
LABEL_17:
    printk(v7, v5, v6, &unk_8E7CE);
    result = 4294967274LL;
    goto LABEL_70;
  }
  if ( !a1 || !a2 || !a1[16] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_70;
    v8 = _ReadStatusReg(SP_EL0);
    v5 = *(unsigned int *)(v8 + 1800);
    v6 = *(unsigned int *)(v8 + 1804);
    v7 = &unk_912BD;
    goto LABEL_17;
  }
  if ( a2[4] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_70;
    v4 = _ReadStatusReg(SP_EL0);
    v5 = *(unsigned int *)(v4 + 1800);
    v6 = *(unsigned int *)(v4 + 1804);
    v7 = &unk_91BFB;
    goto LABEL_17;
  }
  mutex_lock(v2 + 376);
  v12 = (__int64 *)(v2 + 360);
  while ( 1 )
  {
    v12 = (__int64 *)*v12;
    if ( v12 == (__int64 *)(v2 + 360) )
      break;
    if ( *((_DWORD *)v12 + 4) == a2[2] )
    {
      if ( *((_DWORD *)v12 + 5) == a2[3] )
      {
        mutex_unlock(v2 + 376);
        print_internal_dsp_buffer(1, "duplicate", v2, v12);
        result = 4294967274LL;
      }
      else
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v35 = _ReadStatusReg(SP_EL0);
          printk(&unk_8B77A, *(unsigned int *)(v35 + 1800), *(unsigned int *)(v35 + 1804), &unk_8E7CE);
        }
        mutex_unlock(v2 + 376);
        result = 4294967274LL;
      }
      goto LABEL_70;
    }
  }
  mutex_unlock(v2 + 376);
  v14 = a1[20];
  v44 = a2[2];
  v13 = v44;
  v15 = task_lookup_next_fdget_rcu(v14, &v44);
  if ( v44 == v13 || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
  {
    if ( v15 )
      goto LABEL_27;
  }
  else
  {
    v32 = _ReadStatusReg(SP_EL0);
    v33 = v15;
    printk(&unk_8CBC9, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
    v15 = v33;
    if ( v33 )
    {
LABEL_27:
      if ( *(_QWORD *)(v15 + 16) == qword_6CF38 )
      {
        v19 = *(_QWORD **)(v15 + 32);
        if ( v19 != (_QWORD *)-22LL )
        {
          if ( *v19 >= (unsigned __int64)(unsigned int)a2[3] )
          {
            v43 = v15;
            if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
              printk(&unk_87BAC, &unk_84256, v19, v16);
            v24 = cvp_kmem_cache_zalloc((_QWORD *)(cvp_driver + 104), 3264);
            if ( v24 )
            {
              v25 = v24;
              v26 = cvp_kmem_cache_zalloc((_QWORD *)(cvp_driver + 120), 3264);
              if ( v26 )
              {
                *(_QWORD *)(v26 + 48) = v19;
                v27 = msm_cvp_debug;
                v28 = v26;
                *(_BYTE *)(v26 + 84) = 0;
                *(_QWORD *)(v26 + 92) = 0;
                *(_DWORD *)(v26 + 100) = a2[2];
                if ( (v27 & 0x40) != 0 && !msm_cvp_debug_out )
                  printk(&unk_953D9, &unk_84256, "msm_cvp_map_buf_dsp", v19);
                v29 = msm_cvp_map_smem((__int64)a1, v28, (__int64)"map dsp");
                if ( !v29 )
                {
                  _X8 = (unsigned int *)(v28 + 40);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v42 = __ldxr(_X8);
                  while ( __stxr(v42 + 1, _X8) );
                  *(_QWORD *)(v25 + 56) = v28;
                  *(_DWORD *)(v25 + 16) = a2[2];
                  *(_DWORD *)(v25 + 20) = a2[3];
                  *(_DWORD *)(v25 + 24) = a2[4];
                  *(_DWORD *)(v25 + 48) = 1;
                  *(_DWORD *)(v25 + 32) = *a2;
                  a2[7] = *(_DWORD *)(v28 + 64);
                  a2[3] = *v19;
                  mutex_lock(v2 + 376);
                  list_add_tail_2((_QWORD *)v25, (_QWORD *)(v2 + 360));
                  mutex_unlock(v2 + 376);
                  result = 0;
                  goto LABEL_70;
                }
                v20 = v29;
                print_client_buffer(1, (__int64)"map failed", (__int64)a1, (__int64)a2);
                if ( *(_DWORD *)(v28 + 64) )
                {
                  v30 = msm_cvp_unmap_smem((__int64)a1, v28, (__int64)"unmap dsp");
                  if ( v30 )
                  {
                    v20 = v30;
                    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    {
                      v31 = _ReadStatusReg(SP_EL0);
                      printk(&unk_86E2C, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
                    }
                  }
                  else
                  {
                    v20 = 0;
                  }
                }
                cvp_kmem_cache_free((_QWORD *)(cvp_driver + 120));
              }
              else
              {
                v20 = -12;
              }
              cvp_kmem_cache_free((_QWORD *)(cvp_driver + 104));
            }
            else
            {
              v20 = -12;
            }
            v15 = v43;
LABEL_69:
            fput(v15);
            result = v20;
            goto LABEL_70;
          }
          v20 = -22;
          if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
            goto LABEL_69;
          v21 = _ReadStatusReg(SP_EL0);
          v22 = v15;
          printk(&unk_95399, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
LABEL_43:
          v15 = v22;
          v20 = -22;
          goto LABEL_69;
        }
      }
      else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v17 = _ReadStatusReg(SP_EL0);
        v18 = v15;
        printk(&unk_8C19B, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), "warn");
        v15 = v18;
      }
      v20 = -22;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_69;
      v23 = _ReadStatusReg(SP_EL0);
      v22 = v15;
      printk(&unk_8F7A3, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
      goto LABEL_43;
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v34 = _ReadStatusReg(SP_EL0);
    printk(&unk_8C0D0, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), "warn");
    result = 4294967274LL;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
