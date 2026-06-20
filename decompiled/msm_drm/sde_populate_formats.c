unsigned __int64 __fastcall sde_populate_formats(int *a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 result; // x0
  int v6; // w10
  int v7; // w11
  _DWORD *v8; // x8
  int v9; // t1
  int v10; // t1

  result = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v6 = *a1;
      result = 0;
      if ( *a1 )
      {
        if ( a4 )
        {
          v7 = 0;
          result = 0;
          v8 = a1 + 4;
          do
          {
            if ( a3 )
            {
              *(_DWORD *)(a2 + 4 * result) = v6;
              *(_QWORD *)(a3 + 8 * result++) = *((_QWORD *)v8 - 1);
              v9 = *v8;
              v8 += 4;
              v6 = v9;
              if ( !v9 )
                return result;
            }
            else
            {
              if ( v7 != v6 )
                *(_DWORD *)(a2 + 4 * result++) = v6;
              v7 = v6;
              v10 = *v8;
              v8 += 4;
              v6 = v10;
              if ( !v10 )
                return result;
            }
          }
          while ( result < a4 );
        }
      }
    }
  }
  return result;
}
