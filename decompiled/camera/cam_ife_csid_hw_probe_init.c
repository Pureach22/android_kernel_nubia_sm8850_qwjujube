__int64 __fastcall cam_ife_csid_hw_probe_init(__int64 a1, __int64 a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 == 512 )
    return cam_ife_csid_hw_ver2_init(a1);
  if ( v2 == 256 )
    return cam_ife_csid_hw_ver1_init(a1);
  return 4294967274LL;
}
