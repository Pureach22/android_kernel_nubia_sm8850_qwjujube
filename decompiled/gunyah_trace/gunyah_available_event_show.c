__int64 __fastcall gunyah_available_event_show(__int64 a1)
{
  seq_printf(a1, "%s%s", (const char *)&unk_75FC, "error");
  seq_printf(a1, "%s%s", " ", "debug");
  seq_printf(a1, "%s%s", " ", "user");
  seq_printf(a1, "%s%s", " ", "trace_log_buffer");
  seq_printf(a1, "%s%s", " ", "log_buffer");
  seq_printf(a1, "%s%s", " ", "info");
  seq_printf(a1, "%s%s", " ", "memdb");
  seq_printf(a1, "%s%s", " ", "profile_level1");
  seq_printf(a1, "%s%s", " ", "profile_level2");
  seq_printf(a1, "%s%s", " ", "psci");
  seq_printf(a1, "%s%s", " ", "vgic");
  seq_printf(a1, "%s%s", " ", "vgic_debug");
  seq_printf(a1, "%s%s", " ", "wait_queue");
  seq_putc(a1, 10);
  return 0;
}
