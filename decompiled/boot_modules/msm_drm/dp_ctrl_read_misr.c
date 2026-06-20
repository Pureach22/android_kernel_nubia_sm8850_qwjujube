__int64 __fastcall dp_ctrl_read_misr(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 272LL);
  if ( *((_DWORD *)v1 - 1) != -1513971590 )
    __break(0x8228u);
  return v1();
}
