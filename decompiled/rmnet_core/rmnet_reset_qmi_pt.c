__int64 __fastcall rmnet_reset_qmi_pt(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 2472) = 0;
  return result;
}
