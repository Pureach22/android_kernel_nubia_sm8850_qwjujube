__int64 __fastcall wifi_pos_get_legacy_ops(__int64 a1)
{
  __int64 psoc; // x0
  __int64 result; // x0

  psoc = wifi_pos_get_psoc(a1);
  result = wifi_pos_get_psoc_priv_obj(psoc);
  if ( result )
    return *(_QWORD *)(result + 112);
  return result;
}
