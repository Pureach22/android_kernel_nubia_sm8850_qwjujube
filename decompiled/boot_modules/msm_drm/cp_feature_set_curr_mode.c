__int64 __fastcall cp_feature_set_curr_mode(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int *v3; // x9
  __int64 v4; // x10
  __int64 (__fastcall *v6)(); // x10
  __int64 v8; // x2

  if ( a2 )
  {
    if ( (unsigned int)result < 7 )
    {
      v3 = &cp_state_feat_info[3 * (unsigned int)result];
      v4 = v3[1];
      if ( (unsigned int)v4 < 2 )
      {
        v6 = cp_feat_state_set_funcs[v4];
        v8 = v3[2];
        if ( *((_DWORD *)v6 - 1) != 1626731627 )
          __break(0x822Au);
        return ((__int64 (__fastcall *)(__int64, __int64, __int64))v6)(a2, a3, v8);
      }
      else
      {
        return _drm_err("Feature: %d doesn't have a mapped cp_state_feature_group\n", (unsigned int)result);
      }
    }
    else
    {
      return _drm_err("Feature: %d is not supported in cp state feature", (unsigned int)result);
    }
  }
  return result;
}
