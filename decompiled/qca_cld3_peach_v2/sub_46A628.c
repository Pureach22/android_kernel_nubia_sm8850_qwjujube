__int64 __fastcall sub_46A628(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int16 v5; // w22
  atomic_ushort *v6; // x29

  atomic_fetch_add_explicit(v6, v5, memory_order_relaxed);
  return pld_get_user_msi_assignment(a1, a2, a3, a4, a5);
}
