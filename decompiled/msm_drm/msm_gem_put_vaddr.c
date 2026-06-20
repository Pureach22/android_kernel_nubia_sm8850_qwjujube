__int64 __fastcall msm_gem_put_vaddr(__int64 a1)
{
  char v2; // w8

  mutex_lock(a1 + 544);
  v2 = *(_BYTE *)(a1 + 373);
  if ( !v2 )
  {
    __break(0x800u);
    v2 = *(_BYTE *)(a1 + 373);
  }
  *(_BYTE *)(a1 + 373) = v2 - 1;
  return mutex_unlock(a1 + 544);
}
