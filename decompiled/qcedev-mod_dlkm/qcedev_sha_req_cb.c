__int64 __fastcall qcedev_sha_req_cb(__int64 result, __int64 *a2, _DWORD *a3)
{
  __int64 *v3; // x9
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x12
  __int64 v7; // x13
  unsigned __int64 v14; // x9

  if ( result )
  {
    v3 = *(__int64 **)(result + 80);
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        if ( a2 )
        {
          v5 = a2[3];
          v6 = *a2;
          v7 = a2[1];
          v3[5] = a2[2];
          v3[6] = v5;
          v3[3] = v6;
          v3[4] = v7;
        }
        if ( a3 )
        {
          *((_DWORD *)v3 + 2) = *a3;
          *((_DWORD *)v3 + 3) = a3[1];
        }
        _X10 = (unsigned __int64 *)(v4 + 288);
        __asm { PRFM            #0x11, [X10] }
        do
          v14 = __ldxr(_X10);
        while ( __stlxr(v14 | 1, _X10) );
        __dmb(0xBu);
        if ( (v14 & 1) == 0 )
          return _tasklet_schedule(v4 + 280);
      }
    }
  }
  return result;
}
