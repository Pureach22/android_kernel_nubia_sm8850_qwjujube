__int64 __fastcall sub_3AB3C4(int a1, int a2, __int64 a3, int a4, int a5)
{
  unsigned __int16 *v5; // x27
  int v6; // w2

  v6 = atomic_load(v5);
  return lim_populate_mac_header(a1, a2, v6, a4, a5);
}
