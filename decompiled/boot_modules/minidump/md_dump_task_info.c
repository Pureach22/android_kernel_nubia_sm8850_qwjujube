__int64 __fastcall md_dump_task_info(__int64 a1, const char *a2, __int64 a3)
{
  int i; // w24
  int v7; // w3

  for ( i = md_align_offset; i; --i )
    seq_buf_printf(md_runq_seq_buf, " | ");
  seq_buf_printf(md_runq_seq_buf, " |--");
  if ( !a1 )
    return seq_buf_printf(md_runq_seq_buf, "%s : None(0)\n", a2);
  v7 = *(_DWORD *)(a1 + 1800);
  if ( a1 == a3 )
    return seq_buf_printf(md_runq_seq_buf, "[status: curr] pid: %d preempt: %#llx\n", v7, *(_QWORD *)(a1 + 16));
  else
    return seq_buf_printf(md_runq_seq_buf, "[status: %s] pid: %d\n", a2, v7);
}
