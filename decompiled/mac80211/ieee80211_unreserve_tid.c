__int64 __fastcall ieee80211_unreserve_tid(__int64 result, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(result - 2608);
  if ( (unsigned int)(*(_DWORD *)(v4 + 4720) - 2) >= 3 )
  {
    __break(0x800u);
  }
  else if ( *(unsigned __int8 *)(result - 1356) == a2 )
  {
    *(_BYTE *)(result - 1356) = -1;
  }
  else
  {
    return printk(&unk_BA75F, v4 + 1640, a2, a4);
  }
  return result;
}
