__int64 __fastcall orientation_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21

  v4 = *(_QWORD *)(a1 + 152);
  if ( (sysfs_streq(a3, "A") & 1) != 0 )
  {
    *(_DWORD *)(v4 + 1236) = 4;
  }
  else if ( (sysfs_streq(a3, "B") & 1) != 0 )
  {
    *(_DWORD *)(v4 + 1236) = 8;
  }
  else
  {
    *(_DWORD *)(v4 + 1236) = 0;
  }
  return a4;
}
