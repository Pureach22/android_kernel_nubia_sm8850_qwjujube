__int64 __fastcall synx_create(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  __int64 (*v7)(void); // x8

  if ( a1
    && a1 <= 0xFFFFFFFFFFFFF000LL
    && (v6 = *(_QWORD *)(a1 + 16)) != 0
    && (v7 = *(__int64 (**)(void))(v6 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v7 - 1) != 1142717801 )
      __break(0x8228u);
    return v7();
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28B09, &unk_29207, "synx_create", 93, a5, a6);
    return 4294967274LL;
  }
}
