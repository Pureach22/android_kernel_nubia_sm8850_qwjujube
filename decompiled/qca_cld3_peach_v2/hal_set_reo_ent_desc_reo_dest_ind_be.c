__int64 __fastcall hal_set_reo_ent_desc_reo_dest_ind_be(__int64 result, char a2)
{
  *(_DWORD *)(result + 20) |= (a2 & 0x1F) << 22;
  return result;
}
