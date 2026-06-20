__int64 __fastcall dbg_prof_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 *v6; // x8
  __int64 v7; // x1
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9[0] = 0;
  if ( !(unsigned int)kstrtouint(a3, 10, v9) )
    *(_BYTE *)(v5 + 18) = LODWORD(v9[0]) != 0;
  v6 = *(__int64 **)(v5 + 64);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  printk(&unk_26FC5, v7, "dbg_prof_store");
  _ReadStatusReg(SP_EL0);
  return a4;
}
