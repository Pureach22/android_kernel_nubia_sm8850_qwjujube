__int64 __fastcall sme_qos_ese_retrieve_tspec_info(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  __int64 v3; // x22
  __int64 v5; // x21
  unsigned int v6; // w20
  __int64 v7; // x8
  unsigned int v8; // w26
  unsigned int v9; // w28
  __int64 v10; // x27
  bool v11; // cc
  unsigned int v12; // w8
  __int64 v13; // x9
  unsigned __int8 v15; // [xsp+Ch] [xbp-4h]

  v3 = qword_856120 + 3040LL * a2;
  v5 = 0;
  v6 = 0;
  while ( 2 )
  {
    v7 = v3 + 728 * v5;
    v15 = 0;
    v8 = *(unsigned __int8 *)(v7 + 322);
    v9 = *(unsigned __int8 *)(v7 + 321);
    v10 = v7 + 4;
    do
    {
      if ( (v9 & 1) != 0 && (v8 & 1) != 0 )
      {
        v12 = v15;
        if ( v15 >= 3u )
          goto LABEL_16;
        v13 = 164;
LABEL_4:
        sme_qos_copy_tspec_info(v10 + v13 + 76LL * v12, a3 + 1);
        ++v6;
        *a3 = 1;
        a3 += 59;
        goto LABEL_5;
      }
      if ( (v9 & 1) != 0 && (v8 & 1) == 0 )
      {
        v12 = v15;
        if ( v15 > 2u )
        {
LABEL_16:
          __break(0x5512u);
          return ((__int64 (*)(void))sme_qos_copy_tspec_info)();
        }
        v13 = 12;
        goto LABEL_4;
      }
LABEL_5:
      v8 >>= 1;
      v11 = v9 > 1;
      v9 >>= 1;
      ++v15;
    }
    while ( v11 );
    if ( ++v5 != 4 )
      continue;
    return v6;
  }
}
