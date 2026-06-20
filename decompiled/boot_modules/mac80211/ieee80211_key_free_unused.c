_QWORD *__fastcall ieee80211_key_free_unused(_QWORD *result, __int64 a2)
{
  if ( result )
  {
    if ( result[1] || *result )
      __break(0x800u);
    return (_QWORD *)ieee80211_key_free_common(result, a2);
  }
  return result;
}
