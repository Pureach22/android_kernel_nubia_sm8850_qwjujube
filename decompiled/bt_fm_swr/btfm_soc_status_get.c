__int64 __fastcall btfm_soc_status_get(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 72) = (unsigned __int8)bt_soc_enable_status;
  return 1;
}
