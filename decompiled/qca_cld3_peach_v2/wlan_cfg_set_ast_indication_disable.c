__int64 __fastcall wlan_cfg_set_ast_indication_disable(__int64 result, char a2)
{
  *(_BYTE *)(result + 824) = a2;
  return result;
}
