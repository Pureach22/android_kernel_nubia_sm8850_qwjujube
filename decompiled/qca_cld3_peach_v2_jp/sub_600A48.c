// positive sp value has been detected, the output may be wrong!
__int64 sub_600A48()
{
  __int64 v0; // x19
  void (__fastcall *v1)(__int64, __int64); // x20
  unsigned int v2; // w21
  __int64 v3; // x22
  int v4; // w25
  int v5; // w30

  if ( v5 )
    return cfr_free_pending_dbr_events();
  while ( 1 )
  {
    --v4;
    if ( v2 <= 0x3FE )
      ++v2;
    else
      v2 = 0;
    if ( !v4 )
      break;
    if ( v2 >= 0x401 )
      goto LABEL_17;
    if ( v2 == 1024 )
    {
      __break(1u);
LABEL_17:
      __break(0x5512u);
      JUMPOUT(0x5510AC);
    }
    if ( *((_DWORD *)v1 - 1) != 1872960511 )
      __break(0x8234u);
    v1(v0, v3);
  }
  if ( (qword_863100 & 1) == 0 )
    return raw_spin_unlock(&g_htc_credit_lock);
  qword_863100 &= ~1uLL;
  return raw_spin_unlock_bh(&g_htc_credit_lock);
}
