__int64 __fastcall wcd9378_mbhc_init(__int64 *a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w0
  void *v12; // x0
  __int64 v13; // x8
  unsigned int v14; // w19

  if ( !a2 )
  {
    v12 = &unk_14301;
LABEL_10:
    printk(v12, "wcd9378_mbhc_init");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a2 + 24);
  v5 = *(_QWORD *)(v3 + 152);
  if ( !v5 )
  {
    v12 = &unk_131C3;
    goto LABEL_10;
  }
  v6 = devm_kmalloc(v3, 1056, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  _init_rwsem(v6 + 976, "&(&wcd9378_mbhc->notifier)->rwsem", &wcd9378_mbhc_init___key);
  v8 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(v7 + 1040) = 0;
  *(_DWORD *)(v7 + 900) = 1;
  v9 = *(_QWORD *)(v8 + 144);
  if ( v9 )
  {
    *(_DWORD *)(v7 + 176) = *(_DWORD *)(v9 + 36);
    v10 = wcd_mbhc_init(v7, a2, &mbhc_cb, &intr_ids, &wcd_mbhc_registers, 1);
    if ( v10 )
    {
      v13 = *(_QWORD *)(a2 + 24);
      v14 = v10;
      dev_err(v13, "%s: mbhc initialization failed\n", "wcd9378_mbhc_init");
      return v14;
    }
    else
    {
      wcd_disable_irq(v5 + 408, 2);
      wcd_disable_irq(v5 + 408, 3);
      wcd_disable_irq(v5 + 408, 10);
      wcd_disable_irq(v5 + 408, 12);
      *a1 = v7;
      snd_soc_add_component_controls(a2, &impedance_detect_controls, 2);
      snd_soc_add_component_controls(a2, &hph_type_detect_controls, 1);
      return 0;
    }
  }
  else
  {
    dev_err(v8, "%s: pdata pointer is NULL\n", "wcd9378_mbhc_init");
    return 4294967274LL;
  }
}
