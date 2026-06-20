__int64 __fastcall md_dump_cgroup_state(const char *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x24
  int v6; // w21
  int i; // w26
  __int64 v8; // x1
  __int64 v9; // x20
  __int64 result; // x0
  int v11; // w8
  __int64 v12; // x21
  int v13; // w22
  int j; // w21

  if ( a2 )
  {
    v4 = *(_QWORD *)(a2 + 168);
    if ( v4 )
    {
      v6 = *(_DWORD *)(v4 + 16);
      for ( i = md_align_offset; i; --i )
        seq_buf_printf(md_runq_seq_buf, " | ");
      seq_buf_printf(md_runq_seq_buf, " |--");
      seq_buf_printf(md_runq_seq_buf, "%s: %d process is grouping\n", a1, v6);
      v8 = *(_QWORD *)(v4 + 80);
      ++md_align_offset;
      md_dump_cgroup_state("curr", v8, a3);
      md_dump_cgroup_state("next", *(_QWORD *)(v4 + 88), a3);
      v9 = *(_QWORD *)(v4 + 72);
      result = rb_first(v4 + 64);
      if ( v9 && result )
      {
        v11 = -199;
        do
        {
          v12 = result;
          v13 = v11;
          md_dump_cgroup_state("pend", result - 16, a3);
          result = rb_next(v12);
          if ( !result )
            break;
          v11 = v13 + 1;
        }
        while ( v13 );
      }
      --md_align_offset;
    }
    else
    {
      return md_dump_task_info(a2 - 192, a1, a3);
    }
  }
  else
  {
    for ( j = md_align_offset; j; --j )
      seq_buf_printf(md_runq_seq_buf, " | ");
    seq_buf_printf(md_runq_seq_buf, " |--");
    return seq_buf_printf(md_runq_seq_buf, "%s : None(0)\n", a1);
  }
  return result;
}
