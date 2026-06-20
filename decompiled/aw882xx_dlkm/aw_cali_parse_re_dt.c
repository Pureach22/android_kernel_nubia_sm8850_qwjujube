__int64 __fastcall aw_cali_parse_re_dt(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x1
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1

  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL), "aw-re-min", a1 + 64, 1, 0)
      & 0x80000000) != 0 )
  {
    v2 = *(__int64 **)(a1 + 112);
    *(_DWORD *)(a1 + 64) = 1000;
    v3 = v2[14];
    if ( !v3 )
      v3 = *v2;
    printk(&unk_22663, v3, "aw_cali_parse_re_dt");
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL), "aw-re-max", a1 + 60, 1, 0)
      & 0x80000000) != 0 )
  {
    v4 = *(__int64 **)(a1 + 112);
    *(_DWORD *)(a1 + 60) = 50000;
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_22351, v5, "aw_cali_parse_re_dt");
  }
  v6 = *(__int64 **)(a1 + 112);
  v7 = v6[14];
  if ( *(_DWORD *)(a1 + 64) >= *(_DWORD *)(a1 + 60) )
  {
    if ( !v7 )
      v7 = *v6;
    printk(&unk_26192, v7, "aw_cali_parse_re_dt");
    return 4294967274LL;
  }
  else
  {
    if ( !v7 )
      v7 = *v6;
    printk(&unk_23767, v7, "aw_cali_parse_re_dt");
    return 0;
  }
}
