__int64 wlan_hdd_get_cpu()
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  __int64 v2; // x9
  unsigned int v3; // w19

  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  result = *(unsigned int *)(StatusReg + 40);
  v2 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v2;
  if ( !v2 || !*(_QWORD *)(StatusReg + 16) )
  {
    v3 = result;
    preempt_schedule(result);
    return v3;
  }
  return result;
}
