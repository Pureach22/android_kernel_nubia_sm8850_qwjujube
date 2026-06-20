__int64 __fastcall sde_encoder_helper_register_irq(__int64 a1, unsigned int a2)
{
  _DWORD *v3; // x23
  _DWORD *v4; // x21
  __int64 v5; // x8
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  int v13; // w4
  __int64 v14; // x8
  __int64 v15; // x7
  int v16; // w8
  const char *v17; // x3
  unsigned int v19; // w19
  unsigned int v20; // w23
  int v21; // w4
  __int64 v22; // [xsp+0h] [xbp-10h]

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 136LL) + 56LL) + 5912LL) == 1 )
    return 0;
  if ( !a1 || a2 >= 0x17 )
  {
    printk(&unk_223EAA, "sde_encoder_helper_register_irq");
    return 4294967274LL;
  }
  v3 = (_DWORD *)(a1 + 56LL * a2);
  v4 = v3 + 250;
  if ( (v3[255] & 0x80000000) == 0 )
  {
    if ( (_drm_debug & 4) == 0 )
      return 0;
    v5 = *(_QWORD *)(a1 + 496);
    v6 = *(unsigned int *)(*(_QWORD *)a1 + 24LL);
    v7 = (unsigned int)(*(_DWORD *)(a1 + 672) - 1);
    if ( v5 )
      v8 = (unsigned int)(*(_DWORD *)(v5 + 32) - 1);
    else
      v8 = 0xFFFFFFFFLL;
    v15 = *(_QWORD *)v4;
    v16 = v3[252];
    v17 = "enc%d intf%d pp%d skipping already registered irq %s type %d\n";
LABEL_22:
    LODWORD(v22) = v16;
    _drm_dev_dbg(0, 0, 0, v17, v6, v7, v8, v15, v22);
    return 0;
  }
  v10 = sde_core_irq_idx_lookup();
  v3[255] = v10;
  if ( (v10 & 0x80000000) != 0 )
  {
    printk(&unk_256E14, "sde_encoder_helper_register_irq");
    return 4294967274LL;
  }
  v11 = sde_core_irq_register_callback(*(_QWORD *)(a1 + 512), v10, v3 + 256);
  if ( v11 )
  {
    v19 = v11;
    printk(&unk_24C701, "sde_encoder_helper_register_irq");
    v3[255] = -22;
    return v19;
  }
  v12 = sde_core_irq_enable(*(_QWORD *)(a1 + 512), v3 + 255, 1);
  if ( !v12 )
  {
    if ( *(_QWORD *)a1 )
      v13 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v13 = -1;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_helper_register_irq", 722, -1, v13, a2, v3[254], v3[255], 239);
    if ( (_drm_debug & 4) == 0 )
      return 0;
    v14 = *(_QWORD *)(a1 + 496);
    v6 = *(unsigned int *)(*(_QWORD *)a1 + 24LL);
    v7 = (unsigned int)(*(_DWORD *)(a1 + 672) - 1);
    if ( v14 )
      v8 = (unsigned int)(*(_DWORD *)(v14 + 32) - 1);
    else
      v8 = 0xFFFFFFFFLL;
    v15 = *(_QWORD *)v4;
    v16 = v3[255];
    v17 = "enc%d intf%d pp%d registered irq %s idx: %d\n";
    goto LABEL_22;
  }
  v20 = v12;
  printk(&unk_242B0B, "sde_encoder_helper_register_irq");
  sde_core_irq_unregister_callback(*(_QWORD *)(a1 + 512), (unsigned int)v4[5], v4 + 6);
  if ( *(_QWORD *)a1 )
    v21 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v21 = -1;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_helper_register_irq", 717, -1, v21, a2, v4[4], v4[5], 173);
  v4[5] = -22;
  return v20;
}
