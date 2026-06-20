__int64 __fastcall extract_dbr_ring_cap_service_ready_ext2_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v13; // x19
  __int64 (*v14)(void); // x8
  const char *v16; // x2
  __int64 v17; // x4

  if ( !a2 )
    return 4;
  if ( !*(_BYTE *)(a2 + 24) )
  {
    v16 = "%s: dma_ring_caps %d";
    v17 = 0;
LABEL_10:
    qdf_trace_msg(0x31u, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "validate_dbr_ring_caps_idx", v17);
    return 4;
  }
  if ( *(unsigned __int8 *)(a2 + 24) <= (unsigned int)a3 )
  {
    v17 = a3;
    v16 = "%s: Index %d exceeds range";
    goto LABEL_10;
  }
  v13 = (_DWORD *)(*(_QWORD *)(a2 + 16) + 24LL * a3);
  v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3712LL);
  if ( *((_DWORD *)v14 - 1) != -2112860426 )
    __break(0x8228u);
  *a4 = v14();
  a4[1] = v13[2];
  a4[2] = v13[3];
  a4[3] = v13[4];
  a4[4] = v13[5];
  return 0;
}
