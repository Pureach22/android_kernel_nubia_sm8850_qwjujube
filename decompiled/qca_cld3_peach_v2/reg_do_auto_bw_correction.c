__int64 __fastcall reg_do_auto_bw_correction(__int64 result, __int64 a2, unsigned __int16 a3)
{
  __int64 v3; // x8
  __int16 *v4; // x10
  __int16 v5; // w12
  int v6; // w12
  unsigned int v7; // w12

  v3 = (unsigned int)(result - 1);
  if ( (_DWORD)result != 1 )
  {
    v4 = (__int16 *)(a2 + 18);
    do
    {
      v6 = (unsigned __int16)*(v4 - 8);
      if ( v6 == (unsigned __int16)*(v4 - 2) )
      {
        v7 = (unsigned __int16)(*(v4 - 1) - v6) + (unsigned __int16)(v6 - *(v4 - 9));
        if ( v7 >= a3 )
          v7 = a3;
        if ( v7 > 0x13F )
        {
          v5 = 320;
        }
        else if ( v7 > 0x9F )
        {
          v5 = 160;
        }
        else if ( v7 > 0x4F )
        {
          v5 = 80;
        }
        else if ( v7 > 0x27 )
        {
          v5 = 40;
        }
        else if ( v7 > 0x13 )
        {
          v5 = 20;
        }
        else if ( v7 > 9 )
        {
          v5 = 10;
        }
        else if ( v7 >= 5 )
        {
          v5 = 5;
        }
        else
        {
          v5 = 0;
        }
        *(v4 - 7) = v5;
        *v4 = v5;
      }
      --v3;
      v4 += 7;
    }
    while ( v3 );
  }
  return result;
}
