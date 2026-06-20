__int64 __fastcall dot11f_unpack_ie_wsc_probe_req(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, _BYTE *a4)
{
  *a4 = 1;
  return unpack_tlv_core(a2, a3, (unsigned int *)&TLVS_WscProbeReq, (__int64)a4);
}
