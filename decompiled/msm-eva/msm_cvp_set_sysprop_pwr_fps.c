__int64 __fastcall msm_cvp_set_sysprop_pwr_fps(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w8

  v2 = *a2 - 30;
  if ( v2 > 0x12 || ((0x4924Fu >> v2) & 1) == 0 )
    return 4294967282LL;
  *(_DWORD *)((char *)*(&off_6AC50 + v2) + a1) = a2[1];
  return 0;
}
