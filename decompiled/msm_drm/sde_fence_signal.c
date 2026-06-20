__int64 __fastcall sde_fence_signal(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  int v8; // w6
  int v9; // w7
  __int64 v10; // x22
  unsigned __int64 v11; // x8
  int v12; // w5
  int v13; // w6
  __int64 result; // x0
  int v15; // w3
  int v16; // w5
  char v17; // w8
  _QWORD *v19; // x26
  _QWORD *v20; // x23
  __int64 v21; // x28
  int v22; // w22
  __int64 v23; // x4
  unsigned int v24; // w8
  __int64 v25; // x5
  int v26; // w6
  int v27; // w22
  _QWORD *v28; // x8
  __int64 v29; // x9
  _QWORD *v31; // x8
  __int64 v32; // x9
  int v34; // w8
  __int64 v36; // x1
  unsigned int v42; // w8
  int v44; // w8
  char v45; // [xsp+0h] [xbp-30h]
  char v46; // [xsp+0h] [xbp-30h]
  unsigned int *v47; // [xsp+20h] [xbp-10h]

  if ( !a1 )
    return printk(&unk_2668C3, "sde_fence_signal");
  v10 = raw_spin_lock_irqsave(a1 + 16);
  if ( a3 == 1 )
  {
    if ( a4 )
    {
      v11 = *(_QWORD *)(a4 + 168);
      if ( v11 )
      {
        if ( v11 <= 0xFFFFFFFFFFFFF000LL )
        {
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_reset_hw_fence_timeline",
            761,
            -1,
            *(_DWORD *)(a4 + 164),
            -1059143953,
            v8,
            v9,
            v45);
          if ( (unsigned int)synx_recover(**(unsigned int **)(a4 + 168)) )
            printk(&unk_22F5D5, "_reset_hw_fence_timeline");
        }
      }
    }
    v13 = *(_DWORD *)a1;
    v12 = *(_DWORD *)(a1 + 4);
    if ( v12 - *(_DWORD *)a1 >= 0 )
      return raw_spin_unlock_irqrestore(a1 + 16, v10);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "timeline reset attempt! ctx:0x%x done count:%d commit:%d\n", *(_DWORD *)(a1 + 8), v12, v13);
      v13 = *(_DWORD *)a1;
    }
    *(_DWORD *)(a1 + 4) = v13;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_fence_signal", 1307, -1, *(_DWORD *)(a1 + 8), v13, v13, a2 / 1000, 1);
  }
  else
  {
    v16 = *(_DWORD *)a1;
    v15 = *(_DWORD *)(a1 + 4);
    if ( v15 - *(_DWORD *)a1 >= 0 )
    {
      printk(&unk_236144, "sde_fence_signal");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_fence_signal",
        1320,
        -1,
        *(_DWORD *)(a1 + 8),
        *(_DWORD *)(a1 + 4),
        *(_DWORD *)a1,
        a2 / 1000,
        a3);
      return raw_spin_unlock_irqrestore(a1 + 16, v10);
    }
    v17 = _drm_debug;
    *(_DWORD *)(a1 + 4) = v15 + 1;
    if ( (v17 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "fence_signal:done count:%d commit count:%d\n", v15 + 1, v16);
  }
  raw_spin_unlock_irqrestore(a1 + 16, v10);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_fence_signal",
    1327,
    -1,
    *(_DWORD *)(a1 + 8),
    *(_DWORD *)(a1 + 4),
    *(_DWORD *)a1,
    a2 / 1000,
    239);
  _X22 = (unsigned int *)(a1 + 12);
  __asm { PRFM            #0x11, [X22] }
  do
    v42 = __ldxr(_X22);
  while ( __stxr(v42 + 1, _X22) );
  if ( !v42 )
  {
    v36 = 2;
    goto LABEL_70;
  }
  if ( (((v42 + 1) | v42) & 0x80000000) != 0 )
  {
    v36 = 1;
LABEL_70:
    refcount_warn_saturate(a1 + 12, v36);
  }
  v47 = (unsigned int *)(a1 + 12);
  raw_spin_lock(a1 + 20);
  v19 = *(_QWORD **)(a1 + 48);
  if ( v19 != (_QWORD *)(a1 + 48) )
  {
    while ( 1 )
    {
      v20 = (_QWORD *)*v19;
      v21 = raw_spin_lock_irqsave(a1 + 16);
      if ( a3 == 2 )
      {
        if ( (*(v19 - 6) & 1) != 0 )
          __break(0x800u);
        *((_DWORD *)v19 - 9) = -16;
      }
      v22 = *(_DWORD *)(a1 + 44);
      if ( v22 == 1 || v22 == 3 )
        goto LABEL_32;
      if ( v22 == 4 )
        break;
LABEL_33:
      v25 = *(v19 - 7);
      v26 = *(_DWORD *)(*(v19 - 4) + 4LL);
      v27 = v25 - v26;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "status:%d fence seq:%llu and timeline:%u\n", v27 < 1, v25, v26);
      if ( v27 <= 0 )
      {
        dma_fence_signal_timestamp_locked(v19 - 12, a2);
        raw_spin_unlock_irqrestore(a1 + 16, v21);
        v28 = (_QWORD *)v19[1];
        if ( (_QWORD *)*v28 == v19 && (v29 = *v19, *(_QWORD **)(*v19 + 8LL) == v19) )
        {
          *(_QWORD *)(v29 + 8) = v28;
          *v28 = v29;
        }
        else
        {
          _list_del_entry_valid_or_report(v19);
        }
        *v19 = v19;
        v19[1] = v19;
        if ( v19 == (_QWORD *)&_ksymtab_msm_dss_clean_io_mem )
          goto LABEL_22;
        _X0 = (unsigned int *)(v19 - 5);
        __asm { PRFM            #0x11, [X0] }
        do
          v34 = __ldxr(_X0);
        while ( __stlxr(v34 - 1, _X0) );
        if ( v34 != 1 )
        {
LABEL_58:
          if ( v34 <= 0 )
            refcount_warn_saturate(_X0, 3);
          goto LABEL_22;
        }
        goto LABEL_48;
      }
LABEL_21:
      raw_spin_unlock_irqrestore(a1 + 16, v21);
LABEL_22:
      v19 = v20;
      if ( v20 == (_QWORD *)(a1 + 48) )
        goto LABEL_62;
    }
    v23 = *(unsigned int *)(a1 + 32);
    if ( *(v19 - 7) == v23 )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "_sde_fence_trigger", 1214, -1, v23, 4, 13107, -1059143953, v46);
      goto LABEL_21;
    }
