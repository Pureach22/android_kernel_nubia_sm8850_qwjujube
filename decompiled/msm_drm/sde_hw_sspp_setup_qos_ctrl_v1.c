__int64 __fastcall sde_hw_sspp_setup_qos_ctrl_v1(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  result = sspp_subblk_offset(a1, 1, &v6);
  if ( !(_DWORD)result )
  {
    if ( *(_BYTE *)(a2 + 24) == 1 )
      v5 = (unsigned __int8)(16 * (*(_BYTE *)(a2 + 20) & 3)) | ((*(_DWORD *)(a2 + 16) & 3) << 20) | 0x10000;
    else
      v5 = 0;
    result = sde_reg_write(a1, v6 + 40, v5 | (unsigned int)*(unsigned __int8 *)(a2 + 25), "SSPP_CMN_QOS_CTRL + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
