__int64 __fastcall rtc6226_dt_parse_vreg_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 v5; // x1
  int v6; // w9
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  v8[0] = 0;
  if ( (of_property_read_variable_u32_array(v4, a3, v8, 2, 0) & 0x80000000) != 0 )
  {
    printk(&unk_D72B, v5);
    result = 4294967274LL;
  }
  else
  {
    v6 = HIDWORD(v8[0]);
    result = 0;
    *(_DWORD *)(a2 + 16) = v8[0];
    *(_DWORD *)(a2 + 20) = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
