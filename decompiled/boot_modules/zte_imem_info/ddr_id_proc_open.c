__int64 __fastcall ddr_id_proc_open(__int64 a1, __int64 a2)
{
  return single_open(a2, ddr_id_read_proc, 0);
}
