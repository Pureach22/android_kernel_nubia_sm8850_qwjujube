__int64 wbuff_module_init()
{
  unsigned __int64 dir; // x0

  dword_933818 = 0;
  qword_933820 = 0;
  qword_933840 = 0;
  qword_933870 = 0;
  qword_9338A0 = 0;
  qword_9338D0 = 0;
  qword_933900 = 0;
  qword_933930 = 0;
  qword_933960 = 0;
  qword_933990 = 0;
  qword_9339C0 = 0;
  qword_9339F0 = 0;
  qword_933A20 = 0;
  qword_933A50 = 0;
  qword_933A80 = 0;
  qword_933AB0 = 0;
  qword_933AE0 = 0;
  qword_933B10 = 0;
  byte_933810 = 0;
  dword_933B40 = 0;
  qword_933B48 = 0;
  qword_933B68 = 0;
  qword_933B98 = 0;
  qword_933BC8 = 0;
  qword_933BF8 = 0;
  qword_933C28 = 0;
  qword_933C58 = 0;
  qword_933C88 = 0;
  qword_933CB8 = 0;
  qword_933CE8 = 0;
  qword_933D18 = 0;
  qword_933D48 = 0;
  qword_933D78 = 0;
  qword_933DA8 = 0;
  qword_933DD8 = 0;
  qword_933E08 = 0;
  qword_933E38 = 0;
  byte_933B38 = 0;
  dir = qdf_debugfs_create_dir((unsigned __int64)"wbuff", 0);
  qword_933E78 = dir;
  if ( dir )
    qword_933E80 = qdf_debugfs_create_entry((__int64)"wbuff_stats", 256, dir, 0, (__int64)&wbuff_stats_fops);
  wbuff = 1;
  return 0;
}
