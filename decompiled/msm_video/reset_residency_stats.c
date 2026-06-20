unsigned __int64 __fastcall reset_residency_stats(unsigned __int64 result)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x9
  _QWORD *v3; // x19
  unsigned __int64 v4; // x20

  if ( *(_BYTE *)(result + 20) == 1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v4 = result;
      printk(&unk_88883, "high", 0xFFFFFFFFLL, "codec", "reset_residency_stats");
      result = v4;
    }
    v1 = (_QWORD *)(result + 40);
    v2 = *(_QWORD **)(result + 40);
    if ( v2 != (_QWORD *)(result + 40) )
    {
      do
      {
        v2[3] = 0;
        v2[4] = 0;
        v2 = (_QWORD *)*v2;
      }
      while ( v2 != v1 );
    }
    if ( result )
    {
      v3 = (_QWORD *)(result + 40);
      while ( 1 )
      {
        v3 = (_QWORD *)*v3;
        if ( v3 == v1 )
          break;
        if ( v3[2] == *(_QWORD *)(result + 24) )
        {
          if ( v3 )
          {
            result = ktime_get(result);
            v3[3] = result / 0x3E8;
          }
          return result;
        }
      }
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "get_residency_stats");
    }
  }
  return result;
}
