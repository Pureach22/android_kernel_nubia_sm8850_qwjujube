__int64 __fastcall ieee80211_reconfig(__int64 a1)
{
  int v2; // w27
  int v3; // w26
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  int v6; // w25
  int v7; // w8
  _QWORD *i; // x20
  unsigned __int64 v15; // x9
  __int64 *v16; // x20
  __int64 *j; // x21
  __int64 v18; // x0
  int v19; // w8
  signed int next_bit; // w20
  __int64 v21; // x0
  int v22; // w8
  signed int v23; // w20
  __int64 k; // x20
  char v25; // w8
  __int64 m; // x20
  unsigned int v27; // w0
  unsigned int v28; // w20
  unsigned int v29; // w0
  __int64 v30; // x1
  unsigned int (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x2
  __int64 v33; // x1
  unsigned int (__fastcall *v34)(__int64, __int64, __int64); // x8
  __int64 v35; // x2
  __int64 v36; // x1
  void (__fastcall *v37)(__int64, __int64, __int64); // x8
  __int64 v38; // x2
  __int64 v39; // x20
  __int64 v40; // x0
  __int64 v41; // x20
  __int64 *v42; // x28
  unsigned int v43; // w21
  __int64 *v44; // x20
  __int64 (__fastcall *v45)(__int64, __int64, __int64); // x8
  int v46; // w0
  __int64 v47; // x1
  __int64 v48; // x2
  __int64 v49; // x8
  __int64 v50; // x1
  __int64 v51; // x20
  int v52; // w8
  int v53; // w21
  int v54; // w3
  _WORD *v55; // x26
  __int64 *v56; // x27
  int v57; // w8
  __int64 v58; // x22
  __int64 v59; // x2
  __int64 v60; // x8
  __int64 ii; // x21
  __int64 v62; // x2
  __int64 v63; // x8
  int v64; // w8
  __int64 v65; // x2
  __int64 v66; // x23
  __int64 v67; // x1
  __int64 v68; // x22
  __int64 (__fastcall *v69)(__int64, __int64, __int64); // x8
  unsigned int v70; // w0
  unsigned __int64 v71; // x22
  _QWORD *v72; // x25
  __int64 next; // x0
  int v74; // w21
  int v75; // w9
  unsigned __int64 v76; // x27
  int v77; // w26
  _QWORD *v78; // x23
  __int64 v79; // x24
  unsigned int v80; // w8
  unsigned int (__fastcall *v81)(__int64, __int64); // x8
  __int64 v82; // x9
  __int64 v83; // x1
  __int64 kk; // x21
  __int64 v85; // x22
  __int64 v86; // x9
  __int64 v87; // x8
  __int64 v88; // x1
  __int64 (__fastcall *v89)(__int64, __int64); // x8
  int v90; // w0
  __int64 v91; // x23
  __int64 jj; // x24
  int v93; // w3
  unsigned int v94; // w25
  __int64 v95; // x8
  __int64 v96; // x1
  __int64 v97; // x1
  __int64 v98; // x20
  __int64 v99; // x21
  __int64 n; // x22
  int v101; // w3
  unsigned int v102; // w23
  unsigned __int64 v103; // x0
  unsigned __int64 v104; // x1
  int v105; // w21
  int v106; // [xsp+8h] [xbp-98h]
  int v107; // [xsp+Ch] [xbp-94h]
  __int64 v108; // [xsp+18h] [xbp-88h] BYREF
  _QWORD v109[16]; // [xsp+20h] [xbp-80h] BYREF

  v109[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 1465);
  if ( !*(_DWORD *)(a1 + 1316) )
  {
LABEL_9:
    v6 = 0;
LABEL_10:
    v7 = *(_DWORD *)(a1 + 1320);
    if ( v7 >= 1 && v7 == *(_DWORD *)(a1 + 1316) )
      ieee80211_add_virtual_monitor(a1);
    if ( (*(_QWORD *)(a1 + 96) & 0x80) != 0 )
    {
      for ( i = *(_QWORD **)(a1 + 1616); i != (_QWORD *)(a1 + 1616); i = (_QWORD *)*i )
      {
        if ( (*(_BYTE *)(a1 + 1467) & 1) == 0 )
          ieee80211_sta_tear_down_BA_sessions(i, 1u);
        _X8 = i + 27;
        __asm { PRFM            #0x11, [X8] }
        do
          v15 = __ldxr(_X8);
        while ( __stxr(v15 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
      }
    }
    if ( *(_DWORD *)(a1 + 1316) && v6 | v2 ^ 1 )
      drv_reconfig_complete(a1, 0);
    if ( *(_BYTE *)(a1 + 1470) == 1 )
    {
      *(_BYTE *)(a1 + 1470) = 0;
      ieee80211_reconfig_roc(a1);
      v16 = *(__int64 **)(a1 + 4616);
      for ( j = (__int64 *)(a1 + 4616); v16 != j; v16 = (__int64 *)*v16 )
        wiphy_work_queue(*(_QWORD *)(a1 + 72), v16 + 245);
      v109[0] = 0xFFFF;
      v18 = raw_spin_lock_irqsave(a1 + 1312);
      v19 = 0;
      v108 = v18;
      while ( 1 )
      {
        next_bit = find_next_bit(v109, *(unsigned __int16 *)(a1 + 128), v19);
        if ( next_bit >= *(unsigned __int16 *)(a1 + 128) )
          break;
        _ieee80211_wake_queue(a1, next_bit, 4u, 0, (__int64)&v108);
        v19 = next_bit + 1;
      }
      raw_spin_unlock_irqrestore(a1 + 1312, v108);
      for ( k = *j; (__int64 *)k != j; k = *(_QWORD *)k )
      {
        if ( (*(_QWORD *)(k + 1632) & 1) != 0 && *(_DWORD *)(k + 4720) == 2 )
          ieee80211_sta_restart(k);
      }
    }
    else
    {
      v109[0] = 0xFFFF;
      v21 = raw_spin_lock_irqsave(a1 + 1312);
      v22 = 0;
      v108 = v21;
      while ( 1 )
      {
        v23 = find_next_bit(v109, *(unsigned __int16 *)(a1 + 128), v22);
        if ( v23 >= *(unsigned __int16 *)(a1 + 128) )
          break;
        _ieee80211_wake_queue(a1, v23, 4u, 0, (__int64)&v108);
        v22 = v23 + 1;
      }
      raw_spin_unlock_irqrestore(a1 + 1312, v108);
    }
    if ( v2 )
    {
      *(_BYTE *)(a1 + 1465) = 0;
      __dsb(0xFu);
      *(_BYTE *)(a1 + 1467) = 0;
      if ( (*(_QWORD *)(a1 + 4696) & 8) != 0 )
      {
        wiphy_delayed_work_queue(*(_QWORD *)(a1 + 72), a1 + 4896, 0);
        wiphy_delayed_work_flush(*(_QWORD *)(a1 + 72), a1 + 4896);
      }
      if ( *(_DWORD *)(a1 + 1316) )
        v25 = v6;
      else
        v25 = 1;
      if ( (v25 & 1) == 0 )
        drv_reconfig_complete(a1, 1);
      for ( m = *(_QWORD *)(a1 + 4616); m != a1 + 4616; m = *(_QWORD *)m )
      {
        if ( (*(_QWORD *)(m + 1632) & 1) != 0 && *(_DWORD *)(m + 4720) == 2 )
          ieee80211_sta_restart(m);
      }
      mod_timer(a1 + 1952, jiffies + 1LL);
    }
    result = 0;
    goto LABEL_310;
  }
  if ( *(_BYTE *)(a1 + 1465) )
    *(_BYTE *)(a1 + 1467) = 1;
  v3 = *(unsigned __int8 *)(a1 + 1472);
  if ( v3 == 1 )
  {
    *(_BYTE *)(a1 + 1465) = 0;
    v4 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 32LL);
    if ( *((_DWORD *)v4 - 1) != -1244592371 )
      __break(0x8228u);
    result = v4();
    *(_BYTE *)(a1 + 1472) = 0;
    if ( (result & 0x80000000) != 0 )
    {
      *(_BYTE *)(a1 + 1467) = 0;
      goto LABEL_310;
    }
    if ( !(_DWORD)result )
      goto LABEL_9;
    if ( (_DWORD)result != 1 )
      __break(0x800u);
    *(_BYTE *)(a1 + 1465) = 1;
  }
  if ( v2 )
  {
    if ( (v3 & 1) == 0 && (*(_BYTE *)(a1 + 1470) & 1) != 0 )
      cancel_work_sync(a1 + 5160);
    *(_BYTE *)(a1 + 1469) = 0;
    v27 = drv_start(a1);
    if ( v27 )
    {
      v28 = v27;
      _warn_printk(
        "Hardware became unavailable upon resume. This could be a software issue prior to suspend or a hardware issue.\n");
      __break(0x800u);
LABEL_69:
      ieee80211_handle_reconfig_failure(a1);
      result = v28;
      goto LABEL_310;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 1469) = 0;
    v29 = drv_start(a1);
    if ( v29 )
    {
      v28 = v29;
      _warn_printk("Hardware became unavailable during restart.\n");
      __break(0x800u);
      goto LABEL_69;
    }
  }
  v30 = *(unsigned int *)(*(_QWORD *)(a1 + 72) + 200LL);
  v31 = *(unsigned int (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 464) + 248LL);
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != -1360243996 )
      __break(0x8228u);
    v32 = v31(a1, v30);
  }
  else
  {
    v32 = 0;
  }
  v33 = *(unsigned int *)(*(_QWORD *)(a1 + 72) + 204LL);
  v34 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 464) + 256LL);
  if ( v34 )
  {
    if ( *((_DWORD *)v34 - 1) != -1360243996 )
      __break(0x8228u);
    v35 = v34(a1, v33, v32);
  }
  else
  {
    v35 = 0;
  }
  v36 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + 208LL);
  v37 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 464) + 408LL);
  if ( v37 )
  {
    if ( *((_DWORD *)v37 - 1) != -1160620618 )
      __break(0x8228u);
    v37(a1, v36, v35);
    v38 = 0;
  }
  else
  {
    v38 = 4294967201LL;
  }
  v39 = *(_QWORD *)(a1 + 5384);
  if ( v39 && (*(_QWORD *)(a1 + 96) & 0x1000) != 0 )
  {
    if ( *(_BYTE *)(a1 + 1467) == 1 )
      __break(0x800u);
    v40 = drv_add_interface(a1, v39);
    if ( (_DWORD)v40 )
    {
      __break(0x800u);
      *(_QWORD *)(a1 + 5384) = 0;
      v105 = v40;
      synchronize_net(v40);
      kfree(v39);
      LODWORD(v40) = v105;
    }
  }
  else
  {
    LODWORD(v40) = 0;
  }
  v41 = *(_QWORD *)(a1 + 4616);
  v42 = (__int64 *)(a1 + 4616);
  while ( (__int64 *)v41 != v42 )
  {
    if ( (*(_DWORD *)(v41 + 4720) | 2) != 6 && (*(_QWORD *)(v41 + 1632) & 1) != 0 )
    {
      LODWORD(v40) = drv_add_interface(a1, v41);
      if ( (_DWORD)v40 )
      {
        __break(0x800u);
        goto LABEL_100;
      }
    }
    v41 = *(_QWORD *)v41;
  }
  if ( !(_DWORD)v40 )
  {
    v44 = *(__int64 **)(a1 + 4984);
    if ( v44 != (__int64 *)(a1 + 4984) )
    {
      _ReadStatusReg(SP_EL0);
      do
      {
        if ( *((_DWORD *)v44 + 16) != 2 )
        {
          v45 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 464) + 592LL);
          if ( v45 )
          {
            if ( *((_DWORD *)v45 - 1) != -739578247 )
              __break(0x8228u);
            v46 = v45(a1, (__int64)(v44 + 19), v38);
          }
          else
          {
            v46 = -95;
          }
          if ( v46 )
            __break(0x800u);
          else
            *((_BYTE *)v44 + 84) = 1;
        }
        v44 = (__int64 *)*v44;
      }
      while ( v44 != (__int64 *)(a1 + 4984) );
    }
    v47 = *(_QWORD *)(a1 + 5384);
    v106 = v2;
    v107 = v3;
    if ( v47 )
    {
      if ( (*(_QWORD *)(v47 + 1632) & 1) != 0 )
      {
        v48 = *(_QWORD *)(v47 + 4560);
        v49 = *(_QWORD *)(v48 + 832);
        if ( v49 )
          drv_assign_vif_chanctx(a1, v47, v48, v49 - 152);
      }
    }
    ieee80211_hw_config(a1, 412);
    ieee80211_configure_filter(a1);
    v51 = *(_QWORD *)(a1 + 4616);
    if ( (__int64 *)v51 == v42 )
    {
LABEL_267:
      ieee80211_recalc_ps(a1, v50);
      v98 = *(_QWORD *)(a1 + 4616);
      if ( (*(_BYTE *)a1 & 2) != 0 )
      {
        v2 = v106;
        v6 = v107;
      }
      else
      {
        v2 = v106;
        v6 = v107;
        if ( (__int64 *)v98 != v42 )
        {
          do
          {
            if ( *(_DWORD *)(v98 + 4720) == 2 && (*(_BYTE *)(v98 + 2477) & 8) != 0 )
              ieee80211_send_nullfunc(a1, v98, 0);
            v98 = *(_QWORD *)v98;
          }
          while ( (__int64 *)v98 != v42 );
          v98 = *v42;
        }
      }
      if ( (__int64 *)v98 != v42 )
      {
        do
        {
          if ( (*(_QWORD *)(v98 + 1632) & 1) != 0 && (unsigned int)(*(_DWORD *)(v98 + 4720) - 3) <= 1 )
          {
            v99 = *(_QWORD *)(v98 + 1616);
            for ( n = *(_QWORD *)(v99 + 1616); n != v99 + 1616; n = *(_QWORD *)n )
            {
              if ( *(_BYTE *)(n + 204) == 1 && *(_QWORD *)(n + 80) == v98 && *(_DWORD *)(n + 208) )
              {
                v101 = 0;
                do
                {
                  v102 = v101 + 1;
                  if ( (unsigned int)drv_sta_state(v99, *(_QWORD *)(n + 80), n, v101, v101 + 1) )
                    __break(0x800u);
                  v101 = v102;
                }
                while ( v102 < *(_DWORD *)(n + 208) );
              }
            }
          }
          v98 = *(_QWORD *)v98;
        }
        while ( (__int64 *)v98 != v42 );
        v98 = *v42;
      }
      if ( (__int64 *)v98 != v42 )
      {
        do
        {
          ieee80211_reenable_keys(v98, v97);
          v98 = *(_QWORD *)v98;
        }
        while ( (__int64 *)v98 != v42 );
        v98 = *v42;
      }
      for ( ; (__int64 *)v98 != v42; v98 = *(_QWORD *)v98 )
      {
        if ( *(_WORD *)(v98 + 4714) )
          ieee80211_set_active_links(v98 + 4720, *(unsigned __int16 *)(v98 + 4714));
        if ( *(_WORD *)(v98 + 4712) )
          wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v98 + 1616) + 72LL), v98 + 4688);
      }
      v103 = *(_QWORD *)(a1 + 4856);
      if ( v103 )
      {
        v104 = *(_QWORD *)(a1 + 4864);
        if ( v104 )
        {
          if ( *(int *)(v104 + 80) > 1 || (unsigned int)_ieee80211_request_sched_scan_start(v103, v104) )
          {
            *(_QWORD *)(a1 + 4856) = 0;
            *(_QWORD *)(a1 + 4864) = 0;
            cfg80211_sched_scan_stopped_locked(*(_QWORD *)(a1 + 72), 0);
          }
        }
      }
      goto LABEL_10;
    }
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_QWORD *)(v51 + 1632) & 1) == 0 )
        goto LABEL_126;
      if ( *(_WORD *)(v51 + 5800) )
      {
        v52 = *(_DWORD *)(v51 + 4720);
        v53 = *(unsigned __int16 *)(v51 + 5802);
        memset(&v109[1], 0, 112);
        v109[0] = v51 + 4808;
        if ( v52 == 2 )
        {
          v54 = v53 & -v53;
          *(_WORD *)(v51 + 5802) = v53 & -(__int16)v53;
        }
        else
        {
          LOWORD(v54) = v53;
          LOWORD(v53) = 0;
        }
        drv_change_vif_links(a1, v51, 0, v54);
        v57 = *(unsigned __int16 *)(v51 + 5800);
        *(_WORD *)(v51 + 4714) = v53;
        v55 = (_WORD *)(v51 + 5802);
        v56 = (__int64 *)(v51 + 4568);
        if ( v57 && (*v55 & 1) == 0 )
        {
          v58 = 0;
          goto LABEL_139;
        }
      }
      else
      {
        *(_WORD *)(v51 + 4714) = 0;
        v55 = (_WORD *)(v51 + 5802);
        v56 = (__int64 *)(v51 + 4568);
      }
      v58 = *v56;
      if ( *v56 )
      {
        v59 = *(_QWORD *)(v58 + 944);
        v60 = *(_QWORD *)(v59 + 832);
        if ( v60 )
          drv_assign_vif_chanctx(a1, v51, v59, v60 - 152);
      }
