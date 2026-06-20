__int64 __fastcall msm_gem_get_pages(__int64 a1)
{
  __int64 pages; // x20

  mutex_lock(a1 + 544);
  if ( *(_BYTE *)(a1 + 372) )
  {
    __break(0x800u);
    pages = -16;
  }
  else
  {
    pages = get_pages(a1);
  }
  mutex_unlock(a1 + 544);
  return pages;
}
