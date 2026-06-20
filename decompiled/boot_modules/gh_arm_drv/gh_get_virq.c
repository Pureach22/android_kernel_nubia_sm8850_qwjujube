__int64 __fastcall gh_get_virq(int a1)
{
  __int64 result; // x0

  LODWORD(result) = idr_alloc(&gh_rm_free_virq_idr, &gh_rm_free_virq_idr, (unsigned int)(a1 - 32), 1019, 3264);
  if ( (int)result >= 0 )
    return (unsigned int)(result + 32);
  else
    return (unsigned int)result;
}
