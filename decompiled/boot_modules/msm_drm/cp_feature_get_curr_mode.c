__int64 __fastcall cp_feature_get_curr_mode(__int64 result, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(); // x8

  if ( a2 && a3 )
  {
    if ( (unsigned int)result < 7 )
    {
      v3 = cp_feat_state_get_funcs[cp_state_feat_info[3 * (unsigned int)result + 1]];
      if ( *((_DWORD *)v3 - 1) != -1586847505 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64))v3)(a2, a3);
    }
    else
    {
      return _drm_err("Feature: %d is not supported in cp state feature", result);
    }
  }
  return result;
}
