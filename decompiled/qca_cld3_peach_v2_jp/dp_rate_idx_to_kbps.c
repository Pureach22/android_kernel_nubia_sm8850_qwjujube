__int64 __fastcall dp_rate_idx_to_kbps(unsigned __int8 a1, char a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  unsigned __int64 v4; // x9
  char *v5; // x8
  char *v6; // x9
  char *v7; // x8

  v2 = 36LL * a1;
  v3 = v2 + 12;
  v4 = v2 + 8;
  if ( a2 )
    v4 = v3;
  if ( v4 >> 4 > 0x710 )
  {
    __break(1u);
    JUMPOUT(0x4A196C);
  }
  v5 = (char *)&dp_11abgnratetable + 36 * a1;
  v6 = v5 + 8;
  v7 = v5 + 12;
  if ( !a2 )
    v7 = v6;
  return *(unsigned int *)v7;
}
