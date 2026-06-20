__int64 __fastcall dcvs_tuning_numbusy_store(__int64 a1, unsigned int a2)
{
  if ( *(_BYTE *)(a1 + 14232) != 1 )
    return 4294967201LL;
  if ( a2 <= 3 )
    return _dcvs_tuning_scm_entry(a1, 2, a2);
  return 4294967274LL;
}
