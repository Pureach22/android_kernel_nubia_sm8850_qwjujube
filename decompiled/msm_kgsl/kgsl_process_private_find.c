__int64 *__fastcall kgsl_process_private_find(int a1)
{
  __int64 *v2; // x0
  __int64 v3; // x8
  __int64 *v4; // x19
  unsigned int v6; // w20
  unsigned int v7; // t1
  unsigned int v13; // w8

  raw_read_lock(&unk_3A870);
  v2 = &qword_3A800;
  do
  {
    v2 = (__int64 *)*v2;
    if ( v2 == &qword_3A800 )
      goto LABEL_16;
    v3 = *(v2 - 8);
    if ( v3 )
      LODWORD(v3) = *(_DWORD *)(v3 + 112);
  }
  while ( (_DWORD)v3 != a1 );
  v4 = v2 - 9;
  if ( v2 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
    goto LABEL_16;
  v7 = *((_DWORD *)v2 - 9);
  _X0 = (unsigned int *)v2 - 9;
  v6 = v7;
  if ( v7 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( v13 == v6 && __stxr(v6 + 1, _X0) );
      if ( v13 == v6 )
        break;
      v6 = v13;
    }
    while ( v13 );
  }
  if ( (((v6 + 1) | v6) & 0x80000000) == 0 )
  {
    if ( v6 )
      goto LABEL_17;
    goto LABEL_16;
  }
  refcount_warn_saturate(_X0, 0);
  if ( !v6 )
LABEL_16:
    v4 = nullptr;
LABEL_17:
  raw_read_unlock(&unk_3A870);
  return v4;
}
