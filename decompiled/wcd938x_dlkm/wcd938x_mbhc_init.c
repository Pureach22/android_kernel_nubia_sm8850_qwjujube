__int64 __fastcall wcd938x_mbhc_init(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w0
  unsigned int v12; // w21

  if ( a2 )
  {
    v6 = devm_kmalloc(*(_QWORD *)(a2 + 24), 1056, 3520);
    if ( v6 )
    {
      v7 = v6;
      *(_QWORD *)(v6 + 1048) = a3;
      _init_rwsem(v6 + 976, "&(&wcd938x_mbhc->notifier)->rwsem", &wcd938x_mbhc_init___key);
      v8 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(v7 + 1040) = 0;
      *(_DWORD *)(v7 + 900) = 1;
      v9 = *(_QWORD *)(v8 + 144);
      if ( v9 )
      {
        *(_DWORD *)(v7 + 176) = *(_DWORD *)(v9 + 36);
        v10 = wcd_mbhc_init(v7, a2, &mbhc_cb, &intr_ids, &wcd_mbhc_registers, 1);
        if ( !v10 )
        {
          *a1 = v7;
          snd_soc_add_component_controls(a2, &impedance_detect_controls, 2);
          snd_soc_add_component_controls(a2, &hph_type_detect_controls, 1);
          return 0;
        }
        v12 = v10;
        dev_err(*(_QWORD *)(a2 + 24), "%s: mbhc initialization failed\n", "wcd938x_mbhc_init");
      }
      else
      {
        dev_err(v8, "%s: pdata pointer is NULL\n", "wcd938x_mbhc_init");
        v12 = -22;
      }
      devm_kfree(*(_QWORD *)(a2 + 24), v7);
      return v12;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_138CA, "wcd938x_mbhc_init");
    return 4294967274LL;
  }
}
