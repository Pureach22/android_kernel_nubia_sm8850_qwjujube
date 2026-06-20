__int64 __fastcall rmnet_ctl_send_ipa(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  __int64 v5; // x8
  unsigned int v6; // w19

  raw_spin_lock_bh(a1 + 52);
  v4 = ipa_rmnet_ctl_xmit(a2);
  v5 = 32;
  if ( !v4 )
    v5 = 24;
  v6 = v4;
  ++*(_QWORD *)(a1 + v5);
  raw_spin_unlock_bh(a1 + 52);
  return v6;
}
