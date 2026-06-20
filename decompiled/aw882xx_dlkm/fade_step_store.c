__int64 __fastcall fade_step_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 *v6; // x8
  __int64 v7; // x1
  void *v8; // x0
  __int64 *v9; // x8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v11[0] = 0;
  if ( !(unsigned int)kstrtouint(a3, 10, v11) )
  {
    if ( LODWORD(v11[0]) > *(_DWORD *)(*(_QWORD *)(v5 + 96) + 612LL) )
    {
      v6 = *(__int64 **)(v5 + 64);
      v7 = v6[14];
      if ( !v7 )
        v7 = *v6;
      v8 = &unk_27310;
      goto LABEL_10;
    }
    aw882xx_dev_set_fade_vol_step();
  }
  v9 = *(__int64 **)(v5 + 64);
  v7 = v9[14];
  if ( !v7 )
    v7 = *v9;
  v8 = &unk_2814C;
LABEL_10:
  printk(v8, v7, "fade_step_store");
  _ReadStatusReg(SP_EL0);
  return a4;
}
