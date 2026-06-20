__int64 __fastcall dp_rx_pdev_mon_desc_pool_free(__int64 a1)
{
  ((void (__fastcall *)(__int64, _QWORD))dp_rx_pdev_mon_cmn_desc_pool_free)(a1, 0);
  return ((__int64 (__fastcall *)(__int64, __int64))dp_rx_pdev_mon_cmn_desc_pool_free)(a1, 1);
}
