__int64 __fastcall dump_trace(__int64 a1, const void *a2)
{
  seq_buf_printf(md_ktask_stack_buf, "%pSb\n", a2);
  return 1;
}
