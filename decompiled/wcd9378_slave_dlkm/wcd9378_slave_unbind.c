__int64 __fastcall wcd9378_slave_unbind(__int64 result)
{
  __int64 v1; // x8

  v1 = result - 72;
  if ( !result )
    v1 = 0;
  if ( !v1 || !*(_QWORD *)(v1 + 224) )
    return dev_err(v1 + 72, "%s: wcd9378_slave is NULL\n", "wcd9378_slave_unbind");
  return result;
}
