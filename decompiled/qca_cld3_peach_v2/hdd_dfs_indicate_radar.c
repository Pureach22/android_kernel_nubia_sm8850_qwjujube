__int64 __fastcall hdd_dfs_indicate_radar(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x0
  __int64 v20; // x21
  __int64 v21; // x20
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 v32; // x8
  __int64 v33; // x26
  __int64 v34; // x4
  _QWORD *context; // x0
  __int64 v36; // x8
  void (*v37)(void); // x8
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x10
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x21
  __int64 v51; // x8
  __int64 v52; // x8
  unsigned int *v53; // x8
  unsigned int v54; // w10
  __int64 v55; // x8
  unsigned int v62; // w9
  _QWORD *v63; // x1
  __int64 v64; // x9
  unsigned __int64 v65; // x8
  __int64 v66; // x9
  unsigned int *v67; // x9
  unsigned int v68; // w12
  __int64 v69; // x9
  __int64 v71; // x0
  __int64 v72; // x22
  __int64 v73; // x9
  unsigned __int64 v74; // x8
  __int64 v75; // x9
  unsigned int *v76; // x9
  unsigned int v77; // w12
  __int64 v78; // x9
  _QWORD *v81; // x20
  unsigned int v83; // w9
  unsigned int v85; // w9
  unsigned __int64 v86; // [xsp+0h] [xbp-20h]
  _BYTE v87[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v88[2]; // [xsp+10h] [xbp-10h] BYREF

  v88[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87[0] = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 4u, "%s: Couldn't get hdd_ctx", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_dfs_indicate_radar");
    goto LABEL_82;
  }
  ucfg_mlme_get_dfs_disable_channel_switch(*a1, v87);
  if ( v87[0] != 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
    }
    v88[0] = 0;
    v19 = qdf_list_peek_front(a1 + 6, v88);
    if ( (_DWORD)v19 || (v63 = (_QWORD *)v88[0], v20 = v88[0] - 8LL, v88[0] == 8) )
    {
      v20 = 0;
    }
    else
    {
      v64 = *(__int64 *)((char *)&off_18 + v88[0]);
      if ( v64 )
      {
        v65 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v65 + 16);
        v66 = *(_QWORD *)(v64 + 1320);
        v67 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v66);
        do
          v68 = __ldxr(v67);
        while ( __stxr(v68 + 1, v67) );
        v69 = *(_QWORD *)(v65 + 16) - 1LL;
        *(_DWORD *)(v65 + 16) = v69;
        if ( !v69 || !*(_QWORD *)(v65 + 16) )
        {
          v81 = v63;
          preempt_schedule_notrace(v19);
          v63 = v81;
        }
      }
      _X8 = (unsigned int *)v63 + 13139;
      __asm { PRFM            #0x11, [X8] }
      do
        v83 = __ldxr(_X8);
      while ( __stxr(v83 + 1, _X8) );
      v88[0] = 0;
      v71 = qdf_list_peek_next(a1 + 6, v63, v88);
      if ( !(_DWORD)v71 )
      {
        v72 = v88[0];
        v21 = v88[0] - 8LL;
        if ( v88[0] != 8 )
        {
          v73 = *(__int64 *)((char *)&off_18 + v88[0]);
          if ( v73 )
          {
            v74 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v74 + 16);
            v75 = *(_QWORD *)(v73 + 1320);
            v76 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v75);
            do
              v77 = __ldxr(v76);
            while ( __stxr(v77 + 1, v76) );
            v78 = *(_QWORD *)(v74 + 16) - 1LL;
            *(_DWORD *)(v74 + 16) = v78;
            if ( !v78 || !*(_QWORD *)(v74 + 16) )
              preempt_schedule_notrace(v71);
          }
          _X8 = (unsigned int *)(v72 + 52556);
          __asm { PRFM            #0x11, [X8] }
          do
            v85 = __ldxr(_X8);
          while ( __stxr(v85 + 1, _X8) );
        }
        goto LABEL_12;
      }
    }
    v21 = 0;
