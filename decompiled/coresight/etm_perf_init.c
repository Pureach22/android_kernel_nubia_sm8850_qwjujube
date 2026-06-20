__int64 etm_perf_init()
{
  __int64 result; // x0

  dword_1199C = 48;
  qword_11980 = (__int64)etm_pmu_attr_groups;
  qword_119D8 = (__int64)etm_event_init;
  qword_11A50 = (__int64)etm_setup_aux;
  qword_11A58 = (__int64)etm_free_aux;
  qword_11A08 = (__int64)etm_event_stop;
  qword_11A10 = (__int64)etm_event_read;
  qword_119F0 = (__int64)etm_event_add;
  qword_119F8 = (__int64)etm_event_del;
  qword_11A00 = (__int64)etm_event_start;
  qword_11A68 = (__int64)etm_addr_filters_validate;
  qword_11A70 = (__int64)etm_addr_filters_sync;
  dword_119C4 = 8;
  dword_119BC = 1;
  qword_11968 = (__int64)&_this_module;
  result = perf_pmu_register();
  if ( !(_DWORD)result )
    etm_perf_up = 1;
  return result;
}
