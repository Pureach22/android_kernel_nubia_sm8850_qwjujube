__int64 __fastcall sha256_digest(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x21
  __int64 v4; // x20
  int v6; // w9

  v1 = *(_QWORD *)(a1 + 32);
  *(_WORD *)(a1 + 224) = 1;
  *(_DWORD *)(a1 + 292) = 0;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(v1 + 68) = 1;
  *(_QWORD *)(a1 + 226) = 0;
  *(_QWORD *)(a1 + 456) = 0x85AE67BB67E6096ALL;
  *(_QWORD *)(a1 + 274) = 0;
  *(_QWORD *)(a1 + 282) = 0;
  *(_QWORD *)(a1 + 258) = 0;
  *(_QWORD *)(a1 + 266) = 0;
  *(_QWORD *)(a1 + 472) = 0x8C68059B7F520E51LL;
  *(_QWORD *)(a1 + 242) = 0;
  *(_QWORD *)(a1 + 250) = 0;
  *(_QWORD *)(a1 + 464) = 0x3AF54FA572F36E3CLL;
  *(_QWORD *)(a1 + 234) = 0;
  *(_QWORD *)(a1 + 480) = 0x19CDE05BABD9831FLL;
  *(_DWORD *)(v1 + 72) = 32;
  ++qword_11A78;
  v3 = *(_QWORD *)(a1 + 32);
  v4 = *(_QWORD *)(v3 + 56);
  if ( *(_BYTE *)(v4 + 25) == 1 && (unsigned int)copy_source(a1) )
    return 4294967284LL;
  v6 = *(_DWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 128) = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 136) = v6;
  *(_WORD *)(a1 + 224) = 257;
  return qcrypto_queue_req(v4, *(_QWORD *)(v3 + 48), a1);
}
