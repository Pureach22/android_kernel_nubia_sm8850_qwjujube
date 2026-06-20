__int64 __fastcall get_effective_result_locked(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 100);
  else
    return 4294967274LL;
}
