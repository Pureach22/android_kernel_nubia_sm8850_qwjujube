__int64 __fastcall qmi_rmnet_has_dfc_client(__int64 result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 24);
    if ( !result )
      return *(_QWORD *)(v1 + 32);
  }
  return result;
}
