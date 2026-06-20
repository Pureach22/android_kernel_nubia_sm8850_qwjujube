__int64 __fastcall sde_hw_sspp_setup_uidle(__int64 result, _DWORD *a2, int a3)
{
  __int64 v4; // x20
  int v5; // w21
  int v6; // w22
  int v7; // w0

  if ( result )
  {
    v4 = result;
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a3 == 2 )
      v6 = 500;
    else
      v6 = 496;
    v7 = sde_reg_read(result, v5 + v6);
    return sde_reg_write(
             v4,
             v5 + v6,
             v7 & 0x7000F0F0
           | ((unsigned __int8)(*a2 == 0) << 31)
           | (a2[1] << 20)
           | (a2[2] << 16)
           | (a2[3] << 8)
           | a2[4],
             "offset + idx");
  }
  return result;
}
