__int64 __fastcall qcrypto_dec_aes_ctr(int *a1)
{
  __int64 v1; // x9
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v5; // x8
  int v6; // w9
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 result; // x0
  __int64 v11; // x12
  _QWORD s[59]; // [xsp+8h] [xbp-1D8h] BYREF

  s[58] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *((_QWORD *)a1 + 8);
  v2 = *(_QWORD *)(v1 + 56);
  if ( (*(_DWORD *)(*(_QWORD *)(v1 + 24) + 32LL) & 0xF) != 5 )
    __break(0x800u);
  if ( *(_DWORD *)(v1 + 216) == 24 && (*(_BYTE *)(v2 + 21) & 1) == 0 && *(_QWORD *)(v1 + 232) )
  {
    v3 = *((_QWORD *)a1 + 8);
    memset(s, 0, 0x1D0u);
    v5 = *(_QWORD *)(v3 + 232);
    v6 = a1[18];
    s[6] = 0;
    LODWORD(s[9]) = v6;
    v7 = *a1;
    s[7] = 0;
    s[8] = v5 + 8;
    v8 = *((_QWORD *)a1 + 2);
    v9 = *((_QWORD *)a1 + 3);
    LODWORD(s[0]) = v7;
    s[2] = v8;
    s[3] = v9;
    s[1] = *((_QWORD *)a1 + 1);
    LODWORD(v3) = crypto_skcipher_decrypt(s);
    memset(s, 0, *(unsigned int *)(s[8] - 8LL) + 80LL);
    result = (unsigned int)v3;
  }
  else
  {
    a1[39] = 0;
    v11 = qword_11A38;
    *((_QWORD *)a1 + 26) = 2;
    a1[54] = 2;
    qword_11A38 = v11 + 1;
    result = qcrypto_queue_req(v2, *(_QWORD *)(v1 + 48), a1 + 8);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
