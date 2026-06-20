__int64 __fastcall dot11f_get_packed_ht2040_bss_coexistence_mgmt_action_frameSize(__int64 a1, __int64 a2, int *a3)
{
  *a3 = 2;
  return get_packed_size_core(a1, a2, a3, IES_ht2040_bss_coexistence_mgmt_action_frame);
}
