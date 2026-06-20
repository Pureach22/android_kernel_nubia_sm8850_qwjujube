__int64 __fastcall adspsleepmon_device_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x8

  if ( (byte_A62C & 1) != 0 )
  {
    if ( !byte_A62C )
      return 4294967277LL;
  }
  else
  {
    adspsleepmon_smem_init();
    if ( (byte_A62C & 1) == 0 )
      return 4294967277LL;
  }
  v4 = (_QWORD *)_kmalloc_cache_noprof(_wake_up, 3520, 32);
  result = 4294967284LL;
  if ( v4 )
  {
    if ( (unsigned __int64)v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4[2] = 0;
      v4[3] = 0;
      *v4 = 0;
      v4[1] = 0;
      *(_QWORD *)(a2 + 32) = v4;
      return 0;
    }
  }
  return result;
}
