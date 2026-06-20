void osif_request_manager_init()
{
  if ( (is_initialized & 1) == 0 )
  {
    requests = (__int64)&requests;
    qword_7168D0 = (__int64)&requests;
    qword_7168D8 = 0x1400000000LL;
    spinlock = 0;
    qword_7168B8 = 0;
    is_initialized = 1;
  }
}
