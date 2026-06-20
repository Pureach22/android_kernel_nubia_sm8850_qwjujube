bool __fastcall policy_mgr_is_freq_on_mac_id(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  unsigned int *v3; // x8

  v3 = (unsigned int *)(a1 + 16LL * a3);
  if ( *v3 <= a2 && v3[1] >= a2 )
    return 1;
  if ( v3[2] <= a2 )
    return v3[3] >= a2;
  return 0;
}