LABEL_139:
      for ( ii = 1; ii != 15; ++ii )
      {
        if ( *(_WORD *)(v51 + 5800) )
        {
          if ( (((unsigned __int64)(unsigned __int16)*v55 >> ii) & 1) != 0 )
          {
            v58 = v56[ii];
            if ( v58 )
            {
              v62 = *(_QWORD *)(v58 + 944);
              v63 = *(_QWORD *)(v62 + 832);
              if ( v63 )
                drv_assign_vif_chanctx(a1, v51, v62, v63 - 152);
            }
          }
        }
      }
      v64 = *(_DWORD *)(v51 + 4720);
      if ( v64 > 3 )
      {
        if ( v64 == 4 || v64 == 6 )
          goto LABEL_152;
        goto LABEL_249;
      }
      if ( v64 == 1 )
      {
        if ( *(_BYTE *)(v51 + 4729) != 1 )
          goto LABEL_249;
        if ( (*(_BYTE *)(*(_QWORD *)(v51 + 1616) + 1471LL) & 1) != 0
          || (*(_DWORD *)(v51 + 1624) & 0x20) != 0
          || (drv_join_ibss___already_done_0 & 1) != 0 )
        {
          if ( (*(_BYTE *)(v51 + 1624) & 0x20) == 0 )
            goto LABEL_179;
LABEL_243:
          v89 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 464) + 696LL);
          if ( v89 )
          {
            if ( *((_DWORD *)v89 - 1) != 844051912 )
              __break(0x8228u);
            v90 = v89(a1, v51 + 4720);
          }
          else
          {
            v90 = 0;
          }
          if ( !v90 )
          {
LABEL_249:
            v91 = *(_QWORD *)(v51 + 1616);
            for ( jj = *(_QWORD *)(v91 + 1616); jj != v91 + 1616; jj = *(_QWORD *)jj )
            {
              if ( *(_BYTE *)(jj + 204) == 1 && *(_QWORD *)(jj + 80) == v51 && *(_DWORD *)(jj + 208) )
              {
                v93 = 0;
                do
                {
                  v94 = v93 + 1;
                  if ( (unsigned int)drv_sta_state(v91, *(_QWORD *)(jj + 80), jj, v93, v93 + 1) )
                    __break(0x800u);
                  v93 = v94;
                }
                while ( v94 < *(_DWORD *)(jj + 208) );
              }
            }
            goto LABEL_149;
          }
        }
        else
        {
          v87 = *(_QWORD *)(v51 + 1608);
          if ( v87 )
            v88 = v87 + 296;
          else
            v88 = v51 + 1640;
          drv_join_ibss___already_done_0 = 1;
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v88);
          __break(0x800u);
          if ( (*(_BYTE *)(v51 + 1624) & 0x20) != 0 )
            goto LABEL_243;
        }
