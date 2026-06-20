__int64 __fastcall aw_dev_parse_fade_flag_dt(__int64 a1)
{
  __int64 v2; // x8
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 *v5; // x8
  __int64 v6; // x1
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 112);
  v8 = 0;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 744), "fade-flag", &v8, 1, 0) & 0x80000000) != 0 )
  {
    v3 = *(__int64 **)(a1 + 112);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    printk(&unk_24BFF, v4, "aw_dev_parse_fade_flag_dt");
  }
  v5 = *(__int64 **)(a1 + 112);
  *(_DWORD *)(a1 + 24) = v8;
  v6 = v5[14];
  if ( !v6 )
    v6 = *v5;
  result = printk(&unk_2294B, v6, "aw_dev_parse_fade_flag_dt");
  _ReadStatusReg(SP_EL0);
  return result;
}
