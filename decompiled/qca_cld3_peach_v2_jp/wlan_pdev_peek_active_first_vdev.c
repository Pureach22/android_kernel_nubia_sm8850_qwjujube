_QWORD *__fastcall wlan_pdev_peek_active_first_vdev(__int64 a1, unsigned int a2)
{
  return wlan_pdev_vdev_list_peek_active_head(a1, (_QWORD *)(a1 + 48), a2);
}
