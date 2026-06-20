__int64 __fastcall dwc3_otg_sm_work(__int64 a1)
{
  __int64 v1; // x25
  _QWORD *v3; // x19
  __int64 v4; // x8
  __int64 v5; // x21
  unsigned int v6; // w8
  _DWORD *v7; // x24
  const char *v8; // x2
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x19
  char v12; // w0
  __int64 v13; // x21
  __int64 *v14; // x26
  __int64 v15; // x22
  unsigned __int8 v16; // w8
  __int64 v17; // x0
  __int64 (*v18)(void); // x8
  int v19; // w0
  _DWORD *v20; // x8
  __int64 v21; // x21
  __int64 v22; // x8
  __int64 v23; // x0
  const char *v24; // x2
  __int64 v25; // x21
  char v26; // w8
  __int64 v27; // x0
  __int64 (*v28)(void); // x8
  int v29; // w0
  __int64 next_available_child; // x0
  __int64 v31; // x21
  int v32; // w0
  __int64 device_by_node; // x0
  __int64 v34; // x21
  unsigned int v35; // w8
  __int64 v36; // x9
  _DWORD *v37; // x8
  bool v38; // w8
  __int64 v39; // x0
  unsigned __int64 v40; // x0
  _QWORD *v41; // x0
  __int64 v42; // x22
  __int64 v43; // x8
  const void *v44; // x1
  _QWORD *v45; // x23
  __int64 v46; // x0
  unsigned int v47; // w0
  int v48; // w8
  __int64 v49; // x22
  int v50; // w0
  __int64 v51; // x21
  int v52; // w3
  unsigned int v53; // w8
  unsigned int v56; // w10
  int v57; // w21
  __int64 v58; // x0
  int v59; // w22
  unsigned int v60; // w8
  unsigned int v63; // w10
  unsigned int v64; // w8
  unsigned int v67; // w10
  unsigned __int64 v74; // x8
  __int64 v75; // x8
  unsigned int v76; // w9
  unsigned int v79; // w11

  v1 = a1 - 616;
  v3 = (_QWORD *)(a1 - 656);
  v4 = *(_QWORD *)(a1 - 616);
  if ( v4 && (v5 = *(_QWORD *)(v4 + 168)) != 0 )
  {
    v7 = (_DWORD *)(a1 + 40);
    v6 = *(_DWORD *)(a1 + 40);
    if ( v6 > 4 )
    {
      v8 = "UNKNOWN";
      goto LABEL_8;
    }
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 40);
    if ( v6 )
      return dev_err(*v3, "dwc is NULL.\n");
    v5 = 0;
    v7 = (_DWORD *)(a1 + 40);
  }
  v8 = state_names[v6];
