__int64 __fastcall ucfg_policy_mgr_get_vdev_same_freq_new_conn(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned __int8 *a4)
{
  return policy_mgr_get_vdev_same_freq_new_conn(a1, a2, a3, a4) & 1;
}
