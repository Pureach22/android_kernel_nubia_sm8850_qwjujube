__int64 __fastcall gsi_get_fw_version(int *a1)
{
  unsigned int reg_nk; // w8
  __int64 result; // x0

  if ( a1 )
  {
    reg_nk = gsihal_read_reg_nk(122, (unsigned __int8)(*(_DWORD *)(gsi_ctx + 16) > 9u) << 6, 0);
    result = 0;
    a1[2] = reg_nk & 0x7F;
    *a1 = (unsigned __int16)reg_nk >> 10;
    a1[1] = (reg_nk >> 7) & 7;
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad parms: ver == NULL\n", "gsi_get_fw_version", 5911);
    return 4294967274LL;
  }
  return result;
}
