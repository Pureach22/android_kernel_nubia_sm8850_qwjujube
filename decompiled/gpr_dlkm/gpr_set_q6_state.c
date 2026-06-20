__int64 __fastcall gpr_set_q6_state(unsigned int a1)
{
  if ( a1 > 2 )
    return 4294967274LL;
  q6 = a1;
  return 0;
}
