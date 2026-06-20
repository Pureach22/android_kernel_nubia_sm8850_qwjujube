__int64 __fastcall reg_dmav1_setup_dspp_pccv4(__int64 a1, __int64 a2, double a3, double a4, double a5, double a6)
{
  int v6; // w8

  if ( !*(_QWORD *)a2 )
    return reg_dmav1_setup_dspp_pcc_common(a1, (_QWORD *)a2, a3, a4, a5, a6);
  v6 = *(_DWORD *)(a2 + 8);
  if ( v6 == 144 )
  {
    **(_QWORD **)a2 = 0;
    return reg_dmav1_setup_dspp_pcc_common(a1, (_QWORD *)a2, a3, a4, a5, a6);
  }
  return _drm_err("invalid size of payload len %d exp %zd\n", v6, 0x90u);
}
