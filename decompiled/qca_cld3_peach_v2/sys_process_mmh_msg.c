void __fastcall sys_process_mmh_msg(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int16 *a10)
{
  int v10; // w3
  int v12; // w2

  if ( a10 )
  {
    v10 = *a10;
    if ( v10 == 5121 )
    {
      v12 = 53;
    }
    else if ( (unsigned int)(v10 - 5120) >= 0xB4 )
    {
      qdf_trace_msg(0x37u, 2u, "Message of ID %d is not yet handled by SYS", a1, a2, a3, a4, a5, a6, a7, a8);
      v12 = 55;
    }
    else
    {
      v12 = 52;
    }
    if ( (unsigned int)scheduler_post_message_debug(0x37u, 0x37u, v12, a10, 0xE7u, (__int64)"sys_process_mmh_msg") )
      _qdf_mem_free(*((_QWORD *)a10 + 1));
  }
}
