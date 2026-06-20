__int64 __fastcall qmi_rmnet_ignore_grant(__int64 a1)
{
  __int64 qmi_pt; // x0
  char v2; // w8

  qmi_pt = rmnet_get_qmi_pt(a1);
  if ( qmi_pt )
    v2 = *(_BYTE *)(qmi_pt + 74);
  else
    v2 = 0;
  return v2 & 1;
}
