__int64 sub_44F260()
{
  __asm { PRFM            #1, [X10,#0x878] }
  return dot11f_pack_add_ts_response();
}
