__int64 __fastcall wda_qmi_client_exit(__int64 a1)
{
  if ( !a1 )
    return printk(&unk_2CF4B, "wda_qmi_client_exit");
  *(_DWORD *)(a1 + 376) = 1;
  destroy_workqueue(*(_QWORD *)(a1 + 8));
  return kfree(a1);
}
