__int64 __fastcall devfreq_cdev_set_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  int v5; // w22
  __int64 v6; // x19
  int updated; // w0
  __int64 v8; // x8
  unsigned int v9; // w20

  v2 = *(_QWORD *)(a1 + 944);
  if ( *(int *)(v2 + 36) < a2 )
    return 4294967274LL;
  if ( *(_DWORD *)(v2 + 32) == a2 )
    return 0;
  v5 = a2;
  v6 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 8 * a2);
  updated = dev_pm_qos_update_request(v2 + 48, (unsigned int)v6);
  if ( updated < 0 )
  {
    v8 = *(_QWORD *)(v2 + 8);
    v9 = updated;
    dev_err(v8, "Error placing qos request:%lu. cdev:%s err:%d\n", v6, *(const char **)(a1 + 8), updated);
    return v9;
  }
  else
  {
    result = 0;
    *(_DWORD *)(v2 + 32) = v5;
  }
  return result;
}
