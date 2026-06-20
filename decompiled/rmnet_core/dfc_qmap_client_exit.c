__int64 __fastcall dfc_qmap_client_exit(__int64 a1)
{
  __int64 v3; // x0
  __int64 v4; // x1

  if ( !a1 )
    return printk(&unk_2C6B1, "dfc_qmap_client_exit");
  v3 = rmnet_qmap_exit();
  *(_DWORD *)(a1 + 432) = 1;
  qmap_dfc_data = 0;
  synchronize_rcu(v3);
  kfree(a1);
  return printk(&unk_2D423, v4);
}
