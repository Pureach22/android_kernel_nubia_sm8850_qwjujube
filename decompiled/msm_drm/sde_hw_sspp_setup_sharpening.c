__int64 __fastcall sde_hw_sspp_setup_sharpening(__int64 result, unsigned int *a2)
{
  __int64 v2; // x8
  int v3; // w20
  __int64 v5; // x19

  if ( result && a2 )
  {
    v2 = *(_QWORD *)(result + 56);
    v3 = *(_DWORD *)(*(_QWORD *)(v2 + 48) + 100LL);
    if ( (*(_QWORD *)(v2 + 32) & 4) != 0 )
    {
      v5 = result;
      sde_reg_write(result, v3 + 48, *a2, "VIG_0_QSEED2_SHARP + idx");
      sde_reg_write(v5, v3 + 52, a2[1], "VIG_0_QSEED2_SHARP + idx + 0x4");
      sde_reg_write(v5, v3 + 56, a2[2], "VIG_0_QSEED2_SHARP + idx + 0x8");
      return sde_reg_write(v5, v3 + 60, a2[3], "VIG_0_QSEED2_SHARP + idx + 0xC");
    }
  }
  return result;
}
