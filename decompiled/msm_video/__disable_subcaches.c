__int64 __fastcall _disable_subcaches(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  unsigned __int64 v3; // x11
  unsigned __int64 v4; // x26

  if ( (msm_vidc_syscache_disable & 1) == 0 )
  {
    v1 = result;
    if ( *(_DWORD *)(*(_QWORD *)(result + 3912) + 120LL) )
    {
      v2 = *(_QWORD *)(result + 3904);
      v3 = *(_QWORD *)(v2 + 96);
      v4 = v3 + 24LL * (unsigned int)(*(_DWORD *)(v2 + 104) - 1);
      if ( v4 >= v3 )
      {
        do
        {
          if ( *(_BYTE *)(v4 + 20) == 1 )
          {
            if ( (msm_vidc_debug & 2) != 0 )
              printk(&unk_8F5AA, "high", 0xFFFFFFFFLL, "codec", "__disable_subcaches");
            result = llcc_slice_deactivate(*(_QWORD *)v4);
            if ( (_DWORD)result )
            {
              if ( (msm_vidc_debug & 1) != 0 )
                result = printk(&unk_845E2, "err ", 0xFFFFFFFFLL, "codec", *(_QWORD *)(v4 + 8));
            }
            *(_BYTE *)(v4 + 20) = 0;
            v2 = *(_QWORD *)(v1 + 3904);
          }
          v4 -= 24LL;
        }
        while ( v4 >= *(_QWORD *)(v2 + 96) );
      }
    }
  }
  return result;
}
