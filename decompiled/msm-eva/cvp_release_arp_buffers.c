__int64 __fastcall cvp_release_arp_buffers(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  char **v6; // x22
  __int64 v7; // x20
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x0
  unsigned int v10; // w0
  _QWORD *v11; // x20
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned int v21; // w0
  _QWORD *v22; // x21
  char **v23; // x24
  unsigned __int64 v24; // x8
  unsigned int v25; // w20
  unsigned int v28; // w9
  __int64 v29; // x8
  __int64 v30; // x28
  _QWORD *v31; // x25
  int v32; // w8
  char **v33; // x26
  char *v34; // x22
  _QWORD *v35; // x8
  __int64 v36; // x9
  char *v37; // x20
  char **v38; // x8
  unsigned int v45; // w10
  unsigned __int64 v46; // x8
  unsigned int v47; // [xsp+4h] [xbp-Ch]

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(StatusReg + 1800);
    v17 = *(unsigned int *)(StatusReg + 1804);
    v18 = &unk_88437;
LABEL_25:
    printk(v18, v16, v17, &unk_8E7CE);
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 128);
  v6 = off_6C000;
  if ( !v4 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v19 = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(v19 + 1800);
    v17 = *(unsigned int *)(v19 + 1804);
    v18 = &unk_93C9F;
    goto LABEL_25;
  }
  v7 = *(_QWORD *)(v4 + 256);
  if ( v7 )
  {
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      printk(&unk_93CD3, &unk_84256, a3, a4);
    mutex_lock(a1 + 416);
    if ( (*(_DWORD *)(a1 + 328) & 0xFFFFFFFC) == 4 )
    {
      v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 80);
      if ( !v8 )
        goto LABEL_28;
      v9 = *(_QWORD *)(a1 + 320);
      if ( *((_DWORD *)v8 - 1) != -1066802076 )
        __break(0x8228u);
      v10 = v8(v9);
      if ( !v10 )
      {
LABEL_28:
        mutex_unlock(a1 + 416);
        v21 = wait_for_sess_signal_receipt(a1, 23);
        v11 = (_QWORD *)(a1 + 400);
        if ( v21 && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v24 = _ReadStatusReg(SP_EL0);
          v25 = v21;
          printk(&unk_945E1, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), "warn");
          v21 = v25;
          v11 = (_QWORD *)(a1 + 400);
        }
        v47 = v21;
        mutex_lock(a1 + 416);
        goto LABEL_33;
      }
      v11 = (_QWORD *)(a1 + 400);
      v47 = v10;
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      {
LABEL_33:
        v22 = (_QWORD *)*v11;
        if ( (_QWORD *)*v11 == v11 )
        {
LABEL_63:
          mutex_unlock(a1 + 416);
          return v47;
        }
        v23 = (char **)(a1 + 464);
        while ( v22 )
        {
          v30 = v22[7];
          if ( !v30 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v6 + 366) )
            {
              v46 = _ReadStatusReg(SP_EL0);
              printk(&unk_82795, *(unsigned int *)(v46 + 1800), *(unsigned int *)(v46 + 1804), &unk_8E7CE);
            }
            mutex_unlock(a1 + 416);
            return 4294967274LL;
          }
          v31 = (_QWORD *)*v22;
          if ( !*((_DWORD *)v22 + 12) )
          {
            if ( (msm_cvp_debug & 0x40) != 0 && !*((_DWORD *)v6 + 366) )
              printk(&unk_88D96, &unk_84256, "free arp", (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
            v32 = *((_DWORD *)v22 + 5);
            _X9 = (unsigned int *)(a1 + 528);
            __asm { PRFM            #0x11, [X9] }
            do
              v45 = __ldxr(_X9);
            while ( __stxr(v45 - v32, _X9) );
            if ( (msm_cvp_debug & 0x40) != 0 && !*((_DWORD *)v6 + 366) )
              printk(&unk_8EC7B, &unk_84256, "FREE ARP buffer", *((unsigned int *)v22 + 5));
            v33 = v6;
            mutex_lock(a1 + 480);
            v34 = *v23;
            if ( *v23 != (char *)v23 )
            {
              do
              {
                v37 = *(char **)v34;
                if ( !strcmp(v34 + 64, "Internal Scratch Buffer") )
                {
                  v38 = *((char ***)v34 + 1);
                  if ( *v38 == v34 && *((char **)v37 + 1) == v34 )
                  {
                    *((_QWORD *)v37 + 1) = v38;
                    *v38 = v37;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v34);
                  }
                  *(_QWORD *)v34 = 0xDEAD000000000100LL;
                  *((_QWORD *)v34 + 1) = 0xDEAD000000000122LL;
                  kfree(v34);
                }
                v34 = v37;
              }
              while ( v37 != (char *)v23 );
            }
            mutex_unlock(a1 + 480);
            v35 = (_QWORD *)v22[1];
            if ( (_QWORD *)*v35 == v22 && (v36 = *v22, *(_QWORD **)(*v22 + 8LL) == v22) )
            {
              *(_QWORD *)(v36 + 8) = v35;
              *v35 = v36;
            }
            else
            {
              _list_del_entry_valid_or_report(v22);
            }
            v11 = (_QWORD *)(a1 + 400);
            *v22 = 0xDEAD000000000100LL;
            v22[1] = 0xDEAD000000000122LL;
            _X8 = (unsigned int *)(v30 + 40);
            __asm { PRFM            #0x11, [X8] }
            do
              v28 = __ldxr(_X8);
            while ( __stxr(v28 - 1, _X8) );
            msm_cvp_smem_free(v30);
            cvp_kmem_cache_free(cvp_driver + 120, v30);
            v29 = cvp_driver;
            v22[7] = 0;
            cvp_kmem_cache_free(v29 + 104, v22);
            v6 = v33;
          }
          v22 = v31;
          if ( v31 == v11 )
            goto LABEL_63;
        }
        return 4294967274LL;
      }
      if ( (unsigned int)__ratelimit(&cvp_release_arp_buffers__rs, "cvp_release_arp_buffers") )
        printk(&unk_89644, "warn", v12, v13);
    }
    else
    {
      v47 = 0;
    }
    v11 = (_QWORD *)(a1 + 400);
    goto LABEL_33;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v20 = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(v20 + 1800);
    v17 = *(unsigned int *)(v20 + 1804);
    v18 = &unk_850A7;
    goto LABEL_25;
  }
  return result;
}
