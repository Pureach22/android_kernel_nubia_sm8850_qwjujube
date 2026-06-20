__int64 __fastcall sub_17C760(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10)
{
  __int64 v10; // d27

  *(_QWORD *)(a8 + 168) = v10;
  *(double *)(a8 + 176) = a10;
  return _qdf_nbuf_data_get_eapol_subtype(a1, a2, a3, a4, a5, a6, a7, a8 + 168);
}
