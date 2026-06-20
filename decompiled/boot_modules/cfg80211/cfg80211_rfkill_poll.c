__int64 __fastcall cfg80211_rfkill_poll(__int64 a1, __int64 a2)
{
  void (__fastcall *v3)(_QWORD); // x8

  mutex_lock(a2 + 992);
  v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)a2 + 440LL);
  if ( *((_DWORD *)v3 - 1) != -1622500677 )
    __break(0x8228u);
  v3(a2 + 992);
  return mutex_unlock(a2 + 992);
}
