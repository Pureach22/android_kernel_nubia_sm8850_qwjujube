__int64 __fastcall sde_hdcp_1x_deinit(_QWORD *a1)
{
  if ( !a1 )
    return printk(&unk_255B25, "sde_hdcp_1x_deinit");
  if ( a1[179] )
    destroy_workqueue();
  hdcp1_deinit(a1[181]);
  kfree(a1[180]);
  return kfree(a1);
}
