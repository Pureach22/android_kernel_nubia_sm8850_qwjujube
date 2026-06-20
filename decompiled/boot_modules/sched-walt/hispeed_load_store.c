__int64 __fastcall hispeed_load_store(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w8

  if ( (unsigned int)kstrtouint(a2, 10, a1 + 176) )
    return -22;
  v5 = *(_DWORD *)(a1 + 176);
  if ( v5 >= 0x64 )
    v5 = 100;
  *(_DWORD *)(a1 + 176) = v5;
  return a3;
}
