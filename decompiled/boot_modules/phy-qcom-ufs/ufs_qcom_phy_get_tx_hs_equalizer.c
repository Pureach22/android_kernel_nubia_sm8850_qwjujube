__int64 __fastcall ufs_qcom_phy_get_tx_hs_equalizer(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 (*v3)(void); // x8

  v3 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 416LL) + 56LL);
  if ( !v3 )
    return 4294967201LL;
  if ( *((_DWORD *)v3 - 1) != -181711763 )
    __break(0x8228u);
  *a3 = v3();
  return 0;
}
