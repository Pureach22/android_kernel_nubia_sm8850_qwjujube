__int64 __fastcall sch_edca_profile_update_all(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 v4; // x21
  unsigned __int8 *v5; // x1
  unsigned __int8 *v6; // x1
  int v7; // t1

  v1 = *(unsigned __int16 *)(result + 3992);
  if ( *(_WORD *)(result + 3992) )
  {
    v2 = result;
    v3 = 0;
    v4 = 70;
    do
    {
      v5 = (unsigned __int8 *)(*(_QWORD *)(v2 + 12264) + v4);
      v7 = *v5;
      v6 = v5 - 70;
      if ( v7 )
      {
        result = sch_edca_profile_update(v2, v6, 0);
        v1 = *(unsigned __int16 *)(v2 + 3992);
      }
      ++v3;
      v4 += 10792;
    }
    while ( v3 < v1 );
  }
  return result;
}
