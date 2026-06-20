__int64 __fastcall ipa3_write_keep_awake(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x1
  void *v6; // x0
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v8);
  if ( !v4 )
  {
    if ( v8[0] )
    {
      if ( !(unsigned int)ipa_pm_add_dummy_clients((unsigned int)v8[0] - 1) )
        goto LABEL_7;
      v6 = &unk_3A30AB;
    }
    else
    {
      if ( !(unsigned int)ipa_pm_remove_dummy_clients() )
        goto LABEL_7;
      v6 = &unk_3FAC9E;
    }
    printk(v6, v5);
    v3 = -14;
    goto LABEL_7;
  }
  v3 = v4;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v3;
}
