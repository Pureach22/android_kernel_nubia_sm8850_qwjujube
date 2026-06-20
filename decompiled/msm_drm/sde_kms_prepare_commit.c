__int64 __fastcall sde_kms_prepare_commit(__int64 result, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x23
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x9
  char v11; // w10
  __int64 v12; // x11
  __int64 v13; // x1
  __int64 v14; // x8
  unsigned int v15; // w8
  _DWORD *v16; // x8
  __int64 v17; // x8
  __int64 v18; // x25
  _QWORD *v19; // x19
  __int64 v20; // x9
  __int64 *v21; // x9
  __int64 v22; // x21
  _QWORD *v23; // x27
  __int64 v24; // x22
  __int64 v25; // x23
  char v26; // w24
  __int64 *v27; // x9
  __int64 v28; // x28
  __int64 v29; // x10
  __int64 v30; // x8
  __int64 v31; // x10
  int secure_transition_ops; // w26
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  int v37; // w6
  int v38; // w7
  __int64 v39; // x8
  __int64 v40; // x21
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 *i; // x25
  __int64 v44; // x26
  unsigned int (__fastcall **v45)(__int64 *, __int64); // x21
  unsigned int (__fastcall *v46)(__int64 *, __int64); // x8
  unsigned int (__fastcall *v47)(__int64 *, __int64); // x8
  unsigned int v48; // w8
  int v49; // w20
  unsigned int v56; // w10
  int v57; // w7
  __int64 v58; // x8
  void (*v59)(void); // x8
  __int64 v60; // x24
  __int64 v61; // x21
  __int64 (__fastcall *v62)(__int64, __int64, unsigned __int64, const char *, _QWORD); // x8
  __int64 v63; // x0
  __int64 v64; // t1
  __int64 v65; // x8
  char v66; // [xsp+0h] [xbp-20h]
  char v67; // [xsp+0h] [xbp-20h]
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-18h]
  __int64 v69; // [xsp+10h] [xbp-10h]
  __int64 v70; // [xsp+18h] [xbp-8h]

  if ( result )
  {
    v2 = *(_QWORD *)(result + 136);
    v3 = result;
    if ( v2 )
    {
      v4 = *(_QWORD *)(v2 + 56);
      if ( v4 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v6 = *(_QWORD *)(*(_QWORD *)(v3 + 136) + 8LL);
          v7 = _pm_runtime_resume(v6, 4);
          if ( (v7 & 0x80000000) != 0 )
          {
            v48 = *(_DWORD *)(v6 + 480);
            v49 = v7;
            do
            {
              if ( !v48 )
                break;
              _X12 = (unsigned int *)(v6 + 480);
              __asm { PRFM            #0x11, [X12] }
              while ( 1 )
              {
                v56 = __ldxr(_X12);
                if ( v56 != v48 )
                  break;
                if ( !__stlxr(v48 - 1, _X12) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              _ZF = v56 == v48;
              v48 = v56;
            }
            while ( !_ZF );
            printk(&unk_269238, "sde_kms_prepare_commit");
            return sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "sde_kms_prepare_commit",
                     1378,
                     -1,
                     v49,
                     60333,
                     -1059143953,
                     v57,
                     v66);
          }
          if ( *(_BYTE *)(v3 + 3744) == 1 )
          {
            v9 = *(unsigned int *)(a2[1] + 860LL);
            if ( (int)v9 < 1 )
            {
              v13 = 1;
            }
            else
            {
              v10 = a2[4];
              v11 = 1;
              do
              {
                if ( *(_QWORD *)v10 )
                {
                  v12 = *(_QWORD *)(*(_QWORD *)v10 + 2008LL);
                  if ( *(_BYTE *)(v12 + 9) != 1 || (*(_BYTE *)(v12 + 10) & 4) == 0 )
                    v11 = 0;
                }
                --v9;
                v10 += 56;
              }
              while ( v9 );
              if ( (v11 & 1) != 0 )
                v13 = 1;
              else
                v13 = 3;
            }
            v7 = sde_power_scale_reg_bus(v4 + 16, v13, 0);
            *(_BYTE *)(v3 + 3744) = 0;
          }
          v14 = *(_QWORD *)(*(_QWORD *)(v3 + 136) + 56LL);
          if ( !v14 )
            break;
          v15 = *(_DWORD *)(v14 + 5912);
          if ( v15 < 3 )
            goto LABEL_22;
          __break(0x5512u);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            v60 = v3;
            ++*(_DWORD *)(StatusReg + 16);
            v61 = qword_29E3D0;
            if ( qword_29E3D0 )
            {
              do
              {
                v62 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64, const char *, _QWORD))v61;
                v63 = *(_QWORD *)(v61 + 8);
                if ( *(_DWORD *)(*(_QWORD *)v61 - 4LL) != -641035679 )
                  __break(0x8228u);
                v7 = v62(v63, 66, StatusReg, "prepare_commit", 0);
                v64 = *(_QWORD *)(v61 + 24);
                v61 += 24;
              }
              while ( v64 );
            }
            v3 = v60;
            v65 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v65;
            if ( !v65 || !*(_QWORD *)(StatusReg + 16) )
              preempt_schedule_notrace(v7);
          }
        }
        printk(&unk_25E374, "sde_kms_get_disp_op");
        v15 = 0;
LABEL_22:
        v16 = *(_DWORD **)(v3 + 8LL * v15 + 6688);
        if ( v16 )
        {
          if ( *(v16 - 1) != -307910306 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(__int64, _QWORD *))v16)(v3, a2) )
            printk(&unk_2573F5, "sde_kms_prepare_commit");
        }
        v17 = a2[1];
        v70 = v3;
        if ( *(int *)(v17 + 860) >= 1 )
        {
          v18 = 0;
          v19 = (_QWORD *)(v2 + 816);
          do
          {
            v21 = (__int64 *)(a2[4] + 56 * v18);
            v22 = *v21;
            if ( *v21 )
            {
              v23 = (_QWORD *)*v19;
              if ( (_QWORD *)*v19 != v19 )
              {
                v24 = v21[3];
                do
                {
                  if ( ((*(_DWORD *)(v24 + 20) >> *((_DWORD *)v23 + 15)) & 1) != 0
                    && (unsigned int)sde_encoder_prepare_commit((__int64)(v23 - 1), v8) == -110 )
                  {
                    printk(&unk_25EC9D, "sde_kms_prepare_commit");
                    ((void (__fastcall *)(_QWORD *))sde_encoder_needs_hw_reset)(v23 - 1);
                    *(_BYTE *)(v22 + 7756) = 1;
                  }
                  v23 = (_QWORD *)*v23;
                }
                while ( v23 != v19 );
                v17 = a2[1];
              }
            }
            v20 = *(int *)(v17 + 860);
            ++v18;
          }
          while ( v18 < v20 );
          if ( (int)v20 >= 1 )
          {
            LODWORD(v25) = 0;
            v26 = 0;
            v69 = *(_QWORD *)(v70 + 136);
            while ( 1 )
            {
              v27 = (__int64 *)(a2[4] + 56LL * (int)v25);
              v28 = *v27;
              if ( *v27 )
              {
                v29 = *(_QWORD *)(v28 + 2008);
                if ( v29 )
                {
                  if ( *(_BYTE *)(v29 + 9) == 1 )
                    break;
                }
              }
LABEL_40:
              v17 = a2[1];
              LODWORD(v25) = v25 + 1;
              if ( (int)v25 >= *(_DWORD *)(v17 + 860) )
                goto LABEL_108;
            }
            v30 = *(unsigned int *)(v17 + 832);
            if ( (int)v30 < 1 )
            {
              LODWORD(v25) = 0;
            }
            else
            {
              v25 = 0;
              v31 = a2[3] + 16LL;
              do
              {
                if ( *(_QWORD *)(v31 - 16) && *(_QWORD *)(*(_QWORD *)v31 + 8LL) && *(_QWORD *)(*(_QWORD *)v31 + 16LL) )
                {
                  v26 = 1;
                  goto LABEL_53;
                }
                ++v25;
                v31 += 32;
              }
              while ( v30 != v25 );
              LODWORD(v25) = v30;
            }
LABEL_53:
            secure_transition_ops = sde_crtc_get_secure_transition_ops(*v27, v27[2], v26 & 1);
            if ( secure_transition_ops < 0 )
            {
              printk(&unk_22109C, "sde_kms_prepare_secure_transition");
              goto LABEL_108;
            }
            if ( !secure_transition_ops )
            {
              *(_DWORD *)(v70 + 3676) = 0;
              goto LABEL_108;
            }
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "%d:secure operations(%x) started on state:%pK\n",
                *(_DWORD *)(v28 + 112),
                secure_transition_ops,
                *(const void **)(v28 + 2008));
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_kms_prepare_secure_transition",
              784,
              -1,
              *(_DWORD *)(v28 + 112),
              secure_transition_ops,
              *(_QWORD *)(v28 + 2008),
              v26 & 1,
              239);
            if ( (secure_transition_ops & 2) != 0 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "wait_for_transfer_done\n");
              sde_kms_wait_for_frame_transfer_complete(v70, (__int64 *)v28, v33, v34, v35, v36, v37, v38);
              if ( (secure_transition_ops & 4) != 0 )
                goto LABEL_65;
