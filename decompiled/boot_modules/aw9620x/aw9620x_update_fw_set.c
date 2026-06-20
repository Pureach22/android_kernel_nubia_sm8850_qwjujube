__int64 __fastcall aw9620x_update_fw_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w8
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v8) )
  {
    mutex_lock(&aw_update_lock);
    if ( v8 == 1 )
    {
      v6 = *(unsigned __int8 *)(v5 - 51);
      *(_BYTE *)(v5 - 53) = 0;
      *(_BYTE *)(v5 - 49) = 1;
      if ( !v6 )
      {
        disable_irq(*(unsigned int *)(v5 - 28));
        *(_BYTE *)(v5 - 51) = 1;
      }
      aw9620x_load_frimware_work(v5 - 56);
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
