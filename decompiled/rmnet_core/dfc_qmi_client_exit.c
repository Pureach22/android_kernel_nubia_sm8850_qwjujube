__int64 __fastcall dfc_qmi_client_exit(__int64 a1)
{
  if ( !a1 )
    return printk(&unk_2C6B1, "dfc_qmi_client_exit");
  *(_DWORD *)(a1 + 432) = 1;
  qmi_handle_release(a1 + 48);
  drain_workqueue(*(_QWORD *)(a1 + 8));
  destroy_workqueue(*(_QWORD *)(a1 + 8));
  return kfree(a1);
}
