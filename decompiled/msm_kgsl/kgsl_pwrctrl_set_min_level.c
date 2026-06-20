char *__fastcall kgsl_pwrctrl_set_min_level(unsigned int a1)
{
  char *result; // x0
  __int64 v3; // x19
  unsigned int v4; // w21
  __int64 v5; // x8
  _DWORD *v6; // x8

  result = (char *)kgsl_get_device(0);
  if ( result )
  {
    v3 = (__int64)result;
    rt_mutex_lock(result + 11088);
    v4 = *(_DWORD *)(v3 + 10056);
    if ( v4 > a1 )
    {
      printk(&unk_144367);
      a1 = v4;
    }
    v5 = *(_QWORD *)(v3 + 8752);
    *(_DWORD *)(v3 + 10060) = a1;
    v6 = *(_DWORD **)(v5 + 304);
    if ( *(v6 - 1) != -227291694 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, _QWORD, __int64))v6)(v3, a1, 1) )
      kgsl_pwrctrl_pwrlevel_change(v3);
    return (char *)rt_mutex_unlock(v3 + 11088);
  }
  return result;
}
