__int64 __fastcall ipa_debugfs_reset_tethering_stats(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w20
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  mutex_lock(ipa3_ctx + 29472);
  v5 = kstrtos8_from_user(a2, a3, 0, v7);
  if ( !v5 )
  {
    if ( v7[0] == -1 )
      ipa_reset_all_teth_stats();
    else
      ((void (*)(void))ipa_reset_all_cons_teth_stats)();
    v5 = a3;
  }
  mutex_unlock(ipa3_ctx + 29472);
  _ReadStatusReg(SP_EL0);
  return v5;
}
