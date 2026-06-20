__int64 ipa_ssr_driver_dump_init()
{
  _mutex_init(&region_list_mutex, "&region_list_mutex", &ipa_ssr_driver_dump_init___key);
  num_of_regions_registered = 0;
  memset(&dump_entry_list, 0, 0x4B00u);
  dmesg_buf = 0;
  qword_1FDBA8 = 0;
  qword_1FDBB0 = 0;
  qword_1FDBB8 = 0;
  qword_1FDBC0 = 0;
  qword_1FDBC8 = 0;
  qword_1FDBD0 = 0;
  qword_1FDBD8 = 0;
  ipc_buf = 0;
  qword_1FDBE8 = 0;
  qword_1FDBF0 = 0;
  qword_1FDBF8 = 0;
  qword_1FDC00 = 0;
  qword_1FDC08 = 0;
  qword_1FDC10 = 0;
  qword_1FDC18 = 0;
  qword_1FDC20 = 0;
  qword_1FDC28 = 0;
  qword_1FDC30 = 0;
  qword_1FDC38 = 0;
  qword_1FDC40 = 0;
  qword_1FDC48 = 0;
  return 0;
}
