__int64 __fastcall target_if_get_combrssi_sec80_seg_gen2(__int64 a1, __int64 a2)
{
  __int64 v2; // x10
  unsigned int v3; // w10

  v2 = *(unsigned int *)(a1 + 1184);
  if ( (unsigned int)v2 > 4 )
    v3 = 56;
  else
    v3 = dword_B2F030[v2];
  return *(_DWORD *)(a2 + 20) - *(_DWORD *)(a2 + 12) + v3;
}
