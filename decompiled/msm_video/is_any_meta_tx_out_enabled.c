bool __fastcall is_any_meta_tx_out_enabled(__int64 a1)
{
  unsigned __int64 v1; // x9
  _BYTE *v2; // x13
  bool v3; // w12
  _BYTE *v4; // x11
  bool v5; // cf
  char v6; // t1
  __int64 v7; // x13

  v1 = 1;
  v2 = (_BYTE *)(a1 + 4536);
  v3 = 1;
  v4 = (_BYTE *)(a1 + 4536);
  do
  {
    v6 = *v4;
    v4 += 168;
    if ( v6 < 0 )
    {
      v7 = *((_QWORD *)v2 - 2);
      if ( (~(_BYTE)v7 & 5) == 0 || (v7 & 0x24) == 0x24 )
        break;
    }
    v5 = v1++ >= 0xC4;
    v2 = v4;
    v3 = !v5;
  }
  while ( v1 != 197 );
  return v3;
}
