__int64 __fastcall sme_set_default_scan_ie(__int64 a1, __int16 a2, const void *a3, unsigned __int16 a4)
{
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x22
  unsigned int v11; // w20

  if ( !a3 )
    return 4;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    v9 = _qdf_mem_malloc(0x808u, "sme_set_default_scan_ie", 13686);
    if ( v9 )
    {
      *(_WORD *)(v9 + 4) = a2;
      v10 = v9;
      *(_WORD *)(v9 + 6) = a4;
      *(_DWORD *)v9 = 134747267;
      qdf_mem_copy((void *)(v9 + 8), a3, a4);
      v11 = umac_send_mb_message_to_mac(v10);
    }
    else
    {
      v11 = 2;
    }
    qdf_mutex_release(a1 + 12848);
    return v11;
  }
  return result;
}