LABEL_32:
    v24 = *(_DWORD *)(a1 + 40);
    if ( (v24 & 0x80000000) != 0 )
    {
      if ( (*(v19 - 6) & 1) != 0 )
      {
        __break(0x800u);
        if ( v24 > 0xFFFFF000 )
          goto LABEL_43;
      }
      else if ( v24 > 0xFFFFF000 )
      {
LABEL_43:
        *((_DWORD *)v19 - 9) = v24;
        dma_fence_signal_timestamp_locked(v19 - 12, a2);
        raw_spin_unlock_irqrestore(a1 + 16, v21);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_fence_trigger",
          1226,
          -1,
          v22,
          *(_DWORD *)(a1 + 40),
          a2 / 1000,
          *(v19 - 7),
          68);
        v31 = (_QWORD *)v19[1];
        if ( (_QWORD *)*v31 == v19 && (v32 = *v19, *(_QWORD **)(*v19 + 8LL) == v19) )
        {
          *(_QWORD *)(v32 + 8) = v31;
          *v31 = v32;
        }
        else
        {
          _list_del_entry_valid_or_report(v19);
        }
        *v19 = v19;
        v19[1] = v19;
        if ( v19 == (_QWORD *)&_ksymtab_msm_dss_clean_io_mem )
          goto LABEL_22;
        _X0 = (unsigned int *)(v19 - 5);
        __asm { PRFM            #0x11, [X0] }
        do
          v34 = __ldxr(_X0);
        while ( __stlxr(v34 - 1, _X0) );
        if ( v34 != 1 )
          goto LABEL_58;
LABEL_48:
        __dmb(9u);
        dma_fence_release(_X0);
        goto LABEL_22;
      }
      __break(0x800u);
      goto LABEL_43;
    }
    goto LABEL_33;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "nothing to trigger!\n");
LABEL_62:
  raw_spin_unlock(a1 + 20);
  result = a1 + 12;
  __asm { PRFM            #0x11, [X0] }
  do
    v44 = __ldxr(v47);
  while ( __stlxr(v44 - 1, v47) );
  if ( v44 == 1 )
  {
    __dmb(9u);
    return kfree(a1);
  }
  else if ( v44 <= 0 )
  {
    return refcount_warn_saturate(v47, 3);
  }
  return result;
}
