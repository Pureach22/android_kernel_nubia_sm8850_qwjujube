__int64 __fastcall rmnet_get_qmi_pt(__int64 result)
{
  if ( result )
    return *(_QWORD *)(result + 2472);
  return result;
}
