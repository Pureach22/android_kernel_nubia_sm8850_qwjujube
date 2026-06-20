__int64 __fastcall _iface_cmdq_write(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x20
  __int64 v5; // x26
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w21
  unsigned __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x2
  void *v13; // x0
  int v14; // w8
  __int64 pkt_name_from_type; // x0
  unsigned int v16; // w20
  unsigned __int64 v17; // x2
  __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x2
  void *v24; // x0
  unsigned __int64 v25; // x28
  _DWORD *v26; // x27
  unsigned int v27; // w28
  unsigned int v28; // w20
  unsigned int v29; // w8
  __int64 v30; // x1
  __int64 v31; // x3
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v33; // x8
  __int64 v34; // x1
  __int64 v35; // x2
  void *v36; // x0
  unsigned int v37; // w20
  unsigned int v38; // w22
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned int v41; // w23
  __int64 v42; // x10
  unsigned __int64 v43; // x9
  void *v44; // x0
  __int64 v45; // x10
  unsigned int v46; // w28
  unsigned int v47; // w23
  size_t v48; // x22
  int v49; // w20
  __int64 v50; // x23
  __int64 v51; // x0
  __int64 v52; // x2
  __int64 v53; // x3
  __int64 v54; // x8
  unsigned int (__fastcall *v55)(_QWORD); // x8
  __int64 v56; // x22
  __int64 v57; // x0
  int v58; // w8
  int v59; // w9
  __int64 v60; // x0
  int v61; // w8
  unsigned __int64 v62; // [xsp+10h] [xbp-70h]
  unsigned __int64 v63; // [xsp+10h] [xbp-70h]
  _QWORD v64[13]; // [xsp+18h] [xbp-68h] BYREF

  v64[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    v9 = -22;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_15;
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(unsigned int *)(StatusReg + 1800);
    v23 = *(unsigned int *)(StatusReg + 1804);
    v24 = &unk_920BB;
LABEL_51:
    printk(v24, v22, v23, &unk_8E7CE);
    goto LABEL_15;
  }
  v4 = *(_QWORD *)(a1 + 2208);
  v5 = *(_QWORD *)(cvp_driver + 48);
  if ( (mutex_is_locked(a1 + 80) & 1) == 0 && *(_BYTE *)(v4 + 376) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v33 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E7D2, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
    }
    __break(0x800u);
  }
  if ( *(_DWORD *)(a1 + 2408) == 1 )
  {
    v9 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      v11 = *(unsigned int *)(v10 + 1800);
      v12 = *(unsigned int *)(v10 + 1804);
      v13 = &unk_84293;
LABEL_30:
      printk(v13, v11, v12, &unk_8E7CE);
      goto LABEL_15;
    }
    goto LABEL_15;
  }
  v19 = *(_QWORD *)(a1 + 1040);
  *(_DWORD *)(a1 + 28) = a2[1];
  if ( !v19 )
  {
    v9 = -61;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_15;
    v21 = _ReadStatusReg(SP_EL0);
    v22 = *(unsigned int *)(v21 + 1800);
    v23 = *(unsigned int *)(v21 + 1804);
    v24 = &unk_8DA90;
    goto LABEL_51;
  }
  if ( !(unsigned int)_resume(a1, v6, v7, v8) )
  {
    v25 = _ReadStatusReg(SP_EL0);
    if ( !*(_QWORD *)(a1 + 1040) )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        printk(&unk_88A12, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), "warn");
      goto LABEL_68;
    }
    v26 = *(_DWORD **)(a1 + 1024);
    if ( !v26 )
    {
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_68;
      v34 = *(unsigned int *)(v25 + 1800);
      v35 = *(unsigned int *)(v25 + 1804);
      v36 = &unk_94CB1;
      goto LABEL_83;
    }
    if ( *a2 >= 0x40 && (msm_cvp_debug & 8) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_83907, "cmd", "__write_queue", a2[1]);
      if ( (msm_cvp_debug & 0x20) == 0 )
        goto LABEL_64;
    }
    else if ( (msm_cvp_debug & 0x20) == 0 )
    {
LABEL_64:
      v37 = *a2;
      if ( *a2 < 4 || (v38 = v37 >> 2, v37 >> 2 > *(_DWORD *)(a1 + 1048) >> 2) )
      {
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_68;
        v34 = *(unsigned int *)(v25 + 1800);
        v35 = *(unsigned int *)(v25 + 1804);
        v36 = &unk_9211B;
LABEL_83:
        printk(v36, v34, v35, &unk_8E7CE);
LABEL_68:
        v9 = -7;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_15;
        v22 = *(unsigned int *)(v25 + 1800);
        v23 = *(unsigned int *)(v25 + 1804);
        v24 = &unk_86BCA;
        goto LABEL_51;
      }
      raw_spin_lock(a1 + 1016);
      v40 = v26[12];
      v39 = v26[13];
      v41 = v40 - v39;
      if ( v40 <= v39 )
        v41 += *(_DWORD *)(a1 + 1048) >> 2;
      if ( v41 <= v38 )
      {
        v26[9] = 1;
        raw_spin_unlock(a1 + 1016);
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_95797, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
        goto LABEL_68;
      }
      v26[9] = 0;
      v42 = 4 * v39;
      v43 = *(_QWORD *)(a1 + 1040);
      v44 = (void *)(v43 + v42);
      if ( v43 + v42 < v43 || (v45 = *(unsigned int *)(a1 + 1048), (unsigned __int64)v44 > v43 + v45) )
      {
        raw_spin_unlock(a1 + 1016);
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_68;
        v34 = *(unsigned int *)(v25 + 1800);
        v35 = *(unsigned int *)(v25 + 1804);
        v36 = &unk_8934A;
        goto LABEL_83;
      }
      v63 = v25;
      v46 = v39 + v38;
      v47 = v39 + v38 - ((unsigned int)v45 >> 2);
      if ( v39 + v38 >= (unsigned int)v45 >> 2 )
      {
        v48 = ((unsigned int)v45 >> 2) - v39;
        memcpy(v44, a2, v48 * 4);
        memcpy(*(void **)(a1 + 1040), &a2[v48], 4 * v47);
        v46 = v47;
      }
      else
      {
        memcpy(v44, a2, v37 & 0xFFFFFFFC);
      }
      __dsb(0xFu);
      v26[13] = v46;
      v49 = v26[8];
      __dsb(0xFu);
      raw_spin_unlock(a1 + 1016);
      trace_tracing_mark_write();
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 329LL) == 1
        && (cancel_delayed_work(&iris_hfi_pm_work),
            v50 = *(_QWORD *)(a1 + 2184),
            v51 = _msecs_to_jiffies(*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 432LL)),
            (queue_delayed_work_on(32, v50, &iris_hfi_pm_work, v51) & 1) == 0)
        && (msm_cvp_debug & 0x400) != 0
        && !msm_cvp_debug_out )
      {
        printk(&unk_86B9F, &unk_8DA84, v52, v53);
        if ( v49 == 1 )
        {
LABEL_92:
          v54 = *(_QWORD *)(a1 + 2512);
          if ( v54 )
          {
            v55 = *(unsigned int (__fastcall **)(_QWORD))(v54 + 56);
            if ( v55 )
            {
              if ( *((_DWORD *)v55 - 1) != -1303076162 )
                __break(0x8228u);
              if ( v55(a1) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_920E3, *(unsigned int *)(v63 + 1800), *(unsigned int *)(v63 + 1804), &unk_8E7CE);
            }
          }
          _write_register(a1, 0xA0150u, 1u);
          if ( v5 )
          {
            v56 = *(_QWORD *)(a1 + 1024);
            if ( v56 )
            {
              v57 = raw_spin_lock(a1 + 1016);
              v58 = *(_DWORD *)(v56 + 48);
              v59 = *(_DWORD *)(v5 + 51324);
              *(_DWORD *)(v5 + 51320) = v58;
              if ( v59 != v58 )
              {
                v60 = ktime_get(v57);
                v61 = *(_DWORD *)(v5 + 51320);
                *(_QWORD *)(v5 + 51312) = v60;
                *(_DWORD *)(v5 + 51324) = v61;
              }
              raw_spin_unlock(a1 + 1016);
            }
          }
        }
      }
      else if ( v49 == 1 )
      {
        goto LABEL_92;
      }
      v9 = 0;
      goto LABEL_15;
    }
    v62 = v25;
    if ( msm_cvp_debug_out )
    {
      v27 = *a2;
      if ( *a2 )
        goto LABEL_42;
    }
    else
    {
      printk(&unk_912A4, &unk_96215, "__write_queue", a1 + 1016);
      v27 = *a2;
      if ( *a2 )
      {
LABEL_42:
        v28 = 0;
        memset(v64, 0, 96);
        do
        {
          v29 = v28;
          v28 += 32;
          if ( v28 <= v27 )
            v30 = 32;
          else
            v30 = v27 & 0x1F;
          hex_dump_to_buffer((char *)a2 + v29, v30, 32, 4, v64, 96, 0);
          if ( (msm_cvp_debug & 0x20) != 0 && !msm_cvp_debug_out )
            printk(&unk_94187, &unk_96215, v64, v31);
        }
        while ( v28 < v27 );
      }
    }
    v25 = v62;
    goto LABEL_64;
  }
  v9 = -7;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v20 = _ReadStatusReg(SP_EL0);
    v11 = *(unsigned int *)(v20 + 1800);
    v12 = *(unsigned int *)(v20 + 1804);
    v13 = &unk_9399C;
    goto LABEL_30;
  }
LABEL_15:
  v14 = msm_cvp_debug;
  if ( (msm_cvp_debug & 0x20000) != 0
    && (pkt_name_from_type = get_pkt_name_from_type(a2[1]),
        _ReadStatusReg(CNTVCT_EL0),
        v14 = msm_cvp_debug,
        (msm_cvp_debug & 0x20000) != 0)
    && !msm_cvp_debug_out )
  {
    printk(&unk_8E884, "perf", "__iface_cmdq_write", pkt_name_from_type);
    if ( (msm_cvp_debug & 0x10000) == 0 )
      goto LABEL_24;
  }
  else if ( (v14 & 0x10000) == 0 )
  {
    goto LABEL_24;
  }
  v16 = a2[1];
  if ( v16 >= 0x4011001 && *a2 >= 0x40 )
  {
    get_pkt_name_from_type(v16);
    v17 = _ReadStatusReg(CNTVCT_EL0);
    if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
      printk(&unk_85F5D, "info", v17, "EVA_KMD_FWD_END");
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v9;
}
