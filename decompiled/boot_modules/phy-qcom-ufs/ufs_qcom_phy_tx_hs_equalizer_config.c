__int64 __fastcall ufs_qcom_phy_tx_hs_equalizer_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  void (__fastcall *v3)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 416) + 48LL);
  if ( !v3 )
    return 4294967201LL;
  if ( (*(_BYTE *)(v2 + 460) & 1) != 0 )
    return 0;
  if ( *((_DWORD *)v3 - 1) != -36396358 )
    __break(0x8228u);
  v3(v2, a2);
  return 0;
}
