__int64 __fastcall wmi_service_enabled(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w0
  __int64 (*v12)(void); // x8

  if ( a2 > 0x154 || *(_DWORD *)(*(_QWORD *)(a1 + 752) + 4LL * a2) == 0xFFFF )
  {
    qdf_trace_msg(0x31u, 4u, "%s: Service %d not supported", a3, a4, a5, a6, a7, a8, a9, a10, "wmi_service_enabled", a2);
LABEL_4:
    v10 = 0;
    return v10 & 1;
  }
  v12 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2312LL);
  if ( !v12 )
    goto LABEL_4;
  if ( *((_DWORD *)v12 - 1) != 262049158 )
    __break(0x8228u);
  v10 = v12();
  return v10 & 1;
}
