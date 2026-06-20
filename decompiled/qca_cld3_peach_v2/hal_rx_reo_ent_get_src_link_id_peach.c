__int64 __fastcall hal_rx_reo_ent_get_src_link_id_peach(__int64 a1, _BYTE *a2)
{
  char v2; // w8

  v2 = *(_BYTE *)(a1 + 30);
  *a2 = v2 & 7;
  return 0;
}
