__int64 __fastcall spi_max_dump_size_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x23
  int *v8; // x21

  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock(v7 + 160);
  v8 = (int *)(v7 + 524);
  if ( (unsigned int)kstrtoint(a3, 0, v7 + 524) )
  {
    dev_err(a1, "%s Invalid input\n", "spi_max_dump_size_store");
    a4 = -22;
  }
  else if ( *v8 <= 0 )
  {
    *v8 = 16;
  }
  raw_spin_unlock(v7 + 160);
  return a4;
}
