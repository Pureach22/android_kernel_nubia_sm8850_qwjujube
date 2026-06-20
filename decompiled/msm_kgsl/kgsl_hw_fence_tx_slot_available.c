bool __fastcall kgsl_hw_fence_tx_slot_available(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w11
  unsigned int v4; // w8
  bool v5; // cf
  unsigned int v6; // w9

  v2 = *(_DWORD *)(qword_17D1F8 + 192);
  v3 = *(_DWORD *)(qword_17D1F8 + 128);
  v4 = *(_DWORD *)(qword_17D1F8 + 80) >> 2;
  v5 = v3 >= v2;
  v6 = v3 - v2;
  if ( v6 == 0 || !v5 )
    v6 += *(_DWORD *)(qword_17D1F8 + 76) >> 2;
  return v4 <= v6 && v6 / v4 - 1 > a2;
}
