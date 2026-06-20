_DWORD *__fastcall sde_crtc_atomic_flush(_DWORD *result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x26
  int v6; // w5
  __int64 v7; // x25
  unsigned __int64 v8; // x24
  __int64 v9; // x20
  __int64 v10; // x8
  _QWORD *v11; // x9
  __int64 v12; // x10
  __int64 *v13; // x11
  int v14; // w1
  __int64 v15; // x20
  __int64 v16; // x8
  __int64 *i; // x22
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x9
  __int64 v24; // x21
  void *v25; // x0
  const char *v26; // x1
  bool v27; // w27
  __int64 v28; // x8
  __int64 v29; // x28
  unsigned int v30; // w26
  __int64 v31; // x8
  int v32; // w23
  char v33; // w27
  unsigned int v34; // w0
  int v35; // w6
  int v36; // w7
  __int64 v37; // x8
  int v38; // w8
  __int64 v39; // x8
  __int64 (__fastcall *v40)(_QWORD); // x8
  __int64 v41; // x8
  __int64 *j; // x20
  int v43; // w6
  __int64 v44; // x0
  __int64 v45; // x8
  char v46; // [xsp+0h] [xbp-100h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-E8h]
  unsigned int v48; // [xsp+24h] [xbp-DCh]
  __int64 v49; // [xsp+28h] [xbp-D8h]
  _QWORD v50[26]; // [xsp+30h] [xbp-D0h] BYREF

  v50[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result || (v2 = *(_QWORD *)result, v3 = (__int64)result, !*(_QWORD *)result) || (v4 = *(_QWORD *)(v2 + 56)) == 0 )
  {
    result = (_DWORD *)printk(&unk_25E167, "sde_crtc_atomic_flush_common");
    goto LABEL_114;
  }
  v5 = *((_QWORD *)result + 251);
  v6 = *(unsigned __int8 *)(v5 + 8);
  if ( (v6 & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      result = (_DWORD *)_drm_dev_dbg(0, 0, 0, "crtc%d -> enable %d, skip atomic_flush\n", result[28], v6);
    goto LABEL_114;
  }
  if ( (*(_WORD *)(*(_QWORD *)(v2 + 8) + 488LL) & 7) != 0 )
  {
    result = (_DWORD *)printk(&unk_24FBDF, "sde_crtc_atomic_flush_common");
    goto LABEL_114;
  }
  v7 = *(_QWORD *)(v4 + 8);
  if ( !v7 )
  {
    printk(&unk_234896, "_sde_crtc_get_kms");
    result = (_DWORD *)printk(&unk_234896, "sde_crtc_atomic_flush_common");
    goto LABEL_114;
  }
  v8 = (unsigned __int64)"ress";
  if ( (_drm_debug & 4) != 0 )
  {
    v9 = a2;
    _drm_dev_dbg(0, 0, 0, "crtc%d\n", result[28]);
    v5 = *(_QWORD *)(v3 + 2008);
    a2 = v9;
  }
  v10 = *(unsigned int *)(a2 + 40);
  if ( (int)v10 >= 1 )
  {
    v11 = *(_QWORD **)(a2 + 48);
    v12 = 0;
    do
    {
      if ( *v11 )
      {
        v13 = (__int64 *)v11[3];
        if ( v13 )
        {
          if ( v13[1] == v3 )
            v12 = *v13;
        }
      }
      --v10;
      v11 += 5;
    }
    while ( v10 );
    if ( v12 && *(_DWORD *)(v12 + 3292) && v5 && *(_QWORD *)(v5 + 1536) )
      sde_crtc_static_img_control((_DWORD *)v3, 2, 0);
  }
  if ( *(_DWORD *)(v3 + 7856) == 2 && v5 && *(_QWORD *)(v5 + 1536) )
    v14 = 4;
  else
    v14 = 2;
  result = sde_crtc_static_img_control((_DWORD *)v3, v14, 0);
  if ( *(_DWORD *)(v3 + 2192) )
  {
    v15 = v3 + 4096;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v16 = *(_QWORD *)v3;
      *(_BYTE *)(v15 + 3466) = 0;
      *(_WORD *)(v15 + 3464) = 0;
      for ( i = *(__int64 **)(v16 + 840); i != (__int64 *)(v16 + 840); i = (__int64 *)*i )
      {
        if ( ((*(_DWORD *)(*(_QWORD *)(v3 + 2008) + 12LL) >> *((_DWORD *)i + 437)) & 1) != 0 )
        {
          sde_plane_restore(i - 1);
          if ( (sde_plane_is_cache_required(i - 1, 0) & 1) != 0 )
            *(_BYTE *)(v15 + 3464) = 1;
          if ( (sde_plane_is_cache_required(i - 1, 1) & 1) != 0 )
            *(_BYTE *)(v15 + 3465) = 1;
          if ( (sde_plane_is_cache_required(i - 1, 2) & 1) != 0 )
            *(_BYTE *)(v15 + 3466) = 1;
          v16 = *(_QWORD *)v3;
        }
      }
      sde_core_perf_crtc_update_llcc(v3);
      v18 = *(_QWORD *)v3;
      memset(v50, 0, 192);
      if ( v18 && (v19 = *(_QWORD *)(v18 + 56)) != 0 )
      {
        v20 = *(_QWORD *)(v19 + 8);
        if ( v20 )
        {
          if ( (*(_BYTE *)(v8 + 4000) & 4) == 0 )
            goto LABEL_45;
        }
        else
        {
          printk(&unk_234896, "_sde_crtc_get_kms");
          if ( (*(_BYTE *)(v8 + 4000) & 4) == 0 )
          {
LABEL_45:
            if ( !v20 )
              goto LABEL_61;
            goto LABEL_50;
          }
        }
      }
      else
      {
        printk(&unk_25E167, "_sde_crtc_get_kms");
        v20 = 0;
        if ( (*(_BYTE *)(v8 + 4000) & 4) == 0 )
          goto LABEL_45;
      }
      _drm_dev_dbg(0, 0, 0, "\n");
      if ( !v20 )
        goto LABEL_61;
LABEL_50:
      if ( !*(_QWORD *)(v3 + 2008) )
      {
LABEL_61:
        result = (_DWORD *)printk(&unk_22716E, "_sde_crtc_wait_for_fences");
        v27 = 0;
        goto LABEL_107;
      }
      if ( !*(_QWORD *)v3 || (v21 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
      {
        v25 = &unk_25E167;
        v26 = "sde_crtc_get_disp_op";
LABEL_65:
        printk(v25, v26);
        goto LABEL_66;
      }
      v22 = *(_QWORD *)(v21 + 8);
      if ( !v22 )
      {
        v25 = &unk_234896;
        v26 = "_sde_crtc_get_kms";
        goto LABEL_65;
      }
      v23 = *(_QWORD *)(v22 + 152);
      if ( v23 && (*(_QWORD *)(v23 + 22008) & 0x8000000000000LL) != 0 )
      {
        v15 = *(unsigned int *)(v21 + 5912);
        v24 = *(_QWORD *)(v3 + 2208);
        if ( v24 )
          goto LABEL_69;
        goto LABEL_67;
      }
LABEL_66:
      v15 = 0;
      v24 = *(_QWORD *)(v3 + 2208);
      if ( v24 )
        goto LABEL_69;
LABEL_67:
      if ( (*(_BYTE *)(v8 + 4000) & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "invalid crtc params %d\n", 0);
LABEL_69:
      v49 = v5;
      v28 = *(_QWORD *)(v20 + 152);
      v29 = v24 + 8LL * (unsigned int)v15;
      if ( *(_BYTE *)(v28 + 22140) == 1 && !*(_DWORD *)(v28 + 52) )
      {
        if ( !v24 )
          goto LABEL_122;
        if ( (unsigned int)v15 >= 3 )
          goto LABEL_126;
        if ( !*(_QWORD *)(v29 + 352) || (*(_QWORD *)(v3 + 7928) & 2) != 0 )
        {
LABEL_122:
          result = (_DWORD *)printk(&unk_276D4E, "_sde_crtc_wait_for_fences");
          v27 = 0;
          goto LABEL_106;
        }
        v30 = 1;
        v31 = *(_QWORD *)(v3 + 2008);
        if ( v31 )
LABEL_72:
          LODWORD(v31) = *(_DWORD *)(v31 + 1568);
      }
      else
      {
        v30 = 0;
        v31 = *(_QWORD *)(v3 + 2008);
        if ( v31 )
          goto LABEL_72;
      }
      v48 = v30;
      if ( (((*(_QWORD *)(v3 + 7928) & 2LL) == 0) & ~v30) == 0
        && !(unsigned int)sde_fence_update_input_hw_fence_signal(
                            v24,
                            *(unsigned int *)(v20 + 6400),
                            *(_QWORD *)(v20 + 3528),
                            (_DWORD)v31 == 1,
                            v30) )
      {
        if ( (sde_encoder_check_curr_mode(*(_QWORD *)(v3 + 2232), 1) & 1) != 0 )
        {
          v37 = *(_QWORD *)(v3 + 2008);
          if ( v37 )
          {
            v5 = (unsigned int)v15;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_crtc_is_power_on_frame",
              1435,
              -1,
              (*(unsigned __int8 *)(v37 + 10) >> 2) & 1,
              *(unsigned __int8 *)(v37 + 9),
              -1059143953,
              v36,
              v46);
            v37 = *(_QWORD *)(v3 + 2008);
            if ( (*(_BYTE *)(v37 + 10) & 4) != 0 )
            {
              LOBYTE(v37) = *(_BYTE *)(v37 + 9);
              goto LABEL_118;
            }
LABEL_116:
            v15 = v8;
            LOBYTE(v37) = 0;
          }
          else
          {
            v5 = (unsigned int)v15;
LABEL_118:
            v15 = v8;
          }
          v33 = v37 ^ 1;
          v32 = 1;
          goto LABEL_76;
        }
        v5 = (unsigned int)v15;
        goto LABEL_116;
      }
      v5 = (unsigned int)v15;
      v15 = v8;
      v32 = 0;
      v33 = 0;
LABEL_76:
      v34 = sde_crtc_fences_wait_list(v3, v33 & 1, v50);
      v8 = v34;
      if ( v34 - 1 <= 0x17 && (unsigned int)sde_fence_register_hw_fences_wait(v24, (int)v50, v34) )
      {
        printk(&unk_24C662, "_sde_crtc_wait_for_fences");
        if ( v24 )
          v43 = *(_DWORD *)(v24 + 64) - 1;
        else
          v43 = -1;
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_crtc_wait_for_fences", 4738, -1, 60333, v8, v43, -1059143953, v46);
        v8 = (unsigned int)sde_crtc_fences_wait_list(v3, 0, v50);
        if ( (*(_BYTE *)(v15 + 4000) & 4) == 0 )
          goto LABEL_93;
LABEL_79:
        if ( v24 )
          v35 = *(_DWORD *)(v24 + 64) - 1;
        else
          v35 = -1;
        _drm_dev_dbg(
          0,
          0,
          0,
          "hfence_enable:%d no_override:%d ctl:%d wait_ipcc:%d num_hfences:%d\n",
          v33 & 1,
          ((unsigned int)*(_QWORD *)(v3 + 7928) >> 2) & 1,
          v35,
          v32,
          v8);
        goto LABEL_93;
      }
      if ( (*(_BYTE *)(v15 + 4000) & 4) != 0 )
        goto LABEL_79;
LABEL_93:
      if ( v24 )
        v38 = *(_DWORD *)(v24 + 64) - 1;
      else
        LOBYTE(v38) = -1;
      result = (_DWORD *)sde_evtlog_log(
                           sde_dbg_base_evtlog,
                           "_sde_crtc_wait_for_fences",
                           4752,
                           -1,
                           v33 & 1,
                           ((unsigned int)*(_QWORD *)(v3 + 7928) >> 2) & 1,
                           v32,
                           v8,
                           v38);
      LODWORD(v39) = 0;
      v27 = (_DWORD)v8 != 0;
      if ( v32 && !(_DWORD)v8 )
      {
        if ( (unsigned int)v5 > 2 )
          goto LABEL_126;
        v39 = *(_QWORD *)(v29 + 352);
        if ( v39 )
          LODWORD(v39) = (*(_QWORD *)(v3 + 7928) & 4LL) == 0;
      }
      if ( !((unsigned int)v39 | v48) )
        goto LABEL_106;
      if ( (unsigned int)v5 <= 2 )
      {
        v40 = *(__int64 (__fastcall **)(_QWORD))(v29 + 352);
        if ( *((_DWORD *)v40 - 1) != 729814110 )
          __break(0x8228u);
        result = (_DWORD *)v40(v24);
LABEL_106:
        v5 = v49;
LABEL_107:
        *(_BYTE *)(v5 + 6920) = v27;
        v41 = *(_QWORD *)v3;
        for ( j = *(__int64 **)(*(_QWORD *)v3 + 840LL); j != (__int64 *)(v41 + 840); j = (__int64 *)*j )
        {
          if ( ((*(_DWORD *)(*(_QWORD *)(v3 + 2008) + 12LL) >> *((_DWORD *)j + 437)) & 1) != 0 )
          {
            if ( *(_DWORD *)(v7 + 3676) )
              sde_plane_set_error(j - 1, 1);
            result = (_DWORD *)sde_plane_flush(j - 1);
            v41 = *(_QWORD *)v3;
          }
        }
        break;
      }
LABEL_126:
      __break(0x5512u);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v44 = _traceiter_tracing_mark_write(0, 66, StatusReg, "sde_crtc_atomic_flush", 0);
        v45 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v45;
        if ( !v45 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v44);
      }
    }
  }
LABEL_114:
  _ReadStatusReg(SP_EL0);
  return result;
}
