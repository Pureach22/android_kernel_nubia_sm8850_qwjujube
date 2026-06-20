__int64 __fastcall sde_hw_sspp_set_src_split_order(__int64 result, unsigned int a2, char a3)
{
  __int64 v4; // x20
  int v5; // w21
  int v6; // w22
  int v7; // w9
  int v8; // w8

  if ( result )
  {
    v4 = result;
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a2 >= 2 )
      v6 = 380;
    else
      v6 = 56;
    v7 = sde_reg_read(result, v5 + v6) & 0xFFFFFFEF;
    if ( (a3 & 1) != 0 )
      v8 = 16;
    else
      v8 = 0;
    return sde_reg_write(v4, v5 + v6, v7 | (unsigned int)v8, "op_mode_off + idx");
  }
  return result;
}
