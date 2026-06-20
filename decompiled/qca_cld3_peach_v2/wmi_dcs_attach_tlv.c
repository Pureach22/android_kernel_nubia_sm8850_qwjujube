__int64 __fastcall wmi_dcs_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[329] = extract_dcs_interference_type_tlv;
  v1[330] = extract_dcs_im_tgt_stats_tlv;
  v1[331] = extract_dcs_awgn_info_tlv;
  return result;
}
