__int64 __fastcall sde_hw_sspp_setup_secure(__int64 result, unsigned int a2, char a3)
{
  __int64 v4; // x20
  int v5; // w21
  int v6; // w8
  int v7; // w22
  int v8; // w0
  unsigned int v9; // w2

  if ( result )
  {
    v4 = result;
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a2 )
      v6 = 5;
    else
      v6 = 15;
    if ( a2 >= 2 )
      v7 = 10;
    else
      v7 = v6;
    v8 = sde_reg_read(result, v5 + 112);
    if ( (a3 & 1) != 0 )
      v9 = v8 | v7;
    else
      v9 = v8 & ~v7;
    result = sde_reg_write(v4, v5 + 112, v9, "SSPP_SRC_ADDR_SW_STATUS + idx");
    __dsb(0xEu);
  }
  return result;
}
