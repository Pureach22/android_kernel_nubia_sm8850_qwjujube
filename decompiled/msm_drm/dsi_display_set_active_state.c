__int64 __fastcall dsi_display_set_active_state(__int64 result, char a2)
{
  __int64 v2; // x20
  char v3; // w19

  if ( result )
  {
    v2 = result;
    v3 = a2 & 1;
    mutex_lock(result + 72);
    *(_BYTE *)(v2 + 1640) = v3;
    return mutex_unlock(v2 + 72);
  }
  return result;
}
