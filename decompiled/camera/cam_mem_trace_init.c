void cam_mem_trace_init()
{
  dword_2FDB40 = 0;
  g_trace = (__int64)&g_trace;
  qword_2FDB28 = (__int64)&g_trace;
  qword_2FDB30 = (__int64)&qword_2FDB30;
  qword_2FDB38 = (__int64)&qword_2FDB30;
  qword_2FDB48 = 0;
  dword_2FDB50 = 0;
  byte_2FDB54 = 0;
  mem_trace_en = 0;
}
