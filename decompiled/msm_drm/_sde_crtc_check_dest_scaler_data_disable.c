__int64 __fastcall sde_crtc_check_dest_scaler_data_disable(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  int v7; // w8
  unsigned __int64 v10; // x9
  unsigned __int64 v17; // x10

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "dest scaler status : %d -> %d\n", *(_DWORD *)(a2 + 2048), a3);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_sde_crtc_check_dest_scaler_data_disable",
             4274,
             4,
             *(_DWORD *)(a1 + 112),
             *(_DWORD *)(a2 + 2048),
             a3,
             *(_DWORD *)(a2 + 2044),
             *(_QWORD *)(a2 + 1792));
  if ( *(_DWORD *)(a2 + 2048) == a3 )
  {
    if ( !a3 )
    {
      _X8 = (unsigned __int64 *)(a2 + 1792);
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    }
  }
  else
  {
    if ( a3 )
      goto LABEL_7;
    v7 = *(_DWORD *)(a2 + 2044);
    if ( !v7 )
      goto LABEL_7;
    *(_DWORD *)(a2 + 2080) = 0;
    *(_QWORD *)(a2 + 2056) = 0x200000000LL;
    *(_DWORD *)(a2 + 2320) = 0;
    if ( v7 == 1 )
      goto LABEL_7;
    *(_DWORD *)(a2 + 2672) = 0;
    *(_DWORD *)(a2 + 2912) = 0;
    *(_QWORD *)(a2 + 2648) = 0x200000001LL;
    if ( v7 == 2 )
      goto LABEL_7;
    *(_DWORD *)(a2 + 3264) = 0;
    *(_QWORD *)(a2 + 3240) = 0x200000002LL;
    *(_DWORD *)(a2 + 3504) = 0;
    if ( v7 == 3
      || (*(_DWORD *)(a2 + 3856) = 0, *(_DWORD *)(a2 + 4096) = 0, *(_QWORD *)(a2 + 3832) = 0x200000003LL, v7 == 4)
      || (*(_DWORD *)(a2 + 4448) = 0, *(_DWORD *)(a2 + 4688) = 0, *(_QWORD *)(a2 + 4424) = 0x200000004LL, v7 == 5) )
    {
LABEL_7:
      *(_DWORD *)(a2 + 2048) = a3;
    }
    else
    {
      __break(0x5512u);
    }
    _X8 = (unsigned __int64 *)(a2 + 1792);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | 1, _X8) );
  }
  return result;
}