LABEL_179:
        __break(0x800u);
        goto LABEL_249;
      }
      if ( v64 != 3 )
        goto LABEL_249;
LABEL_149:
      drv_conf_tx(a1, (_DWORD *)(v51 + 3616), 0, v51 + 4504);
      drv_conf_tx(a1, (_DWORD *)(v51 + 3616), 1, v51 + 4518);
      drv_conf_tx(a1, (_DWORD *)(v51 + 3616), 2, v51 + 4532);
      drv_conf_tx(a1, (_DWORD *)(v51 + 3616), 3, v51 + 4546);
      v64 = *(_DWORD *)(v51 + 4720);
LABEL_152:
      if ( *(_BYTE *)(v51 + 5639) )
        v65 = 42214654;
      else
        v65 = 33826046;
      if ( *(_WORD *)(v51 + 5800) )
        v66 = v65;
      else
        v66 = v65 | 0x4000;
      if ( v64 <= 7 )
      {
        if ( v64 > 2 )
        {
          if ( v64 == 3 )
            goto LABEL_213;
          if ( v64 == 5 )
            goto LABEL_125;
          if ( v64 != 7 )
            goto LABEL_126;
        }
        else
        {
          if ( !v64 )
            goto LABEL_125;
          if ( v64 != 1 )
          {
            if ( v64 != 2 )
              goto LABEL_126;
            if ( !*(_WORD *)(v51 + 5800) )
            {
              v86 = 151553;
              if ( *(_BYTE *)(v51 + 4179) )
                v86 = 1200129;
              v67 = v86 | v65;
              if ( *(_WORD *)(v51 + 5100) || *(_BYTE *)(v51 + 5102) == 1 )
                v67 |= 0x1000000uLL;
              goto LABEL_238;
            }
            if ( v58 )
            {
              ieee80211_link_info_change_notify(v51, v58, v65);
              ieee80211_vif_cfg_change_notify(v51, 151553);
              goto LABEL_126;
            }
LABEL_125:
            __break(0x800u);
            goto LABEL_126;
          }
          v66 |= 0x800uLL;
LABEL_213:
          if ( *(_WORD *)(v51 + 5800) )
          {
            v66 |= 0x80000uLL;
            ieee80211_vif_cfg_change_notify(v51, 0x8000);
          }
          else
          {
            v66 |= 0x88000uLL;
          }
          if ( *(_BYTE *)(v51 + 5103) == 1 )
            v66 |= (unsigned __int64)(*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v51 + 1616) + 72LL) + 116LL) & 1) << 26;
          if ( *(_DWORD *)(v51 + 4720) == 3 )
          {
            v66 |= 0x10000uLL;
            if ( *(_WORD *)(v51 + 5800) )
            {
              for ( kk = 0; kk != 15; ++kk )
              {
                if ( (((unsigned __int64)(unsigned __int16)*v55 >> kk) & 1) != 0 )
                {
                  v85 = v56[kk];
                  if ( v85 )
                  {
                    if ( *(_QWORD *)(v85 + 536) )
                      drv_start_ap_0(a1, v51, *(_QWORD *)(v85 + 944));
                    if ( *(_BYTE *)(*(_QWORD *)(v85 + 944) + 48LL) == 1 )
                    {
                      v66 |= 0x300uLL;
                      ieee80211_link_info_change_notify(v51, v85, v66);
                    }
                  }
                }
              }
              goto LABEL_126;
            }
            if ( *(_QWORD *)(v51 + 4152) )
              drv_start_ap_0(a1, v51, *(_QWORD *)(v51 + 4560));
          }
        }
        if ( *(_BYTE *)(v51 + 4856) == 1 )
        {
          v67 = v66 | 0x300;
          goto LABEL_238;
        }
        goto LABEL_126;
      }
      if ( v64 > 11 )
      {
        if ( v64 == 12 )
        {
          v68 = *(_QWORD *)(v51 + 1616);
          LODWORD(v109[0]) = 0;
          if ( (*(_BYTE *)(v68 + 1471) & 1) == 0
            && (*(_DWORD *)(v51 + 1624) & 0x20) == 0
            && (drv_start_nan___already_done_0 & 1) == 0 )
          {
            v95 = *(_QWORD *)(v51 + 1608);
            if ( v95 )
              v96 = v95 + 296;
            else
              v96 = v51 + 1640;
            drv_start_nan___already_done_0 = 1;
            _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v96);
            __break(0x800u);
          }
          v69 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v68 + 464) + 768LL);
          if ( *((_DWORD *)v69 - 1) != -798033652 )
            __break(0x8228u);
          v70 = v69(v68, v51 + 4720, v51 + 2264);
          if ( v70 )
          {
            v43 = v70;
            __break(0x800u);
            if ( (v70 & 0x80000000) != 0 )
              goto LABEL_309;
          }
          else
          {
            v71 = 8LL * *(unsigned __int8 *)(*(_QWORD *)(v51 + 1616) + 170LL) + 8;
            v72 = (_QWORD *)_kmalloc_noprof(v71, 3520);
            if ( !v72 )
            {
              v43 = -12;
              goto LABEL_309;
            }
            raw_spin_lock_bh(v51 + 2268);
            LODWORD(v109[0]) = 0;
            next = idr_get_next(v51 + 2272, v109);
            if ( next )
            {
              v74 = 0;
              do
              {
                if ( v71 <= 8LL * v74 )
LABEL_311:
                  __break(1u);
                v75 = v109[0];
                v72[v74++] = next;
                LODWORD(v109[0]) = v75 + 1;
                next = idr_get_next(v51 + 2272, v109);
              }
              while ( next );
            }
            raw_spin_unlock_bh(v51 + 2268);
            if ( *v72 )
            {
              v76 = 0;
              v77 = 1;
              v78 = v72;
              do
              {
                v79 = *(_QWORD *)(v51 + 1616);
                if ( (*(_BYTE *)(v79 + 1471) & 1) == 0 )
                {
                  v80 = *(_DWORD *)(v51 + 1624);
                  if ( (v80 & 0x20) == 0 && (drv_add_nan_func___already_done_0 & 1) == 0 )
                  {
                    v82 = *(_QWORD *)(v51 + 1608);
                    if ( v82 )
                      v83 = v82 + 296;
                    else
                      v83 = v51 + 1640;
                    drv_add_nan_func___already_done_0 = 1;
                    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v83, v80);
                    __break(0x800u);
                  }
                }
                if ( !*(_QWORD *)(*(_QWORD *)(v79 + 464) + 792LL) )
                  goto LABEL_202;
                v81 = *(unsigned int (__fastcall **)(__int64, __int64))(*(_QWORD *)(v79 + 464) + 792LL);
                if ( *((_DWORD *)v81 - 1) != -1628156260 )
                  __break(0x8228u);
                if ( v81(v79, v51 + 4720) )
                {
LABEL_202:
                  __break(0x800u);
                  if ( v71 < v76 )
                    goto LABEL_311;
                  if ( v71 - v76 < 8 )
                    goto LABEL_311;
                  ieee80211_nan_func_terminated((_DWORD *)(v51 + 4720), *(unsigned __int8 *)(*v78 + 98LL), 2u, 0xCC0u);
                  if ( v71 <= 8LL * v77 )
                    goto LABEL_311;
                }
                else if ( v71 <= 8LL * v77 )
                {
                  goto LABEL_311;
                }
                v76 = 8LL * v77;
                if ( v71 <= v76 )
                  goto LABEL_311;
                v78 = &v72[v77++];
              }
              while ( *v78 );
            }
            kfree(v72);
          }
        }
        else if ( v64 == 13 )
        {
          goto LABEL_125;
        }
      }
      else
      {
        if ( (unsigned int)(v64 - 8) < 2 )
          goto LABEL_125;
        if ( v64 == 11 )
        {
          v67 = v66 | 0x400000;
LABEL_238:
          ieee80211_bss_info_change_notify(v51, v67);
        }
      }
LABEL_126:
      v51 = *(_QWORD *)v51;
      if ( (__int64 *)v51 == v42 )
        goto LABEL_267;
    }
  }
LABEL_100:
  v43 = v40;
  while ( 1 )
  {
    v41 = *(_QWORD *)(v41 + 8);
    if ( (__int64 *)v41 == v42 )
      break;
    if ( (*(_DWORD *)(v41 + 4720) | 2) != 6 && (*(_QWORD *)(v41 + 1632) & 1) != 0 )
      drv_remove_interface(a1, v41);
  }
LABEL_309:
  ieee80211_handle_reconfig_failure(a1);
  result = v43;
LABEL_310:
  _ReadStatusReg(SP_EL0);
  return result;
}
