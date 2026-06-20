__int64 __fastcall sde_hw_ctl_update_dnsc_blur_bitmask(__int64 result, char a2, char a3)
{
  __int64 v3; // x8
  int v4; // w9
  int v5; // w10
  int v6; // w8

  v3 = 1LL << (a2 + 15);
  v4 = *(_DWORD *)(result + 100);
  v5 = v4 & ~(_DWORD)v3;
  v6 = v4 | v3;
  if ( (a3 & 1) == 0 )
    v6 = v5;
  *(_DWORD *)(result + 100) = v6;
  return result;
}
