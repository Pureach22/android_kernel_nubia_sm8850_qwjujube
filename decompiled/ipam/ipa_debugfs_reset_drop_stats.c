__int64 __fastcall ipa_debugfs_reset_drop_stats(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  mutex_lock(ipa3_ctx + 29472);
  if ( !(unsigned int)kstrtos8_from_user(a2, a3, 0, v6) )
  {
    if ( v6[0] == -1 )
      ipa_reset_all_drop_stats();
    else
      ipa_reset_drop_stats(v6[0]);
  }
  mutex_unlock(ipa3_ctx + 29472);
  _ReadStatusReg(SP_EL0);
  return a3;
}
