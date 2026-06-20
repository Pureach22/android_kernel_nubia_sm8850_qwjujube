__int64 __fastcall sub_7155B8(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  atomic_load_explicit((atomic_uint *volatile)(v2 - 238), memory_order_acquire);
  return ucfg_fwol_update_fw_cap_info(a1, a2);
}
