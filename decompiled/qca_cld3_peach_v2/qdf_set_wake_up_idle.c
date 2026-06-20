__int64 __fastcall qdf_set_wake_up_idle(__int64 result)
{
  char *StatusReg; // x8
  bool v2; // zf
  char *v3; // x10
  _BYTE *v4; // x8

  StatusReg = (char *)_ReadStatusReg(SP_EL0);
  v2 = StatusReg == (char *)&init_task;
  v3 = StatusReg + 5184;
  v4 = &vendor_data_pad;
  if ( !v2 )
    v4 = v3;
  v4[188] = result;
  return result;
}
