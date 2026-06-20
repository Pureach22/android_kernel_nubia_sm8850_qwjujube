void __fastcall cpu_mpam_switch_task(__int64 a1, __int64 a2, char *a3)
{
  _BYTE *v3; // x8
  unsigned __int64 v4; // x8

  v3 = &vendor_data_pad;
  if ( a3 != (char *)&init_task )
    v3 = a3 + 5184;
  v4 = (unsigned __int8)(v3[385] + 16) | ((unsigned __int64)(unsigned __int8)(v3[385] + 16) << 16);
  _WriteStatusReg(MPAM0_EL1, v4);
  _WriteStatusReg(MPAM1_EL1, v4);
}
