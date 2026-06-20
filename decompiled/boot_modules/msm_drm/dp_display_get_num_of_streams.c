__int64 __fastcall dp_display_get_num_of_streams(__int64 a1)
{
  __int64 result; // x0

  if ( !g_dp_display )
    return 0;
  if ( *(_QWORD *)g_dp_display == a1 )
    result = *(unsigned int *)(g_dp_display + 3336);
  else
    result = 0;
  if ( qword_293438 )
  {
    if ( *(_QWORD *)qword_293438 == a1 )
      result = (unsigned int)(*(_DWORD *)(qword_293438 + 3336) + result);
    if ( qword_293440 )
    {
      if ( *(_QWORD *)qword_293440 == a1 )
        result = (unsigned int)(*(_DWORD *)(qword_293440 + 3336) + result);
      if ( qword_293448 )
      {
        if ( *(_QWORD *)qword_293448 == a1 )
          result = (unsigned int)(*(_DWORD *)(qword_293448 + 3336) + result);
        if ( qword_293450 )
        {
          if ( *(_QWORD *)qword_293450 == a1 )
            result = (unsigned int)(*(_DWORD *)(qword_293450 + 3336) + result);
          if ( qword_293458 )
          {
            if ( *(_QWORD *)qword_293458 == a1 )
              result = (unsigned int)(*(_DWORD *)(qword_293458 + 3336) + result);
            if ( qword_293460 )
            {
              if ( *(_QWORD *)qword_293460 == a1 )
                result = (unsigned int)(*(_DWORD *)(qword_293460 + 3336) + result);
              if ( qword_293468 )
              {
                if ( *(_QWORD *)qword_293468 == a1 )
                  return (unsigned int)(*(_DWORD *)(qword_293468 + 3336) + result);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
