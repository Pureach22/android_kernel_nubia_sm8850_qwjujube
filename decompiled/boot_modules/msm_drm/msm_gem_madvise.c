bool __fastcall msm_gem_madvise(__int64 a1, char a2)
{
  _BOOL4 v4; // w20

  mutex_lock(a1 + 544);
  if ( (mutex_is_locked(*(_QWORD *)(a1 + 8) + 128LL) & 1) == 0 )
    __break(0x800u);
  if ( *(_BYTE *)(a1 + 372) == 2 )
  {
    v4 = 0;
  }
  else
  {
    *(_BYTE *)(a1 + 372) = a2;
    v4 = a2 != 2;
  }
  mutex_unlock(a1 + 544);
  return v4;
}
