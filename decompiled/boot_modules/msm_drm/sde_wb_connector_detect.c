__int64 __fastcall sde_wb_connector_detect(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  if ( a3 )
    return *(unsigned int *)(a3 + 112);
  else
    return 3;
}
