__int64 __fastcall sub_866B0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, _QWORD *a7)
{
  atomic_uint *v7; // x9
  __int64 v8; // d8
  __int64 v9; // d14

  atomic_fetch_add_explicit(v7, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  *a7 = v8;
  a7[1] = v9;
  return wiphy_dev_release(a1, a2, a3, a4, a5, a6, a7 + 3);
}
