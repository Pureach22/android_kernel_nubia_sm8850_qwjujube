__int64 __fastcall bcl_set_adc_value(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        long double _Q0,
        double a6,
        double a7,
        double a8,
        double a9,
        long double _Q5)
{
  __int64 v10; // x10
  unsigned int v11; // w9
  __int64 result; // x0
  int v13; // w9
  unsigned int v14; // w21
  unsigned int v16; // w9
  int v17; // w8
  __int64 v21; // x8
  unsigned int v22; // w20
  unsigned int v23; // w21

  if ( (int)a3 < 1 )
    return 4294967274LL;
  v10 = *(_QWORD *)(a1 + 1888);
  v11 = *(_DWORD *)(v10 + 20);
  if ( v11 > a3 || *(_DWORD *)(v10 + 24) < a3 )
    return 4294967274LL;
  if ( a2 >= 3 )
  {
    __break(0x5512u);
    __asm { XAR             V30.2D, V5.2D, V0.2D, #0x12 }
    return bcl_read_ibat();
  }
  if ( a2 || *(_BYTE *)v10 != 1 )
  {
    _CF = a3 >= v11;
    v16 = a3 - v11;
    if ( !_CF )
      v16 = 0;
    v14 = v16 / 0x19;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 39) )
      v13 = 1000;
    else
      v13 = 2000;
    v14 = (int)(v13 * a3) / 49827;
  }
  v17 = *(_DWORD *)(v10 + 4LL * a2 + 4);
  *a4 = v14;
  if ( !a1 )
  {
    printk(&unk_8411, "bcl_pmic5", "bcl_write_register");
    return 4294967274LL;
  }
  result = regmap_write(
             *(_QWORD *)(a1 + 8),
             (unsigned int)*(unsigned __int16 *)(a1 + 16) + (__int16)v17,
             (unsigned __int8)v14);
  if ( (result & 0x80000000) != 0 )
  {
    v23 = result;
    printk(&unk_86BF, "bcl_pmic5", "bcl_write_register");
    result = v23;
    v21 = *(_QWORD *)(a1 + 24);
    if ( v21 )
      goto LABEL_19;
  }
  else
  {
    v21 = *(_QWORD *)(a1 + 24);
    if ( v21 )
    {
LABEL_19:
      v22 = result;
      ipc_log_string(
        v21,
        "[%s]: %s: threshold:%d mV ADC:0x%x\n",
        (const char *)(_ReadStatusReg(SP_EL0) + 2320),
        "bcl_set_adc_value",
        a3,
        *a4);
      return v22;
    }
  }
  return result;
}
