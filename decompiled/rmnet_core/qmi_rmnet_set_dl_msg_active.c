__int64 __fastcall qmi_rmnet_set_dl_msg_active(__int64 a1)
{
  __int64 result; // x0

  result = rmnet_get_qmi_pt(a1);
  if ( result )
    *(_BYTE *)(result + 73) = 1;
  return result;
}
