__int64 wbuff_module_init()
{
  unsigned __int64 dir; // x0

  dword_869EE8 = 0;
  qword_869EF0 = 0;
  qword_869F10 = 0;
  qword_869F40 = 0;
  qword_869F70 = 0;
  qword_869FA0 = 0;
  qword_869FD0 = 0;
  qword_86A000 = 0;
  qword_86A030 = 0;
  qword_86A060 = 0;
  qword_86A090 = 0;
  qword_86A0C0 = 0;
  qword_86A0F0 = 0;
  qword_86A120 = 0;
  qword_86A150 = 0;
  qword_86A180 = 0;
  qword_86A1B0 = 0;
  qword_86A1E0 = 0;
  byte_869EE0 = 0;
  dword_86A210 = 0;
  qword_86A218 = 0;
  qword_86A238 = 0;
  qword_86A268 = 0;
  qword_86A298 = 0;
  qword_86A2C8 = 0;
  qword_86A2F8 = 0;
  qword_86A328 = 0;
  qword_86A358 = 0;
  qword_86A388 = 0;
  qword_86A3B8 = 0;
  qword_86A3E8 = 0;
  qword_86A418 = 0;
  qword_86A448 = 0;
  qword_86A478 = 0;
  qword_86A4A8 = 0;
  qword_86A4D8 = 0;
  qword_86A508 = 0;
  byte_86A208 = 0;
  dir = qdf_debugfs_create_dir((unsigned __int64)"wbuff", 0);
  qword_86A548 = dir;
  if ( dir )
    qword_86A550 = qdf_debugfs_create_entry((__int64)"wbuff_stats", 256, dir, 0, (__int64)&wbuff_stats_fops);
  wbuff = 1;
  return 0;
}
