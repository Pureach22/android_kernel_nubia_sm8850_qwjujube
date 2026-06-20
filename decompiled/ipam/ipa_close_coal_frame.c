__int64 __fastcall ipa_close_coal_frame(__int64 *a1)
{
  unsigned int ep_mapping; // w20
  int ep_reg_offset; // w0
  __int64 result; // x0
  int v5; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v6; // [xsp+10h] [xbp-20h]
  int v7; // [xsp+18h] [xbp-18h]
  int v8; // [xsp+1Ch] [xbp-14h]
  _QWORD v9[2]; // [xsp+20h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v7 = 0;
  ep_mapping = ipa_get_ep_mapping(95);
  v8 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x14u )
    ep_reg_offset = ipahal_get_ep_reg_offset(133, ep_mapping);
  else
    ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
  v5 = ep_reg_offset;
  ipahal_get_aggr_force_close_valmask(ep_mapping, v9);
  v6 = v9[0];
  result = ((__int64 (__fastcall *)(__int64, int *, _QWORD))ipahal_construct_imm_cmd)(7, &v5, 0);
  _ReadStatusReg(SP_EL0);
  *a1 = result;
  return result;
}
