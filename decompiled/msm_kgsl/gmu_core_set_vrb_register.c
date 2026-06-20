__int64 __fastcall gmu_core_set_vrb_register(unsigned __int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x9

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned __int64)a2 >= *(_QWORD *)(a1 + 40) >> 2 )
    {
      __break(0x800u);
      printk(&unk_13DA5C);
      return 4294967274LL;
    }
    else
    {
      v3 = *(_QWORD *)(a1 + 8);
      *(_DWORD *)(v3 + 4LL * a2) = a3;
      __dsb(0xEu);
      return 0;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967277LL;
  }
}
