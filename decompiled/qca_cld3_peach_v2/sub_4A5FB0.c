double __fastcall sub_4A5FB0(__int64 a1, __int64 a2)
{
  __asm { PRFM            #0x1C, locret_415F34 }
  return csr_convert_mode_to_nw_type(a1, a2);
}
