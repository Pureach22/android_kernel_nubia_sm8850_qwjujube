__int64 __fastcall sub_6203DC(__int64 a1, __int64 a2)
{
  if ( (a1 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x6236B0);
  return cm_add_fw_roam_cmd_to_list_n_ser(a1, a2);
}
