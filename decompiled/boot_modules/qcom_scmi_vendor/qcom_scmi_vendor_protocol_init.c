__int64 __fastcall qcom_scmi_vendor_protocol_init(__int64 a1)
{
  __int64 (*v2)(void); // x8
  unsigned int v3; // w0
  __int64 v4; // x1
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v2 = **(__int64 (***)(void))(a1 + 8);
  if ( *((_DWORD *)v2 - 1) != 895999316 )
    __break(0x8228u);
  v3 = v2();
  if ( v3 == -110 )
    v4 = 4294966779LL;
  else
    v4 = v3;
  if ( (_DWORD)v4 )
    result = dev_err_probe(*(_QWORD *)a1, v4, "Unable to get version\n");
  else
    result = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
