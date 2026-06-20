__int64 __fastcall hal_gen_reo_remap_val_generic_be(int a1, unsigned __int8 *a2)
{
  if ( (a1 | 2) == 2 )
    return *a2
         | (16 * a2[1])
         | (a2[2] << 8)
         | (a2[3] << 12)
         | (a2[4] << 16)
         | (a2[5] << 20)
         | (a2[6] << 24)
         | (a2[7] << 28);
  else
    return 0;
}
