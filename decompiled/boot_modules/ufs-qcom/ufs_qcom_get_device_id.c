__int64 __fastcall ufs_qcom_get_device_id(__int64 result)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(result + 174) == 6 && *(_WORD *)(result + 172) == 2 )
  {
    v1 = result;
    result = readl((unsigned int *)(**(_QWORD **)(result + 16) + 10316LL));
    *(_DWORD *)(v1 + 3196) = (unsigned __int16)((unsigned int)result >> 8);
  }
  return result;
}
