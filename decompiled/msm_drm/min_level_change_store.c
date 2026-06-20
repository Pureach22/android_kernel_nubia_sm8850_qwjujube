__int64 __fastcall min_level_change_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  void (*v6)(void); // x8
  void *v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( !a1 )
  {
    v7 = &unk_241618;
LABEL_11:
    printk(v7, "min_level_change_store");
    a4 = -19;
    goto LABEL_13;
  }
  v4 = *(_QWORD *)(a1 + 152);
  if ( !v4 )
  {
    v7 = &unk_2339E9;
    goto LABEL_11;
  }
  if ( (unsigned int)kstrtoint(a3, 10, &v9) )
  {
    printk(&unk_241641, "min_level_change_store");
    a4 = -22;
  }
  else
  {
    v6 = *(void (**)(void))(v4 + 840);
    if ( v6 && *(_QWORD *)(v4 + 832) )
    {
      if ( *((_DWORD *)v6 - 1) != -538254584 )
        __break(0x8228u);
      v6();
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return a4;
}
