__int64 __fastcall bmic_sw_control_put(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned int v5; // w2
  __int64 v6; // x0
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w19

  v2 = *(_DWORD *)(a2 + 72);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL);
  v4 = *(_QWORD *)(**(_QWORD **)(v3 + 152) + 144LL);
  dev_info(v3, "%s: status = %d\n", "bmic_sw_control_put", v2);
  v5 = *(_DWORD *)(v4 + 292);
  if ( (v5 & 0x80000000) != 0 )
  {
    printk(&unk_1A965, "bmic_sw_control_put");
    return 4294967274LL;
  }
  v6 = gpio_to_desc(v5);
  if ( !v2 )
  {
    v7 = gpiod_direction_output_raw(v6, 0);
    if ( (v7 & 0x80000000) == 0 )
      goto LABEL_4;
LABEL_7:
    v9 = v7;
    printk(&unk_18DF5, "bmic_sw_control_put");
    return v9;
  }
  v7 = gpiod_direction_output_raw(v6, 1);
  if ( (v7 & 0x80000000) != 0 )
    goto LABEL_7;
LABEL_4:
  result = 0;
  bmic_sw_control = v2;
  return result;
}
