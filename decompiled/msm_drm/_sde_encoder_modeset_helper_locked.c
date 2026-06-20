__int64 __fastcall sde_encoder_modeset_helper_locked(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w8
  __int64 (*v4)(void); // x9
  __int64 (*v5)(void); // x9
  __int64 (*v6)(void); // x9
  __int64 (*v7)(void); // x9

  v2 = result;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(
               0,
               0,
               0,
               "enc%d sw_event:%d, vblank_enabled:%d\n",
               *(_DWORD *)(result + 24),
               a2,
               *(unsigned __int8 *)(result + 1312));
  if ( *(_BYTE *)(v2 + 1312) == 1 )
  {
    v3 = *(_DWORD *)(v2 + 196);
    if ( v3 )
    {
      result = *(_QWORD *)(v2 + 200);
      if ( result )
      {
        v4 = *(__int64 (**)(void))(result + 104);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -320796721 )
            __break(0x8229u);
          result = v4();
          v3 = *(_DWORD *)(v2 + 196);
        }
      }
      if ( v3 >= 2 )
      {
        result = *(_QWORD *)(v2 + 208);
        if ( result )
        {
          v5 = *(__int64 (**)(void))(result + 104);
          if ( v5 )
          {
            if ( *((_DWORD *)v5 - 1) != -320796721 )
              __break(0x8229u);
            result = v5();
            v3 = *(_DWORD *)(v2 + 196);
          }
        }
        if ( v3 >= 3 )
        {
          result = *(_QWORD *)(v2 + 216);
          if ( result )
          {
            v6 = *(__int64 (**)(void))(result + 104);
            if ( v6 )
            {
              if ( *((_DWORD *)v6 - 1) != -320796721 )
                __break(0x8229u);
              result = v6();
              v3 = *(_DWORD *)(v2 + 196);
            }
          }
          if ( v3 >= 4 )
          {
            result = *(_QWORD *)(v2 + 224);
            if ( result )
            {
              v7 = *(__int64 (**)(void))(result + 104);
              if ( v7 )
              {
                if ( *((_DWORD *)v7 - 1) != -320796721 )
                  __break(0x8229u);
                result = v7();
                v3 = *(_DWORD *)(v2 + 196);
              }
            }
            if ( v3 > 4 )
            {
              __break(0x5512u);
              return sde_encoder_atomic_check_qsync(result, a2);
            }
          }
        }
      }
    }
  }
  return result;
}
