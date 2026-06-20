__int64 cam_mem_get_slot()
{
  unsigned int first_zero_bit; // w0
  unsigned int v1; // w19
  unsigned int v2; // w21
  char *v3; // x20
  unsigned __int64 v11; // x10

  mutex_lock(&tbl);
  first_zero_bit = find_first_zero_bit(qword_2FDB90, qword_2FDB98);
  v1 = first_zero_bit;
  if ( first_zero_bit - 2048 > 0xFFFFF800 )
  {
    v2 = first_zero_bit;
    _X9 = (unsigned __int64 *)(qword_2FDB90 + 8LL * (first_zero_bit >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v11 = __ldxr(_X9);
    while ( __stxr(v11 | (1LL << first_zero_bit), _X9) );
    mutex_unlock(&tbl);
    v3 = (char *)&tbl + 296 * v2;
    mutex_lock(v3 + 72);
    raw_spin_lock_bh(v3 + 352);
    v3[184] = 1;
    raw_spin_unlock_bh(v3 + 352);
    v3[185] = 0;
    ktime_get_real_ts64(v3 + 192);
    *((_DWORD *)v3 + 86) = 2;
    mutex_unlock(v3 + 72);
  }
  else
  {
    mutex_unlock(&tbl);
    return (unsigned int)-12;
  }
  return v1;
}
