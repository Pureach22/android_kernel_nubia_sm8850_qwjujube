void osif_request_manager_init()
{
  if ( (is_initialized & 1) == 0 )
  {
    requests = (__int64)&requests;
    qword_7CF300 = (__int64)&requests;
    qword_7CF308 = 0x1400000000LL;
    spinlock = 0;
    qword_7CF2E8 = 0;
    is_initialized = 1;
  }
}
