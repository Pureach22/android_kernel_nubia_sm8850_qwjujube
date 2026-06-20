unsigned __int64 _mem_buf_relinquish_mem()
{
  unsigned __int64 result; // x0
  unsigned __int64 v1; // x19
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x21
  int v4; // w20

  result = mem_buf_init_txn(*(_QWORD *)msgqs, 0);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = result;
    v2 = mem_buf_construct_relinquish_msg();
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      v3 = v2;
      v4 = mem_buf_msgq_send(*(_QWORD *)msgqs, v2);
      kfree(v3);
      if ( v4 < 0 )
        printk(&unk_99BD, "__mem_buf_relinquish_mem");
      mem_buf_txn_wait(*(_QWORD *)msgqs, v1);
    }
    return mem_buf_destroy_txn(*(_QWORD *)msgqs, v1);
  }
  return result;
}
