__int64 __fastcall qce_suspend(__int64 a1)
{
  __int64 v1; // x20

  if ( !a1 )
    return 4294967277LL;
  v1 = a1 + 69632;
  if ( *(_BYTE *)(a1 + 70250) == 1 && *(_DWORD *)(a1 + 316) )
  {
    sps_disconnect(*(_QWORD *)(a1 + 1520));
    sps_disconnect(*(_QWORD *)(a1 + 416));
  }
  if ( *(_BYTE *)(v1 + 619) == 1 )
  {
    if ( *(_DWORD *)(a1 + 320) )
    {
      sps_disconnect(*(_QWORD *)(a1 + 1704));
      sps_disconnect(*(_QWORD *)(a1 + 600));
    }
    if ( *(_BYTE *)(v1 + 619) == 1 )
    {
      if ( *(_DWORD *)(a1 + 324) )
      {
        sps_disconnect(*(_QWORD *)(a1 + 1888));
        sps_disconnect(*(_QWORD *)(a1 + 784));
      }
      if ( *(_BYTE *)(v1 + 619) == 1 )
      {
        if ( *(_DWORD *)(a1 + 328) )
        {
          sps_disconnect(*(_QWORD *)(a1 + 2072));
          sps_disconnect(*(_QWORD *)(a1 + 968));
        }
        if ( *(_BYTE *)(v1 + 619) == 1 )
        {
          if ( *(_DWORD *)(a1 + 332) )
          {
            sps_disconnect(*(_QWORD *)(a1 + 2256));
            sps_disconnect(*(_QWORD *)(a1 + 1152));
          }
          if ( *(_BYTE *)(v1 + 619) == 1 )
          {
            if ( *(_DWORD *)(a1 + 336) )
            {
              sps_disconnect(*(_QWORD *)(a1 + 2440));
              sps_disconnect(*(_QWORD *)(a1 + 1336));
            }
          }
        }
      }
    }
  }
  return 0;
}
