__int64 __fastcall sch_send_beacon_report(__int64 result, __int64 a2)
{
  _DWORD *v2; // x20
  __int64 v3; // x22
  __int64 v5; // x9
  __int64 v6; // x0
  _QWORD v7[4]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v8; // [xsp+28h] [xbp-28h] BYREF
  __int64 v9; // [xsp+30h] [xbp-20h]
  __int64 v10; // [xsp+38h] [xbp-18h] BYREF
  unsigned __int64 v11; // [xsp+40h] [xbp-10h]
  __int64 v12; // [xsp+48h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(result + 12440);
  if ( v2
    && *(_DWORD *)(a2 + 88) == 2
    && *(unsigned __int8 *)(a2 + 24) == (unsigned __int8)byte_9177DF
    && *(unsigned __int8 *)(a2 + 25) == (unsigned __int8)byte_9177E0
    && *(unsigned __int8 *)(a2 + 26) == (unsigned __int8)byte_9177E1
    && *(unsigned __int8 *)(a2 + 27) == (unsigned __int8)byte_9177E2
    && *(unsigned __int8 *)(a2 + 28) == (unsigned __int8)byte_9177E3
    && *(unsigned __int8 *)(a2 + 29) == (unsigned __int8)byte_9177E4 )
  {
    v3 = result;
    v10 = 0;
    v11 = 0;
    v8 = 0;
    v9 = 0;
    memset(v7, 0, sizeof(v7));
    qdf_mem_copy((char *)&v8 + 2, &byte_9177DF, 6u);
    qdf_mem_copy(&v10, &sch_beacon_process_bcn, 8u);
    WORD2(v9) = word_917348;
    LODWORD(v9) = dword_917388;
    BYTE1(v7[0]) = byte_91734C;
    qdf_mem_copy((char *)v7 + 2, &unk_91734D, (unsigned __int8)byte_91734C);
    v5 = (unsigned __int128)(ktime_get_with_offset(1) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
    v6 = *(_QWORD *)(v3 + 12832);
    LOBYTE(v7[0]) = *(_BYTE *)(a2 + 10);
    v11 = ((v5 >> 7) + ((unsigned __int64)v5 >> 63)) / 0x3E8;
    if ( *(v2 - 1) != -239266345 )
      __break(0x8234u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v2)(v6, v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
