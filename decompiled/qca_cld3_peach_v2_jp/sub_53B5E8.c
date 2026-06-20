__int64 __fastcall sub_53B5E8(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 )
    JUMPOUT(0x5D822C);
  return wmi_extract_dcs_im_tgt_stats(0, a2, a3);
}
