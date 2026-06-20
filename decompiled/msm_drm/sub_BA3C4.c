__int64 sub_BA3C4()
{
  __asm { PRFM            #0xE, loc_D9710 }
  return hfi_kms_get_plane_indices();
}
