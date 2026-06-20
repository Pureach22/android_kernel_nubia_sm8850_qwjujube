__int64 __fastcall dp_rate_idx_to_kbps(unsigned __int8 a1, char a2)
{
  _UNKNOWN **v2; // x8
  unsigned int *v3; // x9
  unsigned int *v4; // x8

  v2 = &dp_11abgnratetable + 5 * a1;
  v3 = (unsigned int *)(v2 + 2);
  v4 = (unsigned int *)v2 + 3;
  if ( a2 )
    v4 = v3;
  return *v4;
}
