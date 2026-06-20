bool __fastcall policy_mgr_3_freq_same_mac_in_freq_range(
        unsigned int *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int v4; // w8
  unsigned int v5; // w8
  _BOOL8 result; // x0

  v4 = *a1;
  result = true;
  if ( (*a1 > a2 || a1[1] < a2) && (a1[2] > a2 || a1[3] < a2)
    || (v4 > a3 || a1[1] < a3) && (a1[2] > a3 || a1[3] < a3)
    || (v4 > a4 || a1[1] < a4) && (a1[2] > a4 || a1[3] < a4) )
  {
    v5 = a1[4];
    if ( (v5 > a2 || a1[5] < a2) && (a1[6] > a2 || a1[7] < a2) )
      return false;
    if ( (v5 > a3 || a1[5] < a3) && (a1[6] > a3 || a1[7] < a3) || (v5 > a4 || a1[5] < a4) && (a1[6] > a4 || a1[7] < a4) )
      return false;
  }
  return result;
}
