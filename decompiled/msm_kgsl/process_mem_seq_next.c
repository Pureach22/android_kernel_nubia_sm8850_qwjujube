__int64 __fastcall process_mem_seq_next(__int64 a1, __int64 a2, _QWORD *a3)
{
  ++*a3;
  return process_mem_seq_find(a1, a2);
}
