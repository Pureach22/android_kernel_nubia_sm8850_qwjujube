__int64 __fastcall qpnp_tm_set_temp_dac_thresh(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v6; // w21
  int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w19

  if ( (mutex_is_locked(a1 + 64) & 1) == 0 )
  {
    __break(0x800u);
    if ( a2 < 3 )
      goto LABEL_3;
LABEL_11:
    dev_err(*(_QWORD *)(a1 + 8), "invalid TEMP_DAC trip = %d\n", a2);
    return 4294967274LL;
  }
  if ( a2 >= 3 )
    goto LABEL_11;
LABEL_3:
  if ( a3 < 80000 || temp_dac_max[a2] < (__int64)(unsigned int)a3 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "invalid TEMP_DAC temp = %d\n", (unsigned int)a3);
    return 4294967274LL;
  }
  v6 = (unsigned __int8)((8 * a3 - 640000) / 5000);
  v7 = regmap_write(*(_QWORD *)a1, a2 + *(_DWORD *)(a1 + 48) + 71, v6);
  if ( v7 < 0 )
  {
    v9 = v7;
    dev_err(*(_QWORD *)(a1 + 8), "TEMP_DAC_STG write failed, ret=%d\n", v7);
    return v9;
  }
  else
  {
    result = 0;
    *(_QWORD *)(a1 + 8LL * a2 + 144) = 625 * v6 + 80000;
  }
  return result;
}
