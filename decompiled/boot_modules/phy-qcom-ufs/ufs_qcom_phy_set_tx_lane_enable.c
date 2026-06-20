__int64 __fastcall ufs_qcom_phy_set_tx_lane_enable(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 + 152);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 416) + 24LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -1243692540 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
