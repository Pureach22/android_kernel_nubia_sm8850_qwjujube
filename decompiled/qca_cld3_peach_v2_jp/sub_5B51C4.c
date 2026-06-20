__int64 __fastcall sub_5B51C4(__int64 a1, __int64 a2)
{
  if ( (a1 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x5B8498);
  return cm_add_fw_roam_cmd_to_list_n_ser(a1, a2);
}
