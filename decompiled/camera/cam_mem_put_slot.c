__int64 __usercall cam_mem_put_slot@<X0>(unsigned int a1@<W0>, __int64 a2@<X8>)
{
  __int64 v2; // x9
  __int64 v3; // x10
  char *v4; // x21
  unsigned __int64 v13; // x10

  if ( a1 >= 0x800 )
  {
    __break(0x5512u);
  }
  else
  {
    v4 = (char *)&tbl + 296 * a1;
    mutex_lock(v4 + 72);
    raw_spin_lock_bh(v4 + 352);
    v4[184] = 0;
    raw_spin_unlock_bh(v4 + 352);
    v4[185] = 0;
    v4[187] = 0;
    *((_QWORD *)v4 + 24) = 0;
    *((_QWORD *)v4 + 25) = 0;
    *((_DWORD *)v4 + 52) = 1;
    *((_DWORD *)v4 + 87) = 1;
    mutex_unlock(v4 + 72);
    mutex_lock(&tbl);
    v2 = qword_2FDB90;
    v3 = a1 >> 6;
    a2 = 1LL << a1;
  }
  _X9 = (unsigned __int64 *)(v2 + 8 * v3);
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stxr(v13 & ~a2, _X9) );
  return mutex_unlock(&tbl);
}
