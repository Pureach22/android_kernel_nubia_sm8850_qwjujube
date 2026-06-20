unsigned __int64 __fastcall ufs_qcom_phy_get_reset(__int64 a1)
{
  unsigned __int64 result; // x0

  if ( *(_QWORD *)(a1 + 464) )
    return 0;
  result = _devm_reset_control_get(*(_QWORD *)(a1 + 16), 0, 0, 0, 0, 1);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 464) = result;
    return 0;
  }
  return result;
}
