__int64 __fastcall msm_gem_iova(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x21

  mutex_lock(a1 + 544);
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  v4 = (_QWORD *)(a1 + 440);
  do
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(a1 + 440) )
    {
      mutex_unlock(a1 + 544);
      goto LABEL_9;
    }
  }
  while ( *(v4 - 1) != a2 );
  mutex_unlock(a1 + 544);
  if ( v4 != &qword_B8 )
    return *(v4 - 2);
LABEL_9:
  __break(0x800u);
  return 0;
}
