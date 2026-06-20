__int64 __fastcall aw9620x_update_reg_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v7) )
  {
    mutex_lock(&aw_update_lock);
    if ( v7 == 1 )
    {
      if ( !*(_BYTE *)(v5 - 51) )
      {
        disable_irq(*(unsigned int *)(v5 - 28));
        *(_BYTE *)(v5 - 51) = 1;
      }
      aw9620x_load_def_reg_bin(v5 - 56);
      if ( *(_BYTE *)(v5 - 51) == 1 )
      {
        enable_irq(*(unsigned int *)(v5 - 28));
        *(_BYTE *)(v5 - 51) = 0;
      }
    }
    mutex_unlock(&aw_update_lock);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
