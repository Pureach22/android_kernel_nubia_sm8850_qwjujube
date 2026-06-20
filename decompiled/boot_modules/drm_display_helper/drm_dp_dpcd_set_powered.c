__int64 __fastcall drm_dp_dpcd_set_powered(__int64 result, char a2)
{
  __int64 v2; // x20

  if ( result )
  {
    v2 = result;
    mutex_lock(result + 1272);
    *(_BYTE *)(v2 + 1553) = (a2 & 1) == 0;
    return mutex_unlock(v2 + 1272);
  }
  return result;
}
