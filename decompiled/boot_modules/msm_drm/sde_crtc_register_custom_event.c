__int64 __fastcall sde_crtc_register_custom_event(_QWORD *a1, __int64 a2, int a3, char a4)
{
  __int64 v7; // x9
  _QWORD *v8; // x20
  _QWORD *v9; // x8
  const void *v10; // x3
  _QWORD *v12; // x22
  _QWORD *v13; // x8
  _QWORD *v14; // x10
  __int64 v15; // x23
  unsigned int v16; // w0
  _DWORD *v17; // x8
  unsigned int v18; // w23
  __int64 v19; // x0
  _QWORD *v20; // x1
  __int64 v21; // x9
  __int64 (__fastcall *v22)(); // x25
  __int64 v23; // x0
  _QWORD *v24; // x22
  _QWORD *v25; // x23
  int v26; // w8
  __int64 v27; // x21
  unsigned int v28; // w0
  _DWORD *v29; // x8
  unsigned int v30; // w0
  unsigned int v31; // w20
  _QWORD *v32; // x0
  __int64 v33; // x0
  _QWORD *v34; // x1
  __int64 v35; // x0
  _QWORD *v36; // x1
  __int64 v37; // x9
  unsigned int v38; // w8
  unsigned int v45; // w10
  int v46; // w7
  unsigned int v47; // w8
  unsigned int v50; // w10
  int v51; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
  {
    if ( a1 )
    {
      v10 = (const void *)a1[17];
LABEL_12:
      _drm_err("invalid sde_crtc %pK kms %pK dev %pK\n", (const void *)a2, a1, v10);
      return 4294967274LL;
    }
LABEL_11:
    v10 = nullptr;
    goto LABEL_12;
  }
  if ( !a1[17] )
    goto LABEL_11;
  v7 = raw_spin_lock_irqsave(a2 + 6032);
  v8 = (_QWORD *)(a2 + 4600);
  if ( (a4 & 1) != 0 )
  {
    v9 = (_QWORD *)(a2 + 4600);
    while ( 1 )
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == v8 )
        break;
      if ( *((_DWORD *)v9 - 4) == a3 )
        goto LABEL_61;
    }
    raw_spin_unlock_irqrestore(a2 + 6032, v7);
    v22 = sde_cp_ad_interrupt;
    switch ( a3 )
    {
      case -2147483648:
        v22 = (__int64 (__fastcall *)())&sde_cp_hist_interrupt;
        goto LABEL_48;
      case -2147483647:
        goto LABEL_48;
      case -2147483646:
        v22 = sde_crtc_power_interrupt_handler;
        goto LABEL_48;
      case -2147483645:
      case -2147483642:
      case -2147483641:
      case -2147483635:
      case -2147483632:
      case -2147483631:
        goto LABEL_90;
      case -2147483644:
        v22 = sde_crtc_pm_event_handler;
        goto LABEL_48;
      case -2147483643:
        v22 = sde_crtc_idle_interrupt_handler;
        goto LABEL_48;
      case -2147483640:
        v22 = sde_cp_ltm_hist_interrupt;
        goto LABEL_48;
      case -2147483639:
        v22 = sde_cp_ltm_wb_pb_interrupt;
        goto LABEL_48;
      case -2147483638:
        v22 = sde_cp_ltm_off_event_handler;
        goto LABEL_48;
      case -2147483637:
        v22 = sde_crtc_mmrm_interrupt_handler;
        goto LABEL_48;
      case -2147483636:
        v22 = sde_crtc_frame_data_interrupt_handler;
        goto LABEL_48;
      case -2147483634:
        v22 = sde_crtc_vm_release_handler;
        goto LABEL_48;
      case -2147483633:
        v22 = sde_crtc_opr_event_handler;
        goto LABEL_48;
      case -2147483630:
        v22 = sde_crtc_mdnie_art_event_handler;
        goto LABEL_48;
      case -2147483629:
        v22 = sde_crtc_copr_status_event_handler;
        goto LABEL_48;
      case -2147483628:
        v22 = sde_crtc_vm_reclaim_handler;
        goto LABEL_48;
      default:
        if ( a3 != 134217745 )
        {
LABEL_90:
          printk(&unk_26C623, "_sde_crtc_event_enable");
          return 4294967274LL;
        }
        v22 = sde_crtc_framedone_event_handler;
LABEL_48:
        v23 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
        v24 = (_QWORD *)v23;
        if ( !v23 )
          return 4294967284LL;
        v25 = (_QWORD *)(v23 + 48);
        *(_QWORD *)(v23 + 48) = v23 + 48;
        *(_QWORD *)(v23 + 56) = v23 + 48;
        *(_QWORD *)v23 = v23;
        *(_QWORD *)(v23 + 8) = v23;
        v26 = *(unsigned __int8 *)(a2 + 172);
        *(_QWORD *)(v23 + 40) = v22;
        *(_DWORD *)(v23 + 32) = a3;
        *(_QWORD *)(v23 + 64) = 0;
        if ( v26 != 1 )
        {
          v33 = raw_spin_lock_irqsave(a2 + 6032);
          v34 = *(_QWORD **)(a2 + 4608);
          v7 = v33;
          if ( v25 == v8 || v34 == v25 || (_QWORD *)*v34 != v8 )
          {
            _list_add_valid_or_report(v24 + 6, v34);
          }
          else
          {
            *(_QWORD *)(a2 + 4608) = v25;
            v24[6] = v8;
            v24[7] = v34;
            *v34 = v25;
          }
          goto LABEL_61;
        }
        v27 = *(_QWORD *)(*(_QWORD *)a2 + 8LL);
        v28 = _pm_runtime_resume(v27, 4);
        if ( (v28 & 0x80000000) != 0 )
        {
          v47 = *(_DWORD *)(v27 + 480);
          v31 = v28;
          do
          {
            if ( !v47 )
              break;
            _X12 = (unsigned int *)(v27 + 480);
            __asm { PRFM            #0x11, [X12] }
            do
            {
              v50 = __ldxr(_X12);
              if ( v50 != v47 )
                goto LABEL_83;
            }
            while ( __stlxr(v47 - 1, _X12) );
            __dmb(0xBu);
LABEL_83:
            _ZF = v50 == v47;
            v47 = v50;
          }
          while ( !_ZF );
          printk(&unk_24C43E, "_sde_crtc_event_enable");
          sde_evtlog_log(sde_dbg_base_evtlog, "_sde_crtc_event_enable", 9455, -1, v31, 60333, -1059143953, v51, vars0);
LABEL_55:
          v32 = v24;
          goto LABEL_56;
        }
        *v24 = v24;
        v24[1] = v24;
        mutex_lock(a2 + 4616);
        v29 = (_DWORD *)v24[5];
        if ( *(v29 - 1) != 1979947765 )
          __break(0x8228u);
        v30 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v29)(a2, 1, v24);
        if ( v30 )
        {
          v31 = v30;
          mutex_unlock(a2 + 4616);
          _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a2 + 8LL), 4);
          goto LABEL_55;
        }
        v35 = raw_spin_lock_irqsave(a2 + 6032);
        v36 = *(_QWORD **)(a2 + 4608);
        v37 = v35;
        if ( v25 == v8 || v36 == v25 || (_QWORD *)*v36 != v8 )
        {
          _list_add_valid_or_report(v24 + 6, v36);
        }
        else
        {
          *(_QWORD *)(a2 + 4608) = v25;
          v24[6] = v8;
          v24[7] = v36;
          *v36 = v25;
        }
        raw_spin_unlock_irqrestore(a2 + 6032, v37);
        mutex_unlock(a2 + 4616);
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a2 + 8LL), 4);
        break;
    }
  }
  else
  {
    v12 = (_QWORD *)(a2 + 4600);
    while ( 1 )
    {
      v12 = (_QWORD *)*v12;
      if ( v12 == v8 )
        break;
      if ( *((_DWORD *)v12 - 4) == a3 )
      {
        v13 = (_QWORD *)v12[1];
        if ( (_QWORD *)*v13 == v12 && (v14 = (_QWORD *)*v12, *(_QWORD **)(*v12 + 8LL) == v12) )
        {
          v14[1] = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v12);
        }
        *v12 = v12;
        v12[1] = v12;
        raw_spin_unlock_irqrestore(a2 + 6032, v7);
        if ( (*(_BYTE *)(a2 + 172) & 1) == 0 )
        {
          kfree(v12 - 6);
          return 0;
        }
        v15 = *(_QWORD *)(*(_QWORD *)a2 + 8LL);
        v16 = _pm_runtime_resume(v15, 4);
        if ( (v16 & 0x80000000) != 0 )
        {
          v38 = *(_DWORD *)(v15 + 480);
          v31 = v16;
          do
          {
            if ( !v38 )
              break;
            _X12 = (unsigned int *)(v15 + 480);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v45 = __ldxr(_X12);
              if ( v45 != v38 )
                break;
              if ( !__stlxr(v38 - 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v45 == v38;
            v38 = v45;
          }
          while ( !_ZF );
          printk(&unk_24C43E, "_sde_crtc_event_disable");
          sde_evtlog_log(sde_dbg_base_evtlog, "_sde_crtc_event_disable", 9524, -1, v31, 60333, -1059143953, v46, vars0);
          v32 = v12 - 6;
LABEL_56:
          kfree(v32);
          return v31;
        }
        else
        {
          v17 = (_DWORD *)*(v12 - 1);
          if ( *(v17 - 1) != 1979947765 )
            __break(0x8228u);
          v18 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *))v17)(a2, 0, v12 - 6);
          if ( v18 )
          {
            v19 = raw_spin_lock_irqsave(a2 + 6032);
            v20 = *(_QWORD **)(a2 + 4608);
            v21 = v19;
            if ( v20 == v12 || (_QWORD *)*v20 != v8 )
            {
              _list_add_valid_or_report(v12, v20);
            }
            else
            {
              *(_QWORD *)(a2 + 4608) = v12;
              *v12 = v8;
              v12[1] = v20;
              *v20 = v12;
            }
            raw_spin_unlock_irqrestore(a2 + 6032, v21);
          }
          else
          {
            kfree(v12 - 6);
          }
          _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a2 + 8LL), 4);
          return v18;
        }
      }
    }
LABEL_61:
    raw_spin_unlock_irqrestore(a2 + 6032, v7);
  }
  return 0;
}
