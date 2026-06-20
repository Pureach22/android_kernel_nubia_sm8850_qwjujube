__int64 __fastcall ufs_qcom_phy_save_controller_version(__int64 result, char a2, __int16 a3, __int16 a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(result + 152);
  *(_BYTE *)(v4 + 360) = a2;
  *(_WORD *)(v4 + 362) = a3;
  *(_WORD *)(v4 + 364) = a4;
  return result;
}
