__int64 __fastcall hyp_assign_table(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5, unsigned int a6)
{
  if ( (gh_rm_needs_hyp_assign(a2, a3, a4, a6) & 1) != 0 )
    return hyp_assign_table(a1, *(unsigned int *)(a1 + 8), a2, a3, a4, a5, a6, 1);
  else
    return 0;
}
