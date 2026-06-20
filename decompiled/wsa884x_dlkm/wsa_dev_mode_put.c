__int64 __fastcall wsa_dev_mode_put(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x9
  __int64 v5; // x8
  int v6; // w10
  unsigned int v7; // w10

  v4 = *(_QWORD *)(a2 + 72);
  if ( v4 >= 2 )
    return 4294967274LL;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  v6 = *(unsigned __int8 *)(v5 + 268);
  *(_DWORD *)(v5 + 116) = v4;
  v7 = v4 | (2 * (v6 - 1 - ((v6 - 1 + (((v6 - 1) & 0x8000u) >> 15)) & 0x7FFFFFFE)));
  if ( v7 > 3 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return wsa884x_get_compander();
  }
  else
  {
    *(_BYTE *)(v5 + 236) = *(_DWORD *)(v5 + 4LL * v7 + 240);
    return 0;
  }
}
