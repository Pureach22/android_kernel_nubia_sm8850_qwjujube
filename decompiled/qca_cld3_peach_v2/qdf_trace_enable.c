__int64 __fastcall qdf_trace_enable(__int64 result, char a2)
{
  __int64 i; // x8
  __int64 v3; // x11
  __int64 v4; // x11
  __int64 j; // x8
  __int64 v6; // x11
  __int64 v7; // x8
  __int64 *v8; // x11
  _QWORD *v9; // x13
  __int64 v10; // x12
  __int64 v11; // x14
  __int64 v12; // x9

  if ( (_DWORD)result )
  {
    for ( i = 0; i != 167; ++i )
    {
      if ( (((unsigned int)result >> i) & 1) != 0 )
      {
        if ( a2 )
        {
          v4 = qdf_trace_restore_cb_table[i];
          if ( v4 )
            qdf_trace_cb_table[i] = v4;
        }
        else
        {
          v3 = qdf_trace_cb_table[i];
          qdf_trace_cb_table[i] = 0;
          qdf_trace_restore_cb_table[i] = v3;
        }
      }
    }
  }
  else if ( a2 )
  {
    for ( j = 0; j != 167; ++j )
    {
      v6 = qdf_trace_restore_cb_table[j];
      if ( v6 )
        qdf_trace_cb_table[j] = v6;
    }
  }
  else
  {
    v7 = 0;
    do
    {
      v8 = &qdf_trace_cb_table[v7];
      v9 = &qdf_trace_restore_cb_table[v7];
      v7 += 2;
      v10 = *v8;
      v11 = v8[1];
      *v8 = 0;
      v8[1] = 0;
      *v9 = v10;
      v9[1] = v11;
    }
    while ( v7 != 166 );
    v12 = qword_7CFFE0;
    qword_7CFFE0 = 0;
    qword_7CFAA8 = v12;
  }
  return result;
}
