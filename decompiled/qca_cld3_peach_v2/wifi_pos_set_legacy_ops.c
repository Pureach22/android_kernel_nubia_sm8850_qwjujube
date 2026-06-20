__int64 __fastcall wifi_pos_set_legacy_ops(__int64 a1, __int64 a2)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  __int64 v5; // x8

  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( !psoc_priv_obj )
    return 16;
  v5 = psoc_priv_obj;
  *(_QWORD *)(v5 + 112) = a2;
  return 0;
}
