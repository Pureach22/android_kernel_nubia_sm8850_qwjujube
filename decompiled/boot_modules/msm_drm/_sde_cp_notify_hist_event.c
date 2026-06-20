__int64 __fastcall sde_cp_notify_hist_event(_QWORD *a1, unsigned int *a2)
{
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x23
  _QWORD *v9; // x9
  _QWORD *v10; // x27
  int v11; // w8
  int v12; // w25
  __int64 result; // x0
  unsigned int disp_op; // w21
  unsigned int v15; // w24
  __int64 v16; // x22
  int v17; // w0
  __int64 v18; // x22
  int v19; // w0
  unsigned int v20; // w8
  int v21; // w20
  unsigned int v28; // w10
  __int64 v29; // x22
  int v30; // w0
  __int64 v31; // x0
  void (*v32)(void); // x8
  __int64 v33; // x0
  void (*v34)(void); // x8
  __int64 v35; // x0
  void (*v36)(void); // x8
  __int64 v37; // x0
  void (*v38)(void); // x8
  __int64 v39; // x0
  void (*v40)(void); // x8
  __int64 v41; // x0
  void (*v42)(void); // x8
  __int64 v43; // x0
  void (*v44)(void); // x8
  __int64 v45; // x0
  void (*v46)(void); // x8
  __int64 v47; // x22
  int v48; // w0
  __int64 v49; // x22
  __int64 v50; // x1
  void (__fastcall *v51)(__int64, __int64); // x8
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x3
  void (__fastcall *v55)(__int64, __int64); // x8
  __int64 v56; // x0
  void (__fastcall *v57)(__int64, __int64); // x8
  __int64 v58; // x0
  void (__fastcall *v59)(__int64, __int64); // x8
  __int64 v60; // x0
  void (__fastcall *v61)(__int64, __int64); // x8
  __int64 v62; // x0
  void (__fastcall *v63)(__int64, __int64); // x8
  __int64 v64; // x0
  void (__fastcall *v65)(__int64, __int64); // x8
  __int64 v66; // x0
  void (__fastcall *v67)(__int64, __int64); // x8
  __int64 v68; // x0
  unsigned int v69; // w8
  unsigned int v72; // w10
  int v73; // w7
  int v74; // w2
  unsigned int v75; // w8
  unsigned int v78; // w10
  char v79; // [xsp+0h] [xbp-20h]
  _QWORD v80[2]; // [xsp+10h] [xbp-10h] BYREF

  v80[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v80[0] = 0;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(*a1 + 56LL) + 8LL);
    if ( v4 && *(_QWORD *)(v4 + 136) )
    {
      v5 = *(_QWORD *)(v4 + 6384);
      if ( !v5 )
        goto LABEL_13;
      mutex_lock(v5);
      v6 = *(_QWORD *)(v4 + 6384);
      if ( !v6 )
        goto LABEL_13;
      v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 88);
      if ( !v7 )
        goto LABEL_12;
      if ( *((_DWORD *)v7 - 1) != 1370937740 )
        __break(0x8228u);
      if ( (v7(v4) & 1) != 0 )
      {
        v6 = *(_QWORD *)(v4 + 6384);
        if ( !v6 )
        {
LABEL_13:
          v8 = raw_spin_lock_irqsave(a1 + 754);
          v9 = a1 + 575;
          while ( 1 )
          {
            v9 = (_QWORD *)*v9;
            if ( v9 == a1 + 575 )
              break;
            if ( *((_DWORD *)v9 - 4) == 0x80000000 )
            {
              v10 = v9 - 6;
              v11 = *((_DWORD *)a1 + 548);
              if ( !v11 )
                goto LABEL_17;
LABEL_20:
              if ( (unsigned int)(v11 - 9) >= 0xFFFFFFF8 )
              {
                v12 = a1[277] != 0;
                if ( v11 != 1 )
                {
                  if ( a1[283] )
                    ++v12;
                  if ( v11 != 2 )
                  {
                    if ( a1[289] )
                      ++v12;
                    if ( v11 != 3 )
                    {
                      if ( a1[295] )
                        ++v12;
                      if ( v11 != 4 )
                      {
                        if ( a1[301] )
                          ++v12;
                        if ( v11 != 5 )
                        {
                          if ( a1[307] )
                            ++v12;
                          if ( v11 != 6 )
                          {
                            if ( a1[313] )
                              ++v12;
                            if ( v11 != 7 && a1[319] )
                              ++v12;
                          }
                        }
                      }
                    }
                  }
                }
                goto LABEL_42;
              }
              goto LABEL_165;
            }
          }
          v10 = nullptr;
          v11 = *((_DWORD *)a1 + 548);
          if ( v11 )
            goto LABEL_20;
LABEL_17:
          v12 = 0;
LABEL_42:
          disp_op = sde_crtc_get_disp_op((__int64)a1);
          if ( !v10 )
          {
            raw_spin_unlock_irqrestore(a1 + 754, v8);
            _drm_dev_dbg(0, 0, 1, "cannot find histogram event node in crtc\n");
            v29 = *(_QWORD *)(*(_QWORD *)(v4 + 136) + 8LL);
            v30 = _pm_runtime_resume(v29, 4);
            if ( v30 < 0 )
            {
              v69 = *(_DWORD *)(v29 + 480);
              v21 = v30;
              do
              {
                if ( !v69 )
                  break;
                _X12 = (unsigned int *)(v29 + 480);
                __asm { PRFM            #0x11, [X12] }
                while ( 1 )
                {
                  v72 = __ldxr(_X12);
                  if ( v72 != v69 )
                    break;
                  if ( !__stlxr(v69 - 1, _X12) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v72 == v69;
                v69 = v72;
              }
              while ( !_ZF );
              printk(&unk_24C43E, "_sde_cp_notify_hist_event");
              v74 = 4060;
              goto LABEL_192;
            }
LABEL_56:
            if ( !v12 )
              goto LABEL_169;
            v31 = a1[277];
            if ( v31 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v32 = *(void (**)(void))(v31 + 8LL * disp_op + 136);
              if ( v32 )
              {
                if ( *((_DWORD *)v32 - 1) != 1841204718 )
                  __break(0x8228u);
                v32();
              }
            }
            if ( v12 == 1 )
              goto LABEL_169;
            v33 = a1[283];
            if ( v33 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v34 = *(void (**)(void))(v33 + 8LL * disp_op + 136);
              if ( v34 )
              {
                if ( *((_DWORD *)v34 - 1) != 1841204718 )
                  __break(0x8228u);
                v34();
              }
            }
            if ( v12 == 2 )
              goto LABEL_169;
            v35 = a1[289];
            if ( v35 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v36 = *(void (**)(void))(v35 + 8LL * disp_op + 136);
              if ( v36 )
              {
                if ( *((_DWORD *)v36 - 1) != 1841204718 )
                  __break(0x8228u);
                v36();
              }
            }
            if ( v12 == 3 )
              goto LABEL_169;
            v37 = a1[295];
            if ( v37 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v38 = *(void (**)(void))(v37 + 8LL * disp_op + 136);
              if ( v38 )
              {
                if ( *((_DWORD *)v38 - 1) != 1841204718 )
                  __break(0x8228u);
                v38();
              }
            }
            if ( v12 == 4 )
              goto LABEL_169;
            v39 = a1[301];
            if ( v39 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v40 = *(void (**)(void))(v39 + 8LL * disp_op + 136);
              if ( v40 )
              {
                if ( *((_DWORD *)v40 - 1) != 1841204718 )
                  __break(0x8228u);
                v40();
              }
            }
            if ( v12 == 5 )
              goto LABEL_169;
            v41 = a1[307];
            if ( v41 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v42 = *(void (**)(void))(v41 + 8LL * disp_op + 136);
              if ( v42 )
              {
                if ( *((_DWORD *)v42 - 1) != 1841204718 )
                  __break(0x8228u);
                v42();
              }
            }
            if ( v12 == 6 )
              goto LABEL_169;
            v43 = a1[313];
            if ( v43 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v44 = *(void (**)(void))(v43 + 8LL * disp_op + 136);
              if ( v44 )
              {
                if ( *((_DWORD *)v44 - 1) != 1841204718 )
                  __break(0x8228u);
                v44();
              }
            }
            if ( v12 == 7 )
              goto LABEL_169;
            v45 = a1[319];
            if ( v45 )
            {
              if ( disp_op > 2 )
                goto LABEL_165;
              v46 = *(void (**)(void))(v45 + 8LL * disp_op + 136);
              if ( v46 )
              {
                if ( *((_DWORD *)v46 - 1) != 1841204718 )
                  __break(0x8228u);
                v46();
              }
            }
            if ( v12 == 8 )
              goto LABEL_169;
LABEL_165:
            __break(0x5512u);
            goto LABEL_166;
          }
          v15 = *a2;
          v16 = raw_spin_lock_irqsave((char *)v10 + 68);
          if ( *((_DWORD *)v10 + 16) == 1 )
          {
            v17 = ((__int64 (__fastcall *)(__int64, _QWORD))sde_core_irq_disable_nolock)(v4, v15);
            if ( v17 )
            {
              _drm_err("failed to disable irq %d, ret %d\n", v15, v17);
              raw_spin_unlock_irqrestore((char *)v10 + 68, v16);
              raw_spin_unlock_irqrestore(a1 + 754, v8);
              v18 = *(_QWORD *)(*(_QWORD *)(v4 + 136) + 8LL);
              v19 = _pm_runtime_resume(v18, 4);
              if ( v19 < 0 )
              {
                v20 = *(_DWORD *)(v18 + 480);
                v21 = v19;
                do
                {
                  if ( !v20 )
                    break;
                  _X12 = (unsigned int *)(v18 + 480);
                  __asm { PRFM            #0x11, [X12] }
                  while ( 1 )
                  {
                    v28 = __ldxr(_X12);
                    if ( v28 != v20 )
                      break;
                    if ( !__stlxr(v20 - 1, _X12) )
                    {
                      __dmb(0xBu);
                      break;
                    }
                  }
                  _ZF = v28 == v20;
                  v20 = v28;
                }
                while ( !_ZF );
                printk(&unk_24C43E, "_sde_cp_notify_hist_event");
                v74 = 4085;
LABEL_192:
                result = sde_evtlog_log(
                           sde_dbg_base_evtlog,
                           "_sde_cp_notify_hist_event",
                           v74,
                           -1,
                           v21,
                           60333,
                           -1059143953,
                           v73,
                           v79);
                goto LABEL_170;
              }
              goto LABEL_56;
            }
            *((_DWORD *)v10 + 16) = 3;
          }
          raw_spin_unlock_irqrestore((char *)v10 + 68, v16);
          result = raw_spin_unlock_irqrestore(a1 + 754, v8);
          if ( !a1[947] )
            goto LABEL_170;
          v47 = *(_QWORD *)(*(_QWORD *)(v4 + 136) + 8LL);
          v48 = _pm_runtime_resume(v47, 4);
          if ( v48 < 0 )
          {
            v75 = *(_DWORD *)(v47 + 480);
            v21 = v48;
            do
            {
              if ( !v75 )
                break;
              _X12 = (unsigned int *)(v47 + 480);
              __asm { PRFM            #0x11, [X12] }
              while ( 1 )
              {
                v78 = __ldxr(_X12);
                if ( v78 != v75 )
                  break;
                if ( !__stlxr(v75 - 1, _X12) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              _ZF = v78 == v75;
              v75 = v78;
            }
            while ( !_ZF );
            printk(&unk_24C43E, "_sde_cp_notify_hist_event");
            v74 = 4110;
            goto LABEL_192;
          }
          v49 = *(_QWORD *)(a1[947] + 80LL);
          memset((void *)(v49 + 8), 0, 0x400u);
          if ( !v12 )
          {
LABEL_129:
            _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(v4 + 136) + 8LL), 4);
            v53 = *a1;
            v54 = a1[947];
            v80[0] = 0x480000000LL;
            result = msm_mode_object_event_notify(a1 + 14, v53, v80, v54);
            goto LABEL_170;
          }
          v50 = a1[277];
          if ( v50 )
          {
            if ( disp_op > 2 )
              goto LABEL_165;
            v51 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
            if ( !v51 )
              goto LABEL_167;
            v52 = a1[277];
            if ( *((_DWORD *)v51 - 1) != 1841204718 )
              __break(0x8228u);
            v51(v52, v49);
            if ( v12 == 1 )
              goto LABEL_129;
            v50 = a1[283];
            if ( v50 )
            {
              v55 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
              if ( !v55 )
                goto LABEL_167;
              v56 = a1[283];
              if ( *((_DWORD *)v55 - 1) != 1841204718 )
                __break(0x8228u);
              v55(v56, v49);
              if ( v12 == 2 )
                goto LABEL_129;
              v50 = a1[289];
              if ( v50 )
              {
                v57 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                if ( !v57 )
                  goto LABEL_167;
                v58 = a1[289];
                if ( *((_DWORD *)v57 - 1) != 1841204718 )
                  __break(0x8228u);
                v57(v58, v49);
                if ( v12 == 3 )
                  goto LABEL_129;
                v50 = a1[295];
                if ( v50 )
                {
                  v59 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                  if ( !v59 )
                    goto LABEL_167;
                  v60 = a1[295];
                  if ( *((_DWORD *)v59 - 1) != 1841204718 )
                    __break(0x8228u);
                  v59(v60, v49);
                  if ( v12 == 4 )
                    goto LABEL_129;
                  v50 = a1[301];
                  if ( v50 )
                  {
                    v61 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                    if ( !v61 )
                      goto LABEL_167;
                    v62 = a1[301];
                    if ( *((_DWORD *)v61 - 1) != 1841204718 )
                      __break(0x8228u);
                    v61(v62, v49);
                    if ( v12 == 5 )
                      goto LABEL_129;
                    v50 = a1[307];
                    if ( v50 )
                    {
                      v63 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                      if ( !v63 )
                        goto LABEL_167;
                      v64 = a1[307];
                      if ( *((_DWORD *)v63 - 1) != 1841204718 )
                        __break(0x8228u);
                      v63(v64, v49);
                      if ( v12 == 6 )
                        goto LABEL_129;
                      v50 = a1[313];
                      if ( v50 )
                      {
                        v65 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                        if ( !v65 )
                          goto LABEL_167;
                        v66 = a1[313];
                        if ( *((_DWORD *)v65 - 1) != 1841204718 )
                          __break(0x8228u);
                        v65(v66, v49);
                        if ( v12 == 7 )
                          goto LABEL_129;
                        v50 = a1[319];
                        if ( v50 )
                        {
                          v67 = *(void (__fastcall **)(__int64, __int64))(v50 + 8LL * disp_op + 112);
                          if ( v67 )
                          {
                            v68 = a1[319];
                            if ( *((_DWORD *)v67 - 1) != 1841204718 )
                              __break(0x8228u);
                            v67(v68, v49);
                            if ( v12 != 8 )
                              goto LABEL_165;
                            goto LABEL_129;
                          }
LABEL_167:
                          if ( !disp_op )
                            _drm_err("invalid dspp %pK or read_histogram func\n", v50);
                          goto LABEL_169;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LABEL_166:
          _drm_err("invalid dspp %pK or read_histogram func\n", 0);
LABEL_169:
          result = _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(v4 + 136) + 8LL), 4);
          goto LABEL_170;
        }
LABEL_12:
        mutex_unlock(v6);
        goto LABEL_13;
      }
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "op not supported due to HW unavailability\n");
      result = *(_QWORD *)(v4 + 6384);
      if ( result )
        result = mutex_unlock(result);
    }
    else
    {
      result = printk(&unk_249CCB, "_sde_cp_notify_hist_event");
    }
  }
  else
  {
    result = _drm_err("invalid drm crtc %pK or arg %pK\n", a1, a2);
  }
LABEL_170:
  _ReadStatusReg(SP_EL0);
  return result;
}
