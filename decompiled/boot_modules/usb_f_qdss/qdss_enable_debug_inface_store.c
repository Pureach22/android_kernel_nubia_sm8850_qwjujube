__int64 __fastcall qdss_enable_debug_inface_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x1
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 176);
  v7[0] = 0;
  if ( a2 )
  {
    if ( (unsigned int)kstrtou8(a2, 0, v7) && v7[0] >= 2u )
    {
      printk(&unk_7F60, v7[0]);
    }
    else
    {
      v5 = raw_spin_lock_irqsave(v4 + 456);
      *(_BYTE *)(v4 + 280) = v7[0] != 0;
      raw_spin_unlock_irqrestore(v4 + 456, v5);
    }
  }
  else
  {
    printk(&unk_8469, 0);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
