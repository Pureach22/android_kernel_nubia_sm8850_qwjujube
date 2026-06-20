__int64 __fastcall qmi_rmnet_set_powersave_mode(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 qmi_pt; // x0
  __int64 v8; // x0
  unsigned int v9; // w0
  unsigned int v11; // w19

  qmi_pt = rmnet_get_qmi_pt(a1);
  if ( !qmi_pt )
    return 4294967274LL;
  v8 = *(_QWORD *)(qmi_pt + 8);
  if ( !v8 )
    return 4294967274LL;
  v9 = wda_set_powersave_mode(v8, a2, a3, a4);
  if ( (v9 & 0x80000000) == 0 )
    return 0;
  v11 = v9;
  printk(&unk_2CD5B, "qmi_rmnet_set_powersave_mode");
  return v11;
}
