__int64 __fastcall synx_uninitialize(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 (**v6)(void); // x8
  __int64 (*v7)(void); // x8

  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && (v6 = *(__int64 (***)(void))(a1 + 16)) != nullptr && (v7 = *v6) != nullptr )
  {
    if ( *((_DWORD *)v7 - 1) != -987686362 )
      __break(0x8228u);
    return v7();
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28B09, &unk_29207, "synx_uninitialize", 83, a5, a6);
    return 4294967274LL;
  }
}
