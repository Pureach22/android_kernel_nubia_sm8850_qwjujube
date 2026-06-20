size_t __fastcall vi530x_offset_data_read(__int64 a1, __int64 a2, __int64 a3, void *a4, __int64 a5, size_t a6)
{
  __int64 v6; // x21

  v6 = *(_QWORD *)(a2 + 152);
  mutex_lock(v6 + 264);
  if ( (tof_enable & 1) != 0 )
  {
    if ( a6 >= 4 )
      a6 = 4;
    memcpy(a4, (const void *)(v6 + 42), a6);
    *(_WORD *)(v6 + 236) = *(_WORD *)(v6 + 42);
  }
  else
  {
    printk(&unk_407C64);
    a6 = -16;
  }
  mutex_unlock(v6 + 264);
  return a6;
}
