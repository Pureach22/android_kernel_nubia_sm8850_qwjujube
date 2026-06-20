__int64 __fastcall dp_stats_tso_segment_histogram_update(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x8

  v2 = 94160;
  if ( a2 == 1 )
  {
    if ( !result )
      return result;
LABEL_19:
    ++*(_QWORD *)(result + v2);
    return result;
  }
  if ( (unsigned int)a2 - 1 <= 4 )
  {
    if ( !result )
      return result;
    v2 = 94168;
    goto LABEL_19;
  }
  if ( (unsigned int)a2 - 6 <= 4 )
  {
    if ( !result )
      return result;
    v2 = 94176;
    goto LABEL_19;
  }
  if ( (unsigned int)a2 - 11 <= 4 )
  {
    if ( !result )
      return result;
    v2 = 94184;
    goto LABEL_19;
  }
  if ( (unsigned int)a2 - 16 <= 4 )
  {
    if ( !result )
      return result;
    v2 = 94192;
    goto LABEL_19;
  }
  if ( result && a2 >= 0x15u )
  {
    v2 = 94200;
    goto LABEL_19;
  }
  return result;
}
