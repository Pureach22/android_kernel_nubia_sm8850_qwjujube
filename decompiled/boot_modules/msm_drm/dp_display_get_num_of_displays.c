__int64 __fastcall dp_display_get_num_of_displays(__int64 a1)
{
  unsigned int v1; // w8
  _QWORD *v2; // x10
  _QWORD *v4; // x9
  _QWORD *v5; // x9
  _QWORD *v6; // x9
  _QWORD *v7; // x9
  _QWORD *v8; // x9

  v1 = g_dp_display;
  if ( !g_dp_display )
    return v1;
  if ( a1 )
  {
    v1 = *(_QWORD *)g_dp_display == a1;
    if ( !qword_293438 )
      return v1;
    if ( *(_QWORD *)qword_293438 == a1 )
    {
      v2 = (_QWORD *)qword_293440;
      if ( *(_QWORD *)g_dp_display == a1 )
        v1 = 2;
      else
        v1 = 1;
      if ( !qword_293440 )
        return v1;
    }
    else
    {
      v2 = (_QWORD *)qword_293440;
      if ( !qword_293440 )
        return v1;
    }
    if ( *v2 == a1 )
    {
      ++v1;
      v4 = (_QWORD *)qword_293448;
      if ( !qword_293448 )
        return v1;
    }
    else
    {
      v4 = (_QWORD *)qword_293448;
      if ( !qword_293448 )
        return v1;
    }
    if ( *v4 == a1 )
    {
      ++v1;
      v5 = (_QWORD *)qword_293450;
      if ( !qword_293450 )
        return v1;
    }
    else
    {
      v5 = (_QWORD *)qword_293450;
      if ( !qword_293450 )
        return v1;
    }
    if ( *v5 == a1 )
    {
      ++v1;
      v6 = (_QWORD *)qword_293458;
      if ( !qword_293458 )
        return v1;
    }
    else
    {
      v6 = (_QWORD *)qword_293458;
      if ( !qword_293458 )
        return v1;
    }
    if ( *v6 == a1 )
    {
      ++v1;
      v7 = (_QWORD *)qword_293460;
      if ( !qword_293460 )
        return v1;
    }
    else
    {
      v7 = (_QWORD *)qword_293460;
      if ( !qword_293460 )
        return v1;
    }
    if ( *v7 == a1 )
    {
      ++v1;
      v8 = (_QWORD *)qword_293468;
      if ( !qword_293468 )
        return v1;
    }
    else
    {
      v8 = (_QWORD *)qword_293468;
      if ( !qword_293468 )
        return v1;
    }
    if ( *v8 != a1 )
      return v1;
    return v1 + 1;
  }
  if ( !qword_293438 )
    return 1;
  if ( !qword_293440 )
    return 2;
  if ( !qword_293448 )
    return 3;
  if ( !qword_293450 )
    return 4;
  if ( !qword_293458 )
    return 5;
  if ( qword_293460 )
  {
    v1 = 7;
    if ( !qword_293468 )
      return v1;
    return v1 + 1;
  }
  return 6;
}
