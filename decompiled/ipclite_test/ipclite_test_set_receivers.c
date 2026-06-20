__int64 ipclite_test_set_receivers()
{
  unsigned int v0; // w8

  v0 = qword_B688;
  if ( (unsigned int)(qword_B688 - 512) <= 0xFFFFFE00 )
  {
    printk(&unk_B572, "ipclite_test", "ipclite_test_set_receivers");
    v0 = 1;
    LODWORD(qword_B688) = 1;
  }
  LODWORD(qword_B69C) = _sw_hweight64(v0);
  return printk(&unk_A534, "ipclite_test", "ipclite_test_set_receivers");
}
