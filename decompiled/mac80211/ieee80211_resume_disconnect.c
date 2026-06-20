_DWORD *__fastcall ieee80211_resume_disconnect(_DWORD *result)
{
  _DWORD *v1; // x9

  if ( result && (*(_BYTE *)(*((_QWORD *)result - 388) + 1467LL) & 1) != 0 && *result == 2 )
  {
    v1 = *((_DWORD **)result - 401);
    for ( *(result - 774) |= 0x10u; v1 != result - 802; v1 = *(_DWORD **)v1 )
      v1[4] |= 2u;
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