LABEL_8:
  result = dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, v8, 0, (const char *)&unk_16A05);
  v10 = *(_DWORD *)(a1 + 40);
  if ( v10 > 1 )
  {
    switch ( v10 )
    {
      case 2:
        if ( (*(_QWORD *)(a1 + 32) & 2) == 0 || (*(_QWORD *)(a1 + 32) & 1) == 0 )
        {
          *(_DWORD *)(a1 + 40) = 1;
          dwc3_otg_start_peripheral(v3, 0);
          _pm_runtime_suspend(*v3, 4);
          dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "!BSV psync", *(_DWORD *)(*v3 + 480LL), (const char *)&unk_16A05);
          return queue_work_on(32, *(_QWORD *)(a1 - 8), a1);
        }
        if ( (*(_QWORD *)(a1 + 32) & 4) != 0 && (*(_QWORD *)(a1 + 32) & 2) != 0 )
        {
          v51 = *v3;
          *(_DWORD *)(a1 + 40) = 3;
          *(_QWORD *)(v51 + 520) = ktime_get_mono_fast_ns(result);
          _pm_runtime_suspend(*v3, 13);
          v22 = *v3;
          v23 = *(_QWORD *)(a1 + 600);
          v24 = "SUSP put";
          goto LABEL_86;
        }
        _X9 = (unsigned __int64 *)(a1 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v74 = __ldxr(_X9);
        while ( __stlxr(v74 & 0xFFFFFFFFFFFFFFEFLL, _X9) );
        __dmb(0xBu);
        if ( (v74 & 0x10) != 0 && *(_BYTE *)(a1 + 1925) == 1 )
        {
          if ( *(_DWORD *)(*(_QWORD *)(v5 + 848) + 72LL) == 3 )
            v26 = 1;
          else
            v26 = *(_BYTE *)(a1 + 91);
          return wcd_usbss_dpdm_switch_update(1, v26 & 1);
        }
        break;
      case 3:
        if ( (*(_QWORD *)(a1 + 32) & 2) == 0 )
        {
          *v7 = 1;
          return dwc3_otg_start_peripheral(v3, 0);
        }
        if ( (*(_QWORD *)(a1 + 32) & 4) == 0 )
        {
          *v7 = 2;
          v21 = *v3;
          if ( (_pm_runtime_resume(*v3, 4) & 0x80000000) == 0 )
          {
            v22 = *v3;
            v23 = *(_QWORD *)(a1 + 600);
            v24 = "!SUSP gsync";
LABEL_86:
            v52 = *(_DWORD *)(v22 + 480);
            return dwc3_dbg_print(v23, 0xFFu, v24, v52, (const char *)&unk_16A05);
          }
          v60 = *(_DWORD *)(v21 + 480);
          do
          {
            if ( !v60 )
              break;
            _X12 = (unsigned int *)(v21 + 480);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v63 = __ldxr(_X12);
              if ( v63 != v60 )
                break;
              if ( !__stlxr(v60 - 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v63 == v60;
            v60 = v63;
          }
          while ( !_ZF );
LABEL_127:
          dev_err(*v3, "%s: pm_runtime_resume_and_get failed\n", "dwc3_otg_sm_work");
          return _pm_runtime_set_status(*v3, 2);
        }
        break;
      case 4:
        if ( (*(_QWORD *)(a1 + 32) & 1) == 0 )
        {
          if ( *(_DWORD *)(v5 + 1124) == 1 )
          {
            dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "XHCIResume", 0, (const char *)&unk_16A05);
            result = _pm_runtime_resume(*(_QWORD *)(v5 + 384) + 16LL, 0);
            if ( (int)result >= 1 )
            {
              v11 = *(_QWORD *)(a1 + 600);
              v12 = hrtimer_active(*(_QWORD *)(v5 + 384) + 360LL);
              dwc3_dbg_print(v11, 0xFFu, "RT active", v12 & 1, (const char *)&unk_16A05);
              return _pm_runtime_idle(*(_QWORD *)(v5 + 384) + 16LL, 1);
            }
          }
          return result;
        }
        dwc3_otg_start_host(v3, 0);
        *v7 = 1;
        return queue_work_on(32, *(_QWORD *)(a1 - 8), a1);
      default:
        return dev_err(*v3, "%s: invalid otg-state\n", "dwc3_otg_sm_work");
    }
    return result;
  }
  if ( !v10 )
  {
    if ( *(_QWORD *)(a1 + 512) )
    {
      regulator_unregister_notifier(*(_QWORD *)(a1 + 536), a1 + 512);
      *(_QWORD *)(a1 + 512) = 0;
    }
    pm_runtime_enable(*v3);
    v13 = *v3;
    if ( (_pm_runtime_resume(*v3, 4) & 0x80000000) != 0 )
    {
      v53 = *(_DWORD *)(v13 + 480);
      do
      {
        if ( !v53 )
          break;
        _X12 = (unsigned int *)(v13 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v56 = __ldxr(_X12);
          if ( v56 != v53 )
            break;
          if ( !__stlxr(v53 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v56 == v53;
        v53 = v56;
      }
      while ( !_ZF );
      dev_err(*v3, "%s: pm_runtime_resume_and_get failed\n", "dwc3_otg_sm_work");
      _pm_runtime_set_status(*v3, 2);
      return _pm_runtime_disable(*v3, 1);
    }
    if ( *(_QWORD *)v1 )
    {
LABEL_137:
      *(_DWORD *)(a1 + 40) = 1;
      if ( (*(_QWORD *)(a1 + 32) & 1) != 0 && (*(_QWORD *)(a1 + 32) & 2) == 0 )
      {
        dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "undef_id_!bsv", 0, (const char *)&unk_16A05);
        _pm_runtime_idle(*v3, 4);
        v23 = *(_QWORD *)(a1 + 600);
        v24 = "Undef NoUSB";
        v52 = *(_DWORD *)(*v3 + 480LL);
        return dwc3_dbg_print(v23, 0xFFu, v24, v52, (const char *)&unk_16A05);
      }
      v75 = *v3;
      v76 = *(_DWORD *)(*v3 + 480LL);
      do
      {
        if ( !v76 )
          break;
        _X13 = (unsigned int *)(v75 + 480);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v79 = __ldxr(_X13);
          if ( v79 != v76 )
            break;
          if ( !__stlxr(v76 - 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v79 == v76;
        v76 = v79;
      }
      while ( !_ZF );
      result = dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "Exit UNDEF", 0, (const char *)&unk_16A05);
      if ( (*(_QWORD *)(a1 + 32) & 8) == 0 )
        goto LABEL_19;
LABEL_150:
      v23 = *(_QWORD *)(a1 + 600);
      v24 = "WAIT_FOR_LPM";
      v52 = 0;
      return dwc3_dbg_print(v23, 0xFFu, v24, v52, (const char *)&unk_16A05);
    }
    v14 = (__int64 *)(a1 - 648);
    v15 = *(_QWORD *)(*v3 + 744LL);
    v16 = readl(*(unsigned int **)(a1 - 648));
    v17 = *(_QWORD *)(a1 - 208);
    *(_DWORD *)(a1 + 2144) = v16;
    if ( v17 )
    {
      v18 = *(__int64 (**)(void))(v17 + 264);
      if ( v18 )
      {
        if ( *((_DWORD *)v18 - 1) != -897463944 )
          __break(0x8228u);
        v19 = v18();
        if ( v19 )
        {
          v57 = v19;
          dev_err(*v3, "failed to init HS PHY\n");
          goto LABEL_130;
        }
      }
    }
    if ( *(_QWORD *)v1 )
      v20 = (_DWORD *)(*(_QWORD *)(*(_QWORD *)v1 + 168LL) + 1232LL);
    else
      v20 = (_DWORD *)(a1 + 472);
    if ( *v20 >= 5u )
    {
      v27 = *(_QWORD *)(a1 - 200);
      if ( v27 )
      {
        v28 = *(__int64 (**)(void))(v27 + 264);
        if ( v28 )
        {
          if ( *((_DWORD *)v28 - 1) != -897463944 )
            __break(0x8228u);
          v29 = v28();
          if ( v29 )
          {
            v57 = v29;
            dev_err(*v3, "failed to init SS PHY\n");
            goto LABEL_130;
          }
        }
      }
    }
    next_available_child = of_get_next_available_child(v15, 0);
    if ( !next_available_child )
    {
      dev_err(*v3, "failed to find dwc3 child\n");
      v57 = -19;
      goto LABEL_130;
    }
    v31 = next_available_child;
    v32 = of_platform_populate(v15, 0, 0, *v3);
    if ( v32 )
    {
      v57 = v32;
      dev_err(*v3, "failed to add create dwc3 core\n");
      goto LABEL_130;
    }
    device_by_node = of_find_device_by_node(v31);
    *(_QWORD *)v1 = device_by_node;
    if ( device_by_node )
    {
      v34 = *(_QWORD *)(device_by_node + 168);
      if ( v34 )
      {
        v35 = *(_DWORD *)(a1 + 472);
        v36 = *(_QWORD *)(device_by_node + 168);
        if ( v35 )
        {
          v36 = *(_QWORD *)(device_by_node + 168);
          if ( v35 <= *(_DWORD *)(v34 + 1232) )
          {
            if ( *(_DWORD *)(a1 + 476) < v35 )
              v35 = *(_DWORD *)(a1 + 476);
            *(_DWORD *)(v34 + 1232) = v35;
            if ( !*(_QWORD *)v1 )
            {
              v37 = (_DWORD *)(a1 + 472);
              goto LABEL_70;
            }
            v36 = *(_QWORD *)(*(_QWORD *)v1 + 168LL);
          }
        }
        v37 = (_DWORD *)(v36 + 1232);
LABEL_70:
        v38 = *v37 >= 5u && *(_DWORD *)(a1 - 108) == 0;
        *(_BYTE *)(a1 + 100) = v38;
        if ( of_find_property(v15, "qcom,host-poweroff-in-pm-suspend", 0) )
        {
          v58 = *v3;
          *(_BYTE *)(a1 + 101) = 1;
          dev_info(v58, "%s: Core power collapse on host PM suspend\n", "dwc3_msm_core_init");
        }
        v39 = _dev_fwnode(*(_QWORD *)(v34 + 368));
        v40 = usb_role_switch_find_by_fwnode(v39);
        *(_QWORD *)(a1 + 568) = v40;
        if ( v40 <= 0xFFFFFFFFFFFFF000LL )
        {
          v41 = (_QWORD *)_kmalloc_cache_noprof(usb_decode_ctrl, 2336, 192);
          *(_QWORD *)(a1 + 184) = v41;
          if ( v41 )
          {
            v42 = *(_QWORD *)(v34 + 368);
            v43 = *(_QWORD *)(v42 + 136);
            if ( v43 && (v44 = *(const void **)(v43 + 120)) != nullptr )
            {
              v45 = v41;
              memcpy(v41, v44, 0xC0u);
              *v45 = dwc3_core_prepare;
              v45[1] = dwc3_core_complete;
              *(_QWORD *)(*(_QWORD *)(v42 + 136) + 120LL) = v45;
            }
            else
            {
              dev_err(*(_QWORD *)(v34 + 368), "can't override PM OPs\n");
            }
            v46 = _kmalloc_cache_noprof(usb_decode_ctrl, 2336, 192);
            *(_QWORD *)(a1 + 192) = v46;
            if ( v46 )
            {
              v47 = readl((unsigned int *)(*v14 + 49440));
              v48 = *(unsigned __int8 *)(a1 + 1906);
              *(_DWORD *)(a1 + 168) = HIWORD(v47);
              if ( v48 == 1 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v1 + 168LL) + 1248LL) == 13105 )
              {
                v49 = *v14;
                v50 = readl((unsigned int *)(*v14 + 53284));
                writel(v50 | 0x400, (unsigned int *)(v49 + 53284));
                readl((unsigned int *)(v49 + 53284));
              }
              dwc3_msm_notify_event((__int64 *)v34, 10, 0);
              pm_runtime_set_autosuspend_delay(*(_QWORD *)(v34 + 368), 0);
              pm_runtime_allow(*(_QWORD *)(v34 + 368));
              goto LABEL_137;
            }
            kfree(*(_QWORD *)(a1 + 184));
          }
          of_platform_depopulate(*v3);
          goto LABEL_137;
        }
        dev_err(*v3, "failed to find dwc3 drd role switch\n");
        v59 = *(_DWORD *)(a1 + 568);
        of_platform_depopulate(*v3);
        v57 = v59;
        if ( !v59 )
          goto LABEL_137;
LABEL_130:
        dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "core_init failed", v57, (const char *)&unk_16A05);
        _pm_runtime_suspend(*v3, 4);
        _pm_runtime_disable(*v3, 1);
        return queue_work_on(32, *(_QWORD *)(a1 - 8), a1);
      }
      dev_err(*v3, "Failed to get dwc3 device\n");
      *(_QWORD *)v1 = 0;
    }
    else
    {
      dev_err(*v3, "failed to get dwc3 platform device\n");
    }
    of_platform_depopulate(*v3);
    v57 = -19;
    goto LABEL_130;
  }
  if ( v10 != 1 )
    return dev_err(*v3, "%s: invalid otg-state\n", "dwc3_otg_sm_work");
  if ( (*(_QWORD *)(a1 + 32) & 8) != 0 )
    goto LABEL_150;
LABEL_19:
  if ( (*(_QWORD *)(a1 + 32) & 1) != 0 )
  {
    if ( (*(_QWORD *)(a1 + 32) & 2) == 0 )
      return result;
    v25 = *v3;
    if ( (_pm_runtime_resume(*v3, 4) & 0x80000000) == 0 )
    {
      dwc3_dbg_print(*(_QWORD *)(a1 + 600), 0xFFu, "BIDLE gsync", *(_DWORD *)(*v3 + 480LL), (const char *)&unk_16A05);
      dwc3_otg_start_peripheral(v3, 1);
      *(_DWORD *)(a1 + 40) = 2;
      return queue_work_on(32, *(_QWORD *)(a1 - 8), a1);
    }
    v64 = *(_DWORD *)(v25 + 480);
    do
    {
      if ( !v64 )
        break;
      _X12 = (unsigned int *)(v25 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v67 = __ldxr(_X12);
        if ( v67 != v64 )
          break;
        if ( !__stlxr(v64 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v67 == v64;
      v64 = v67;
    }
    while ( !_ZF );
    goto LABEL_127;
  }
  *v7 = 4;
  result = dwc3_otg_start_host(v3, 1);
  if ( (_DWORD)result )
  {
    result = dev_err(*v3, "unable to start host\n");
    *v7 = 1;
  }
  return result;
}
