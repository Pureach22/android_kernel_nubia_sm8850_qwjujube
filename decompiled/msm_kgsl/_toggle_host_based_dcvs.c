_QWORD *__fastcall toggle_host_based_dcvs(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w21
  _BYTE *v4; // x20
  __int64 v5; // x1
  _QWORD *result; // x0
  __int64 v7; // x1

  v2 = *a2;
  v4 = (_BYTE *)(a1 + 10368);
  if ( v2 == 1 )
  {
    *(_BYTE *)(a1 + 12960) = 1;
    *v4 = 1;
    kgsl_pwrscale_close(a1);
    v5 = *(_QWORD *)(a1 + 11168);
    v4[3864] = 1;
    kgsl_pwrscale_init((_QWORD *)a1, v5);
    return kgsl_pwrscale_tz_enable((_QWORD *)a1);
  }
  else
  {
    kgsl_pwrscale_tz_disable((_QWORD *)a1, 0);
    kgsl_pwrscale_close(a1);
    v7 = *(_QWORD *)(a1 + 11168);
    v4[3864] = v2;
    result = (_QWORD *)kgsl_pwrscale_init((_QWORD *)a1, v7);
    v4[2592] = 0;
    *v4 = 0;
  }
  return result;
}
