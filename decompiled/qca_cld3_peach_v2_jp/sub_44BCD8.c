double __fastcall sub_44BCD8(__int64 a1, __int64 a2)
{
  __asm { PRFM            #0x1C, loc_3BBC5C }
  return csr_convert_mode_to_nw_type(a1, a2);
}
