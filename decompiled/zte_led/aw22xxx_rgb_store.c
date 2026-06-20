__int64 __fastcall aw22xxx_rgb_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v7; // [xsp+0h] [xbp-10h] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( sscanf(s, "%x %x", &v7, (char *)&v7 + 4) == 2 && (unsigned int)v7 <= 8 )
  {
    *(_DWORD *)(v5 + 4LL * (unsigned int)v7 + 764) = HIDWORD(v7);
    printk(&unk_12A98, "aw22xxx_rgb_store");
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
