__int64 __fastcall get_effective_client_locked(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 96);
  else
    return 4294967274LL;
}
