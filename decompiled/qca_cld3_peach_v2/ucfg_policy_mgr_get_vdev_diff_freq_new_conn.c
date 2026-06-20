__int64 __fastcall ucfg_policy_mgr_get_vdev_diff_freq_new_conn(__int64 a1, unsigned int a2, _BYTE *a3)
{
  return policy_mgr_get_vdev_diff_freq_new_conn(a1, a2, a3) & 1;
}
