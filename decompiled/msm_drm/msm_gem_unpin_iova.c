__int64 __fastcall msm_gem_unpin_iova(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x9

  mutex_lock(a1 + 544);
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  v4 = (_QWORD *)(a1 + 440);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(a1 + 440) )
      break;
    if ( *(v4 - 1) == a2 )
    {
      if ( v4 != &qword_B8 )
      {
        msm_gem_unmap_vma();
        return mutex_unlock(a1 + 544);
      }
      break;
    }
  }
  __break(0x800u);
  return mutex_unlock(a1 + 544);
}
