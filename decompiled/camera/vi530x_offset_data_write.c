__int64 __fastcall vi530x_offset_data_write(__int64 a1, __int64 a2, __int64 a3, __int16 *a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x21
  __int16 v9; // w8
  __int64 v10; // x19
  void *v12; // x0

  v6 = *(_QWORD *)(a2 + 152);
  mutex_lock(v6 + 264);
  if ( tof_enable != 1 )
  {
    v10 = -16;
    v12 = &unk_407C64;
LABEL_9:
    printk(v12);
    goto LABEL_6;
  }
  if ( a6 != 4 )
  {
    v10 = -22;
    v12 = &unk_40BE04;
    goto LABEL_9;
  }
  if ( *(_DWORD *)(v6 + 228) )
    printk(&unk_403E29);
  v9 = *a4;
  v10 = 4;
  *(_WORD *)(v6 + 236) = v9;
LABEL_6:
  mutex_unlock(v6 + 264);
  return v10;
}
