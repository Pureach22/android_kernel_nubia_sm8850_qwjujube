__int64 __fastcall show_throttle_adj(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v4)(void); // x8
  int v5; // w3

  v4 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 8) + 48LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 718041638 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    v5 = 0;
  }
  return (int)scnprintf(a3, 4096, "%u\n", v5);
}
