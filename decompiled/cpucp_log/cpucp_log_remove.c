__int64 __fastcall cpucp_log_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  v2 = v1[8];
  v3 = v1[9];
  kfree(*v1);
  v4 = v1[8];
  *v1 = 0;
  result = mbox_free_channel(v4);
  if ( v2 != v3 )
    return mbox_free_channel(v1[9]);
  return result;
}
