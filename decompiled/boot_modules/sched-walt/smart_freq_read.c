__int64 __fastcall smart_freq_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v7; // x22
  unsigned int v8; // w26
  int v9; // w0
  __int64 v10; // x4
  __int64 result; // x0
  _BYTE s[1024]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v13; // [xsp+408h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( num_sched_clusters < 1 )
  {
    v10 = 0;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    do
    {
      if ( v7 > 7 || v8 >= 0x401 )
        __break(0x5512u);
      v9 = scnprintf(
             &s[v8],
             1024,
             "%d: cluster_active_reason 0x%x\n",
             v7,
             *(_DWORD *)(*(_QWORD *)(sched_cluster[v7] + 480) + 4LL));
      ++v7;
      v8 += v9;
    }
    while ( (__int64)v7 < num_sched_clusters );
    v10 = (int)v8;
  }
  result = simple_read_from_buffer(a2, a3, a4, s, v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
