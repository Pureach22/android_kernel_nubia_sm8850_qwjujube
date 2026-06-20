__int64 __fastcall count_format_args(_BYTE *a1, unsigned int *a2)
{
  unsigned int v2; // w19
  _BYTE *v4; // x21
  char v5; // w8
  int v6; // w24
  int v7; // w23

  v2 = -1;
  if ( a2 )
  {
    v4 = a1;
    *a2 = -1;
    v2 = 0;
    if ( a1 )
    {
      v5 = 0;
      v6 = -1;
      while ( 1 )
      {
        v7 = (unsigned __int8)*v4;
        if ( v7 == 37 )
          break;
        if ( !*v4 )
          return v2;
        if ( (v5 & 1) != 0 )
        {
          if ( memchr("diouxXfFeEgGaAcsSpn", v7, 0x14u) )
          {
            v5 = 0;
            ++v2;
            if ( v7 == 115 && v6 == -1 )
            {
              v5 = 0;
              *a2 = v2;
              v6 = v2;
              ++v4;
            }
            else
            {
LABEL_13:
              ++v4;
            }
          }
          else
          {
            if ( v7 == 42 )
              return (unsigned int)-1;
            v5 = 1;
            ++v4;
          }
        }
        else
        {
          v5 = 0;
          ++v4;
        }
      }
      v5 ^= 1u;
      goto LABEL_13;
    }
  }
  return v2;
}
