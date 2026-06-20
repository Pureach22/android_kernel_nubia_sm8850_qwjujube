__int64 __fastcall sub_17DDB0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return qdf_nbuf_fast_xmit(a1, a2, a3, a4, a5, (char *)wlan_objmgr_get_peer + 2);
}
