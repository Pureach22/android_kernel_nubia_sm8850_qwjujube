__int64 __fastcall get_adc_tm_gen3(__int64 a1, const char *a2)
{
  __int64 v3; // x0
  int v4; // w8
  __int64 result; // x0
  _UNKNOWN **v6; // x10
  _QWORD v7[4]; // [xsp+8h] [xbp-78h] BYREF
  _QWORD v8[11]; // [xsp+28h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v7, 0, sizeof(v7));
  scnprintf(v7, 32, "qcom,%s-adc_tm", a2);
  v3 = *(_QWORD *)(a1 + 744);
  memset(v8, 0, 80);
  v4 = _of_parse_phandle_with_args(v3, v7, 0, 0, 0, v8);
  result = -19;
  if ( !v4 && v8[0] )
  {
    v6 = &adc_tm_device_list;
    while ( 1 )
    {
      v6 = (_UNKNOWN **)*v6;
      if ( v6 == &adc_tm_device_list )
        break;
      if ( *((_QWORD *)*(v6 - 18) + 93) == v8[0] )
      {
        result = (__int64)(v6 - 19);
        goto LABEL_8;
      }
    }
    result = -517;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
