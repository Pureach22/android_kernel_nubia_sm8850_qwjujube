__int64 __fastcall kgsl_memfree_purge(__int64 result, unsigned __int64 a2, __int64 a3)
{
  int v5; // w21
  __int64 v6; // x9
  __int64 v7; // x8
  unsigned __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x12
  unsigned __int64 v11; // x13
  unsigned __int64 v12; // x12

  if ( result )
    v5 = *(_DWORD *)(result + 24);
  else
    v5 = 0;
  if ( memfree )
  {
    raw_spin_lock(&memfree_lock);
    v6 = memfree;
    v7 = 0;
    v8 = a3 + a2;
    do
    {
      if ( *(_DWORD *)(v6 + v7) == v5 )
      {
        v9 = v6 + v7;
        v10 = *(_QWORD *)(v6 + v7 + 16);
        if ( v10 )
        {
          v11 = *(_QWORD *)(v9 + 8);
          v12 = v11 + v10;
          if ( a2 > v11 && v12 > a2 )
          {
            *(_QWORD *)(v9 + 16) = a2 - v11;
          }
          else if ( a2 <= v11 )
          {
            if ( v8 <= v11 || v8 >= v12 )
            {
              if ( v8 >= v12 )
                *(_QWORD *)(v9 + 16) = 0;
            }
            else
            {
              *(_QWORD *)(v9 + 8) = v8;
            }
          }
        }
      }
      v7 += 40;
    }
    while ( v7 != 20480 );
    return raw_spin_unlock(&memfree_lock);
  }
  return result;
}
