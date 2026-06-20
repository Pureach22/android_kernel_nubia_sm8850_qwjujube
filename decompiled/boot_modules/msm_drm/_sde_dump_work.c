__int64 sde_dump_work()
{
  __int64 result; // x0

  result = sde_dump_array(byte_294378, (__int64)"evtlog_workitem", byte_2945A0, qword_294598);
  if ( (dword_29437C & 8) != 0 )
  {
    result = dev_coredumpm_timeout(
               qword_2942C8,
               &_this_module,
               &sde_dbg_base,
               0,
               3264,
               sde_devcoredump_read,
               sde_devcoredump_free,
               75000);
    LOBYTE(word_294380) = 1;
  }
  return result;
}
