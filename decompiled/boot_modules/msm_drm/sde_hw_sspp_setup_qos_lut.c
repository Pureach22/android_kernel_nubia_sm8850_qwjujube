__int64 __fastcall sde_hw_sspp_setup_qos_lut(__int64 result, unsigned int *a2)
{
  __int64 v3; // x19
  int v4; // w21
  __int64 v5; // x8
  unsigned int v6; // w2
  const char *v7; // x3
  unsigned int v8; // w1

  if ( result )
  {
    v3 = result;
    v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    sde_reg_write(result, v4 + 96, *a2, "SSPP_DANGER_LUT + idx");
    sde_reg_write(v3, v4 + 100, a2[1], "SSPP_SAFE_LUT + idx");
    v5 = *(_QWORD *)(v3 + 56);
    if ( v5 && (*(_QWORD *)(v5 + 40) & 4) != 0 )
    {
      sde_reg_write(v3, v4 + 116, a2[2], "SSPP_CREQ_LUT_0 + idx");
      v6 = a2[3];
      v7 = "SSPP_CREQ_LUT_1 + idx";
      v8 = v4 + 120;
    }
    else
    {
      v6 = a2[2];
      v7 = "SSPP_CREQ_LUT + idx";
      v8 = v4 + 104;
    }
    return sde_reg_write(v3, v8, v6, v7);
  }
  return result;
}
