__int64 __fastcall qvadj_get_overrides_show(__int64 a1)
{
  _BYTE v3[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v3[0] = 0;
  qvadj_get_cur_voltage_overrides(v4, v3);
  seq_printf(a1, "CPUSS rails index: %u\n", v3[0]);
  seq_printf(a1, "Global rails index: %u\n", v4[0]);
  _ReadStatusReg(SP_EL0);
  return 0;
}
