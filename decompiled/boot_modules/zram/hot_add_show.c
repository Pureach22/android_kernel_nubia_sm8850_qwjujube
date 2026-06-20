__int64 __fastcall hot_add_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w19

  mutex_lock(&zram_index_mutex);
  v4 = zram_add();
  mutex_unlock(&zram_index_mutex);
  if ( (v4 & 0x80000000) == 0 )
    return (int)scnprintf(a3, 4096, &unk_B398, v4);
  return (int)v4;
}