LABEL_12:
    v22 = a1[5];
    if ( (v22 & 1) != 0 )
    {
      a1[5] = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      if ( !v20 )
        goto LABEL_82;
    }
    else
    {
      raw_spin_unlock(a1 + 4);
      if ( !v20 )
        goto LABEL_82;
    }
    v86 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_DWORD *)(v20 + 40) | 2) == 3 )
      {
        if ( (*(_QWORD *)(v20 + 1640) & 1) != 0 && (v33 = v20 + 52840, v20 != -52840)
          || (*(_QWORD *)(v20 + 1640) & 2) != 0 && (v33 = v20 + 58928, v20 != -58928)
          || (*(_QWORD *)(v20 + 1640) & 4) != 0 && (v33 = v20 + 65016, v20 != -65016) )
        {
          do
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   a1[1],
                   *(_DWORD *)(v33 + 2424),
                   0,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30) )
            {
              v34 = *(unsigned __int8 *)(v33 + 8);
              *(_BYTE *)(v33 + 256) = 1;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: tx blocked for vdev: %d",
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                "hdd_dfs_indicate_radar",
                v34);
              if ( *(unsigned __int8 *)(v33 + 8) != 255 )
              {
                context = _cds_get_context(
                            71,
                            (__int64)"hdd_dfs_indicate_radar",
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29,
                            v30);
                if ( context && *context )
                {
                  v36 = *(_QWORD *)(*context + 120LL);
                  if ( v36 )
                  {
                    v37 = *(void (**)(void))(v36 + 40);
                    if ( v37 )
                    {
                      if ( *((_DWORD *)v37 - 1) != -251540498 )
                        __break(0x8228u);
                      v37();
                    }
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x89u,
                    8u,
                    "%s: invalid instance",
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    v30,
                    "cdp_fc_vdev_flush",
                    v86);
                }
              }
            }
            if ( (unsigned __int8)(73 * ((unsigned int)(v33 - *(_DWORD *)v33 - 52840) >> 3) + 1) > 2u )
              break;
            v38 = (unsigned __int8)(73 * ((unsigned int)(v33 - *(_DWORD *)v33 - 52840) >> 3) + 1);
            v33 = 0;
            v39 = v20 + 52840 + 6088LL * (unsigned int)v38;
            do
            {
              if ( v33 )
                break;
              v40 = *(_QWORD *)(v20 + 1640) >> v38++;
              v33 = (v40 << 63 >> 63) & v39;
              v39 += 6088;
            }
            while ( v38 != 3 );
          }
          while ( v33 );
        }
      }
      hdd_adapter_dev_put_debug(v20, 10);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v86 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v86 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 4);
        if ( v21 )
          goto LABEL_46;
LABEL_16:
        v31 = 0;
        v20 = 0;
        v32 = a1[5];
        if ( (v32 & 1) == 0 )
          goto LABEL_17;
LABEL_59:
        a1[5] = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 4);
        v21 = v31;
        if ( !v20 )
          goto LABEL_82;
      }
      else
      {
        raw_spin_lock_bh(a1 + 4);
        a1[5] |= 1uLL;
        if ( !v21 )
          goto LABEL_16;
LABEL_46:
        v88[0] = 0;
        v41 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v21 + 8), v88);
        v31 = v88[0] - 8LL;
        if ( (_DWORD)v41 )
          v50 = 0;
        else
          v50 = v88[0] - 8LL;
        if ( v21 == v50 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v21, 10);
          goto LABEL_16;
        }
        if ( v50 )
        {
          v51 = *(_QWORD *)(v50 + 32);
          if ( v51 )
          {
            ++*(_DWORD *)(v86 + 16);
            v52 = *(_QWORD *)(v51 + 1320);
            v53 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v52);
            do
              v54 = __ldxr(v53);
            while ( __stxr(v54 + 1, v53) );
            v55 = *(_QWORD *)(v86 + 16) - 1LL;
            *(_DWORD *)(v86 + 16) = v55;
            if ( !v55 || !*(_QWORD *)(v86 + 16) )
              preempt_schedule_notrace(v41);
          }
          _X8 = (unsigned int *)(v50 + 52564);
          __asm { PRFM            #0x11, [X8] }
          do
            v62 = __ldxr(_X8);
          while ( __stxr(v62 + 1, _X8) );
        }
        else
        {
          v31 = 0;
        }
        v20 = v21;
        v32 = a1[5];
        if ( (v32 & 1) != 0 )
          goto LABEL_59;
LABEL_17:
        raw_spin_unlock(a1 + 4);
        v21 = v31;
        if ( !v20 )
          goto LABEL_82;
      }
    }
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: skip tx block hdd_ctx=%pK, disableDFSChSwitch=%d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "hdd_dfs_indicate_radar",
    a1,
    1);
LABEL_82:
  _ReadStatusReg(SP_EL0);
  return 1;
}
