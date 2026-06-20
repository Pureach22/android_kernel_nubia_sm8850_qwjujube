__int64 __fastcall sde_hw_sspp_update_multirect(__int64 result, char a2, int a3, int a4)
{
  int v5; // w22
  __int64 v8; // x23
  int v9; // w0
  int v10; // w8
  unsigned int v11; // w2

  if ( result )
  {
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a3 )
    {
      v8 = result;
      v9 = sde_reg_read(result, v5 + 368);
      v10 = v9 | a3;
      if ( (a2 & 1) == 0 )
        v10 = v9 & ~a3;
      if ( a4 == 2 && (a2 & 1) != 0 )
        v11 = v10 | 4;
      else
        v11 = v10 & 0xFFFFFFFB;
      result = v8;
    }
    else
    {
      v11 = 0;
    }
    return sde_reg_write(result, v5 + 368, v11, "SSPP_MULTIRECT_OPMODE + idx");
  }
  return result;
}
