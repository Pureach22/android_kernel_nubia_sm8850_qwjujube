__int64 __fastcall syna_tcm_set_touch_report_config(__int64 a1, void *a2, __int64 a3, unsigned int a4)
{
  void *v4; // x0
  unsigned int v6; // w22
  __int64 v7; // x19
  void *v8; // x20
  unsigned int v9; // w21
  __int64 v10; // x20
  void *v11; // x22
  unsigned int v12; // w24
  unsigned int v13; // w21
  __int64 v14; // x23
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x2
  __int64 v18; // x0
  __int64 v19; // x19
  int v20; // w0
  __int64 v21; // x2
  int v22; // w20
  void *v23; // x0
  _DWORD *v24; // x8

  if ( !a1 )
  {
    v4 = &unk_3365A;
LABEL_12:
    printk(v4, "syna_tcm_set_touch_report_config", a3);
    return 4294967055LL;
  }
  if ( !a2 || !(_DWORD)a3 )
  {
    v4 = &unk_34B2B;
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a1 + 9) != 1 )
  {
    printk(&unk_36DD4, "syna_tcm_set_touch_report_config", *(unsigned __int8 *)(a1 + 9));
    return 4294967055LL;
  }
  if ( !a4 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
    {
      v6 = *(_DWORD *)(a1 + 524);
      v7 = a1;
      v8 = a2;
      v9 = a3;
      printk(&unk_3BA3F, "syna_tcm_set_touch_report_config", a3);
      a2 = v8;
      a3 = v9;
      a4 = v6;
      a1 = v7;
      if ( !*(_WORD *)(v7 + 176) )
        goto LABEL_10;
      goto LABEL_17;
    }
    a4 = 0;
  }
  if ( !*(_WORD *)(a1 + 176) )
  {
LABEL_10:
    v4 = &unk_3C27E;
    goto LABEL_12;
  }
LABEL_17:
  v10 = *(unsigned __int16 *)(a1 + 188);
  if ( (unsigned int)v10 < (unsigned int)a3 )
  {
    printk(&unk_332E4, "syna_tcm_set_touch_report_config", a3);
    return 4294967055LL;
  }
  v11 = a2;
  v12 = a3;
  v13 = a4;
  v14 = a1;
  v15 = syna_request_managed_device();
  if ( !v15 )
  {
    printk(&unk_3BE43, "syna_pal_mem_alloc", v16);
LABEL_22:
    printk(&unk_351D9, "syna_tcm_set_touch_report_config", v17);
    return 4294967053LL;
  }
  v18 = devm_kmalloc(v15, v10, 3520);
  if ( !v18 )
    goto LABEL_22;
  v19 = v18;
  v20 = syna_pal_mem_cpy_1(v18, v10, v11, v12, v12);
  if ( v20 < 0 )
  {
    v22 = v20;
    v23 = &unk_38006;
  }
  else
  {
    v24 = *(_DWORD **)(v14 + 920);
    if ( *(v24 - 1) != 606091918 )
      __break(0x8228u);
    v22 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v24)(
            v14,
            38,
            v19,
            (unsigned int)v10,
            0,
            v13);
    if ( v22 >= 0 )
      v23 = &unk_3A63C;
    else
      v23 = &unk_373B9;
  }
  printk(v23, "syna_tcm_set_touch_report_config", v21);
  syna_pal_mem_free_0(v19);
  return (unsigned int)v22;
}
