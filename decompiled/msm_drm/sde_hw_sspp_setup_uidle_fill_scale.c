__int64 __fastcall sde_hw_sspp_setup_uidle_fill_scale(__int64 result, __int64 a2)
{
  if ( result )
    return sde_reg_write(
             result,
             *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + 504,
             65793 * (*(_DWORD *)(a2 + 20) & 0xFu),
             "SSPP_FILL_LEVEL_SCALE + idx");
  return result;
}
