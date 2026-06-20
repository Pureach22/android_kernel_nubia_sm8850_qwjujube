__int64 __fastcall reg_get_ignore_fw_reg_offload_ind(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  char v10; // w8

  psoc_obj = reg_get_psoc_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_obj )
    v10 = *(_BYTE *)(psoc_obj + 91149);
  else
    v10 = 0;
  return v10 & 1;
}
