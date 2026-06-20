void _qdf_minidump_init()
{
  if ( (qdf_va_md_initialized & 1) == 0 )
  {
    qdf_va_md_list_lock = 0;
    qword_76D270 = 0;
    qdf_va_md_list = (__int64)&qdf_va_md_list;
    qword_76D280 = (__int64)&qdf_va_md_list;
    qword_76D288 = 0x8000000000LL;
    qdf_va_md_initialized = (unsigned int)qcom_va_md_register("peach_v2", &qdf_va_md_notif_blk) == 0;
  }
}
