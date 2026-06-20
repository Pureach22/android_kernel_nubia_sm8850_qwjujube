__int64 __fastcall reg_debug_voltage_read(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v11; // x22
  unsigned __int64 v12; // x0
  unsigned int voltage; // w0
  int v14; // w0
  __int64 result; // x0
  __int64 v16; // [xsp+0h] [xbp-40h] BYREF
  __int64 v17; // [xsp+8h] [xbp-38h]
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int16 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 32);
  v12 = *(_QWORD *)(v11 + 16);
  if ( v12 )
  {
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
  }
  else
  {
    v12 = regulator_get(0);
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_7;
    *(_QWORD *)(v11 + 16) = v12;
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    if ( !v12 )
    {
LABEL_7:
      printk(&unk_818A, "reg_debug_voltage_read");
      result = -19;
      goto LABEL_6;
    }
  }
  voltage = regulator_get_voltage(v12, a2, a3, a4, a5, a6, a7, a8);
  v14 = scnprintf(&v16, 50, &unk_7D8A, voltage);
  result = simple_read_from_buffer(a2, a3, a4, &v16, v14);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
