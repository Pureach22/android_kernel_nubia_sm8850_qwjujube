__int64 __fastcall sde_hw_sspp_setup_qos_ctrl(__int64 result, __int64 a2)
{
  int v2; // w9

  if ( result )
  {
    if ( *(_BYTE *)(a2 + 24) == 1 )
      v2 = (unsigned __int8)(16 * (*(_BYTE *)(a2 + 20) & 3)) | ((*(_DWORD *)(a2 + 16) & 3) << 20) | 0x10000;
    else
      v2 = 0;
    return sde_reg_write(
             result,
             *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + 108,
             v2 | (unsigned int)*(unsigned __int8 *)(a2 + 25),
             "SSPP_QOS_CTRL + idx");
  }
  return result;
}
