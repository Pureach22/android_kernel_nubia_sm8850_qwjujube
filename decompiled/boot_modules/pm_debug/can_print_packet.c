__int64 __fastcall can_print_packet(int a1, int a2, int a3)
{
  __int64 real_seconds; // x0
  unsigned int v14; // w8
  signed int v15; // w8

  if ( tcp_output_debug == 3 )
  {
    real_seconds = ktime_get_real_seconds();
    if ( glastUid != a1 && a1 != 1000 && a1 )
    {
      glastUid = a1;
      glastPort = 0;
      glastDataDirect = 0;
      glastTime = real_seconds;
      gpacketCount = 0;
      return 1;
    }
    if ( real_seconds - glastTime > 1 )
    {
      glastPort = 0;
      glastDataDirect = 0;
      glastTime = real_seconds;
      gpacketCount = 0;
    }
    else
    {
      if ( glastPort == a2 && glastDataDirect == a3 )
        return 0;
      glastPort = a2;
      glastDataDirect = a3;
      _X9 = &gpacketCount;
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v14 = __ldxr((unsigned int *)&gpacketCount);
        v15 = v14 + 1;
      }
      while ( __stlxr(v15, (unsigned int *)&gpacketCount) );
      __dmb(0xBu);
      if ( v15 >= 4 )
        return 0;
    }
  }
  return 1;
}
