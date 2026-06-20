__int64 __fastcall wlan_cfg_set_tso_desc_attach_defer(__int64 result, char a2)
{
  *(_BYTE *)(result + 713) = a2;
  return result;
}