LABEL_59:
              if ( (secure_transition_ops & 1) == 0 )
                goto LABEL_60;
LABEL_75:
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "secure ctrl\n");
              sde_kms_secure_ctrl(v70, v28, 0);
              if ( (secure_transition_ops & 8) != 0 )
              {
LABEL_80:
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(0, 0, 0, "prepare planes %d", *(_DWORD *)(*(_QWORD *)(v28 + 2008) + 12LL));
                v42 = *(_QWORD *)v28;
                for ( i = *(__int64 **)(*(_QWORD *)v28 + 840LL); i != (__int64 *)(v42 + 840); i = (__int64 *)*i )
                {
                  if ( ((*(_DWORD *)(*(_QWORD *)(v28 + 2008) + 12LL) >> *((_DWORD *)i + 437)) & 1) != 0 )
                  {
                    v44 = i[220];
                    v45 = (unsigned int (__fastcall **)(__int64 *, __int64))i[219];
                    if ( (_drm_debug & 4) != 0 )
                      _drm_dev_dbg(0, 0, 0, "psde:%d FB[%u]\n", *((_DWORD *)i + 24), *(_DWORD *)(i[22] + 24));
                    if ( v45 )
                    {
                      v46 = *v45;
                      if ( *((_DWORD *)*v45 - 1) != -2123931425 )
                        __break(0x8228u);
                      if ( v46(i - 1, v44) )
                      {
                        v47 = *v45;
                        if ( *((_DWORD *)*v45 - 1) != -2123931425 )
                          __break(0x8228u);
                        if ( v47(i - 1, v44) )
                          goto LABEL_108;
                      }
                    }
                  }
                  v42 = *(_QWORD *)v28;
                }
              }
            }
            else
            {
              if ( (secure_transition_ops & 4) == 0 )
                goto LABEL_59;
LABEL_65:
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "cleanup planes\n");
              drm_atomic_helper_cleanup_planes(v69, a2);
              v39 = a2[1];
              if ( *(int *)(v39 + 832) < 1 )
              {
                LODWORD(v25) = 0;
                if ( (secure_transition_ops & 1) != 0 )
                  goto LABEL_75;
              }
              else
              {
                v40 = 0;
                v25 = 0;
                do
                {
                  v41 = a2[3];
                  if ( *(_QWORD *)(v41 + v40) )
                  {
                    sde_plane_destroy_fb(*(_QWORD *)(v41 + v40 + 16));
                    v39 = a2[1];
                  }
                  ++v25;
                  v40 += 32;
                }
                while ( v25 < *(int *)(v39 + 832) );
                if ( (secure_transition_ops & 1) != 0 )
                  goto LABEL_75;
              }
LABEL_60:
              if ( (secure_transition_ops & 8) != 0 )
                goto LABEL_80;
            }
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_kms_prepare_secure_transition",
              826,
              -1,
              *(_DWORD *)(v28 + 112),
              8738,
              -1059143953,
              v38,
              v67);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "secure operations completed\n");
            goto LABEL_40;
          }
        }
LABEL_108:
        v58 = *(_QWORD *)(v70 + 6384);
        if ( v58 )
        {
          v59 = *(void (**)(void))(v58 + 96);
          if ( v59 )
          {
            if ( *((_DWORD *)v59 - 1) != -307910306 )
              __break(0x8228u);
            v59();
          }
        }
        return sde_kms_drm_check_dpms(a2, 1);
      }
    }
  }
  return result;
}
