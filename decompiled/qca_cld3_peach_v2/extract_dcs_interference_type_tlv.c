__int64 __fastcall extract_dcs_interference_type_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 (*v13)(void); // x10
  const char *v15; // x2

  if ( !a2 )
  {
    v15 = "%s: Invalid dcs interference event buffer";
LABEL_8:
    qdf_trace_msg(0x31u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "extract_dcs_interference_type_tlv");
    return 4;
  }
  if ( !*(_QWORD *)a2 )
  {
    v15 = "%s: Invalid fixed param";
    goto LABEL_8;
  }
  *(_DWORD *)a3 = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
  v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3728LL);
  if ( *((_DWORD *)v13 - 1) != -2112860426 )
    __break(0x822Au);
  *(_DWORD *)(a3 + 4) = v13();
  *(_BYTE *)(a3 + 8) = *(_DWORD *)(*(_QWORD *)a2 + 12LL);
  return 0;
}
