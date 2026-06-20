__int64 __fastcall wlan_vdev_aid_mgr_free(__int64 result)
{
  unsigned int v7; // w9
  unsigned int v8; // w9

  if ( result )
  {
    _X8 = (unsigned int *)(result + 260);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v7 = __ldxr(_X8);
      v8 = v7 - 1;
    }
    while ( __stlxr(v8, _X8) );
    __dmb(0xBu);
    if ( !v8 )
    {
      *(_WORD *)(result + 258) = 0;
      return _qdf_mem_free(result);
    }
  }
  return result;
}
