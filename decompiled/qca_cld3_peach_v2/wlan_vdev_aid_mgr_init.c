__int64 __fastcall wlan_vdev_aid_mgr_init(__int16 a1)
{
  __int64 result; // x0
  unsigned int v9; // w9

  result = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
  if ( result )
  {
    _X8 = (unsigned int *)(result + 260);
    *(_WORD *)(result + 256) = 0;
    *(_WORD *)(result + 258) = a1;
    *(_DWORD *)(result + 260) = 0;
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 + 1, _X8) );
  }
  return result;
}
