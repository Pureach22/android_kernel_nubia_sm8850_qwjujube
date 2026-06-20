__int64 __fastcall aw22xxx_cfg_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( sscanf(s, "%u", &v7) == 1 )
  {
    *(_BYTE *)(v5 + 756) = v7 & 0xF;
    printk(&unk_12E8A, "aw22xxx_cfg_store");
  }
  else
  {
    printk(&unk_139C4, "aw22xxx_cfg_store");
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
