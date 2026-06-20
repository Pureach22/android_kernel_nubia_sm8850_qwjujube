__int64 __fastcall msm_gem_fault(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned __int64 pages; // x0
  int v5; // w8
  unsigned int inserted; // w20

  v1 = *a1;
  v2 = *(_QWORD *)(*a1 + 96);
  if ( (unsigned int)mutex_lock_interruptible(v2 + 544) )
    return 256;
  if ( *(_BYTE *)(v2 + 372) )
  {
    __break(0x800u);
    inserted = 2;
  }
  else
  {
    pages = get_pages(v2);
    if ( pages < 0xFFFFFFFFFFFFF001LL )
    {
      inserted = vmf_insert_mixed(v1);
    }
    else
    {
      if ( (_DWORD)pages == -133 )
        v5 = 16;
      else
        v5 = 2;
      if ( (_DWORD)pages == -12 )
        inserted = 1;
      else
        inserted = v5;
    }
  }
  mutex_unlock(v2 + 544);
  return inserted;
}
