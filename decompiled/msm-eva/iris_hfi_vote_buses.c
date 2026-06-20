__int64 __fastcall iris_hfi_vote_buses(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w19

  if ( a1 )
  {
    mutex_lock(a1 + 80);
    v6 = cvp_set_bw(a2, a3);
    mutex_unlock(a1 + 80);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
