__int64 __fastcall speed_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v5; // x19
  unsigned int v7; // w8
  __int64 v8; // x9
  int *v9; // x9
  int v10; // w10
  unsigned int v11; // w9
  __int64 v12; // x1

  v4 = *(_QWORD *)(a1 + 152);
  if ( (*(_QWORD *)(v4 + 688) & 1) == 0 )
    return -1;
  v5 = a4;
  if ( (sysfs_streq(a3, "full") & 1) != 0 )
  {
    v7 = 2;
    v8 = *(_QWORD *)(v4 + 40);
    if ( !v8 )
      goto LABEL_14;
  }
  else if ( (sysfs_streq(a3, "high") & 1) != 0 )
  {
    v7 = 3;
    v8 = *(_QWORD *)(v4 + 40);
    if ( !v8 )
      goto LABEL_14;
  }
  else if ( (sysfs_streq(a3, "super") & 1) != 0 )
  {
    v7 = 5;
    v8 = *(_QWORD *)(v4 + 40);
    if ( !v8 )
    {
LABEL_14:
      v9 = (int *)(v4 + 1128);
      goto LABEL_15;
    }
  }
  else
  {
    if ( (sysfs_streq(a3, "ssp") & 1) == 0 )
      return -22;
    v7 = 6;
    v8 = *(_QWORD *)(v4 + 40);
    if ( !v8 )
      goto LABEL_14;
  }
  v9 = (int *)(*(_QWORD *)(v8 + 168) + 1232LL);
LABEL_15:
  v10 = *v9;
  v11 = *(_DWORD *)(v4 + 1132);
  if ( v7 == v10 || v7 > v11 )
  {
    if ( v7 >= v11 )
      *(_DWORD *)(v4 + 1128) = 0;
  }
  else
  {
    v12 = system_wq;
    *(_DWORD *)(v4 + 1128) = v7;
    queue_work_on(32, v12, v4 + 600);
  }
  return v5;
}
