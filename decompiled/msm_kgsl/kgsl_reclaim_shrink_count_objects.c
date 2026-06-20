__int64 kgsl_reclaim_shrink_count_objects()
{
  __int64 v0; // x19
  __int64 v1; // x8

  if ( (*(_BYTE *)(_ReadStatusReg(SP_EL0) + 70) & 2) == 0 )
    return 0;
  raw_read_lock(&unk_3A870);
  v1 = qword_3A800;
  if ( (__int64 *)qword_3A800 == &qword_3A800 )
  {
    v0 = 0;
  }
  else
  {
    v0 = 0;
    do
    {
      if ( (*(_QWORD *)(v1 + 320) & 2) == 0 )
        v0 += (unsigned int)(kgsl_reclaim_max_page_limit - *(_DWORD *)(v1 + 328));
      v1 = *(_QWORD *)v1;
    }
    while ( (__int64 *)v1 != &qword_3A800 );
  }
  raw_read_unlock(&unk_3A870);
  return v0;
}
