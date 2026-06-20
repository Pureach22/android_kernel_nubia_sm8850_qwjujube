__int64 __fastcall sme_create_mon_session(__int64 a1, const void *a2, char a3)
{
  __int64 v5; // x0
  __int64 v6; // x20

  v5 = _qdf_mem_malloc(0xCu, "sme_create_mon_session", 13204);
  if ( !v5 )
    return 16;
  *(_BYTE *)(v5 + 4) = a3;
  v6 = v5;
  *(_DWORD *)v5 = 791678;
  qdf_mem_copy((void *)(v5 + 5), a2, 6u);
  return umac_send_mb_message_to_mac(v6);
}
