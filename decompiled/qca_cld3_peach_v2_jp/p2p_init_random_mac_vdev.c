__int64 __fastcall p2p_init_random_mac_vdev(_QWORD *a1)
{
  *((_DWORD *)a1 + 6) = 0;
  a1[4] = 0;
  qdf_mem_set(a1 + 5, 0xD8u, 0);
  *((_BYTE *)a1 + 48) = 0;
  a1[5] = a1;
  a1[29] = a1 + 29;
  a1[30] = a1 + 29;
  a1[31] = 0;
  qdf_mc_timer_init((__int64)(a1 + 8), 0, (__int64)p2p_mac_clear_timeout, (__int64)(a1 + 5));
  qdf_mem_set(a1 + 32, 0xD8u, 0);
  *((_BYTE *)a1 + 264) = 0;
  a1[32] = a1;
  a1[56] = a1 + 56;
  a1[57] = a1 + 56;
  a1[58] = 0;
  qdf_mc_timer_init((__int64)(a1 + 35), 0, (__int64)p2p_mac_clear_timeout, (__int64)(a1 + 32));
  qdf_mem_set(a1 + 59, 0xD8u, 0);
  *((_BYTE *)a1 + 480) = 0;
  a1[59] = a1;
  a1[83] = a1 + 83;
  a1[84] = a1 + 83;
  a1[85] = 0;
  qdf_mc_timer_init((__int64)(a1 + 62), 0, (__int64)p2p_mac_clear_timeout, (__int64)(a1 + 59));
  qdf_mem_set(a1 + 86, 0xD8u, 0);
  *((_BYTE *)a1 + 696) = 0;
  a1[86] = a1;
  a1[110] = a1 + 110;
  a1[111] = a1 + 110;
  a1[112] = 0;
  return qdf_mc_timer_init((__int64)(a1 + 89), 0, (__int64)p2p_mac_clear_timeout, (__int64)(a1 + 86));
}
