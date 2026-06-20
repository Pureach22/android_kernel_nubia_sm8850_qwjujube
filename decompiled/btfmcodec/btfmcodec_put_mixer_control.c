bool __fastcall btfmcodec_put_mixer_control(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x10
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v12; // x22
  _DWORD **v13; // x23
  _DWORD *v14; // x8
  _QWORD v16[7]; // [xsp+18h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[7];
  v3 = *(_QWORD *)(a1[16] + 24LL);
  v16[2] = a1[6];
  v16[3] = v2;
  v4 = a1[9];
  v5 = *(_QWORD *)(v3 + 152);
  v16[4] = a1[8];
  v16[5] = v4;
  v6 = *(_QWORD *)(v5 + 984);
  v7 = *(unsigned int *)(v6 + 100);
  v8 = *(_QWORD *)(v6 + 88);
  v9 = a1[5];
  v16[0] = a1[4];
  v16[1] = v9;
  if ( (int)v7 < 1 )
  {
    LODWORD(v12) = 0;
  }
  else
  {
    v12 = 0;
    v13 = (_DWORD **)(v8 + 56);
    while ( strncmp((const char *)v16, (const char *)*(v13 - 5), 0x40u) )
    {
      ++v12;
      v13 += 10;
      if ( v7 == v12 )
      {
        LODWORD(v12) = v7;
        goto LABEL_10;
      }
    }
    v14 = *v13;
    if ( *(*v13 - 1) != -833906259 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v14)(a1, a2);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return (_DWORD)v7 != (_DWORD)v12;
}
