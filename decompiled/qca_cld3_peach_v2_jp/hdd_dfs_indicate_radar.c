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
  unsigned __int64 v31; // x24
  __int64 v32; // x25
  __int64 v33; // x8
  __int64 v34; // x4
  _QWORD *context; // x0
  __int64 v36; // x8
  void (*v37)(void); // x8
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x21
  __int64 v48; // x8
  __int64 v49; // x8
  unsigned int *v50; // x8
  unsigned int v51; // w10
  __int64 v52; // x8
  unsigned int v59; // w9
  _QWORD *v60; // x1
  __int64 v61; // x9
  unsigned __int64 v62; // x8
  __int64 v63; // x9
  unsigned int *v64; // x9
  unsigned int v65; // w12
  __int64 v66; // x9
  __int64 v68; // x0
  __int64 v69; // x22
  __int64 v70; // x9
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  unsigned int *v73; // x9
  unsigned int v74; // w12
  __int64 v75; // x9
  _QWORD *v78; // x20
  unsigned int v80; // w9
  unsigned int v82; // w9
  _BYTE v83[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v84[2]; // [xsp+10h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83[0] = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 4u, "%s: Couldn't get hdd_ctx", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_dfs_indicate_radar");
    goto LABEL_73;
  }
  ucfg_mlme_get_dfs_disable_channel_switch(*a1, v83);
  if ( v83[0] != 1 )
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
    v84[0] = 0;
    v19 = qdf_list_peek_front(a1 + 6, v84);
    if ( (_DWORD)v19 || (v60 = (_QWORD *)v84[0], v20 = v84[0] - 8LL, v84[0] == 8) )
    {
      v20 = 0;
    }
    else
    {
      v61 = *(__int64 *)((char *)&off_18 + v84[0]);
      if ( v61 )
      {
        v62 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v62 + 16);
        v63 = *(_QWORD *)(v61 + 1320);
        v64 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v63);
        do
          v65 = __ldxr(v64);
        while ( __stxr(v65 + 1, v64) );
        v66 = *(_QWORD *)(v62 + 16) - 1LL;
        *(_DWORD *)(v62 + 16) = v66;
        if ( !v66 || !*(_QWORD *)(v62 + 16) )
        {
          v78 = v60;
          preempt_schedule_notrace(v19);
          v60 = v78;
        }
      }
      _X8 = (unsigned int *)v60 + 13139;
      __asm { PRFM            #0x11, [X8] }
      do
        v80 = __ldxr(_X8);
      while ( __stxr(v80 + 1, _X8) );
      v84[0] = 0;
      v68 = qdf_list_peek_next(a1 + 6, v60, v84);
      if ( !(_DWORD)v68 )
      {
        v69 = v84[0];
        v21 = v84[0] - 8LL;
        if ( v84[0] != 8 )
        {
          v70 = *(__int64 *)((char *)&off_18 + v84[0]);
          if ( v70 )
          {
            v71 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v71 + 16);
            v72 = *(_QWORD *)(v70 + 1320);
            v73 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v72);
            do
              v74 = __ldxr(v73);
            while ( __stxr(v74 + 1, v73) );
            v75 = *(_QWORD *)(v71 + 16) - 1LL;
            *(_DWORD *)(v71 + 16) = v75;
            if ( !v75 || !*(_QWORD *)(v71 + 16) )
              preempt_schedule_notrace(v68);
          }
          _X8 = (unsigned int *)(v69 + 52556);
          __asm { PRFM            #0x11, [X8] }
          do
            v82 = __ldxr(_X8);
          while ( __stxr(v82 + 1, _X8) );
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
        goto LABEL_73;
    }
    else
    {
      raw_spin_unlock(a1 + 4);
      if ( !v20 )
        goto LABEL_73;
    }
    v31 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_DWORD *)(v20 + 40) | 2) == 3 && (*(_QWORD *)(v20 + 1640) & 1) != 0 && v20 != -52832 )
      {
        do
        {
          if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                 a1[1],
                 *(_DWORD *)(v20 + 54984),
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
            v34 = *(unsigned __int8 *)(v20 + 52840);
            *(_BYTE *)(v20 + 53088) = 1;
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
            if ( *(unsigned __int8 *)(v20 + 52840) != 255 )
            {
              context = _cds_get_context(71, (__int64)"hdd_dfs_indicate_radar", v23, v24, v25, v26, v27, v28, v29, v30);
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
                  "cdp_fc_vdev_flush");
              }
            }
          }
        }
        while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v20 - *(_DWORD *)(v20 + 52832)) >> 4))
             && (*(_QWORD *)(v20 + 1640) & 1) != 0 );
      }
      hdd_adapter_dev_put_debug(v20, 10);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v31 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 4);
        if ( v21 )
          goto LABEL_37;
LABEL_16:
        v32 = 0;
        v20 = 0;
        v33 = a1[5];
        if ( (v33 & 1) == 0 )
          goto LABEL_17;
LABEL_50:
        a1[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 4);
        v21 = v32;
        if ( !v20 )
          goto LABEL_73;
      }
      else
      {
        raw_spin_lock_bh(a1 + 4);
        a1[5] |= 1uLL;
        if ( !v21 )
          goto LABEL_16;
LABEL_37:
        v84[0] = 0;
        v38 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v21 + 8), v84);
        v32 = v84[0] - 8LL;
        if ( (_DWORD)v38 )
          v47 = 0;
        else
          v47 = v84[0] - 8LL;
        if ( v21 == v47 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v21, 10);
          goto LABEL_16;
        }
        if ( v47 )
        {
          v48 = *(_QWORD *)(v47 + 32);
          if ( v48 )
          {
            ++*(_DWORD *)(v31 + 16);
            v49 = *(_QWORD *)(v48 + 1320);
            v50 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v49);
            do
              v51 = __ldxr(v50);
            while ( __stxr(v51 + 1, v50) );
            v52 = *(_QWORD *)(v31 + 16) - 1LL;
            *(_DWORD *)(v31 + 16) = v52;
            if ( !v52 || !*(_QWORD *)(v31 + 16) )
              preempt_schedule_notrace(v38);
          }
          _X8 = (unsigned int *)(v47 + 52564);
          __asm { PRFM            #0x11, [X8] }
          do
            v59 = __ldxr(_X8);
          while ( __stxr(v59 + 1, _X8) );
        }
        else
        {
          v32 = 0;
        }
        v20 = v21;
        v33 = a1[5];
        if ( (v33 & 1) != 0 )
          goto LABEL_50;
LABEL_17:
        raw_spin_unlock(a1 + 4);
        v21 = v32;
        if ( !v20 )
          goto LABEL_73;
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
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return 1;
}
