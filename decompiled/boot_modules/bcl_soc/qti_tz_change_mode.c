__int64 __fastcall qti_tz_change_mode(__int64 a1, int a2)
{
  int v2; // w8
  __int64 v5; // x24
  _QWORD *v6; // x26
  __int64 v7; // x8

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 1056);
    *(_QWORD *)(a1 + 1100) = 0x8000000100000000LL;
    *(_DWORD *)(a1 + 1088) = -274000;
    *(_DWORD *)(a1 + 1108) = 0x7FFFFFFF;
    if ( v2 >= 1 )
    {
      v5 = a1 + 1440;
      do
      {
        v6 = *(_QWORD **)(v5 + 208);
        if ( v6 != (_QWORD *)(v5 + 208) )
        {
          do
          {
            *((_BYTE *)v6 - 144) = 0;
            if ( !a2 )
            {
              v7 = *(v6 - 20);
              *(v6 - 15) = -1;
              *(_BYTE *)(v7 + 968) = 0;
              thermal_cdev_update(*(v6 - 20));
            }
            v6 = (_QWORD *)*v6;
          }
          while ( v6 != (_QWORD *)(v5 + 208) );
          v2 = *(_DWORD *)(a1 + 1056);
        }
        v5 += 232;
      }
      while ( 0x34F72C234F72C235LL * ((v5 - (a1 + 1440)) >> 3) < v2 );
    }
  }
  return 0;
}
