bool __fastcall is_any_meta_tx_inp_enabled(__int64 a1)
{
  unsigned __int64 v1; // x9
  bool v2; // w11
  _BYTE *v3; // x12
  _BYTE *v4; // x10
  bool v5; // cf
  char v6; // t1
  __int64 v7; // x12

  v1 = 1;
  v2 = 1;
  v3 = (_BYTE *)(a1 + 4536);
  v4 = (_BYTE *)(a1 + 4536);
  do
  {
    v6 = *v4;
    v4 += 168;
    if ( v6 < 0 )
    {
      v7 = *((_QWORD *)v3 - 2);
      if ( (~(_BYTE)v7 & 3) == 0 || (v7 & 0x22) == 0x22 )
        break;
    }
    v5 = v1++ >= 0xC4;
    v3 = v4;
    v2 = !v5;
  }
  while ( v1 != 197 );
  return v2;
}
