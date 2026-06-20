bool __fastcall compare_name_mdp(__int64 *a1)
{
  __int64 v2; // x0

  v2 = a1[14];
  if ( !v2 )
    v2 = *a1;
  return strnstr(v2, "mdp", 3) != 0;
}
