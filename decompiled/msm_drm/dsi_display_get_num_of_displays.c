__int64 __fastcall dsi_display_get_num_of_displays(__int64 a1)
{
  __int64 v2; // x10
  __int64 result; // x0
  __int64 v4; // x10

  if ( !qword_F120 )
    goto LABEL_7;
  v2 = *(_QWORD *)(qword_F120 + 8);
  result = 0;
  if ( v2 && v2 == a1 )
  {
    if ( *(_QWORD *)(qword_F120 + 272) || *(_QWORD *)(qword_F120 + 1584) )
    {
      result = 1;
      goto LABEL_8;
    }
LABEL_7:
    result = 0;
  }
LABEL_8:
  if ( qword_F348 )
  {
    v4 = *(_QWORD *)(qword_F348 + 8);
    if ( v4 )
    {
      if ( v4 == a1 && (*(_QWORD *)(qword_F348 + 272) || *(_QWORD *)(qword_F348 + 1584)) )
        return (unsigned int)(result + 1);
    }
  }
  return result;
}
