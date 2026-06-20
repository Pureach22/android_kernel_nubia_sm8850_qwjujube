__int64 __fastcall sde_connector_lm_preference(__int64 result, __int64 a2, int a3)
{
  __int64 (__fastcall *v3)(__int64, unsigned int *); // x8
  __int64 v4; // x20
  __int64 v5; // x0
  unsigned int v7; // w5
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( a2 && (v3 = *(__int64 (__fastcall **)(__int64, unsigned int *))(result + 3144)) != nullptr )
  {
    if ( (unsigned int)(a3 - 3) > 0xFFFFFFFD )
    {
      v4 = result;
      v5 = *(_QWORD *)(result + 2760);
      if ( *((_DWORD *)v3 - 1) != -1453071423 )
        __break(0x8228u);
      result = v3(v5, &v8);
      if ( (_DWORD)result || !v8 )
      {
        if ( (_drm_debug & 4) != 0 )
          result = _drm_dev_dbg(0, 0, 0, "failed to get default lm count");
      }
      else
      {
        result = *(_QWORD *)(a2 + 152);
        v7 = *(_DWORD *)(result + 6952);
        if ( v8 <= v7 )
        {
          result = sde_hw_mixer_set_preference();
          *(_DWORD *)(v4 + 4668) = result;
        }
        else if ( (_drm_debug & 4) != 0 )
        {
          result = _drm_dev_dbg(0, 0, 0, "topology requesting more lms [%d] than hw exists [%d]", v8, v7);
        }
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      result = _drm_dev_dbg(0, 0, 0, "invalid display_type");
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    result = _drm_dev_dbg(0, 0, 0, "invalid input params");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
