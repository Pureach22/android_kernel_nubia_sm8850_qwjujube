__int64 __fastcall ufs_qcom_phy_dbg_register_save(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 + 152);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 416) + 72LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -36396358 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
