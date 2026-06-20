__int64 __fastcall hdcp2_deinit_qseecom(__int64 a1)
{
  if ( a1 )
  {
    kfree_sensitive(*(_QWORD *)(a1 + 104));
    kfree_sensitive(*(_QWORD *)(a1 + 96));
  }
  else
  {
    printk(&unk_C81E);
  }
  return kfree_sensitive(a1);
}
