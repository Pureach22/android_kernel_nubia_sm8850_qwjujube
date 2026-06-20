__int64 __fastcall rmnet_frag_descriptor_add_frags_from(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // w8
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 *v8; // x20
  __int64 *v9; // x23
  unsigned int v10; // w8
  unsigned int v11; // w8
  __int64 v12; // x1
  int v13; // w22

  v4 = *(_DWORD *)(a2 + 48);
  result = 4294967274LL;
  if ( a4 + a3 <= v4 && v4 >= a3 )
  {
    v7 = a4;
    if ( v4 >= a4 )
    {
      result = 0;
      v8 = (__int64 *)(a2 + 16);
      v9 = *(__int64 **)(a2 + 16);
      if ( v9 != (__int64 *)(a2 + 16) )
      {
        if ( a4 )
        {
          do
          {
            v10 = *((_DWORD *)v9 + 6);
            if ( a3 >= v10 )
            {
              a3 -= v10;
            }
            else
            {
              v11 = v10 - a3;
              if ( (v9[2] & 1) != 0 )
                v12 = 0;
              else
                v12 = v9[2];
              if ( v7 >= v11 )
                v13 = v11;
              else
                v13 = v7;
              result = rmnet_frag_descriptor_add_frag(a1, v12, *((_DWORD *)v9 + 7) + a3, v13);
              if ( (result & 0x80000000) != 0 )
                return result;
              a3 = 0;
              v7 -= v13;
            }
            v9 = (__int64 *)*v9;
            result = 0;
          }
          while ( v9 != v8 && v7 );
        }
      }
    }
  }
  return result;
}
