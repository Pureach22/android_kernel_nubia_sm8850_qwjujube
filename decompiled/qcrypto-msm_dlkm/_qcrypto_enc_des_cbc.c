__int64 __fastcall qcrypto_enc_des_cbc(__int64 a1)
{
  _QWORD *v1; // x9
  __int64 v2; // x8
  __int64 v3; // x11

  v1 = *(_QWORD **)(a1 + 64);
  v2 = v1[7];
  if ( (*(_DWORD *)(v1[3] + 32LL) & 0xF) != 5 )
    __break(0x800u);
  *(_DWORD *)(a1 + 156) = 0;
  v3 = qword_11A40;
  *(_QWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  qword_11A40 = v3 + 1;
  return qcrypto_queue_req(v2, v1[6], a1 + 32);
}
