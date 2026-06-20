__int64 __fastcall sde_hw_sspp_setup_solidfill(__int64 result, unsigned int a2, unsigned int a3)
{
  int v3; // w10
  const char *v4; // x3

  if ( result )
  {
    if ( a3 >= 2 )
      v3 = 384;
    else
      v3 = 60;
    if ( a3 >= 2 )
      v4 = "SSPP_SRC_CONSTANT_COLOR_REC1 + idx";
    else
      v4 = "SSPP_SRC_CONSTANT_COLOR + idx";
    return sde_reg_write(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + v3, a2, v4);
  }
  return result;
}
