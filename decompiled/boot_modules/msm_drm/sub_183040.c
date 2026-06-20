__int64 __fastcall sub_183040(__int64 a1)
{
  atomic_uint *v1; // x12

  atomic_fetch_or_explicit(v1, a1, memory_order_release);
  return sde_hw_ctl_intf_cfg(a1);
}
