__int64 __fastcall ucfg_p2p_check_random_mac(__int64 a1, __int64 a2, const void *a3)
{
  return p2p_check_random_mac(a1, a2, a3) & 1;
}
