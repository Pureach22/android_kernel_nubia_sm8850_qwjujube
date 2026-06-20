__int64 __fastcall dfs_update_cur_chan_flags(__int64 result, __int64 a2, __int16 a3)
{
  *(_QWORD *)(*(_QWORD *)(result + 14888) + 8LL) = a2;
  *(_WORD *)(*(_QWORD *)(result + 14888) + 16LL) = a3;
  return result;
}
