__int64 check_segment_granule_alignment()
{
  __int64 v0; // x1
  void *v1; // x0
  unsigned __int64 *v2; // x10
  unsigned __int64 v3; // x2
  unsigned __int64 v4; // t1

  if ( num_segments < 1 )
    return 0;
  v0 = 0;
  v1 = &unk_A1A0;
  v2 = (unsigned __int64 *)(segment_infos + 8);
  do
  {
    v4 = *v2;
    v2 += 4;
    v3 = v4;
    if ( (v4 & (v4 - 1)) != 0 )
      goto LABEL_9;
    if ( v3 >> 27 )
    {
      if ( (v3 & 0x7FFFFFF) != 0 )
        goto LABEL_8;
    }
    else if ( 0x8000000 % (unsigned int)v3 )
    {
LABEL_8:
      v1 = &unk_954B;
LABEL_9:
      printk(v1);
      return 4294967274LL;
    }
    ++v0;
  }
  while ( num_segments != v0 );
  return 0;
}
