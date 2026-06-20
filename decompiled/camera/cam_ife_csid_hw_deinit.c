__int64 __fastcall cam_ife_csid_hw_deinit(__int64 a1, __int64 a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 == 512 )
    return cam_ife_csid_hw_ver2_deinit(*(_QWORD *)(a1 + 112));
  if ( v2 == 256 )
    return cam_ife_csid_hw_ver1_deinit(*(_QWORD *)(a1 + 112));
  return 4294967274LL;
}
