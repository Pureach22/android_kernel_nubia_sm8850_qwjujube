__int64 __fastcall sde_hw_hyp_ctl_cesta_reserve(__int64 result, char a2)
{
  if ( result )
    return sde_reg_write(
             result + 32,
             (unsigned int)((*(_DWORD *)(result + 64) << 7) + 196),
             (unsigned __int8)(1LL << a2),
             "HYP_CTL_CESTA_RESERVE + (ctl_idx * 0x80)");
  return result;
}
