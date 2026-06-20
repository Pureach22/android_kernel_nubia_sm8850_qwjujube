_DWORD *__fastcall ieee80211_disconnect(_DWORD *result, char a2)
{
  __int64 v2; // x8
  char v3; // w11

  v2 = *((_QWORD *)result - 388);
  if ( *result == 2 )
  {
    if ( (a2 & 1) != 0 )
      v3 = 6;
    else
      v3 = 2;
    *((_BYTE *)result - 2243) = v3 | *((_BYTE *)result - 2243) & 0xF9;
    return (_DWORD *)wiphy_work_queue(*(_QWORD *)(v2 + 72), result - 578);
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
