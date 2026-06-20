__int64 __fastcall gmu_core_get_vrb_register(unsigned __int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 result; // x0

  result = 4294967277LL;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned __int64)a2 >= *(_QWORD *)(a1 + 40) >> 2 )
    {
      __break(0x800u);
      printk(&unk_13CB09);
      return 4294967274LL;
    }
    else
    {
      result = 0;
      *a3 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL * a2);
    }
  }
  return result;
}
