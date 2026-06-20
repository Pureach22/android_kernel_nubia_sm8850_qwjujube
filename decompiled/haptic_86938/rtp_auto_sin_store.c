__int64 __fastcall rtp_auto_sin_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  unsigned int v7; // w4
  __int64 v8; // x0
  __int64 v9; // x3
  int v11; // w20
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  v6 = kstrtouint(a3, 0, &v12);
  if ( v6 < 0 )
  {
    v11 = v6;
    printk(&unk_162DB, "haptic_hv", 2269, "rtp_auto_sin_store");
    a4 = v11;
    goto LABEL_8;
  }
  mutex_lock(v5 + 584);
  v7 = v12;
  if ( v12 )
  {
    if ( v12 >= *(_DWORD *)(v5 + 1592) )
    {
      *(_DWORD *)(v5 - 104) = 0;
      printk(&unk_158A0, "haptic_hv", 2286, "rtp_auto_sin_store");
      goto LABEL_7;
    }
    v8 = v5 - 168;
    v9 = 32;
    *(_DWORD *)(v5 - 104) = 1;
    *(_DWORD *)(v5 - 24) = v7;
  }
  else
  {
    v8 = v5 - 168;
    v9 = 0;
    *(_DWORD *)(v5 - 104) = 0;
  }
  i2c_w_bits(v8, 45, 4294967263LL, v9);
LABEL_7:
  mutex_unlock(v5 + 584);
  queue_work_on(32, *(_QWORD *)(v5 + 928), v5 + 760);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
