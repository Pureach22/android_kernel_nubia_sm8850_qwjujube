__int64 __fastcall qdf_seq_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 696);
  result = seq_open(a2, _qdf_debugfs_seq_ops);
  if ( !(_DWORD)result )
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 128LL) = v3;
  return result;
}
