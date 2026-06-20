__int64 __fastcall sde_hw_sspp_setup_sourceaddress(__int64 result, unsigned int *a2, int a3)
{
  int v3; // w21
  __int64 v5; // x20
  unsigned int v6; // w2
  unsigned int v7; // w1
  __int64 v8; // x0
  const char *v9; // x3
  __int64 v11; // x19

  if ( result )
  {
    v3 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a3 == 1 )
    {
      v11 = result;
      sde_reg_write(result, v3 + 20, a2[6], "SSPP_SRC0_ADDR + idx");
      v6 = a2[8];
      v9 = "SSPP_SRC2_ADDR + idx";
      v7 = v3 + 28;
    }
    else
    {
      if ( !a3 )
      {
        v5 = result;
        sde_reg_write(result, v3 + 20, a2[6], "SSPP_SRC0_ADDR + idx + i * 0x4");
        sde_reg_write(v5, v3 + 24, a2[7], "SSPP_SRC0_ADDR + idx + i * 0x4");
        sde_reg_write(v5, v3 + 28, a2[8], "SSPP_SRC0_ADDR + idx + i * 0x4");
        v6 = a2[9];
        v7 = v3 + 32;
        v8 = v5;
        v9 = "SSPP_SRC0_ADDR + idx + i * 0x4";
        return sde_reg_write(v8, v7, v6, v9);
      }
      v11 = result;
      sde_reg_write(result, v3 + 24, a2[6], "SSPP_SRC1_ADDR + idx");
      v6 = a2[8];
      v9 = "SSPP_SRC3_ADDR + idx";
      v7 = v3 + 32;
    }
    v8 = v11;
    return sde_reg_write(v8, v7, v6, v9);
  }
  return result;
}
