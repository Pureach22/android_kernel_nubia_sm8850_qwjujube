__int64 cvp_remove_dsp_sessions()
{
  __int64 v0; // x8
  int v1; // w22
  __int64 v2; // x25
  __int64 result; // x0
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 *v6; // x22
  __int64 *v7; // x24
  __int64 *v8; // x8
  __int64 *v9; // x27
  __int64 **v10; // x8
  __int64 *v11; // x8
  void (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  __int64 *v14; // x23
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x22
  __int64 *v18; // x27
  int v19; // w8
  int v20; // w9
  __int64 v21; // x10
  bool v22; // zf
  int v23; // w8
  unsigned int v24; // w0
  unsigned int v25; // w21
  __int64 **v26; // x8
  __int64 *v27; // x9
  int v28; // w8
  int v29; // w9
  unsigned int v30; // w8
  __int64 v31; // x9
  __int64 v32; // x10
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-50h]
  __int64 v42; // [xsp+8h] [xbp-48h] BYREF
  __int64 v43; // [xsp+10h] [xbp-40h]
  __int64 v44; // [xsp+18h] [xbp-38h]
  __int64 v45; // [xsp+20h] [xbp-30h]
  __int64 v46; // [xsp+28h] [xbp-28h]
  __int64 v47; // [xsp+30h] [xbp-20h]
  __int64 v48; // [xsp+38h] [xbp-18h]
  __int64 v49; // [xsp+40h] [xbp-10h]
  __int64 v50; // [xsp+48h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&unk_6CF58);
  v0 = qword_6CF48;
  if ( (__int64 *)qword_6CF48 != &qword_6CF48 )
  {
    v1 = 10;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( !v0 )
        goto LABEL_84;
      v2 = v0;
      if ( !*(_DWORD *)(v0 + 28) )
        break;
      mutex_unlock(&unk_6CF58);
      result = usleep_range_state(5000, 10000, 2);
      if ( !v1 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v40 = _ReadStatusReg(SP_EL0);
          result = printk(&unk_8EFD6, *(unsigned int *)(v40 + 1800), *(unsigned int *)(v40 + 1804), &unk_8E7CE);
        }
        goto LABEL_85;
      }
      --v1;
      mutex_lock(&unk_6CF58);
      v0 = qword_6CF48;
      if ( (__int64 *)qword_6CF48 == &qword_6CF48 )
      {
LABEL_12:
        mutex_unlock(&unk_6CF58);
        mutex_lock(v2 + 312);
        v6 = *(__int64 **)(v2 + 296);
        if ( !v6 )
        {
          result = mutex_unlock(v2 + 312);
          goto LABEL_92;
        }
        v7 = (__int64 *)(v2 + 296);
        if ( v6 != (__int64 *)(v2 + 296) )
        {
          v8 = (__int64 *)*v6;
          if ( *v6 )
          {
            do
            {
              v9 = v8;
              if ( v6 != &qword_10 )
              {
                v10 = (__int64 **)v6[1];
                if ( *v10 == v6 && (__int64 *)v9[1] == v6 )
                {
                  v9[1] = (__int64)v10;
                  *v10 = v9;
                }
                else
                {
                  _list_del_entry_valid_or_report(v6);
                }
                *v6 = 0xDEAD000000000100LL;
                v6[1] = 0xDEAD000000000122LL;
                --*(_DWORD *)(v2 + 20);
                mutex_unlock(v2 + 312);
                v11 = *(__int64 **)(v6[14] + 256);
                *((_DWORD *)v6 + 3848) = 0x7FFFFFFF;
                if ( v11 )
                {
                  v12 = (void (__fastcall *)(_QWORD))v11[23];
                  if ( v12 )
                  {
                    v13 = *v11;
                    if ( *((_DWORD *)v12 - 1) != -1066802076 )
                      __break(0x8229u);
                    v12(v13);
                  }
                }
                if ( (unsigned int)msm_cvp_close((__int64)(v6 - 2)) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                  printk(
                    &unk_832BF,
                    *(unsigned int *)(StatusReg + 1800),
                    *(unsigned int *)(StatusReg + 1804),
                    &unk_8E7CE);
                mutex_lock(v2 + 312);
              }
              if ( v9 == v7 )
                break;
              v8 = (__int64 *)*v9;
              v6 = v9;
            }
            while ( *v9 );
          }
        }
        mutex_unlock(v2 + 312);
        v14 = (__int64 *)(v2 + 360);
        mutex_lock(v2 + 376);
        v17 = *(_QWORD *)(v2 + 360);
        if ( v17 != v2 + 360 && v17 )
        {
          do
          {
            v18 = *(__int64 **)v17;
            v19 = msm_cvp_debug_out;
            v20 = msm_cvp_debug & 0x800;
            if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8714C, "dsp", *(unsigned int *)(v17 + 16), v16);
              v19 = msm_cvp_debug_out;
              v20 = msm_cvp_debug & 0x800;
            }
            v21 = *(_QWORD *)(v17 + 56);
            if ( v20 )
              v22 = v19 == 0;
            else
              v22 = 0;
            v23 = v22;
            if ( v21 )
            {
              if ( v23 )
                printk(&unk_90F61, "dsp", "eva_fastrpc_remove_buffers", *(unsigned int *)(v21 + 64));
              v24 = eva_fastrpc_dev_unmap_dma(*(_QWORD *)(v2 + 256), v17, v15, v16);
              if ( v24 )
              {
                if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
                {
                  v25 = v24;
                  if ( (unsigned int)__ratelimit(&eva_fastrpc_remove_buffers__rs, "eva_fastrpc_remove_buffers") )
                    printk(&unk_886EE, "warn", "eva_fastrpc_remove_buffers", v25);
                }
              }
              if ( (unsigned int)cvp_release_dsp_buffers(v17) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_93ED2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              v26 = *(__int64 ***)(v17 + 8);
              if ( *v26 == (__int64 *)v17 && (v27 = *(__int64 **)v17, *(_QWORD *)(*(_QWORD *)v17 + 8LL) == v17) )
              {
                v27[1] = (__int64)v26;
                *v26 = v27;
              }
              else
              {
                _list_del_entry_valid_or_report(v17);
              }
              *(_QWORD *)v17 = 0xDEAD000000000100LL;
              *(_QWORD *)(v17 + 8) = 0xDEAD000000000122LL;
              cvp_kmem_cache_free((_QWORD *)(cvp_driver + 104));
              if ( v18 == v14 )
                break;
            }
            else if ( v23 )
            {
              printk(&unk_8EFFA, "dsp", v15, v16);
              if ( v18 == v14 )
                break;
            }
            else if ( v18 == v14 )
            {
              break;
            }
            v17 = (__int64)v18;
          }
          while ( v18 );
        }
        v28 = msm_cvp_debug_out;
        v29 = msm_cvp_debug & 0x800;
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        {
          v31 = *(_QWORD *)(v2 + 336);
          v46 = *(_QWORD *)(v2 + 328);
          v47 = v31;
          v32 = *(_QWORD *)(v2 + 352);
          v48 = *(_QWORD *)(v2 + 344);
          v49 = v32;
          v33 = *(_QWORD *)(v2 + 304);
          v42 = *v7;
          v43 = v33;
          v34 = *(_QWORD *)(v2 + 320);
          v44 = *(_QWORD *)(v2 + 312);
          v45 = v34;
          printk(&unk_8D57A, "dsp", "cvp_remove_dsp_sessions", &v42);
          v28 = msm_cvp_debug_out;
          v29 = msm_cvp_debug & 0x800;
        }
        if ( v29 && !v28 )
        {
          v35 = *(_QWORD *)(v2 + 400);
          v46 = *(_QWORD *)(v2 + 392);
          v47 = v35;
          v36 = *(_QWORD *)(v2 + 416);
          v48 = *(_QWORD *)(v2 + 408);
          v49 = v36;
          v37 = *(_QWORD *)(v2 + 368);
          v42 = *v14;
          v43 = v37;
          v38 = *(_QWORD *)(v2 + 384);
          v44 = *(_QWORD *)(v2 + 376);
          v45 = v38;
          printk(&unk_8D57A, "dsp", "cvp_remove_dsp_sessions", &v42);
          v28 = msm_cvp_debug_out;
          if ( (msm_cvp_debug & 0x800) != 0 )
          {
LABEL_73:
            if ( !v28 )
              printk(&unk_8C16C, "dsp", "cvp_remove_dsp_sessions", v2);
          }
        }
        else if ( v29 )
        {
          goto LABEL_73;
        }
        fastrpc_driver_unregister(v2 + 32);
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
          printk(&unk_8D5A7, "dsp", "cvp_remove_dsp_sessions", *(unsigned int *)(v2 + 16));
        mutex_lock(&unk_6C630);
        v30 = *(_DWORD *)(v2 + 24);
        if ( v30 >= 8 )
          __break(0x5512u);
        *((_DWORD *)&gfa_cv + 5 * v30 + 622) = 1;
        mutex_unlock(&unk_6C630);
        kfree(v2);
        mutex_lock(&unk_6CF58);
        v0 = qword_6CF48;
        v1 = 10;
        if ( (__int64 *)qword_6CF48 == &qword_6CF48 )
          goto LABEL_84;
      }
    }
    v4 = *(_QWORD **)(v0 + 8);
    if ( *v4 == v2 && (v5 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
    {
      *(_QWORD *)(v5 + 8) = v4;
      *v4 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *(_QWORD *)v2 = 0xDEAD000000000100LL;
    *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
    goto LABEL_12;
  }
LABEL_84:
  result = mutex_unlock(&unk_6CF58);
LABEL_85:
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v39 = _ReadStatusReg(SP_EL0);
    result = printk(&unk_82AE0, *(unsigned int *)(v39 + 1800), *(unsigned int *)(v39 + 1804), "warn");
  }
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return result;
}
