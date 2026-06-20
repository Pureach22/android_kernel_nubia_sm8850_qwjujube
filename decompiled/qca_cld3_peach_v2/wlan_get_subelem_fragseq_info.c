__int64 __fastcall wlan_get_subelem_fragseq_info(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        _BYTE *a4,
        _QWORD *a5,
        _QWORD *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  return wlan_get_elemsubelem_fragseq_info(1, a7, a8, a9, a10, a11, a12, a13, a14, a1, a2, a3, a4, a5, a6);
}
