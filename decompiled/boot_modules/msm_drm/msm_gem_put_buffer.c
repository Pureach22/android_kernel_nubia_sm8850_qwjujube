__int64 __fastcall msm_gem_put_buffer(__int64 result)
{
  __int64 v1; // x19
  char v2; // w8

  if ( result )
  {
    v1 = result;
    mutex_lock(result + 544);
    v2 = *(_BYTE *)(v1 + 373);
    if ( !v2 )
    {
      __break(0x800u);
      v2 = *(_BYTE *)(v1 + 373);
    }
    *(_BYTE *)(v1 + 373) = v2 - 1;
    return mutex_unlock(v1 + 544);
  }
  return result;
}
