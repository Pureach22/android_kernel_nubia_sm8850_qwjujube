__int64 __fastcall sde_plane_set_danger_state(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 *v3; // x24
  __int64 v4; // x19
  __int64 v6; // x8

  v2 = *(_QWORD *)(result + 136);
  v3 = *(__int64 **)(v2 + 840);
  if ( v3 != (__int64 *)(v2 + 840) )
  {
    v4 = result;
    do
    {
      if ( v3[22] && v3[220] )
      {
        result = sde_plane_danger_signal_ctrl((_BYTE *)v3 - 8, a2 & 1);
        if ( (_drm_debug & 4) != 0 )
        {
          result = _drm_dev_dbg(
                     0,
                     0,
                     0,
                     "plane:%d img:%dx%d ",
                     *((_DWORD *)v3 + 24),
                     *(_DWORD *)(v3[22] + 128),
                     *(_DWORD *)(v3[22] + 132));
          if ( (_drm_debug & 4) != 0 )
          {
            v6 = v3[220];
            result = _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "src[%d,%d,%d,%d] dst[%d,%d,%d,%d]\n",
                       *(unsigned __int16 *)(v6 + 50),
                       *(unsigned __int16 *)(v6 + 54),
                       *(unsigned __int16 *)(v6 + 62),
                       *(unsigned __int16 *)(v6 + 58),
                       *(_DWORD *)(v6 + 32),
                       *(_DWORD *)(v6 + 36),
                       *(_DWORD *)(v6 + 40),
                       *(_DWORD *)(v6 + 44));
          }
        }
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "Inactive plane:%d\n", *((_DWORD *)v3 + 24));
      }
      v3 = (__int64 *)*v3;
    }
    while ( v3 != (__int64 *)(*(_QWORD *)(v4 + 136) + 840LL) );
  }
  return result;
}
