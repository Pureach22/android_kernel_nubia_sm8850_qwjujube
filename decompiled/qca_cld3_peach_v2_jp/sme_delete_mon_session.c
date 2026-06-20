__int64 __fastcall sme_delete_mon_session(__int64 a1, char a2)
{
  __int64 v3; // x0

  v3 = _qdf_mem_malloc(6u, "sme_delete_mon_session", 13220);
  if ( !v3 )
    return 16;
  *(_BYTE *)(v3 + 4) = a2;
  *(_DWORD *)v3 = 398492;
  return umac_send_mb_message_to_mac(v3);
}
