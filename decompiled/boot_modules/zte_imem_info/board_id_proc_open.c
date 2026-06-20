__int64 __fastcall board_id_proc_open(__int64 a1, __int64 a2)
{
  return single_open(a2, board_id_read_proc, 0);
}
