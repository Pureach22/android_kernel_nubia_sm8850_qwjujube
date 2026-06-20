__int64 __fastcall bcl_remove(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 168);
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1888) + 16LL) & 1) == 0 )
    return blocking_notifier_chain_unregister(&bcl_pmic5_notifier, v1 + 1896);
  return result;
}
