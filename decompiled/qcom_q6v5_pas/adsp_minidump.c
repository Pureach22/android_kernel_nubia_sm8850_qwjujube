__int64 __fastcall adsp_minidump(__int64 result)
{
  if ( *(_DWORD *)(result + 976) )
    return qcom_minidump();
  return result;
}
